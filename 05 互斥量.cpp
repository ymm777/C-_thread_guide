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
//			cout << "inMsgRecvQueue()ִ�У�����һ��Ԫ��" << i << endl;
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
//		//std::lock_guard<mutex> sbguard1(my_mutex1);	//sbguard���������� lock_guard<>Ҳ��һ��ģ�壬ʹ��lock_guard������ʹ��lock��unlock
//													//lock_guard���캯����ִ����mutex::lock();  lock_guard����������ִ��mutex::unlock();
//													//����lock_guard���ɵĶ������˳�ʱ����������mutex::unlock();
//		//std::lock_guard<mutex> sbguard2(my_mutex2);
//		lock(my_mutex1, my_mutex2);
//		std::lock_guard<mutex> sbguard1(my_mutex1, std::adopt_lock);
//		std::lock_guard<mutex> sbguard2(my_mutex2, std::adopt_lock);
//		//my_mutex2.lock();
//		//my_mutex1.lock();
//		if (!msgRecvQueue.empty())
//		{
//			//��Ϣ��Ϊ��
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
//				cout << "outMsgRecvQueue()ִ���ˣ�ȡ��һ��Ԫ��" << command << endl;
//			}
//			else {
//				cout << "outMsgRecvQueue()ִ���ˣ���Ŀǰ��Ϣ����Ϊ��" << endl;
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
//	//һ����������mutex)
//	//�������Ǹ������ʹ����Ҫ����#include<mutex>
//	//������ʹ��ҪС�ģ��������ݲ���Ҳ���٣����ˣ�û�дﵽ����Ч��������Ӱ��Ч��
//
//	//�������������÷�
//	//(2.1)lock(),unlock()
//	//ÿһ��lock()��ȻҪ��unlock(),һ��lock()���ж��ٳ��ھ�Ҫ��Ӧ���ٸ�unlock()��
//	//��lock(),û��unlock()������ǳ����Ų�
//	//Ϊ�˷�ֹ�������unlock()��������һ����std::loch_guard����ģ�壺������unlock()��Ҫ����ϵͳ����unlock();
//	//ѧ������ָ��(unique_ptr<>)���������ͷ��ڴ治Ҫ�����Ҹ����ͷţ�
//
//	//(2.2)std::lockguard<>��ģ�壺ֱ��ȡ��lock()��unlocjk();Ҳ����˵��������lock_guard֮������ʹ��lock()��unlocjk();
//
//	//��������
//	//(3.1)������ʾ
//	//(3.2)������һ��������
//	//ֻҪ��֤������������������˳��һ�¾Ͳ�������
//	//(3.3)std::lock()����ģ�壺����������������
//	//������һ����ס�������������ϵĻ�������һ�����У�
//	//��������������Ϊ����߳��� ��Ϊ����˳�����⵼�������ķ�������
//	//std::lock():�������������һ��û�����ͻ�ȴ����л���������ס����������
//	//Ҫô��������������ס��Ҫô��û��ס�����ֻ����һ������һ��û�ɹ���û�����ͷ��Ѿ�������
//
//	//(3.4)std::lock_guard��std::adop_lock����
//	//std::adop_lock�Ǹ��ṹ�������һ��������ã���ʾ�û������Ѿ�lock()���ˣ�����Ҫ��std::lock_guard<std::mutex>�ٴ�lock();
//	//�ܽ᣺std::lock()��һ���������������������ʹ�ã�����һ��һ������
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