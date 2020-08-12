#include"stdafx.h"
//#include<iostream>
//using namespace std;
//#include<future>
//#include<thread>
//
//int mythread(int mypar) {
//	cout << mypar << endl;
//	cout << "mythread()　begin" << " threadid=" << std::this_thread::get_id() << endl;
//	std::chrono::milliseconds dura(5000);
//	std::this_thread::sleep_for(dura);
//	cout << "mythread()　end" << " threadid=" << std::this_thread::get_id() << endl;
//	return 5;
//}
//
//int main() {
//
//	//二：std::packaged_task:打包任务，把任务包装起来
//	//是个类模板，它的模板参数是 各种调用对象；通过std::packaged_task来把各种可调用对象包装起来，方便将来作为线程入口函数
//	//packaged_task包装起来的可调用对象还可以直接调用，所以从这个角度来将，packaged_task对象，也是一个可调用对象;
//
//	cout << "main()" << "threadid=" << std::this_thread::get_id() << endl;
//	//std::packaged_task<int(int)> mypt(mythread);	//我们把函数mythread通过packaged_task包装起来
//
//	//lambda表达式
//	std::packaged_task<int(int)> mypt([](int mypar) {
//		cout << mypar << endl;
//		cout << "mythread() start" << "threadid=" << std::this_thread::get_id() << endl;
//		std::chrono::milliseconds dura(5000);
//		std::this_thread::sleep_for(dura);
//		cout << "mythread() end" << "threadid=" << std::this_thread::get_id() << endl;
//		return 5;
//		});
//
//	//std::thread t1(std::ref(mypt), 1);			//线程直接开始执行，第二个参数 作为线程入口函数的参数
//	//t1.join();	//等待线程执行完毕	
//	//std::future<int> result = mypt.get_future();	//std::future对象里包含有线程入口函数的返回结果，这里result保存mythread()的返回结果。
//	//cout << result.get() << endl;
//	//cout << "I love China!" << endl;
//
//	mypt(105);		//直接调用，相当于函数调用；
//	std::future<int> result = mypt.get_future();
//	cout << result.get() << endl;
//
//	system("pause");
//	return 0;
//}