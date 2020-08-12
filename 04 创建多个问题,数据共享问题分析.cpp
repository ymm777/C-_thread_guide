#include"stdafx.h"
//#include<iostream>
//using namespace std;
//#include<vector>
//#include<thread>
//
//vector<int>g_v = { 1,2,3 };
//
////线程入口函数
//void myprint(int numi)
//{
//	//cout << "我的线程开始执行了，线程编号为：" << numi << endl;
//	//cout << "我的线程结束执行了，线程编号为：" << numi << endl;
//	cout << "线程号为" << std::this_thread::get_id() << "开始打印数组g_v" << g_v[0] << g_v[1] << g_v[2] << endl;
//}
//
//int main()
//{
//	//一：创建和等待多个线程
//	vector<thread> mythreads;
//	//创建10个线程，线程入口函数统一使用myprint
//	//a)多个线程执行顺序是乱的，跟操作系统内部对线程的运行调度机制有关。
//	//b)主线程等待所有子线程运行结束，最后主线程结束，老师推荐这种join()的写法，更容易写出稳定的程序。
//	//c)咱们把thread对象放到容器中管理，看起来像是个thread对象数组，这对我们一次创建大量的线程并对大量线程进行管理很方便。
//
//	for (int i = 0; i < 10; i++)
//	{
//		mythreads.push_back(thread(myprint, i));	//创建10个线程，同时这10个线程已经开始执行
//	}
//
//	for (auto iter = mythreads.begin(); iter != mythreads.end(); iter++) {
//		iter->join();	//等待10个线程都返回
//	}
//
//	cout << "I Love China！" << endl;	//最后执行这句，整个进程退出
//
//	//二：数据共享问题分析
//	//(2.1)只读的数据：是安全稳定的，不需要特别什么处理手段，直接读就可以。
//	//(2.2)有读有写
//	//(2.3)其他案例

//	return 0;
//