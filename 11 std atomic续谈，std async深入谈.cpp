#include"stdafx.h"
//#include<iostream>
//#include<thread>
//#include<future>
//
//using namespace std;
//
////std::atomic<int> g_mycount;		//这个是原子整型类型变量，可以像使用整型变量一样使用
////
////void mythread() {
////	for (int i = 0; i < 10000000; i++) {
////		//g_mycount++;	//对应的操作是原子操作，不会被打断
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
//	//一：std::atomic续谈
//	//一般atomic原子操作，针对++,--,+=,&=,|=,^=是支持的，其他的可能不支持.
//
//	//std::thread mytobj1(mythread);
//	//std::thread mytobj2(mythread);
//
//	//mytobj1.join();
//	//mytobj2.join();
//
//	//cout << "两个线程执行完毕，最终结果为g_mycount=" << g_mycount << endl;
//
//	//二：std::async深入谈
//	//(2.1)std::async参数详述，async用来创建 一个异步任务
//	//cout << "main() start " << " thread id=" << std::this_thread::get_id() << endl;
//	//std::future<int> result = std::async(mythread);
//	//cout << result.get() << endl;
//
//	//老师讲解过 参数：std::launch::deferred【延迟调用】，std::launch::async【强制创建一个线程】
//	//std::thread() 如果系统资源紧张，那么可能创建线程就会失败，那么执行std::thread()时整个程序会崩溃；
//	//std::async() 我们一般不叫创建线程（解释async能够创建线程），我们一般叫他创建 一个异步任务
//	//std::async和std::thread最明显的不同，就是async有时候并不创建新线程。
//
//	//a)如果你用std::launch::deferred来调用async会怎么样？
//	//std::launch::deferred延迟调用，并且不创建新线程，延迟到future对象调用.get()或者.wait时才执行mythread()，如果没有执行.get()或者.wait则mythread不执行
//	//b)std::launch::async:强制这个异步任务在新线程上执行，这意味着，系统必须要给我创建新线程来运行mythread();
//	//c)std::launch::async|std::launch::deferred
//	//这里这个|:意味着调用async的行为可能是“创建新线程并立即执行”或者
//								//没有创建新线程并且延迟到调用result.get()才开始执行任务入口函数，两者居其一
//	
//	//d)我们不带额外参数：只给async函数一个 入口函数名；
//	//其实，默认值为std::launch::async|std::launch::deferred	和c)效果完全一致
//		//换句话说：系统会自行决定是异步(创建新线程)还是同步(不创建新线程)方式进行
//
//	//(2.2)std::async和std::thread的区别
//	//std::thread创建线程，如果系统资源紧张，创建线程失败，那么整个程序就会报异常崩溃（有脾气）
//	//int mythread(){return 1}
//	//std::thread mytobj1(mythread);
//	//mytobj.join();
//	//std::thread创建线程的方式，如果线程返回值，你想拿到这个值不容易；
//	//std::async创建异步任务。可能创建也可能不创建线程。并且async调用方法很容易拿到线程入口函数的返回值；
//	//由于系统资源限制：
//	//（1）如果用std::thread创建的线程过多，则可能创建失败，系统报告异常，崩溃
//	//(2）如果用std::async，一般就不会报异常不会崩溃，因为 如果系统资源紧张无法创建新线程的时候，
//		//std::async这种不加额外参数的调用就不会创建新线程。而是后续谁调用了result.get()来请求结果，
//		//那么这个异步任务mythread()就运行在执行这条get()语句所在的线程上。
//	//如果你强制std::async一定要创建新线程，那么就必须使用 std::launch::async。承受的代价就是系统资源紧张时，程序崩溃。
//	//(3)经验：一个程序里 线程数量不宜超过100-200，时间片。
//
//	//(2.3)std::async不确定性问题的解决
//	//不加额外参数的std::async调用，让系统自行决定是否创建新线程。
//	//问题焦点在于 std::future<int> result=std::async(mythread); 写法；
//	//这个异步任务到底有没有被推迟执行，(std::launch::async还是std::launch::deferred)
//	//std::future对象的wait_for函数，第10节讲过
//
//	cout << "main start " << " thread id=" << std::this_thread::get_id() << endl;
//	std::future<int> result = std::async(mythread);	//想判断async到底有没有创建新线程立即执行还是延迟(没创建新线程)执行。
//
//	std::future_status status = result.wait_for(0s);		//std::chrono::seconds(0);
//	if (status == std::future_status::deferred) {
//		//线程被延迟执行了（系统资源紧张了，它给我采用了std::launch::deferred策略了)
//		cout << result.get() << endl;	//这时候才调用mythread()
//	}
//	else {
//		//任务没有被推迟，已经开始运行，线程被创建了
//		if (status == std::future_status::ready) {
//			//线程成功返回
//			cout << "线程成功执行完毕并返回" << endl;
//			cout << result.get() << endl;
//		}
//		else if (status == std::future_status::timeout) {
//			//线程执行超时
//			cout << "线程执行超时" << endl;
//			cout << result.get() << endl;
//		}
//	}
//
//	system("pause");
//	return 0;
//}