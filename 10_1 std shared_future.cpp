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
////void mythread2(std::future<int>& tempf) {		//注意参数
//void mythread2(std::shared_future<int>& tempf) {
//	cout << "mythread2() start" << " threadid=" << std::this_thread::get_id() << endl;
//	auto result = tempf.get();	//获取值，只能get一次否则会报异常
//								//为什么第二次get这个future我们会得到一个异常；主要是因为get的设计，是一个移动语义
//	cout << "mythread2 result=" << result << endl;
//	return;
//}
//
//int main() {
//
//	//二：std::shared_future：也是个类模板。
//	//std::future的get()函数是转移数据，std::shared_future的get()函数是复制数据
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
//	//std::shared_future<int> results_s(result.share());	//执行完毕后results_s里有值，而result里空了
//	//ifcanget = result.valid();
//
//	std::shared_future<int> results_s(mypt.get_future());	//通过get_future返回值直接构造了一个shared_future对象。
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