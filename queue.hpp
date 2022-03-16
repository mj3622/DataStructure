//队列的顺序结构实现
#define MAXSIZE 100
typedef int status;
#include<iostream>
using namespace std;
class mQueue {

	status m_Arr[MAXSIZE + 1];
	int head;		//头指针
	int tail;		//尾指针
	int m_Size;
public:
	mQueue() {
		head = 0;
		tail = 0;
		m_Size = 0;
	}
	//插入
	void push(status value) {
		if (m_Size != MAXSIZE) {
			m_Arr[tail] = value;
			tail = (tail + 1) % (MAXSIZE + 1);		//%MAXSIZE是为了实现循环功能
			m_Size++;
		}
	}
	//删除
	void pop() {
		if (m_Size != 0) {
			head = (head + 1) % (MAXSIZE + 1);
			m_Size--;
		}
	}
	//取出头元素
	status getFront() {
		return m_Arr[head];
	}
	//取出尾元素
	status getBack() {
		return m_Arr[(tail +MAXSIZE)%(MAXSIZE + 1)];
	}
	//判断是否为空
	bool isEmpy() {
		if (m_Size == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	//清空队列
	void clearQueue() {
		head = 0;
		tail = 0;
		m_Size = 0;
	}
};