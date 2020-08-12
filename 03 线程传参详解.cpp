#include"stdafx.h"
//#include<iostream>
//using namespace std;
//#include<thread>
//#include<memory>
//
//class A {
//public:
//	mutable int m_i;
//	//类型转换构造函数，可以把一个int转换成一个类A对象
//	A(int a) :m_i(a) { cout << "[A:A(int a)构造函数执行]" << this << "threadid=" << std::this_thread::get_id() << endl; }
//	A(const A &a):m_i(a.m_i){ cout << "[A:A(const A &a)拷贝构造函数执行]"<< this << "threadid=" << std::this_thread::get_id() << endl; }
//	~A(){ cout << "[A:~A()析构函数执行]" << this << "threadid=" << std::this_thread::get_id() << endl; }
//	
//	void thread_work(int num)
//	{
//		cout << "[子线程thread_work执行]" << this << "threadid=" << std::this_thread::get_id() << endl;
//	}
//
//	void operator()()
//	{
//		cout << "[子线程thread_work执行]" << this << "threadid=" << std::this_thread::get_id() << endl;
//	}
//};
//
////void myprint(const int& i, char* pmybuf)
////void myprint(const int i, const string &pmybuf)
////{
////	cout << i << endl;		//分析认为，i并不是mvar的引用，实际是值传递，那么我们认为，即便主线程detach()了子线程，那么子线程中用i值应该是安全的
////	cout << pmybuf.c_str() << endl;	//指针在detach()子线程时，绝对会有问题
////	return;
////}
//
//void myprint(const int i, const A &mybuf)
//{
//	cout << &mybuf << "threadid=" << std::this_thread::get_id() << endl;		//这里打印的是mybuf对象的地址
//	return;
//}
//
//void myprint2(const A &pmybuf)
////void myprint2(unique_ptr<int>ptr) 
//{
//	//pmybuf.m_i=199;
//	cout << "子线程myprint2的参数地址是" << &pmybuf << std::this_thread::get_id() << endl;
//}
//
//
//int main()
//{
//	//一：传递临时对象作为线程参数
//	//(1.1)要避免的陷阱（解释1）
//	//(1.2)要避免的陷阱（解释2）
//	//事实1：只要用临时构造的A类对象作为参数传递给线程，那么就一定能够在主线程执行完毕前把线程的第二个参数构建出来，从而确保即使detach后子线程也安全运行
//	//（1.3）总结：
//	//a)若传递int这种简单类型参数，建议都是值传递，不要引用。防止节外生枝
//	//b)如果传递类对象，避免隐式类型转换。全部在创建线程这一行，就构建出临时对象来，然后在函数参数用引用来接；否则系统还会再构建一个对象
//	//终极结论：
//	//c)建议不适用detach(),只使用join();这样就不存在局部变量失效导致线程对内存的非法引用问题；
//
//
//	//二：临时对象作为线程参数继续讲，老师常用测试大法：
//	//(2.1)线程id概念：id是个数字，每个线程（不管是主线程还是子线程）实际上都对应着一个数字，而且每个线程对应的数值不同
//			//也就是说，不同的线程，它的线程id（数字）必然不同
//	//线程id可以用c++标准库里的函数来获取，std::this_thread::get_id()来获取
//	//(2.2)临时对象构造时机抓捕
//
//	//三：传递类对象、智能指针作为线程参数
//	//std::ref()函数；  真正的引用
//
//
//	//int mvar = 1;
//	//int &mvary = mvar;
//	//char mybuf[] = "this is a test!";
//	//// thread mytobj(myprint, mvar, mybuf);	//但是mybuf到底是在什么时候转换成string。
//	//										//事实上存在，mybuf都被回收了（main函数执行完毕），系统才去用mybuf转string的可能性。
//	//
//	//thread mytobj(myprint, mvar, string(mybuf));//我们这里直接将mubuf转换成string对象，这是一个可以保证在线程中用肯定有效的对象。
//	//// mytobj.join();
//	//mytobj.detach();	//	主线程和子线程分别执行
//
///*	int mvar = 1;
//	int mysecondpar = 12;
//	thread mytobj(myprint, mvar, A(mysecondpar));	*///我们是希望mysecondpar转成A类型对象传递给myprint的第二个参数
//												//在创建线程的同时构造临时对象的方法传递参数是可行的；
//
//
//	cout << "主线id是" << std::this_thread::get_id() << endl;
//	//int mvar = 1;
//	//std::thread mytobj(myprint2, A(mvar));
//
//	////智能指针
//	//unique_ptr<int> myp(new int(100));
//	//thread mytobj(myprint2, myp);
//
//
//	//mytobj.join();
//	//mytobj.detach();
//
//
//	A myobj(10);//生成一个类对象
//	//std::thread mytobj(&A::thread_work, &myobj, 15);  //std::ref(myobj)  ==  &myobj
//	std::thread mytobj(myprint2, myobj);
//	////std::thread mytobj(std::ref(myobj), 15);	//不调用拷贝构造函数了，那么后续如果调用mytobj.detach()就不安全了
//	mytobj.join();
//
//
//	cout << "I love China!" << endl;
//
//	return 0;
//}