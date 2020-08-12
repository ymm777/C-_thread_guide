#include"stdafx.h"
//#include<iostream>
//#include<mutex>
//#include<list>
//#include<thread>
//using namespace std;
//
//class A {
//public:
//
//	std::unique_lock<std::mutex> rtn_unique_lock() {
//		std::unique_lock<std::mutex> tmpguard(my_mutex1);
//		return tmpguard;		//从函数返回一个局部的unique_lock对象是可以的，移动构造函数
//								//返回这种局部对象temguard会导致系统生成临时的unique_lock对象，并调用unique_lock的移动构造函数
//	}
//
//	void inMsgRecvQueue()
//	{
//		for (int i = 0; i < 100000; i++) {
//			cout << "inMsgRecvQueue执行,插入一个元素：" << i << endl;
//
//			//my_mutex1.lock();
//			//std::unique_lock<std::mutex> sbguard1(my_mutex1,std::adopt_lock);
//
//			//std::unique_lock<std::mutex> sbguard1(my_mutex1, std::try_to_lock);
//
//			//std::unique_lock<std::mutex> sbguard1(my_mutex1, std::defer_lock);
//			
//			//sbguard1.lock();
//			//处理共享数据
//			//sbguard1.unlock();
//			//处理一些非共享数据
//			
//			//std::unique_lock<std::mutex> sbguard1(my_mutex1);
//
//			//std::unique_lock<std::mutex> sbguard2(sbguard1);		//复制所有权非法
//
//			//std::unique_lock<std::mutex> sbguard2(std::move(sbguard1));	//移动语义,现在sbguard2与mutex绑定
//																		//现在sbguard1指向空，sbguard2指向mutex
//
//			std::unique_lock<std::mutex> sbguard1 = rtn_unique_lock();
//
//			//std::mutex *ptr = sbguard1.release();
//
//
//			//sbguard1.lock();
//
//			//if (sbguard1.owns_lock()) {
//				//拿到了锁
//			msgRecvQueue.push_back(i);
//			//}
//			//else {
//				//没拿到锁
//			//	cout << "inMsgRecvQueue执行，但没有拿到锁，只能干点别的事" << i << endl;
//			//}
//			//sbguard1.lock();	//画蛇添足
//			//ptr->unlock();
//		}
//	}
//
//	bool outMsgLULProc(int& command)
//	{
//		//std::lock_guard<std::mutex> sbguard1(my_mutex1);
//
//		my_mutex1.lock();
//		std::unique_lock<std::mutex> sbguard1(my_mutex1,std::adopt_lock);
//
//		//std::chrono::milliseconds dura(2000);
//		//std::this_thread::sleep_for(dura);	//休息一定时长
//
//		if (!msgRecvQueue.empty()) {
//			command = msgRecvQueue.front();
//			msgRecvQueue.pop_front();
//			return true;
//		}
//		return false;
//	}
//
//	void outMsgRecvQueue() {
//		int command = 0;
//		for (int i = 0; i < 100000; i++) {
//			bool result = outMsgLULProc(command);
//			if (result == true) {
//				cout << "outMsgRecvQueue()执行了，取出一个元素" << command << endl;
//			}
//			else
//			{
//				cout << "outMsgRecvQueue()执行了，但目前消息队列为空" << endl;
//			}
//		}
//		cout << endl;
//	}
//
//	//void outMsgRecvQueue() {
//	//	for (int i = 0; i < 10000; i++) {
//	//		if (!msgRecvQueue.empty()) {
//	//			cout << "outMsgRecvQueue()执行了，取出一个元素" << endl;
//	//			msgRecvQueue.pop_front();
//	//		}
//	//		else {
//	//			cout << "outMsgRecvQueue()执行了，但目前消息队列为空" << endl;
//	//		}
//	//	}
//	//	cout << endl;
//	//}
//
//private:
//	list<int> msgRecvQueue;
//	mutex my_mutex1;
//	mutex my_mutex2;
//};
//
//
//
//int main() {
//
//	//一：unique_lock取代lock_guard
//	//unique_lock是个类模板，工作中，一般lock_guard(推荐使用)；lock_guard取代了mutex的lock()和unlock()
//	//unique_lock比lock_guard灵活很多，效率上差一点，内存占用多一点
//	//二：unique_lock的第二个参数
//	//lock_guard可以带第二个参数
//
//	//std::lock_guard<std::mutex> sbguard1(my_mutex1,adop_lock)	//adop_lock标记作用
//	//(2.1)std::adop_lock:表示这个互斥量已经被lock了（你必须要把互斥量提前lock，否则会报异常）
//	//std::adop_lock标记的作用就是“假设调用方 线程已经拥有了互斥的所有权（已经lock()成功）；
//	//通知lock_guard不需要在构造函数中lock这个互斥量了；
//	//unique_lock也可以带std::adop_lock这个标记，含义相同，就是不希望在unique_lock()的构造函数中lock这个mutex。
//	//用这个adop_lock的前提是，你需要自己先把mutex先lock上
//
//	//(2.2)std::try_to_lock
//	//我们会尝试用mutex的lock()去锁定这个mutex，但如果没有锁定成功，我也会立即返回，并不会阻塞在那里。
//	//用这个try_to_lock的前提是你自己不能先去lock()；
//
//	//(2.3)std::defer_lock
//	//用这个defer_lock的前提是 你不能自己先lock否则会报异常
//	//defer_lock的意思 就是 没有给mutex加锁，初始化了一个未加锁的mutex
//	//我们借着defer_lock的话题来介绍一些unique_lock的重要成员函数
//
//	//三：unique_lock的成员函数
//	//(3.1) lock(),加锁
//	//(3.2) unlock(),解锁
//	//(3.3) try_lock(),尝试给互斥量加锁，如果加锁成功返回true，否则返回false，这个函数是不能阻塞的。
//	//(3.4) release(),返回它所管理的mutex对象指针，并释放所有权，也就是说，这个unique_lock和mutex不再有关系
//	//严格区分unlock()和release()的区别，不要混淆。
//	//如果原来mutex对象处于加锁转状态，你有责任接管过来并负责解锁。（release返回的是原始mutex的指针）
//	//为什么有时候需要unlock(),因为lock()锁住的代码越少，执行越快，整个程序的效率越高
//	//有人也把lock()锁住的代码多少 称为 锁的粒度，粒度一般用粗细来描述
//	//a)锁住的代码少，叫做粒度细，执行效率高
//	//b)锁住的代码多，粒度叫粗，那么执行效率低。
//	//要尽量选择合适粒度的代码进行保护，粒度太细，可能漏掉共享数据的保护，粒度太粗，导致执行效率低
//
//	//四：unique_lock所有权的传递mutex
//	//std::unique_lock<std::mutex> sbguard1(my_mutex1); 所有权概念
//	//sbguard1拥有my_mutex1的所有权
//	//sbguard1可以把自己对mutex（my_mutex1）的所有权转移给其他的unique_lock对象
//	//所以，unique_lock对象这个mutex的所有权可以转移但是不可以复制、
//
//	//a)std::move
//	//b)return	std::unique_lock<std::mutex>
//
//	A myobja;
//
//	thread myInMsgObj(&A::inMsgRecvQueue, &myobja);
//
//	thread myOutMsgObj(&A::outMsgRecvQueue, &myobja);
//
//	myInMsgObj.join();
//	myOutMsgObj.join();
//
//	return 0;
//}