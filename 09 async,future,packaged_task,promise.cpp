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
//	//一：std::async,std::future创建后台任务并返回值
//	//希望线程返回一个结果
//	//std::async 是个函数模板，用来启动一个异步任务，启动起来一个异步任务后，他返回一个std::future对象，std::future是个类模板。
//	//什么叫“启动一个异步任务”，就是创建一个线程并开始执行对应的线程入口函数，它返回一个std::future对象，
//		//这个std::future对象里边就含有线程入口函数所返回的结果（线程返回的结果），我们可以通过调用future对象的成员函数get()来获取结果；
//		//std::future:将来的意思。有人也称呼std::future提供了一种访问异步操作结果的机制，就是说这个结果你可能没有办法马上拿到，但不久的将来
//		//在线程执行完毕后，你就能拿到结果了，所以大家可以这么理解，这个future（对象）里会保存一个值，在将来的某个时刻，可以拿到
//
//	//下列程序通过std::future对象的get()成员函数等待线程之行结束并返回结果;
//	//这个get()函数很牛，不拿到将来的返回值 誓不罢休，不拿到值就卡在这里，等待拿值；
//	//我们通过额外向std::async()传递一个参数，该参数类型是std::launch类型(枚举类型)，来达到一些特殊的目的
//	//a)std::launch::deferred：表示线程入口函数调用被延迟到std::future的wait()或者get()函数调用时才执行；
//		//那如果wait()或者get()没有被调用，那么线程会执行吗？没执行，实际上，线程根本没有创建
//		//std::launch::deferred：延迟调用，并且没有调用新线程，是在主线程中调用的线程入口函数
//
//	//b)std::launch::async，在调用async函数的时候就开始创建线程；
//		//async()这个函数默认使用std::launch::async标记
//
//	A a;
//	int mypar = 12;
//
//	cout << "main()" << "threadid=" << std::this_thread::get_id() << endl;
//	//std::future<int> result = std::async(mythread);		//创建一个线程并开始执行,绑定关系，流程并不会卡到这里
//	//std::future<int> result = std::async(std::launch::deferred,&A::mythread,&a,mypar);	//第二个参数为对象引用，才能保证线程里的是同一个对象
//	std::future<int> result = std::async(std::launch::async, &A::mythread, &a, mypar);
//	cout << "continue..." << endl;
//	int def;
//	def = 0;
//	cout << result.get() << endl;		//流程卡到这里，等待mythread()线程执行完毕，拿到结果
//										//get()只能调用一次，不能调用多次;
//	//result.wait();		//等待线程返回，本身不返回结果
//	cout << "I love China!" << endl;
//
//	system("pause");
//	return 0;
//}