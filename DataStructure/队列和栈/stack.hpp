#include<iostream>
using namespace std;
typedef int status;
class mStack {
public:
	int m_Size;
	int m_Capacity;
	status* m_Stack;

	//构造时先指定大小，后续如果超出会自动扩大
	mStack(int capacity) {
		this->m_Capacity = capacity;
		this->m_Size = 0;
		//分配空间
		this->m_Stack = new status[this->m_Capacity];
	}
	//插入（到最后位置）
	void insert(status value) {

		if (this->m_Size < this->m_Capacity) {
			//没有充满
			this->m_Stack[this->m_Size] = value;
			this->m_Size++;
		}
		else {
			//充满了之后自动扩容

			status* temp = new status[this->m_Capacity];
			for (int i = 0; i < m_Size; i++)
				temp[i] = m_Stack[i];
			this->m_Capacity = this->m_Capacity * 3;
			delete[] m_Stack;
			this->m_Stack = NULL;
			this->m_Stack = new status[this->m_Capacity];
			for (int i = 0; i < m_Size; i++)
				m_Stack[i] = temp[i];
			this->m_Stack[this->m_Size] = value;
			this->m_Size++;
		}
	}
	//返回栈顶的值
	status getValue() {
		if (!isEmpty())
			return this->m_Stack[this->m_Size - 1];
	}
	//删除栈顶的值
	void pop() {
		if (!isEmpty()) {
			this->m_Size--;
		}
	}
	//判断是否为空
	bool isEmpty() {
		return this->m_Size ? false : true;
	}
	//获取栈的长度
	int getLength() {
		return this->m_Size;
	}
};
