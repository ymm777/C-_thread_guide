#include"stdafx.h"
//#include<thread>
//#include<future>
//#include<iostream>
//
//using namespace std;
//
//int mythread(int mypar) {
//	cout << mypar << endl;
//	cout << "mythread() start" << " threadid=" << std::this_thread::get_id() << endl;
//	std::chrono::milliseconds dura(5000);
//	std::this_thread::sleep_for(dura);
//	cout << "mythrad() end" << " threadid=" << std::this_thread::get_id() << endl;
//	return 5;
//}
//
////void mythread2(std::future<int>& tempf) {		//ע�����
//void mythread2(std::shared_future<int>& tempf) {
//	cout << "mythread2() start" << " threadid=" << std::this_thread::get_id() << endl;
//	auto result = tempf.get();	//��ȡֵ��ֻ��getһ�η���ᱨ�쳣
//								//Ϊʲô�ڶ���get���future���ǻ�õ�һ���쳣����Ҫ����Ϊget����ƣ���һ���ƶ�����
//	cout << "mythread2 result=" << result << endl;
//	return;
//}
//
//int main() {
//
//	//����std::shared_future��Ҳ�Ǹ���ģ�塣
//	//std::future��get()������ת�����ݣ�std::shared_future��get()�����Ǹ�������
//
//	cout << "main" << " threadid=" << std::this_thread::get_id() << endl;
//	std::packaged_task<int(int)> mypt(mythread);
//	std::thread t1(std::ref(mypt), 1);
//	t1.join();
//
//	//std::future<int> result = mypt.get_future();
//
//	//bool ifcanget = result.valid();
//
//	//std::shared_future<int> results_s(std::move(result));
//	//std::shared_future<int> results_s(result.share());	//ִ����Ϻ�results_s����ֵ����result�����
//	//ifcanget = result.valid();
//
//	std::shared_future<int> results_s(mypt.get_future());	//ͨ��get_future����ֱֵ�ӹ�����һ��shared_future����
//
//	auto mythread_result = results_s.get();
//	mythread_result = results_s.get();
//	mythread_result = results_s.get();
//
//	//std::thread t2(mythread2, std::ref(result));
//
//	std::thread t2(mythread2, std::ref(results_s));
//	t2.join();
//
//	cout << "I love China" << endl;
//
//	system("pause");
//	return 0;
//}