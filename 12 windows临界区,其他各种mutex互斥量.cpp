#include"stdafx.h"
//#include<iostream>
//#include<thread>
//#include<mutex>
//#include<list>
//#include<future>
//#include<Windows.h>
//using namespace std;
//
////#define _WINDOWSJQ_
//
////���������Զ��ͷ�windows�µ��ٽ�������ֹ����LeaveCriticalSection������������ķ�����������c++11�е�std::lock_guard<std::mutex>
//class CWinLock {	//��RAII�ࣨResource Acquisition is Initialization��������Դ��ȡ����ʼ����
//					//����������ָ�������࣬������RAII�ࣻ
//public:
//	CWinLock(CRITICAL_SECTION* pCritmp) {	//���캯��
//		m_pCritical = pCritmp;
//		EnterCriticalSection(m_pCritical);
//	}
//
//	~CWinLock()
//	{
//		LeaveCriticalSection(m_pCritical);
//	}
//	
//private:
//	CRITICAL_SECTION* m_pCritical;
//};
//
//class A {
//public:
//	//���յ�����Ϣ�뵽���е��߳�
//	void inMsgRecvQueue() {
//		for (int i = 0; i < 100000; i++)
//		{
//			cout << "inMsgRecvQueue()xִ�У�����һ��Ԫ��" << i << endl;
//#ifdef _WINDOWSJQ_
//			//EnterCriticalSection(&my_winsec);	//�����ٽ�����������
//			//EnterCriticalSection(&my_winsec);
//			CWinLock wlock(&my_winsec);		//wlock����RAII���� 
//			msgRecvQueue.push_back(i);
//			//LeaveCriticalSection(&my_winsec);	//�뿪�ٽ�����������
//			//LeaveCriticalSection(&my_winsec);
//#else
//			//my_mutex.lock();
//			//std::lock_guard<std::recursive_mutex> sbguard(my_mutex);
//			//testfunction1();		//����3��,std::mutex���쳣������һ�ξ��쳣�� std::recursive_mutex���Զ�μ���
//
//			std::chrono::milliseconds timeout(100);	//100����
//			//if (my_mutex.try_lock_for(timeout)) {
//			if (my_mutex.try_lock_until(std::chrono::steady_clock::now() + timeout)) {
//				msgRecvQueue.push_back(i);	//����������־������յ��������ֱ��Ū����Ϣ����������
//				my_mutex.unlock();	//������Ҫ����
//			}
//			else {
//				//���û�õ���
//				std::chrono::milliseconds sleeptime(100);
//				std::this_thread::sleep_for(sleeptime);
//
//			}
//			//my_mutex.unlock();
//#endif // _WINDOWSJQ
//		}
//	}
//
//	bool outMsgLULProc(int& command) {
//#ifdef _WINDOWSJQ_
//		EnterCriticalSection(&my_winsec);
//		if (!msgRecvQueue.empty()) {
//			command = msgRecvQueue.front();
//			msgRecvQueue.pop_front();
//			LeaveCriticalSection(&my_winsec);
//			return true;
//		}
//		LeaveCriticalSection(&my_winsec);
//#else
//		my_mutex.lock();
//		std::chrono::milliseconds sleeptime(10000);
//		std::this_thread::sleep_for(sleeptime);
//		if (!msgRecvQueue.empty())
//		{
//			command = msgRecvQueue.front();
//			msgRecvQueue.pop_front();
//			my_mutex.unlock();
//			return true;
//		}
//		my_mutex.unlock(); 
//#endif // _WINDOWS_
//		return false;
//	}
//
//
//	void outMsgRecvQueue() {
//		int command = 0;
//		for (int i = 0; i < 100000; i++) {
//			bool result = outMsgLULProc(command);
//			if (result = true) {
//				cout << "outMsgRecvQueue() ִ�У�ȡ��һ��Ԫ��" << command << endl;
//				//���￼�Ǵ�������
//			}
//			else {
//				cout << "outMsgRecvQueue() ִ��,��Ŀǰ���ǿ�Ԫ��" << i << endl;
//			}
//		}
//		cout << "end" << endl;
//	}
//	
//	A() 
//	{
//#ifdef _WINDOWSJQ_
//		InitializeCriticalSection(&my_winsec);	//���ٽ���ǰ��Ҫ�ȳ�ʼ��
//
//#endif // _
//	}
//
//	//void testfunction1() {
//	//	std::lock_guard<std::recursive_mutex> sbguard1(my_mutex);
//	//	//��һЩ����
//	//	testfunction2();
//	//}
//
//	//void testfunction2() {
//	//	std::lock_guard<std::recursive_mutex> sbguard2(my_mutex);
//	//	//�������һЩ����
//	//}
//
//private:
//	std::list<int> msgRecvQueue;
//	//std::mutex my_mutex;				//��ռ������
//	//std::recursive_mutex my_mutex;	//�ݹ��ռ������
//	std::timed_mutex my_mutex;			//��ʱ��ռ������
//#ifdef _WINDOWSJQ_
//	CRITICAL_SECTION my_winsec; //windows�е��ٽ������ǳ�������c++11�е�mutex
//#endif // _
//};
//
//int main() {
//	
//	//һ��windows�ٽ���
//	//������ν����ٽ�������
//	//��"ͬһ���߳�"����ͬ�̻߳Ῠס�ȴ����У�windows�еġ���ͬ�ٽ���������������ٽ����Ľ��루EnterCriticalSection�����Ա���ν���
//		//����������˼���EnterCriticalSection����͵õ��ü���LeaveCriticalSection
//		//����c++11�У������� ͬһ���߳���lockͬһ����������Σ�����ᱨ�쳣
//
//	//�����Զ���������
//	//sd::lock_guard<std::mutex>
//
//	//�ģ�recursive_mutex�ݹ�Ķ�ռ������
//	//std::mutex::��ռ���������Լ�lockʱ������lock����
//	//std::recursive_mutex:�ݹ�Ķ�ռ������������ͬһ���̣߳�ͬһ����������α�.lock(),Ч���ϱ�mutexҪ��һЩ��
//		//recursive_mutexҲ��lock()��Ҳ��unlock()
//		//���Ǵ����Ƿ����Ż��ռ�
//		//�ݹ������˵�����ƣ��ݹ�̫��ο��ܱ��쳣��
//
//	//�壺����ʱ�Ļ�����std::timed_mutex��std::recursive_timed_mutex
//	//std::timed_mutex���Ǵ���ʱ���ܵĶ�ռ������
//			//try_lock_for() : ������һ��ʱ�䣬�ǵȴ�һ��ʱ�䡣������õ����������ߵȴ�����ʱ��û�õ�������������
//			//tru_lock_until(): ������δ����һ��ʱ��㣬�����δ����ʱ��û����ʱ���ڣ�����õ���������ô����������
//													//���ʱ�䵽�ˣ�û�õ�������������Ҳ������
//
//	//std::recursive_timed_mutex:����ʱ���ܵĵݹ��ռ������������ͬһ���̶߳�λ�ȡ�����������
//
//	A myobja;
//
//	std::thread myOutMsgObj(&A::outMsgRecvQueue, &myobja);
//	std::thread myInMsgObj(&A::inMsgRecvQueue,&myobja);	//ע������ڶ����������������ã����ܱ�֤�߳����õ���ͬһ������
//
//
//	myInMsgObj.join();
//	myOutMsgObj.join();
//
//	system("pause");
//	return 0;
//}