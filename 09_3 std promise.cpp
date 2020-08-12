#include"stdafx.h"
//#include<iostream>
//#include<future>
//#include<thread>
//
//using namespace std;
//
//void mythread(std::promise<int>& tmpp, int calc) {
//	//做一系列复杂的操作
//	calc++;
//	calc *= 10;
//	//做其他运算，比如整整花费5秒;
//	std::chrono::milliseconds dura(5000);
//	std::this_thread::sleep_for(dura);
//
//	//终于计算出结果
//	int result = calc;
//	tmpp.set_value(calc);	//结果保存到tmpp这个对象;
//	return;
//}
//
//void mythead2(std::future<int>& temp) {
//	auto result = temp.get();
//	cout << "mythread2 result=" << result << endl;
//	return;
//}
//
//int main() {
//
//	//三：std::promise，类模板
//	//我们能够在某个线程中给它赋值，然后我们在其他线程中，把这个值取出来用
//	//总结：通过promise保存一个值，在将来某个时刻我们通过把一个future绑定到这个promise上来得到这个绑定的值
//
//	std::promise<int> myprom;	//声明一个std::promise对象myprom,保存的值类型为int
//	std::thread t1(mythread, std::ref(myprom), 180);
//	t1.join();
//
//	std::future<int> ful1 = myprom.get_future();	//promise与future绑定，用于获取线程返回值
//
//	//auto result = ful1.get();	//get()只能调用一次，不能调用多次
//	//cout << "result=" << result << endl;
//
//	std::thread t2(mythead2, std::ref(ful1));
//	t2.join();
//
//	cout << "I love China!" << endl;
//
//	//四：小结：到底怎么用，什么时候用
//	//我们学习这些东西的目的，并不是要把他们都用在咱们自己的实际开发中。
//	//相反，如果我们能够用最少的东西能够写出一个稳定、高效的多线程程序，更值得赞赏；
//	//我们为了成长，必须要阅读一些高手写的代码，从而快速实现自己代码的积累，我们的技术就会有一个大幅度的提升。
//	//更愿意将学习这些内容的理由解释为：为我们将来能够读懂高手甚至大师写的代码而铺路；
//
//	system("pause");
//	return 0;
//}