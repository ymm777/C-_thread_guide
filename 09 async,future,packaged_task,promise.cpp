#include"stdafx.h"
//#include<iostream>
//using namespace std;
//#include<thread>
//#include<future>
//
//class A{
//public:
//	int mythread(int par) {
//		cout << par << endl;
//		cout << "mythread() begin" << "threadid=" << std::this_thread::get_id() << endl;
//		std::chrono::milliseconds dura(5000);
//		std::this_thread::sleep_for(dura);
//		cout << "mythread() end" << "threadid=" << std::this_thread::get_id() << endl;
//		return 5;
//	}
//};
//
//
//int main() {
//
//	//һ��std::async,std::future������̨���񲢷���ֵ
//	//ϣ���̷߳���һ�����
//	//std::async �Ǹ�����ģ�壬��������һ���첽������������һ���첽�����������һ��std::future����std::future�Ǹ���ģ�塣
//	//ʲô�С�����һ���첽���񡱣����Ǵ���һ���̲߳���ʼִ�ж�Ӧ���߳���ں�����������һ��std::future����
//		//���std::future������߾ͺ����߳���ں��������صĽ�����̷߳��صĽ���������ǿ���ͨ������future����ĳ�Ա����get()����ȡ�����
//		//std::future:��������˼������Ҳ�ƺ�std::future�ṩ��һ�ַ����첽��������Ļ��ƣ�����˵�����������û�а취�����õ��������õĽ���
//		//���߳�ִ����Ϻ�������õ�����ˣ����Դ�ҿ�����ô��⣬���future��������ᱣ��һ��ֵ���ڽ�����ĳ��ʱ�̣������õ�
//
//	//���г���ͨ��std::future�����get()��Ա�����ȴ��߳�֮�н��������ؽ��;
//	//���get()������ţ�����õ������ķ���ֵ �Ĳ����ݣ����õ�ֵ�Ϳ�������ȴ���ֵ��
//	//����ͨ��������std::async()����һ���������ò���������std::launch����(ö������)�����ﵽһЩ�����Ŀ��
//	//a)std::launch::deferred����ʾ�߳���ں������ñ��ӳٵ�std::future��wait()����get()��������ʱ��ִ�У�
//		//�����wait()����get()û�б����ã���ô�̻߳�ִ����ûִ�У�ʵ���ϣ��̸߳���û�д���
//		//std::launch::deferred���ӳٵ��ã�����û�е������̣߳��������߳��е��õ��߳���ں���
//
//	//b)std::launch::async���ڵ���async������ʱ��Ϳ�ʼ�����̣߳�
//		//async()�������Ĭ��ʹ��std::launch::async���
//
//	A a;
//	int mypar = 12;
//
//	cout << "main()" << "threadid=" << std::this_thread::get_id() << endl;
//	//std::future<int> result = std::async(mythread);		//����һ���̲߳���ʼִ��,�󶨹�ϵ�����̲����Ῠ������
//	//std::future<int> result = std::async(std::launch::deferred,&A::mythread,&a,mypar);	//�ڶ�������Ϊ�������ã����ܱ�֤�߳������ͬһ������
//	std::future<int> result = std::async(std::launch::async, &A::mythread, &a, mypar);
//	cout << "continue..." << endl;
//	int def;
//	def = 0;
//	cout << result.get() << endl;		//���̿�������ȴ�mythread()�߳�ִ����ϣ��õ����
//										//get()ֻ�ܵ���һ�Σ����ܵ��ö��;
//	//result.wait();		//�ȴ��̷߳��أ��������ؽ��
//	cout << "I love China!" << endl;
//
//	system("pause");
//	return 0;
//}