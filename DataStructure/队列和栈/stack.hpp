#include<iostream>
using namespace std;
typedef int status;
class mStack {
public:
	int m_Size;
	int m_Capacity;
	status* m_Stack;

	//����ʱ��ָ����С����������������Զ�����
	mStack(int capacity) {
		this->m_Capacity = capacity;
		this->m_Size = 0;
		//����ռ�
		this->m_Stack = new status[this->m_Capacity];
	}
	//���루�����λ�ã�
	void insert(status value) {

		if (this->m_Size < this->m_Capacity) {
			//û�г���
			this->m_Stack[this->m_Size] = value;
			this->m_Size++;
		}
		else {
			//������֮���Զ�����

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
	//����ջ����ֵ
	status getValue() {
		if (!isEmpty())
			return this->m_Stack[this->m_Size - 1];
	}
	//ɾ��ջ����ֵ
	void pop() {
		if (!isEmpty()) {
			this->m_Size--;
		}
	}
	//�ж��Ƿ�Ϊ��
	bool isEmpty() {
		return this->m_Size ? false : true;
	}
	//��ȡջ�ĳ���
	int getLength() {
		return this->m_Size;
	}
};
