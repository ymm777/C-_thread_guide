#include"stdafx.h"
//#include<iostream>
//using namespace std;
//#include<mutex>
//
//std::mutex resource_mutex;
//std::once_flag g_flag;
//
//class MyCAS		//����һ��������
//{
//	static void CreateInstance(){	//ֻ��ִ��һ��
//		std::chrono::milliseconds dura(20000);	//��Ϣ20s
//		std::this_thread::sleep_for(dura);
//		
//		cout << "CreateInstance()��ִ����" << endl;
//
//		m_instance = new MyCAS;
//		static CGarhuishou cl;
//	}
//
//private:
//	MyCAS() {};	//˽�л��˹��캯��
//
//private:
//	static MyCAS *m_instance;	//��̬��Ա����
//
//public:
//	static MyCAS* GetInstance()
//	{
//		//���Ч��
//		//a)��� if (m_instance != NULL) ������������϶���ʾm_instance�Ѿ���new���ˣ�
//		//b)��� if (m_instance == NULL)�� ������m_instanceһ��û��new����
//
//		//if (m_instance == NULL) {	//˫������(˫�ؼ��)
//		//	std::unique_lock<std::mutex> mymutex(resource_mutex);	//�Զ�����
//		//	if (m_instance == NULL)
//		//	{
//		//		m_instance = new MyCAS;
//		//		static CGarhuishou cl;
//		//	}
//		//}
//		std::call_once(g_flag, CreateInstance);	//�����߳�ͬʱִ�е��������һ���߳�Ҫ������һ���߳�ִ�����CreateInstance
//		cout << "call_onceִ�����" << endl;
//		return m_instance;
//	}
//
//	class CGarhuishou	//��������,�����ͷŶ���
//	{
//	public:
//		~CGarhuishou()	//�������������
//		{
//			if (MyCAS::m_instance) {
//				delete MyCAS::m_instance;
//				MyCAS::m_instance = NULL;
//			}
//		}
//	};
//
//	void func() {
//		cout << "����" << endl;
//	}
//};
//
////�ྲ̬������ʼ��
//MyCAS* MyCAS::m_instance = NULL;
//
////�߳���ں���
//void mythread() {
//	cout << "�ҵ��߳̿�ʼִ����" << endl;
//	MyCAS* p_a = MyCAS::GetInstance();
//	p_a->func();
//	cout << "�ҵ��߳�ִ�������" << endl;
//}
//
//int main() {
//
//	//һ�����ģʽ���̸
//	//�����ģʽ���������һЩд������Щд��������д������ôһ������������ά���������ܷܺ��㣬���Ǳ��˽ӹܡ��Ķ�����ʮ��ʹ��
//	//�á����ģʽ������д�����Ĵ���ܻ�ɬ�ġ���head first��
//	//���ģʽ��
//	//���� Ӧ���ر�����Ŀ��ʱ�� ����Ŀ�Ŀ������顢ģ�黮�־��飬�ܽ���������ģʽ�����п������󣬺��������ܼƺ�����
//	//���ģʽ�õ��й�������̫һ��������Ӳ�ף���ĩ����
//	//���ģʽ�и����ص��ŵ㣬Ҫ��ѧ���ã���Ҫ�������У�����Ӳ�ס�
//
//	//�����������ģʽ��
//	//�������ģʽ��ʹ��Ƶ�ʱȽ� ��
//	//������������Ŀ�У���ĳ������ĳЩ�ر���࣬���ڸ���Ķ�����ֻ�ܴ���һ���������Ҵ�������
//	//�����ࣻ
//
//	//����������
//	//MyCAS* p_a = MyCAS::GetInstance();	//����һ�����󣬷��ظ���(MyCAS)�����ָ��
//
//	//p_a->func();
//	//MyCAS::GetInstance()->func();
//
//	//�����������ģʽ��������������������
//	//���ٵ����⣺��Ҫ�����Լ��������̣߳����������̣߳���������MyCAS���������Ķ��������̣߳����ܲ�ֹһ������������
//	//���ǿ��ܻ�����GetInstance()���ֳ�Ա����Ҫ����
//	//��Ȼ�����߳���ں�����ͬ�������ǧ��Ҫ��ס�����������̣߳����Ի�������ͨ·��ִ��mythread
//
//	std::thread mytobj1(mythread);
//	std::thread mytobj2(mythread);
//
//	mytobj1.join();
//	mytobj2.join();
//
//	//�ģ�std::call_once(); c++11����ĺ������ú������õĵڶ������� ��һ��������a();
//	//call_once�������ܹ���֤����a()ֻ��ִ��һ��;
//	//call_once�߱���������������������Ч���ϣ��Ȼ��������ĵ���Դ����
//	//call_once()��Ҫ��һ����ǽ��ʹ�ã�������std::once_flag; ��ʵonce_flag��һ���ṹ
//	//call_once()����ͨ����������������Ӧ��a()�Ƿ�ִ�У�����call_once()�ɹ���call_once()�Ͱ�����������Ϊһ���ѵ���״̬��
//	//�����ٴε���call_once()��ֻҪonce_flag������Ϊ���ѵ��ã���ô��Ӧ����a()�Ͳ����ٱ�ִ����
//
//	system("pause");
//	return 0;
//}