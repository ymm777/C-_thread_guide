#include"stdafx.h"
//#include<iostream>
//#include<list>
//#include<thread>
//using namespace std;
//
//class A
//{
//public:
//	//���յ�����Ϣ�����������뵽һ�����е��߳�
//	void inMsgRecvQueue()
//	{
//		for (int i = 0; i < 10000; i++)
//		{
//			cout << "inMsgRecvQueue()ִ�У�����һ��Ԫ��" << i << endl;
//			msgRecvQueue.push_back(i);	//�����������i�������յ��������ֱ��Ū����Ϣ����������
//		}
//	}
//	//�����ݴ���Ϣ������ȡ�����߳�
//	void outMsgRecvQueue()
//	{
//		for (int i = 0; i < 10000; i++)
//		{
//			if (!msgRecvQueue.empty())
//			{
//				//��Ϣ���в�Ϊ��
//				int command = msgRecvQueue.front();	//���ص�һ��Ԫ�أ��������Ԫ���Ƿ����
//				msgRecvQueue.pop_front();	//�Ƴ���һ��Ԫ�أ���������
//			}
//			else {
//				//��Ϣ����Ϊ��
//				cout << "outMsgRecvQueue()ִ�У���Ŀǰ��Ϣ����Ϊ��" << endl;
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
//	//�����������ݵı�����������
//	//������Ϸ�������������Լ��������̣߳�һ���߳��ռ���ҵ������һ�����ִ�����ҷ��͵������������������д��һ������
//	//									��һ���߳� �Ӷ�����ȥ�����	�����������������Ȼ��ִ�������Ҫ�Ķ�����
//	//׼���ó�Ա������Ϊ�̺߳���������д�̡߳�
//	//���뻯������⣺����һ��c++����̱߳���������������ĵ�һ�����������������
//
//	A myobja;
//	std::thread myOutMsgObj(&A::outMsgRecvQueue, &myobja);	//�ڶ������������ã����ܱ�֤�߳���ʹ�õ���ͬһ������
//	std::thread myInMsgObj(&A::inMsgRecvQueue, &myobja);
//
//	myInMsgObj.join();
//	myOutMsgObj.join();
//
//	return 0;
//}