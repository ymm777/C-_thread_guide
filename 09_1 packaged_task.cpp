#include"stdafx.h"
//#include<iostream>
//using namespace std;
//#include<future>
//#include<thread>
//
//int mythread(int mypar) {
//	cout << mypar << endl;
//	cout << "mythread()��begin" << " threadid=" << std::this_thread::get_id() << endl;
//	std::chrono::milliseconds dura(5000);
//	std::this_thread::sleep_for(dura);
//	cout << "mythread()��end" << " threadid=" << std::this_thread::get_id() << endl;
//	return 5;
//}
//
//int main() {
//
//	//����std::packaged_task:������񣬰������װ����
//	//�Ǹ���ģ�壬����ģ������� ���ֵ��ö���ͨ��std::packaged_task���Ѹ��ֿɵ��ö����װ���������㽫����Ϊ�߳���ں���
//	//packaged_task��װ�����Ŀɵ��ö��󻹿���ֱ�ӵ��ã����Դ�����Ƕ�������packaged_task����Ҳ��һ���ɵ��ö���;
//
//	cout << "main()" << "threadid=" << std::this_thread::get_id() << endl;
//	//std::packaged_task<int(int)> mypt(mythread);	//���ǰѺ���mythreadͨ��packaged_task��װ����
//
//	//lambda���ʽ
//	std::packaged_task<int(int)> mypt([](int mypar) {
//		cout << mypar << endl;
//		cout << "mythread() start" << "threadid=" << std::this_thread::get_id() << endl;
//		std::chrono::milliseconds dura(5000);
//		std::this_thread::sleep_for(dura);
//		cout << "mythread() end" << "threadid=" << std::this_thread::get_id() << endl;
//		return 5;
//		});
//
//	//std::thread t1(std::ref(mypt), 1);			//�߳�ֱ�ӿ�ʼִ�У��ڶ������� ��Ϊ�߳���ں����Ĳ���
//	//t1.join();	//�ȴ��߳�ִ�����	
//	//std::future<int> result = mypt.get_future();	//std::future������������߳���ں����ķ��ؽ��������result����mythread()�ķ��ؽ����
//	//cout << result.get() << endl;
//	//cout << "I love China!" << endl;
//
//	mypt(105);		//ֱ�ӵ��ã��൱�ں������ã�
//	std::future<int> result = mypt.get_future();
//	cout << result.get() << endl;
//
//	system("pause");
//	return 0;
//}