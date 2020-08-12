#include"stdafx.h"
//#include<iostream>
//using namespace std;
//#include<mutex>
//
//std::mutex resource_mutex;
//std::once_flag g_flag;
//
//class MyCAS		//这是一个单例类
//{
//	static void CreateInstance(){	//只被执行一次
//		std::chrono::milliseconds dura(20000);	//休息20s
//		std::this_thread::sleep_for(dura);
//		
//		cout << "CreateInstance()被执行了" << endl;
//
//		m_instance = new MyCAS;
//		static CGarhuishou cl;
//	}
//
//private:
//	MyCAS() {};	//私有化了构造函数
//
//private:
//	static MyCAS *m_instance;	//静态成员变量
//
//public:
//	static MyCAS* GetInstance()
//	{
//		//提高效率
//		//a)如果 if (m_instance != NULL) 条件成立，则肯定表示m_instance已经被new过了；
//		//b)如果 if (m_instance == NULL)， 不代表m_instance一定没有new过；
//
//		//if (m_instance == NULL) {	//双重锁定(双重检查)
//		//	std::unique_lock<std::mutex> mymutex(resource_mutex);	//自动加锁
//		//	if (m_instance == NULL)
//		//	{
//		//		m_instance = new MyCAS;
//		//		static CGarhuishou cl;
//		//	}
//		//}
//		std::call_once(g_flag, CreateInstance);	//两个线程同时执行到这里，其中一个线程要等另外一个线程执行完毕CreateInstance
//		cout << "call_once执行完毕" << endl;
//		return m_instance;
//	}
//
//	class CGarhuishou	//类中套类,用来释放对象
//	{
//	public:
//		~CGarhuishou()	//类的析构函数中
//		{
//			if (MyCAS::m_instance) {
//				delete MyCAS::m_instance;
//				MyCAS::m_instance = NULL;
//			}
//		}
//	};
//
//	void func() {
//		cout << "测试" << endl;
//	}
//};
//
////类静态变量初始化
//MyCAS* MyCAS::m_instance = NULL;
//
////线程入口函数
//void mythread() {
//	cout << "我的线程开始执行了" << endl;
//	MyCAS* p_a = MyCAS::GetInstance();
//	p_a->func();
//	cout << "我的线程执行完毕了" << endl;
//}
//
//int main() {
//
//	//一：设计模式大概谈
//	//“设计模式”：代码的一些写法（这些写法跟常规写法不怎么一样）：程序灵活，维护起来可能很方便，但是别人接管、阅读代码十分痛苦
//	//用“设计模式”理念写出来的代码很晦涩的。《head first》
//	//设计模式：
//	//老外 应付特别大的项目的时候 把项目的开发经验、模块划分经验，总结整理成设计模式（先有开发需求，后有理论总计和整理）
//	//设计模式拿到中国来，不太一样，生搬硬套，本末倒置
//	//设计模式有个独特的优点，要活学活用，不要深陷其中，生搬硬套。
//
//	//二：单例设计模式：
//	//单例设计模式，使用频率比较 高
//	//单例：整个项目中，有某个或者某些特别的类，属于该类的对象，我只能创建一个，多了我创建不了
//	//单例类；
//
//	//创建单例类
//	//MyCAS* p_a = MyCAS::GetInstance();	//创建一个对象，返回该类(MyCAS)对象的指针
//
//	//p_a->func();
//	//MyCAS::GetInstance()->func();
//
//	//三：单例设计模式共享数据问题分析、解决
//	//面临的问题：需要我们自己创建的线程（而不是主线程）中来创建MyCAS这个单例类的对象，这种线程（可能不止一个）至少两个
//	//我们可能会面临GetInstance()这种成员函数要互斥
//	//虽然两个线程入口函数相同，但大家千万要记住，这是两个线程，所以会有两个通路来执行mythread
//
//	std::thread mytobj1(mythread);
//	std::thread mytobj2(mythread);
//
//	mytobj1.join();
//	mytobj2.join();
//
//	//四：std::call_once(); c++11引入的函数，该函数调用的第二个参数 是一个函数名a();
//	//call_once功能是能够保证函数a()只被执行一次;
//	//call_once具备互斥量这种能力，而且效率上，比互斥量消耗的资源更少
//	//call_once()需要与一个标记结合使用，这个标记std::once_flag; 其实once_flag是一个结构
//	//call_once()就是通过这个标记来决定对应的a()是否执行，调用call_once()成功后，call_once()就把这个标记设置为一种已调用状态；
//	//后续再次调用call_once()，只要once_flag被设置为了已调用，那么对应函数a()就不会再被执行了
//
//	system("pause");
//	return 0;
//}