#include"stdafx.h"
//#include<iostream>
//#include<thread>
//#include<mutex>
//#include<future>
//
//using namespace std;
//
////int g_mycount = 0;
//
////std::atomic<int> g_mycount = 0;	//我们封装了一个类型为int的对象（值）；我们可以像操作一个int类型变量来操作这个atomic
//
////mutex g_my_mutex;
//
////void mythread() {		//线程入口函数
////	for (int i = 0; i < 10000000; i++) {
////		//g_my_mutex.lock();	//执行完需要7s
////		//g_mycount++;
////		//g_my_mutex.unlock();
////		g_mycount++;	//对应的操作是原子操作（不会被打断） 
////	}
////}
//
//std::atomic<bool> g_myflag = false;
//
//void mythread() {
//	std::chrono::milliseconds dura(1000);	//1秒钟
//	while (g_myflag == false) {
//		//系统没有要求线程退出，所以本线程可以干自己想干的事情
//		cout << "thread id=" << std::this_thread::get_id() << " 正在执行...." << endl;
//		std::this_thread::sleep_for(dura);
//	}
//	cout << "thread id=" << std::this_thread::get_id() << " 运行结束..." << endl;
//}
//
//int main() {
//
//	//三：原子操作std::atomic
//	//(3.1)原子操作概念引出范例
//	//互斥量：多线程编程中 保护共享数据： 锁，操作共享数据，开锁
//	//大家可以把原子操作理解成一种：不需要用到互斥量加锁（无锁）技术的多线程并发编程方式
//	//原子操作：是在多线程中 不会被打断的 程序执行片段，比互斥量效率上更胜一筹。
//	//互斥量的加锁一般是针对一个代码段（几行代码），而原子操作针对的一般都是一个变量，而不是一个代码段；
//
//	//原子操作，一般都是指“不可分割的操作”；
//	//std::atomic来代表原子操作，std::atomic是个类模板。其实std::atomic这个东西是用来封装某个类型的值的。
//
//	//(3.2)基本std::atomic用法范例
//	//(3.3)老师的心得：一般用于计数或统计（累计发送出去了多少个数据包，累计接受到了多少个数据包）
//
//	//std::thread mytboj1(mythread);
//	//std::thread mytboj2(mythread);
//
//	//mytboj1.join();
//	//mytboj2.join();
//
//	//cout << "线程执行完毕，g_mycount=" << g_mycount << endl;
//
//	std::thread mytobj1(mythread);
//	std::thread mytobj2(mythread);
//
//	std::chrono::milliseconds dura(5000);	//五秒钟
//	std::this_thread::sleep_for(dura);
//
//	g_myflag = true;
//
//	mytobj1.join();
//	mytobj2.join();
//
//	cout << "程序执行完毕，退出" << endl;
//
//	system("pause");
//	return 0;
//}