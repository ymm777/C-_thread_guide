#include"stdafx.h"
//#include<iostream>
//#include<mutex>
//#include<list>
//#include<thread>
//using namespace std;
//
//class A {
//public:
//
//	std::unique_lock<std::mutex> rtn_unique_lock() {
//		std::unique_lock<std::mutex> tmpguard(my_mutex1);
//		return tmpguard;		//�Ӻ�������һ���ֲ���unique_lock�����ǿ��Եģ��ƶ����캯��
//								//�������־ֲ�����temguard�ᵼ��ϵͳ������ʱ��unique_lock���󣬲�����unique_lock���ƶ����캯��
//	}
//
//	void inMsgRecvQueue()
//	{
//		for (int i = 0; i < 100000; i++) {
//			cout << "inMsgRecvQueueִ��,����һ��Ԫ�أ�" << i << endl;
//
//			//my_mutex1.lock();
//			//std::unique_lock<std::mutex> sbguard1(my_mutex1,std::adopt_lock);
//
//			//std::unique_lock<std::mutex> sbguard1(my_mutex1, std::try_to_lock);
//
//			//std::unique_lock<std::mutex> sbguard1(my_mutex1, std::defer_lock);
//			
//			//sbguard1.lock();
//			//����������
//			//sbguard1.unlock();
//			//����һЩ�ǹ�������
//			
//			//std::unique_lock<std::mutex> sbguard1(my_mutex1);
//
//			//std::unique_lock<std::mutex> sbguard2(sbguard1);		//��������Ȩ�Ƿ�
//
//			//std::unique_lock<std::mutex> sbguard2(std::move(sbguard1));	//�ƶ�����,����sbguard2��mutex��
//																		//����sbguard1ָ��գ�sbguard2ָ��mutex
//
//			std::unique_lock<std::mutex> sbguard1 = rtn_unique_lock();
//
//			//std::mutex *ptr = sbguard1.release();
//
//
//			//sbguard1.lock();
//
//			//if (sbguard1.owns_lock()) {
//				//�õ�����
//			msgRecvQueue.push_back(i);
//			//}
//			//else {
//				//û�õ���
//			//	cout << "inMsgRecvQueueִ�У���û���õ�����ֻ�ܸɵ�����" << i << endl;
//			//}
//			//sbguard1.lock();	//��������
//			//ptr->unlock();
//		}
//	}
//
//	bool outMsgLULProc(int& command)
//	{
//		//std::lock_guard<std::mutex> sbguard1(my_mutex1);
//
//		my_mutex1.lock();
//		std::unique_lock<std::mutex> sbguard1(my_mutex1,std::adopt_lock);
//
//		//std::chrono::milliseconds dura(2000);
//		//std::this_thread::sleep_for(dura);	//��Ϣһ��ʱ��
//
//		if (!msgRecvQueue.empty()) {
//			command = msgRecvQueue.front();
//			msgRecvQueue.pop_front();
//			return true;
//		}
//		return false;
//	}
//
//	void outMsgRecvQueue() {
//		int command = 0;
//		for (int i = 0; i < 100000; i++) {
//			bool result = outMsgLULProc(command);
//			if (result == true) {
//				cout << "outMsgRecvQueue()ִ���ˣ�ȡ��һ��Ԫ��" << command << endl;
//			}
//			else
//			{
//				cout << "outMsgRecvQueue()ִ���ˣ���Ŀǰ��Ϣ����Ϊ��" << endl;
//			}
//		}
//		cout << endl;
//	}
//
//	//void outMsgRecvQueue() {
//	//	for (int i = 0; i < 10000; i++) {
//	//		if (!msgRecvQueue.empty()) {
//	//			cout << "outMsgRecvQueue()ִ���ˣ�ȡ��һ��Ԫ��" << endl;
//	//			msgRecvQueue.pop_front();
//	//		}
//	//		else {
//	//			cout << "outMsgRecvQueue()ִ���ˣ���Ŀǰ��Ϣ����Ϊ��" << endl;
//	//		}
//	//	}
//	//	cout << endl;
//	//}
//
//private:
//	list<int> msgRecvQueue;
//	mutex my_mutex1;
//	mutex my_mutex2;
//};
//
//
//
//int main() {
//
//	//һ��unique_lockȡ��lock_guard
//	//unique_lock�Ǹ���ģ�壬�����У�һ��lock_guard(�Ƽ�ʹ��)��lock_guardȡ����mutex��lock()��unlock()
//	//unique_lock��lock_guard���ܶ࣬Ч���ϲ�һ�㣬�ڴ�ռ�ö�һ��
//	//����unique_lock�ĵڶ�������
//	//lock_guard���Դ��ڶ�������
//
//	//std::lock_guard<std::mutex> sbguard1(my_mutex1,adop_lock)	//adop_lock�������
//	//(2.1)std::adop_lock:��ʾ����������Ѿ���lock�ˣ������Ҫ�ѻ�������ǰlock������ᱨ�쳣��
//	//std::adop_lock��ǵ����þ��ǡ�������÷� �߳��Ѿ�ӵ���˻��������Ȩ���Ѿ�lock()�ɹ�����
//	//֪ͨlock_guard����Ҫ�ڹ��캯����lock����������ˣ�
//	//unique_lockҲ���Դ�std::adop_lock�����ǣ�������ͬ�����ǲ�ϣ����unique_lock()�Ĺ��캯����lock���mutex��
//	//�����adop_lock��ǰ���ǣ�����Ҫ�Լ��Ȱ�mutex��lock��
//
//	//(2.2)std::try_to_lock
//	//���ǻ᳢����mutex��lock()ȥ�������mutex�������û�������ɹ�����Ҳ���������أ����������������
//	//�����try_to_lock��ǰ�������Լ�������ȥlock()��
//
//	//(2.3)std::defer_lock
//	//�����defer_lock��ǰ���� �㲻���Լ���lock����ᱨ�쳣
//	//defer_lock����˼ ���� û�и�mutex��������ʼ����һ��δ������mutex
//	//���ǽ���defer_lock�Ļ���������һЩunique_lock����Ҫ��Ա����
//
//	//����unique_lock�ĳ�Ա����
//	//(3.1) lock(),����
//	//(3.2) unlock(),����
//	//(3.3) try_lock(),���Ը���������������������ɹ�����true�����򷵻�false����������ǲ��������ġ�
//	//(3.4) release(),�������������mutex����ָ�룬���ͷ�����Ȩ��Ҳ����˵�����unique_lock��mutex�����й�ϵ
//	//�ϸ�����unlock()��release()�����𣬲�Ҫ������
//	//���ԭ��mutex�����ڼ���ת״̬���������νӹܹ����������������release���ص���ԭʼmutex��ָ�룩
//	//Ϊʲô��ʱ����Ҫunlock(),��Ϊlock()��ס�Ĵ���Խ�٣�ִ��Խ�죬���������Ч��Խ��
//	//����Ҳ��lock()��ס�Ĵ������ ��Ϊ �������ȣ�����һ���ô�ϸ������
//	//a)��ס�Ĵ����٣���������ϸ��ִ��Ч�ʸ�
//	//b)��ס�Ĵ���࣬���Ƚд֣���ôִ��Ч�ʵ͡�
//	//Ҫ����ѡ��������ȵĴ�����б���������̫ϸ������©���������ݵı���������̫�֣�����ִ��Ч�ʵ�
//
//	//�ģ�unique_lock����Ȩ�Ĵ���mutex
//	//std::unique_lock<std::mutex> sbguard1(my_mutex1); ����Ȩ����
//	//sbguard1ӵ��my_mutex1������Ȩ
//	//sbguard1���԰��Լ���mutex��my_mutex1��������Ȩת�Ƹ�������unique_lock����
//	//���ԣ�unique_lock�������mutex������Ȩ����ת�Ƶ��ǲ����Ը��ơ�
//
//	//a)std::move
//	//b)return	std::unique_lock<std::mutex>
//
//	A myobja;
//
//	thread myInMsgObj(&A::inMsgRecvQueue, &myobja);
//
//	thread myOutMsgObj(&A::outMsgRecvQueue, &myobja);
//
//	myInMsgObj.join();
//	myOutMsgObj.join();
//
//	return 0;
//}