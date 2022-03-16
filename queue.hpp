//���е�˳��ṹʵ��
#define MAXSIZE 100
typedef int status;
#include<iostream>
using namespace std;
class mQueue {

	status m_Arr[MAXSIZE + 1];
	int head;		//ͷָ��
	int tail;		//βָ��
	int m_Size;
public:
	mQueue() {
		head = 0;
		tail = 0;
		m_Size = 0;
	}
	//����
	void push(status value) {
		if (m_Size != MAXSIZE) {
			m_Arr[tail] = value;
			tail = (tail + 1) % (MAXSIZE + 1);		//%MAXSIZE��Ϊ��ʵ��ѭ������
			m_Size++;
		}
	}
	//ɾ��
	void pop() {
		if (m_Size != 0) {
			head = (head + 1) % (MAXSIZE + 1);
			m_Size--;
		}
	}
	//ȡ��ͷԪ��
	status getFront() {
		return m_Arr[head];
	}
	//ȡ��βԪ��
	status getBack() {
		return m_Arr[(tail +MAXSIZE)%(MAXSIZE + 1)];
	}
	//�ж��Ƿ�Ϊ��
	bool isEmpy() {
		if (m_Size == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	//��ն���
	void clearQueue() {
		head = 0;
		tail = 0;
		m_Size = 0;
	}
};