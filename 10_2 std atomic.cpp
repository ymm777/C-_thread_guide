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
////std::atomic<int> g_mycount = 0;	//���Ƿ�װ��һ������Ϊint�Ķ���ֵ�������ǿ��������һ��int���ͱ������������atomic
//
////mutex g_my_mutex;
//
////void mythread() {		//�߳���ں���
////	for (int i = 0; i < 10000000; i++) {
////		//g_my_mutex.lock();	//ִ������Ҫ7s
////		//g_mycount++;
////		//g_my_mutex.unlock();
////		g_mycount++;	//��Ӧ�Ĳ�����ԭ�Ӳ��������ᱻ��ϣ� 
////	}
////}
//
//std::atomic<bool> g_myflag = false;
//
//void mythread() {
//	std::chrono::milliseconds dura(1000);	//1����
//	while (g_myflag == false) {
//		//ϵͳû��Ҫ���߳��˳������Ա��߳̿��Ը��Լ���ɵ�����
//		cout << "thread id=" << std::this_thread::get_id() << " ����ִ��...." << endl;
//		std::this_thread::sleep_for(dura);
//	}
//	cout << "thread id=" << std::this_thread::get_id() << " ���н���..." << endl;
//}
//
//int main() {
//
//	//����ԭ�Ӳ���std::atomic
//	//(3.1)ԭ�Ӳ���������������
//	//�����������̱߳���� �����������ݣ� ���������������ݣ�����
//	//��ҿ��԰�ԭ�Ӳ�������һ�֣�����Ҫ�õ������������������������Ķ��̲߳�����̷�ʽ
//	//ԭ�Ӳ��������ڶ��߳��� ���ᱻ��ϵ� ����ִ��Ƭ�Σ��Ȼ�����Ч���ϸ�ʤһ�
//	//�������ļ���һ�������һ������Σ����д��룩����ԭ�Ӳ�����Ե�һ�㶼��һ��������������һ������Σ�
//
//	//ԭ�Ӳ�����һ�㶼��ָ�����ɷָ�Ĳ�������
//	//std::atomic������ԭ�Ӳ�����std::atomic�Ǹ���ģ�塣��ʵstd::atomic���������������װĳ�����͵�ֵ�ġ�
//
//	//(3.2)����std::atomic�÷�����
//	//(3.3)��ʦ���ĵã�һ�����ڼ�����ͳ�ƣ��ۼƷ��ͳ�ȥ�˶��ٸ����ݰ����ۼƽ��ܵ��˶��ٸ����ݰ���
//
//	//std::thread mytboj1(mythread);
//	//std::thread mytboj2(mythread);
//
//	//mytboj1.join();
//	//mytboj2.join();
//
//	//cout << "�߳�ִ����ϣ�g_mycount=" << g_mycount << endl;
//
//	std::thread mytobj1(mythread);
//	std::thread mytobj2(mythread);
//
//	std::chrono::milliseconds dura(5000);	//������
//	std::this_thread::sleep_for(dura);
//
//	g_myflag = true;
//
//	mytobj1.join();
//	mytobj2.join();
//
//	cout << "����ִ����ϣ��˳�" << endl;
//
//	system("pause");
//	return 0;
//}