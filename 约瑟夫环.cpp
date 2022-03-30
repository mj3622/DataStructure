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

	//读入数据
	cout << "请输入总人数" << endl;
	int numOfperson = 0;
	while (true)
	{
		cin >> numOfperson;
		if (numOfperson <= 0) {
			cout << "输入非法，重新输入" << endl;
		}
		else
		{
			break;
		}
	}
	cout << "请输入第一次报数" << endl;
	int firstKey = 0;
	while (true)
	{
		cin >> firstKey;
		if (firstKey <= 0) {
			cout << "输入非法，重新输入" << endl;
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
	//读取所有人的Key值
	cout << "请输入第1个人的key值" << endl;
	while (true)
	{
		int tempValue;
		cin >> tempValue;
		if (tempValue <= 0) {
			cout << "输入非法，请重新输入" << endl;
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
		cout << "请输入第" << i + 1 << "个人的Key值" << endl;
		int tempKey = 0;
		while (true)
		{
			cin >> tempKey;
			if (tempKey <= 0) {
				cout << "输入非法，请重新输入" << endl;
			}
			else {
				p->key = tempKey;
				p->index = i + 1;
				break;
			}
		}
	}
	p->next = joseph;	//尾指向头
	front = p;
	p = p->next;
	//开始筛人
	int key = firstKey;
	while (true)
	{
		if (front == p)break;	//两个指针指一起是说明只剩一人了
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