#include"stdafx.h"
//#include<iostream>
//#include<thread>
//#include<future>
//
//using namespace std;
//
//int mythread(int mypar) {
//	cout << mypar << endl;
//	cout << "mythread() begin" << "threadid=" << std::this_thread::get_id() << endl;
//	std::chrono::milliseconds dura(5000);
//	std::this_thread::sleep_for(dura);
//	cout << "mythread() end" << "threadid=" << std::this_thread::get_id() << endl;
//	return 5;
//}
//
//int main() {
//
//	//һ��std::future��������Ա����
//
//	int mypar = 12;
//	cout << "main()" << "threadid=" << std::this_thread::get_id() << endl;
//	//std::launch::deferred�߳��ӳ�ִ��
//	//std::future<int> result = std::async( std::launch::deferred,mythread, mypar);		//����һ���첽�߳�
//
//	std::future<int> result = std::async(mythread, mypar);
//	cout << "continue..." << endl;
//
//	//std::future_status
//	//ö������
//
//	//wait_for(�ȴ�һ��ʱ��)��
//	std::future_status status = result.wait_for(std::chrono::seconds(6));	//�ȴ�1��
//	if (status == std::future_status::timeout) {
//		//��ʾ�̻߳�û��ִ����
//		cout << "��ʱ���̻߳�û��ִ�����" << endl;
//	}
//	else if (status == std::future_status::ready) {
//		//��ʾ�߳�ִ�����
//		cout << "�̳߳ɹ�ִ����ϣ�����" << endl;
//		cout << result.get() << endl;
//	} 
//	else if (status == std::future_status::deferred) {
//		//���async�ĵ�һ������������Ϊstd::launch::deferred������������
//		cout << "�̱߳��ӳ�ִ��" << endl;
//		cout << result.get() << endl;
//	}
//
//
//
//	cout << "I love China!" << endl;
//
//	system("pause");
//	return 0;
//}