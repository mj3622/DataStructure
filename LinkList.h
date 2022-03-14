/*
���ߣ�Minjer
��ϵ��ʽ��minjer@foxmail.com
һЩ������
1.Ŀǰstatus�ݲ�֧���Զ����������ͣ������Լ�ֻ���Թ����ͣ����������޷���֤��������
2.��Ȼ����һ���ı�����ʩ���������п��ܳ��ָ������⣬�����ֻ�ӭ������ϵ
*/
#include<iostream>
using namespace std;
typedef int status;
#define OVERFLOW -2
#define ERROR -1
typedef struct node
{
	status value;
	node* next;
	node* prior;
}LinkList;
typedef LinkList* linklist;
//���ٵ�����
void deleteList(linklist& head);
//�ж������Ƿ�Ϊ��
bool isEmpty(linklist& head);
//��ӡ���������е�Ԫ��
void myPrint(linklist& head);
//��ʼ������
void initList(linklist& head);
//�������
void clearList(linklist& head);
//��ȡ����ĳ���(ѭ����������)
int getLength(linklist& head);
//��ָ��λ�ò���Ԫ��(����ֵ�����Ƿ����ɹ�)
bool insertList(linklist& head, int pos);
//ȡ�������е��ض�Ԫ��(��λ��)	
status getPosList(linklist& head, int pos);
//ȡ�������е��ض�Ԫ��(��ֵ)	����λ��	δ�ҵ��򷵻�0	ֻ�᷵�ص�һ���ҵ���ֵ
int getValList(linklist& head, status value);

//��ʼ������
void initList(linklist& head) {
	head->next = new LinkList;
	linklist p = head->next;
	for (int i = 0; i < 8; i++) {
		p->value = 10 * (i + 1);
		p->next = new LinkList;
		p = p->next;
	}
	p->next = NULL;
}
//��ӡ���������е�Ԫ��
void myPrint(linklist& head) {
	if (!isEmpty(head)) {
		linklist p = head->next;
		while (p->next)
		{
			cout << p->value << "  ";
			p = p->next;
		}
	}
	else {
		cout << "����Ϊ��";
	}
	cout << endl;
}
//�ж������Ƿ�Ϊ��
bool isEmpty(linklist& head) {
	if (!head)return true;
	if (head->next) {
		return false;
	}
	else {
		return true;
	}
}
//���ٵ�����
void deleteList(linklist& head) {
	linklist p = head;
	while (head->next) {
		head = head->next;
		delete p;
		p = head;
	}
	head = NULL;
}
//�������
void clearList(linklist& head) {
	if (!isEmpty(head)) {
		linklist p = head->next;
		linklist r = p->next;	//ָ��P����һ��
		head->next = NULL;		//��head�ÿ�
		while (r->next) {
			delete p;
			p = r;
			r = r->next;
		}
		delete p;
	}
}
//��ȡ����ĳ���(ѭ����������)
int getLength(linklist& head) {
	int num = 0;	//��¼����
	if (isEmpty(head)) {
		return 0;
	}
	else {
		linklist p = head->next;
		while (p->next)
		{
			num++;
			p = p->next;
		}
		return num;
	}
}
//��ָ��λ�ò���Ԫ��(����ֵ�����Ƿ����ɹ�)
bool insertList(linklist& head, int pos) {
	status tar;
	cout << "������Ҫ�����Ԫ��" << endl;
	cin >> tar;		 //��¼Ҫ�����Ԫ��
	if (pos > 0 && pos <= getLength(head) + 1) {
		linklist p = head->next;
		linklist l = head;		//ָ��p��ǰһ��λ��
		for (int i = 1; i < pos; i++) {
			l = l->next;
			p = p->next;
		}
		linklist temp = new LinkList;
		temp->value = tar;
		l->next = temp;
		temp->next = p;
	}
	else {
		return false;
	}
}
//ȡ�������е��ض�Ԫ��(��λ��)
status getPosList(linklist& head, int pos) {
	if (isEmpty(head)) {
		return ERROR;
	}
	else {
		if (pos <= getLength(head) && pos > 0) {
			linklist p = head->next;
			for (int i = 1; i < pos; i++) {
				p = p->next;
			}
			return p->value;
		}
		else {
			return OVERFLOW;
		}
	}
}
//ȡ�������е��ض�Ԫ��(��ֵ)
int getValList(linklist& head, status tvalue) {
	if (isEmpty(head)) {
		return ERROR;
	}
	else {
		linklist p = head->next;
		int pos = 1;
		while (p->next)
		{
			if (p->value == tvalue) {
				return pos;
			}
			pos++;
			p = p->next;
		}
		return 0;	//����û�ҵ�
	}
}
