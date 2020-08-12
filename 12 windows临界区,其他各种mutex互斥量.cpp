#include"stdafx.h"
//#include<iostream>
//#include<thread>
//#include<mutex>
//#include<list>
//#include<future>
//#include<Windows.h>
//using namespace std;
//
////#define _WINDOWSJQ_
//
////本类用于自动释放windows下的临界区，防止忘记LeaveCriticalSection导致死锁情况的发生，类似于c++11中的std::lock_guard<std::mutex>
//class CWinLock {	//叫RAII类（Resource Acquisition is Initialization）：“资源获取即初始化”
//					//容器，智能指针这种类，都属于RAII类；
//public:
//	CWinLock(CRITICAL_SECTION* pCritmp) {	//构造函数
//		m_pCritical = pCritmp;
//		EnterCriticalSection(m_pCritical);
//	}
//
//	~CWinLock()
//	{
//		LeaveCriticalSection(m_pCritical);
//	}
//	
//private:
//	CRITICAL_SECTION* m_pCritical;
//};
//
//class A {
//public:
//	//把收到的消息入到队列的线程
//	void inMsgRecvQueue() {
//		for (int i = 0; i < 100000; i++)
//		{
//			cout << "inMsgRecvQueue()x执行，插入一个元素" << i << endl;
//#ifdef _WINDOWSJQ_
//			//EnterCriticalSection(&my_winsec);	//进入临界区（加锁）
//			//EnterCriticalSection(&my_winsec);
//			CWinLock wlock(&my_winsec);		//wlock属于RAII对象 
//			msgRecvQueue.push_back(i);
//			//LeaveCriticalSection(&my_winsec);	//离开临界区（解锁）
//			//LeaveCriticalSection(&my_winsec);
//#else
//			//my_mutex.lock();
//			//std::lock_guard<std::recursive_mutex> sbguard(my_mutex);
//			//testfunction1();		//加锁3次,std::mutex报异常（超过一次就异常） std::recursive_mutex可以多次加锁
//
//			std::chrono::milliseconds timeout(100);	//100毫秒
//			//if (my_mutex.try_lock_for(timeout)) {
//			if (my_mutex.try_lock_until(std::chrono::steady_clock::now() + timeout)) {
//				msgRecvQueue.push_back(i);	//假设这个数字就是我收到的命令，我直接弄到消息队列里来。
//				my_mutex.unlock();	//用完了要解锁
//			}
//			else {
//				//这次没拿到锁
//				std::chrono::milliseconds sleeptime(100);
//				std::this_thread::sleep_for(sleeptime);
//
//			}
//			//my_mutex.unlock();
//#endif // _WINDOWSJQ
//		}
//	}
//
//	bool outMsgLULProc(int& command) {
//#ifdef _WINDOWSJQ_
//		EnterCriticalSection(&my_winsec);
//		if (!msgRecvQueue.empty()) {
//			command = msgRecvQueue.front();
//			msgRecvQueue.pop_front();
//			LeaveCriticalSection(&my_winsec);
//			return true;
//		}
//		LeaveCriticalSection(&my_winsec);
//#else
//		my_mutex.lock();
//		std::chrono::milliseconds sleeptime(10000);
//		std::this_thread::sleep_for(sleeptime);
//		if (!msgRecvQueue.empty())
//		{
//			command = msgRecvQueue.front();
//			msgRecvQueue.pop_front();
//			my_mutex.unlock();
//			return true;
//		}
//		my_mutex.unlock(); 
//#endif // _WINDOWS_
//		return false;
//	}
//
//
//	void outMsgRecvQueue() {
//		int command = 0;
//		for (int i = 0; i < 100000; i++) {
//			bool result = outMsgLULProc(command);
//			if (result = true) {
//				cout << "outMsgRecvQueue() 执行，取出一个元素" << command << endl;
//				//这里考虑处理数据
//			}
//			else {
//				cout << "outMsgRecvQueue() 执行,但目前还是空元素" << i << endl;
//			}
//		}
//		cout << "end" << endl;
//	}
//	
//	A() 
//	{
//#ifdef _WINDOWSJQ_
//		InitializeCriticalSection(&my_winsec);	//用临界区前需要先初始化
//
//#endif // _
//	}
//
//	//void testfunction1() {
//	//	std::lock_guard<std::recursive_mutex> sbguard1(my_mutex);
//	//	//做一些事情
//	//	testfunction2();
//	//}
//
//	//void testfunction2() {
//	//	std::lock_guard<std::recursive_mutex> sbguard2(my_mutex);
//	//	//做另外的一些事情
//	//}
//
//private:
//	std::list<int> msgRecvQueue;
//	//std::mutex my_mutex;				//独占互斥量
//	//std::recursive_mutex my_mutex;	//递归独占互斥量
//	std::timed_mutex my_mutex;			//超时独占互斥量
//#ifdef _WINDOWSJQ_
//	CRITICAL_SECTION my_winsec; //windows中的临界区，非常类似于c++11中的mutex
//#endif // _
//};
//
//int main() {
//	
//	//一：windows临界区
//	//二：多次进入临界区试验
//	//在"同一个线程"（不同线程会卡住等待）中，windows中的“相同临界区变量”代表的临界区的进入（EnterCriticalSection）可以被多次进入
//		//但是你调用了几次EnterCriticalSection，你就得调用几次LeaveCriticalSection
//		//而在c++11中，不允许 同一个线程中lock同一个互斥量多次，否则会报异常
//
//	//三：自动析构技术
//	//sd::lock_guard<std::mutex>
//
//	//四：recursive_mutex递归的独占互斥量
//	//std::mutex::独占互斥量，自己lock时，别人lock不了
//	//std::recursive_mutex:递归的独占互斥量：允许同一个线程，同一个互斥量多次被.lock(),效率上比mutex要差一些。
//		//recursive_mutex也有lock()，也有unlock()
//		//考虑代码是否有优化空间
//		//递归次数据说有限制，递归太多次可能报异常。
//
//	//五：带超时的互斥量std::timed_mutex和std::recursive_timed_mutex
//	//std::timed_mutex：是带超时功能的独占互斥量
//			//try_lock_for() : 参数是一段时间，是等待一段时间。如果我拿到了锁，或者等待超过时间没拿到锁，就走下来
//			//tru_lock_until(): 参数是未来的一个时间点，在这个未来的时间没到的时间内，如果拿到了锁，那么就走下来；
//													//如果时间到了，没拿到锁，程序流程也走下来
//
//	//std::recursive_timed_mutex:带超时功能的递归独占互斥量（允许同一个线程多次获取这个互斥量）
//
//	A myobja;
//
//	std::thread myOutMsgObj(&A::outMsgRecvQueue, &myobja);
//	std::thread myInMsgObj(&A::inMsgRecvQueue,&myobja);	//注意这里第二个参数必须是引用，才能保证线程里用的是同一个对象
//
//
//	myInMsgObj.join();
//	myOutMsgObj.join();
//
//	system("pause");
//	return 0;
//}