#include"stdafx.h"
#include<iostream>
#include<mutex>
#include<thread>
#include<future>
#include<list>
using namespace std;

class A {
public:
	atomic<int> atm;
	A() {
		atm = 0;
		//auto atm2 = atm;	//���ֶ���ʱ��ʼ��������������ʾ������������ɾ���ĺ������������ڲ��϶��ѿ������캯�����ɵ�����=delete
		//atomic<int> atm3 = atm;
		//atomic<int> atm2;
		//atm2 = atm;	//����������ɾ���ĺ��������������Ҳ������
		//load():��ԭ�ӷ�ʽ��atomic�����ֵ
		atomic<int> atm2(atm.load());	//��
		auto atm3(atm.load());
		//store()��ԭ�ӷ�ʽд������
		atm2.store(12);
		atm2 = 12;	
	}

	void inMsgRecvQueue() {
		//for (int i = 0; i < 100000; i++) {
		//	cout << "inMsgRecvQueue()ִ�У�����һ��Ԫ��" << i << endl;
		//	std::unique_lock<std::mutex> sbguard1(my_mutex1);
		//	msgRecvQueue.push_back(i);
		//	my_cond.notify_one();
		//}
		for (int i = 0; i < 100000; i++) {
			//atm += 1;	//ԭ�Ӳ���
			atm = atm + 1;	//	��ԭ�Ӳ���
		}
	}

	void outMsgRecvQueue() {
		//int command = 0;
		//while (true)
		//{
		//	std::unique_lock<std::mutex> sbguard1(my_mutex1);	//�ٽ��ȥ
		//	my_cond.wait(sbguard1, [this] {		//this,���Բο� δ����֪ʶ �ڰ˽�
		//		if (!msgRecvQueue.empty())
		//			return true;	//��lambda����true����wait�ͷ��أ������������������������߳��õ�
		//		return false;		//���������ߣ�����wait�ȴ����ٴλ���
		//		});
		//	//�̻߳��������ţ�������������������������
		//	command = msgRecvQueue.front();		//���ص�һ��Ԫ�أ��������Ԫ���Ƿ����
		//	msgRecvQueue.pop_front();			//�Ƴ���һ��Ԫ�أ���������
		//	sbguard1.unlock();		//��Ϊunique_lock������ԣ����ǿ�����ʱunlock������������ס̫��ʱ��
		//	cout << "outMsgRecvQueue()ִ�У�ȡ��һ��Ԫ��" << command << endl;
		//}//end while

		while (true)
		{
			cout << atm << endl;
		}
	}

private:
	std::list<int> msgRecvQueue;
	std::mutex my_mutex1;
	std::condition_variable my_cond;
};

int main() {

	A myobja;
	std::thread myOutObj(&A::outMsgRecvQueue, &myobja);
	std::thread myInObj(&A::inMsgRecvQueue, &myobja);
	std::thread myInObj2(&A::inMsgRecvQueue, &myobja);

	myOutObj.join();
	myInObj.join();
	myInObj2.join();

	//һ������һЩ֪ʶ��
	//(1.1)��ٻ��ѣ�wait��Ҫ�еڶ���������lambda���������lambda��Ҫ��ȷ�ж�Ҫ����Ĺ��������Ƿ����
	//wait(),notify_one(),notify_all(); 

	//(1.2)atomic,10,11�ڶ��н���

	//����ǳ̸�̳߳�
	//(2.1)��������
	//����������--���ͻ��ˣ�ÿ��һ���ͻ��ˣ��ʹ���һ�����߳�Ϊ�ÿͻ����ṩ����
	//a)������Ϸ��2����Ҳ����ܸ�ÿ����Ҵ��������̣߳��˳���д�������ֳ����²�ͨ
	//b)�����ȶ������⣺��д�Ĵ����У�ż������һ���߳����ִ��룬����д���������˸е�����
	//�̳߳أ���һ���߳�Ū��һ��ͳһ��������ͳһ������ȣ�ѭ�������̵߳ķ�ʽ���ͽ��̳߳�
	//(2.2)ʵ�ַ�ʽ
	//�ڳ�������ʱ����һ���Դ�����һ���������̡߳�10,8,100-200�������˷��ģ����ó��������ȶ�

	//�����̴߳�������̸
	//��3.1���߳̿��������������⣬2000���̻߳������Ǽ��ޣ��ٴ����̳߳���ͻ������
	//��3.2���̴߳�����������
	//a)����ĳЩ������������api�ӿ��ṩ�̽����㴴���߳����� =cpu������cou*2��cpu*2+2������רҵ�����ָʾ����רҵ����ȷ�������Чִ��
	//b)�������߳����ҵ��һ���̵߳���һ��ִ��ͨ·��100��������ֵ���������￪110���̣߳����Ǻܺ��ʵ�
	//c)1800���̣߳����飬�߳�����������Ҫ����500���ܿ�����200��֮��

	//�ģ�c++���߳��ܽ�
	//windows,linux



	system("pause");
	return 0;
}