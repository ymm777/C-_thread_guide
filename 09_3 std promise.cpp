#include"stdafx.h"
//#include<iostream>
//#include<future>
//#include<thread>
//
//using namespace std;
//
//void mythread(std::promise<int>& tmpp, int calc) {
//	//��һϵ�и��ӵĲ���
//	calc++;
//	calc *= 10;
//	//���������㣬������������5��;
//	std::chrono::milliseconds dura(5000);
//	std::this_thread::sleep_for(dura);
//
//	//���ڼ�������
//	int result = calc;
//	tmpp.set_value(calc);	//������浽tmpp�������;
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
//	//����std::promise����ģ��
//	//�����ܹ���ĳ���߳��и�����ֵ��Ȼ�������������߳��У������ֵȡ������
//	//�ܽ᣺ͨ��promise����һ��ֵ���ڽ���ĳ��ʱ������ͨ����һ��future�󶨵����promise�����õ�����󶨵�ֵ
//
//	std::promise<int> myprom;	//����һ��std::promise����myprom,�����ֵ����Ϊint
//	std::thread t1(mythread, std::ref(myprom), 180);
//	t1.join();
//
//	std::future<int> ful1 = myprom.get_future();	//promise��future�󶨣����ڻ�ȡ�̷߳���ֵ
//
//	//auto result = ful1.get();	//get()ֻ�ܵ���һ�Σ����ܵ��ö��
//	//cout << "result=" << result << endl;
//
//	std::thread t2(mythead2, std::ref(ful1));
//	t2.join();
//
//	cout << "I love China!" << endl;
//
//	//�ģ�С�᣺������ô�ã�ʲôʱ����
//	//����ѧϰ��Щ������Ŀ�ģ�������Ҫ�����Ƕ����������Լ���ʵ�ʿ����С�
//	//�෴����������ܹ������ٵĶ����ܹ�д��һ���ȶ�����Ч�Ķ��̳߳��򣬸�ֵ�����ͣ�
//	//����Ϊ�˳ɳ�������Ҫ�Ķ�һЩ����д�Ĵ��룬�Ӷ�����ʵ���Լ�����Ļ��ۣ����ǵļ����ͻ���һ������ȵ�������
//	//��Ը�⽫ѧϰ��Щ���ݵ����ɽ���Ϊ��Ϊ���ǽ����ܹ���������������ʦд�Ĵ������·��
//
//	system("pause");
//	return 0;
//}