#include<iostream>
using namespace std;
struct Joseph{
	int index;
	int key;
	Joseph* next;
};
typedef Joseph* jh;
void JosephDemo(jh& joseph, int numOfperson, int firstKey);
int main() {
	jh joseph = new Joseph;

	/*
	7 20
	3 1 7 2 4 8 4
	*/

	//��������
	cout << "������������" << endl;
	int numOfperson = 0;
	while (true)
	{
		cin >> numOfperson;
		if (numOfperson <= 0) {
			cout << "����Ƿ�����������" << endl;
		}
		else
		{
			break;
		}
	}
	cout << "�������һ�α���" << endl;
	int firstKey = 0;
	while (true)
	{
		cin >> firstKey;
		if (firstKey <= 0) {
			cout << "����Ƿ�����������" << endl;
		}
		else
		{
			break;
		}
	}
	JosephDemo(joseph, numOfperson, firstKey);
}
void JosephDemo(jh& joseph, int numOfperson, int firstKey) {
	jh p = joseph;
	jh front = joseph;
	//��ȡ�����˵�Keyֵ
	cout << "�������1���˵�keyֵ" << endl;
	while (true)
	{
		int tempValue;
		cin >> tempValue;
		if (tempValue <= 0) {
			cout << "����Ƿ�������������" << endl;
		}
		else {
			p->key = tempValue;
			p->index = 1;
			break;
		}
	}
	for (int i = 1; i < numOfperson; i++) {
		p->next = new Joseph;
		p = p->next;
		cout << "�������" << i + 1 << "���˵�Keyֵ" << endl;
		int tempKey = 0;
		while (true)
		{
			cin >> tempKey;
			if (tempKey <= 0) {
				cout << "����Ƿ�������������" << endl;
			}
			else {
				p->key = tempKey;
				p->index = i + 1;
				break;
			}
		}
	}
	p->next = joseph;	//βָ��ͷ
	front = p;
	p = p->next;
	//��ʼɸ��
	int key = firstKey;
	while (true)
	{
		if (front == p)break;	//����ָ��ָһ����˵��ֻʣһ����
		for (int i = 1; i < key; i++) {
			front = p;
			p = p->next;
		}
		key = p->key;
		cout << p->index << "\t";
		front->next = p->next;
		//front = p;
		p = p->next;
	}
	cout << p->index;
}