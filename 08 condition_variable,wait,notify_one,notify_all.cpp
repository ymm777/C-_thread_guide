#include"stdafx.h"
//#include<iostream>
//using namespace std;
//#include<list>
//#include<thread>
//#include<mutex>
//
//class A {
//public:
//	void inMsgRecvQueue()
//	{
//		for (int i = 0; i < 100000; i++) {
//			cout << "inMsgRecvQueue()执行,插入一个元素" << i << endl;
//
//			std::unique_lock<std::mutex> sbguard1(my_mutex1);
//			msgRecvQueue.push_back(i);	//假设这个数字i是收到的命令，我直接加入到消息队列
//
//			//假如outMsgRecvQueue()正在处理一个事务，需要一段时间，而不是正卡在wait()那里等你唤醒，那么此时这个notify_one也许就没效果
//			//my_cond.notify_one();	//尝试把wait()线程唤醒，执行完这行，那么outMsgRecvQueue()里面的wait()就会被唤醒
//									//唤醒之后的事，后续再研究
//			my_cond.notify_all();
//			//....
//			//其他处理代码	
//		}
//	}
//
//	//bool outMsgLULProc(int& command) {
//	//	std::unique_lock<std::mutex> sbguard1(my_mutex1);
//
//	//	if (!msgRecvQueue.empty()) {
//	//		command = msgRecvQueue.front();
//	//		msgRecvQueue.pop_front();
//	//		return true;
//	//	}
//	//	return false;
//	//}
//
//	void outMsgRecvQueue() {
//		int command = 0;
//
//		while (true)
//		{
//			std::unique_lock<std::mutex> sbguard1(my_mutex1);
//
//			//wait()用来等一个东西
//			//如果第二个参数lambda表达式返回值是true，那wait()直接返回;
//			//如果第二个参数lambda表达式返回值是false，那么wait()将解锁互斥量，并堵塞到本行;
//				//	那堵塞到什么时候为止呢？堵塞到其他某个线程调用notify_one()成员函数为止;
//			//如果wait()没有第二个参数：my_cond.wait(sbguard1); 那么就跟第二个参数lambda表达式返回false效果一样。
//				//wait()将解锁互斥量，并堵塞到本行，堵塞到其他某个线程调用notify_one()成员函数为止；
//			//当其他线程用notify_one()将本wait()(原来是睡眠/堵塞)的状态唤醒后，wait就开始恢复干活了，恢复后wait干什么？
//				//a)wait()不断尝试重新获取互斥量锁，如果获取不到,那么流程就卡在wait这里等着获取，如果获取到了锁（获取到就加锁）就继续往下执行b
//				//b)
//					//b.1)如果wait有第二个参数(lambda),就判断这个lambda表达式，如果lambda表达式为false，那么wait又释放锁，等待其他线程notify_one唤醒
//					//b.2)如果lambda表达式为true，则wait返回，流程走下来（此时互斥锁被锁着）
//					//b.3)如果wait没有第二个参数，则wait返回，流程走下来。
//
//
//			my_cond.wait(sbguard1, [this] {		//一个lambda就是一个可调用对象(函数)
//				if (!msgRecvQueue.empty())
//					return true;
//				return false;
//				});
//
//			//流程只要能走到这里，这个互斥锁一定是锁着的,同时msgRecvQueue至少有一条数据
//			command = msgRecvQueue.front();
//			msgRecvQueue.pop_front();
//			cout << "outMsgRecvQueue()执行了，取出一个元素" << "thread_id=" << std::this_thread::get_id() << command << endl;
//			sbguard1.unlock();	//因为unique_lock的灵活性，所以我们可以随时unlock,以免锁住太长时间
//
//
//			//执行一些具体动作，帮助玩家抽卡，抽卡需要100毫秒的处理时间
//			//....
//			//执行100毫秒
//			//
//		}
//		
//		//for (int i = 0; i < 100000; i++) {
//		//	bool result = outMsgLULProc(command);
//		//	if (result) {
//		//		cout << "outMsgRecvQueue()执行了，取出一个元素" << command << endl;
//		//	}
//		//	else {
//		//		cout << "outMsgRecvQueue()执行了，但目前消息队列为空" << endl;
//		//	}
//		//}
//	}
//
//private:
//	mutex my_mutex1;
//	list<int> msgRecvQueue;
//	std::condition_variable my_cond;
//};
//
//int main() {
//
//	//一：条件变量std::condition_variable,wait(),notify_one:只能通知一个outMsgRecvQueue线程
//	//线程A：等待一个条件满足
//	//线程B：专门往消息队列中扔消息（数据）
//	//std::condition_variable实际上是一个类，是一个和条件相关的一个类，说白了就是等待一个条件达成
//	//这个类是需要和互斥量来配合工作，用的时候我们要生成这个类的对象；
//
//	//二：上述代码深入思考
//
//	//三：notify_all
//
//	A myobja;
//	std::thread myOutMsgObj(&A::outMsgRecvQueue, &myobja);	//第二个参数是引用，才能保证线程里 用的是同一个对象
//	std::thread myOutMsgObj2(&A::outMsgRecvQueue, &myobja);
//	std::thread myInMsgObj(&A::inMsgRecvQueue, &myobja);
//	myInMsgObj.join();
//	myOutMsgObj.join();
//	myOutMsgObj2.join();
//
//	system("pause");
//	return 0;
//}