#include"stdafx.h"
//#include<iostream>
//#include<thread>
//#include<future>
//
//using namespace std;
//
////std::atomic<int> g_mycount;		//�����ԭ���������ͱ�����������ʹ�����ͱ���һ��ʹ��
////
////void mythread() {
////	for (int i = 0; i < 10000000; i++) {
////		//g_mycount++;	//��Ӧ�Ĳ�����ԭ�Ӳ��������ᱻ���
////		g_mycount = g_mycount + 1;
////	}
////}
//
//int mythread() {
//	cout << "mythread() start " << " thread id=" << std::this_thread::get_id() << endl;
//	std::chrono::milliseconds dura(5000);
//	std::this_thread::sleep_for(dura);
//	return 1;
//}
//
//int main() {
//
//	//һ��std::atomic��̸
//	//һ��atomicԭ�Ӳ��������++,--,+=,&=,|=,^=��֧�ֵģ������Ŀ��ܲ�֧��.
//
//	//std::thread mytobj1(mythread);
//	//std::thread mytobj2(mythread);
//
//	//mytobj1.join();
//	//mytobj2.join();
//
//	//cout << "�����߳�ִ����ϣ����ս��Ϊg_mycount=" << g_mycount << endl;
//
//	//����std::async����̸
//	//(2.1)std::async����������async�������� һ���첽����
//	//cout << "main() start " << " thread id=" << std::this_thread::get_id() << endl;
//	//std::future<int> result = std::async(mythread);
//	//cout << result.get() << endl;
//
//	//��ʦ����� ������std::launch::deferred���ӳٵ��á���std::launch::async��ǿ�ƴ���һ���̡߳�
//	//std::thread() ���ϵͳ��Դ���ţ���ô���ܴ����߳̾ͻ�ʧ�ܣ���ôִ��std::thread()ʱ��������������
//	//std::async() ����һ�㲻�д����̣߳�����async�ܹ������̣߳�������һ��������� һ���첽����
//	//std::async��std::thread�����ԵĲ�ͬ������async��ʱ�򲢲��������̡߳�
//
//	//a)�������std::launch::deferred������async����ô����
//	//std::launch::deferred�ӳٵ��ã����Ҳ��������̣߳��ӳٵ�future�������.get()����.waitʱ��ִ��mythread()�����û��ִ��.get()����.wait��mythread��ִ��
//	//b)std::launch::async:ǿ������첽���������߳���ִ�У�����ζ�ţ�ϵͳ����Ҫ���Ҵ������߳�������mythread();
//	//c)std::launch::async|std::launch::deferred
//	//�������|:��ζ�ŵ���async����Ϊ�����ǡ��������̲߳�����ִ�С�����
//								//û�д������̲߳����ӳٵ�����result.get()�ſ�ʼִ��������ں��������߾���һ
//	
//	//d)���ǲ������������ֻ��async����һ�� ��ں�������
//	//��ʵ��Ĭ��ֵΪstd::launch::async|std::launch::deferred	��c)Ч����ȫһ��
//		//���仰˵��ϵͳ�����о������첽(�������߳�)����ͬ��(���������߳�)��ʽ����
//
//	//(2.2)std::async��std::thread������
//	//std::thread�����̣߳����ϵͳ��Դ���ţ������߳�ʧ�ܣ���ô��������ͻᱨ�쳣��������Ƣ����
//	//int mythread(){return 1}
//	//std::thread mytobj1(mythread);
//	//mytobj.join();
//	//std::thread�����̵߳ķ�ʽ������̷߳���ֵ�������õ����ֵ�����ף�
//	//std::async�����첽���񡣿��ܴ���Ҳ���ܲ������̡߳�����async���÷����������õ��߳���ں����ķ���ֵ��
//	//����ϵͳ��Դ���ƣ�
//	//��1�������std::thread�������̹߳��࣬����ܴ���ʧ�ܣ�ϵͳ�����쳣������
//	//(2�������std::async��һ��Ͳ��ᱨ�쳣�����������Ϊ ���ϵͳ��Դ�����޷��������̵߳�ʱ��
//		//std::async���ֲ��Ӷ�������ĵ��þͲ��ᴴ�����̡߳����Ǻ���˭������result.get()����������
//		//��ô����첽����mythread()��������ִ������get()������ڵ��߳��ϡ�
//	//�����ǿ��std::asyncһ��Ҫ�������̣߳���ô�ͱ���ʹ�� std::launch::async�����ܵĴ��۾���ϵͳ��Դ����ʱ�����������
//	//(3)���飺һ�������� �߳��������˳���100-200��ʱ��Ƭ��
//
//	//(2.3)std::async��ȷ��������Ľ��
//	//���Ӷ��������std::async���ã���ϵͳ���о����Ƿ񴴽����̡߳�
//	//���⽹������ std::future<int> result=std::async(mythread); д����
//	//����첽���񵽵���û�б��Ƴ�ִ�У�(std::launch::async����std::launch::deferred)
//	//std::future�����wait_for��������10�ڽ���
//
//	cout << "main start " << " thread id=" << std::this_thread::get_id() << endl;
//	std::future<int> result = std::async(mythread);	//���ж�async������û�д������߳�����ִ�л����ӳ�(û�������߳�)ִ�С�
//
//	std::future_status status = result.wait_for(0s);		//std::chrono::seconds(0);
//	if (status == std::future_status::deferred) {
//		//�̱߳��ӳ�ִ���ˣ�ϵͳ��Դ�����ˣ������Ҳ�����std::launch::deferred������)
//		cout << result.get() << endl;	//��ʱ��ŵ���mythread()
//	}
//	else {
//		//����û�б��Ƴ٣��Ѿ���ʼ���У��̱߳�������
//		if (status == std::future_status::ready) {
//			//�̳߳ɹ�����
//			cout << "�̳߳ɹ�ִ����ϲ�����" << endl;
//			cout << result.get() << endl;
//		}
//		else if (status == std::future_status::timeout) {
//			//�߳�ִ�г�ʱ
//			cout << "�߳�ִ�г�ʱ" << endl;
//			cout << result.get() << endl;
//		}
//	}
//
//	system("pause");
//	return 0;
//}