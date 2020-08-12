#include"stdafx.h"
//#include<iostream>
//using namespace std;
//#include<list>
//#include<thread>
//#include<mutex>
//
//
//class A
//{
//public:
//	void inMsgRecvQueue()
//	{
//		for (int i = 0; i < 10000; i++)
//		{
//			cout << "inMsgRecvQueue()执行，插入一个元素" << i << endl;
//			{
//				//std::lock_guard<mutex> sbguard1(my_mutex1);
//				//std::lock_guard<mutex> sbguard2(my_mutex2);
//				//my_mutex1.lock();
//				//my_mutex2.lock();
//				std::lock(my_mutex1, my_mutex2);
//				std::lock_guard<mutex> sbguard1(my_mutex1, adopt_lock);
//				std::lock_guard<mutex> sbguard2(my_mutex2, adopt_lock); 
//				msgRecvQueue.push_back(i);
//			}
//
//
//			//my_mutex1.unlock();
//			//my_mutex2.unlock();
//		}
//	}
//
//	bool outMsgLULProc(int& command)
//	{
//		//std::lock_guard<mutex> sbguard1(my_mutex1);	//sbguard是随便起的名 lock_guard<>也是一个模板，使用lock_guard不能再使用lock，unlock
//													//lock_guard构造函数里执行了mutex::lock();  lock_guard析构函数里执行mutex::unlock();
//													//但是lock_guard生成的对象在退出时会析构调用mutex::unlock();
//		//std::lock_guard<mutex> sbguard2(my_mutex2);
//		lock(my_mutex1, my_mutex2);
//		std::lock_guard<mutex> sbguard1(my_mutex1, std::adopt_lock);
//		std::lock_guard<mutex> sbguard2(my_mutex2, std::adopt_lock);
//		//my_mutex2.lock();
//		//my_mutex1.lock();
//		if (!msgRecvQueue.empty())
//		{
//			//消息不为空
//			int command1 = msgRecvQueue.front();
//			msgRecvQueue.pop_front();
//			//my_mutex1.unlock();
//			//my_mutex2.unlock();
//			return true;
//		}
//		//my_mutex1.unlock();
//		//my_mutex2.unlock();
//		return false;
//	}
//
//	void outMsgRecvQueue()
//	{
//		int command = 0;
//		for (int i = 0; i < 10000; i++)
//		{
//			bool result = outMsgLULProc(command);
//			if (result == true)
//			{
//				cout << "outMsgRecvQueue()执行了，取出一个元素" << command << endl;
//			}
//			else {
//				cout << "outMsgRecvQueue()执行了，但目前消息队列为空" << endl;
//			}
//		}
//		cout << "end!" << endl;
//	}
//
//private:
//	list<int>msgRecvQueue;
//	mutex my_mutex1;
//	mutex my_mutex2;
//};
//
//
//int main()
//{
//	//一、互斥量（mutex)
//	//互斥量是个类对象，使用需要包含#include<mutex>
//	//互斥量使用要小心，保护数据不多也不少，少了，没有达到保护效果，多了影响效率
//
//	//二：互斥量的用法
//	//(2.1)lock(),unlock()
//	//每一个lock()必然要有unlock(),一个lock()，有多少出口就要对应多少个unlock()；
//	//有lock(),没有unlock()的问题非常难排查
//	//为了防止大家忘记unlock()，引入了一个叫std::loch_guard的类模板：你忘记unlock()不要紧，系统替你unlock();
//	//学过智能指针(unique_ptr<>)：你忘了释放内存不要紧，我给你释放；
//
//	//(2.2)std::lockguard<>类模板：直接取代lock()和unlocjk();也就是说，你用了lock_guard之后不能在使用lock()和unlocjk();
//
//	//三：死锁
//	//(3.1)死锁演示
//	//(3.2)死锁的一般解决方案
//	//只要保证这两个互斥量上锁的顺序一致就不会死锁
//	//(3.3)std::lock()函数模板：用来处理多个互斥量
//	//能力：一次锁住两个或两个以上的互斥量（一个不行）
//	//它不存在这种因为多个线程中 因为锁的顺序问题导致死锁的风险问题
//	//std::lock():如果互斥量中有一个没锁，就会等待所有互斥量都锁住，才往下走
//	//要么两个互斥量都锁住。要么都没锁住。如果只锁了一个。另一个没成功，没立刻释放已经锁定的
//
//	//(3.4)std::lock_guard的std::adop_lock参数
//	//std::adop_lock是个结构体对象，起一个标记作用：表示该互斥量已经lock()过了，不需要在std::lock_guard<std::mutex>再次lock();
//	//总结：std::lock()；一次锁定多个互斥量。谨慎使用（建议一个一个锁）
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