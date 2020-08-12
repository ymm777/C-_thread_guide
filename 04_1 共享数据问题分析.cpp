#include"stdafx.h"
//#include<iostream>
//#include<list>
//#include<thread>
//using namespace std;
//
//class A
//{
//public:
//	//把收到的消息（玩家命令）存入到一个队列的线程
//	void inMsgRecvQueue()
//	{
//		for (int i = 0; i < 10000; i++)
//		{
//			cout << "inMsgRecvQueue()执行，插入一个元素" << i << endl;
//			msgRecvQueue.push_back(i);	//假设这个数字i就是我收到的命令，我直接弄到消息队列里面来
//		}
//	}
//	//把数据从消息队列中取出的线程
//	void outMsgRecvQueue()
//	{
//		for (int i = 0; i < 10000; i++)
//		{
//			if (!msgRecvQueue.empty())
//			{
//				//消息队列不为空
//				int command = msgRecvQueue.front();	//返回第一个元素，但不检查元素是否存在
//				msgRecvQueue.pop_front();	//移除第一个元素，但不返回
//			}
//			else {
//				//消息队列为空
//				cout << "outMsgRecvQueue()执行，但目前消息队列为空" << endl;
//				
//			}
//		}
//		cout << "end!" << endl;
//	}
//private:
//	list<int>msgRecvQueue;
//};
//
//int main() {
//
//	//三：共享数据的保护案例代码
//	//网络游戏服务器。两个自己创建的线程，一个线程收集玩家的命令（用一个数字代表玩家发送的命令），并把命令数据写入一个容器
//	//									另一个线程 从队列中去除玩家	发送来的命令，解析，然后执行玩家需要的动作。
//	//准备用成员函数作为线程函数方法来写线程。
//	//代码化解决问题：引入一个c++解决线程保护共享数据问题的第一个概念：”互斥量“；
//
//	A myobja;
//	std::thread myOutMsgObj(&A::outMsgRecvQueue, &myobja);	//第二个参数是引用，才能保证线程里使用的是同一个对象
//	std::thread myInMsgObj(&A::inMsgRecvQueue, &myobja);
//
//	myInMsgObj.join();
//	myOutMsgObj.join();
//
//	return 0;
//}