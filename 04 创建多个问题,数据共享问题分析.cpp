#include"stdafx.h"
//#include<iostream>
//using namespace std;
//#include<vector>
//#include<thread>
//
//vector<int>g_v = { 1,2,3 };
//
////�߳���ں���
//void myprint(int numi)
//{
//	//cout << "�ҵ��߳̿�ʼִ���ˣ��̱߳��Ϊ��" << numi << endl;
//	//cout << "�ҵ��߳̽���ִ���ˣ��̱߳��Ϊ��" << numi << endl;
//	cout << "�̺߳�Ϊ" << std::this_thread::get_id() << "��ʼ��ӡ����g_v" << g_v[0] << g_v[1] << g_v[2] << endl;
//}
//
//int main()
//{
//	//һ�������͵ȴ�����߳�
//	vector<thread> mythreads;
//	//����10���̣߳��߳���ں���ͳһʹ��myprint
//	//a)����߳�ִ��˳�����ҵģ�������ϵͳ�ڲ����̵߳����е��Ȼ����йء�
//	//b)���̵߳ȴ��������߳����н�����������߳̽�������ʦ�Ƽ�����join()��д����������д���ȶ��ĳ���
//	//c)���ǰ�thread����ŵ������й������������Ǹ�thread�������飬�������һ�δ����������̲߳��Դ����߳̽��й���ܷ��㡣
//
//	for (int i = 0; i < 10; i++)
//	{
//		mythreads.push_back(thread(myprint, i));	//����10���̣߳�ͬʱ��10���߳��Ѿ���ʼִ��
//	}
//
//	for (auto iter = mythreads.begin(); iter != mythreads.end(); iter++) {
//		iter->join();	//�ȴ�10���̶߳�����
//	}
//
//	cout << "I Love China��" << endl;	//���ִ����䣬���������˳�
//
//	//�������ݹ����������
//	//(2.1)ֻ�������ݣ��ǰ�ȫ�ȶ��ģ�����Ҫ�ر�ʲô�����ֶΣ�ֱ�Ӷ��Ϳ��ԡ�
//	//(2.2)�ж���д
//	//(2.3)��������

//	return 0;
//