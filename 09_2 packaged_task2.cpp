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
//	mytasks.push_back(std::move(mypt));		//�����������������ƶ����壬���ȥ��mypt��Ϊ����
//	//...
//	std::packaged_task<int(int)> mypt2;
//
//	auto iter = mytasks.begin();
//
//	mypt2 = std::move(*iter);	//	�ƶ�����
//	mytasks.erase(iter);		//	ɾ����һ��Ԫ�أ������Ѿ�ʧЧ���������벻����ʹ��iter;
//	mypt2(123);
//	std::future<int> result = mypt2.get_future();
//	cout << result.get() << endl;
//
//
//	system("pause");
//	return 0;
//}