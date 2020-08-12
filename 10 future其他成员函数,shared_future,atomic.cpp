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
//	//一：std::future的其他成员函数
//
//	int mypar = 12;
//	cout << "main()" << "threadid=" << std::this_thread::get_id() << endl;
//	//std::launch::deferred线程延迟执行
//	//std::future<int> result = std::async( std::launch::deferred,mythread, mypar);		//创建一个异步线程
//
//	std::future<int> result = std::async(mythread, mypar);
//	cout << "continue..." << endl;
//
//	//std::future_status
//	//枚举类型
//
//	//wait_for(等待一定时间)；
//	std::future_status status = result.wait_for(std::chrono::seconds(6));	//等待1秒
//	if (status == std::future_status::timeout) {
//		//表示线程还没有执行完
//		cout << "超时，线程还没有执行完毕" << endl;
//	}
//	else if (status == std::future_status::ready) {
//		//表示线程执行完毕
//		cout << "线程成功执行完毕，返回" << endl;
//		cout << result.get() << endl;
//	} 
//	else if (status == std::future_status::deferred) {
//		//如果async的第一个参数被设置为std::launch::deferred，则本条件成立
//		cout << "线程被延迟执行" << endl;
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