#include"stdafx.h"
//#include<iostream>
//using namespace std;
//#include<thread>
//#include<memory>
//
//class A {
//public:
//	mutable int m_i;
//	//����ת�����캯�������԰�һ��intת����һ����A����
//	A(int a) :m_i(a) { cout << "[A:A(int a)���캯��ִ��]" << this << "threadid=" << std::this_thread::get_id() << endl; }
//	A(const A &a):m_i(a.m_i){ cout << "[A:A(const A &a)�������캯��ִ��]"<< this << "threadid=" << std::this_thread::get_id() << endl; }
//	~A(){ cout << "[A:~A()��������ִ��]" << this << "threadid=" << std::this_thread::get_id() << endl; }
//	
//	void thread_work(int num)
//	{
//		cout << "[���߳�thread_workִ��]" << this << "threadid=" << std::this_thread::get_id() << endl;
//	}
//
//	void operator()()
//	{
//		cout << "[���߳�thread_workִ��]" << this << "threadid=" << std::this_thread::get_id() << endl;
//	}
//};
//
////void myprint(const int& i, char* pmybuf)
////void myprint(const int i, const string &pmybuf)
////{
////	cout << i << endl;		//������Ϊ��i������mvar�����ã�ʵ����ֵ���ݣ���ô������Ϊ���������߳�detach()�����̣߳���ô���߳�����iֵӦ���ǰ�ȫ��
////	cout << pmybuf.c_str() << endl;	//ָ����detach()���߳�ʱ�����Ի�������
////	return;
////}
//
//void myprint(const int i, const A &mybuf)
//{
//	cout << &mybuf << "threadid=" << std::this_thread::get_id() << endl;		//�����ӡ����mybuf����ĵ�ַ
//	return;
//}
//
//void myprint2(const A &pmybuf)
////void myprint2(unique_ptr<int>ptr) 
//{
//	//pmybuf.m_i=199;
//	cout << "���߳�myprint2�Ĳ�����ַ��" << &pmybuf << std::this_thread::get_id() << endl;
//}
//
//
//int main()
//{
//	//һ��������ʱ������Ϊ�̲߳���
//	//(1.1)Ҫ��������壨����1��
//	//(1.2)Ҫ��������壨����2��
//	//��ʵ1��ֻҪ����ʱ�����A�������Ϊ�������ݸ��̣߳���ô��һ���ܹ������߳�ִ�����ǰ���̵߳ĵڶ������������������Ӷ�ȷ����ʹdetach�����߳�Ҳ��ȫ����
//	//��1.3���ܽ᣺
//	//a)������int���ּ����Ͳ��������鶼��ֵ���ݣ���Ҫ���á���ֹ������֦
//	//b)�����������󣬱�����ʽ����ת����ȫ���ڴ����߳���һ�У��͹�������ʱ��������Ȼ���ں����������������ӣ�����ϵͳ�����ٹ���һ������
//	//�ռ����ۣ�
//	//c)���鲻����detach(),ֻʹ��join();�����Ͳ����ھֲ�����ʧЧ�����̶߳��ڴ�ķǷ��������⣻
//
//
//	//������ʱ������Ϊ�̲߳�������������ʦ���ò��Դ󷨣�
//	//(2.1)�߳�id���id�Ǹ����֣�ÿ���̣߳����������̻߳������̣߳�ʵ���϶���Ӧ��һ�����֣�����ÿ���̶߳�Ӧ����ֵ��ͬ
//			//Ҳ����˵����ͬ���̣߳������߳�id�����֣���Ȼ��ͬ
//	//�߳�id������c++��׼����ĺ�������ȡ��std::this_thread::get_id()����ȡ
//	//(2.2)��ʱ������ʱ��ץ��
//
//	//�����������������ָ����Ϊ�̲߳���
//	//std::ref()������  ����������
//
//
//	//int mvar = 1;
//	//int &mvary = mvar;
//	//char mybuf[] = "this is a test!";
//	//// thread mytobj(myprint, mvar, mybuf);	//����mybuf��������ʲôʱ��ת����string��
//	//										//��ʵ�ϴ��ڣ�mybuf���������ˣ�main����ִ����ϣ���ϵͳ��ȥ��mybufתstring�Ŀ����ԡ�
//	//
//	//thread mytobj(myprint, mvar, string(mybuf));//��������ֱ�ӽ�mubufת����string��������һ�����Ա�֤���߳����ÿ϶���Ч�Ķ���
//	//// mytobj.join();
//	//mytobj.detach();	//	���̺߳����̷ֱ߳�ִ��
//
///*	int mvar = 1;
//	int mysecondpar = 12;
//	thread mytobj(myprint, mvar, A(mysecondpar));	*///������ϣ��mysecondparת��A���Ͷ��󴫵ݸ�myprint�ĵڶ�������
//												//�ڴ����̵߳�ͬʱ������ʱ����ķ������ݲ����ǿ��еģ�
//
//
//	cout << "����id��" << std::this_thread::get_id() << endl;
//	//int mvar = 1;
//	//std::thread mytobj(myprint2, A(mvar));
//
//	////����ָ��
//	//unique_ptr<int> myp(new int(100));
//	//thread mytobj(myprint2, myp);
//
//
//	//mytobj.join();
//	//mytobj.detach();
//
//
//	A myobj(10);//����һ�������
//	//std::thread mytobj(&A::thread_work, &myobj, 15);  //std::ref(myobj)  ==  &myobj
//	std::thread mytobj(myprint2, myobj);
//	////std::thread mytobj(std::ref(myobj), 15);	//�����ÿ������캯���ˣ���ô�����������mytobj.detach()�Ͳ���ȫ��
//	mytobj.join();
//
//
//	cout << "I love China!" << endl;
//
//	return 0;
//}