#include"stdafx.h"
//#include<iostream>
//#include<vector>
//#include<future>
//#include<thread>
//
//using namespace std;
//
//std::vector<packaged_task<int(int)>> mytasks;
//int main() {
//
//	cout << "main()" << " threadid=" << std::this_thread::get_id() << endl;
//	std::packaged_task<int(int)> mypt([](int mypar) {
//		cout << mypar << endl;
//		cout << "mythread() begin" << std::this_thread::get_id() << endl;
//		std::chrono::milliseconds dura(5000);
//		std::this_thread::sleep_for(dura);
//		cout << "mythread() end" << std::this_thread::get_id() << endl;
//		return 5;
//		});
//
//	mytasks.push_back(std::move(mypt));		//入容器，这里用了移动语义，入进去后mypt就为空了
//	//...
//	std::packaged_task<int(int)> mypt2;
//
//	auto iter = mytasks.begin();
//
//	mypt2 = std::move(*iter);	//	移动语义
//	mytasks.erase(iter);		//	删除第一个元素，迭代已经失效，后续代码不能再使用iter;
//	mypt2(123);
//	std::future<int> result = mypt2.get_future();
//	cout << result.get() << endl;
//
//
//	system("pause");
//	return 0;
//}