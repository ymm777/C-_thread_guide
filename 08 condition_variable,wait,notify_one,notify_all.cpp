#include"stdafx.h"
//#include<iostream>
//using namespace std;
//#include<list>
//#include<thread>
//#include<mutex>
//
//class A {
//public:
//	void inMsgRecvQueue()
//	{
//		for (int i = 0; i < 100000; i++) {
//			cout << "inMsgRecvQueue()ִ��,����һ��Ԫ��" << i << endl;
//
//			std::unique_lock<std::mutex> sbguard1(my_mutex1);
//			msgRecvQueue.push_back(i);	//�����������i���յ��������ֱ�Ӽ��뵽��Ϣ����
//
//			//����outMsgRecvQueue()���ڴ���һ��������Ҫһ��ʱ�䣬������������wait()������㻽�ѣ���ô��ʱ���notify_oneҲ���ûЧ��
//			//my_cond.notify_one();	//���԰�wait()�̻߳��ѣ�ִ�������У���ôoutMsgRecvQueue()�����wait()�ͻᱻ����
//									//����֮����£��������о�
//			my_cond.notify_all();
//			//....
//			//�����������	
//		}
//	}
//
//	//bool outMsgLULProc(int& command) {
//	//	std::unique_lock<std::mutex> sbguard1(my_mutex1);
//
//	//	if (!msgRecvQueue.empty()) {
//	//		command = msgRecvQueue.front();
//	//		msgRecvQueue.pop_front();
//	//		return true;
//	//	}
//	//	return false;
//	//}
//
//	void outMsgRecvQueue() {
//		int command = 0;
//
//		while (true)
//		{
//			std::unique_lock<std::mutex> sbguard1(my_mutex1);
//
//			//wait()������һ������
//			//����ڶ�������lambda���ʽ����ֵ��true����wait()ֱ�ӷ���;
//			//����ڶ�������lambda���ʽ����ֵ��false����ôwait()��������������������������;
//				//	�Ƕ�����ʲôʱ��Ϊֹ�أ�����������ĳ���̵߳���notify_one()��Ա����Ϊֹ;
//			//���wait()û�еڶ���������my_cond.wait(sbguard1); ��ô�͸��ڶ�������lambda���ʽ����falseЧ��һ����
//				//wait()�������������������������У�����������ĳ���̵߳���notify_one()��Ա����Ϊֹ��
//			//�������߳���notify_one()����wait()(ԭ����˯��/����)��״̬���Ѻ�wait�Ϳ�ʼ�ָ��ɻ��ˣ��ָ���wait��ʲô��
//				//a)wait()���ϳ������»�ȡ���������������ȡ����,��ô���̾Ϳ���wait������Ż�ȡ�������ȡ����������ȡ���ͼ������ͼ�������ִ��b
//				//b)
//					//b.1)���wait�еڶ�������(lambda),���ж����lambda���ʽ�����lambda���ʽΪfalse����ôwait���ͷ������ȴ������߳�notify_one����
//					//b.2)���lambda���ʽΪtrue����wait���أ���������������ʱ�����������ţ�
//					//b.3)���waitû�еڶ�����������wait���أ�������������
//
//
//			my_cond.wait(sbguard1, [this] {		//һ��lambda����һ���ɵ��ö���(����)
//				if (!msgRecvQueue.empty())
//					return true;
//				return false;
//				});
//
//			//����ֻҪ���ߵ�������������һ�������ŵ�,ͬʱmsgRecvQueue������һ������
//			command = msgRecvQueue.front();
//			msgRecvQueue.pop_front();
//			cout << "outMsgRecvQueue()ִ���ˣ�ȡ��һ��Ԫ��" << "thread_id=" << std::this_thread::get_id() << command << endl;
//			sbguard1.unlock();	//��Ϊunique_lock������ԣ��������ǿ�����ʱunlock,������ס̫��ʱ��
//
//
//			//ִ��һЩ���嶯����������ҳ鿨���鿨��Ҫ100����Ĵ���ʱ��
//			//....
//			//ִ��100����
//			//
//		}
//		
//		//for (int i = 0; i < 100000; i++) {
//		//	bool result = outMsgLULProc(command);
//		//	if (result) {
//		//		cout << "outMsgRecvQueue()ִ���ˣ�ȡ��һ��Ԫ��" << command << endl;
//		//	}
//		//	else {
//		//		cout << "outMsgRecvQueue()ִ���ˣ���Ŀǰ��Ϣ����Ϊ��" << endl;
//		//	}
//		//}
//	}
//
//private:
//	mutex my_mutex1;
//	list<int> msgRecvQueue;
//	std::condition_variable my_cond;
//};
//
//int main() {
//
//	//һ����������std::condition_variable,wait(),notify_one:ֻ��֪ͨһ��outMsgRecvQueue�߳�
//	//�߳�A���ȴ�һ����������
//	//�߳�B��ר������Ϣ����������Ϣ�����ݣ�
//	//std::condition_variableʵ������һ���࣬��һ����������ص�һ���࣬˵���˾��ǵȴ�һ���������
//	//���������Ҫ�ͻ���������Ϲ������õ�ʱ������Ҫ���������Ķ���
//
//	//����������������˼��
//
//	//����notify_all
//
//	A myobja;
//	std::thread myOutMsgObj(&A::outMsgRecvQueue, &myobja);	//�ڶ������������ã����ܱ�֤�߳��� �õ���ͬһ������
//	std::thread myOutMsgObj2(&A::outMsgRecvQueue, &myobja);
//	std::thread myInMsgObj(&A::inMsgRecvQueue, &myobja);
//	myInMsgObj.join();
//	myOutMsgObj.join();
//	myOutMsgObj2.join();
//
//	system("pause");
//	return 0;
//}