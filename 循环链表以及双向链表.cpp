#include<iostream>
using namespace std;
typedef int status;
#define OVERFLOW -2	//溢出
#define ERROR -1	//链表为空或者一些其他错误
//节点的定义
typedef struct node
{
	status value;
	node* next;
	node* prior;
}LinkList;
typedef LinkList* linklist;

void init(linklist& head);		//初始化双向循环链表	
void printList(linklist& head);	//正向打印一遍，再反向打印一遍


void test01() {
	linklist head = new LinkList;
	head->next = head;
	head->prior = head;
	init(head);
	
	{
		//合并两个循环表
		linklist head1 = new LinkList;
		linklist head2 = new LinkList;
		init(head1);
		init(head2);
		printList(head1);
		cout << "-------------------------" << endl;
		printList(head2);
		cout << "-------------------------" << endl;
		head2->next->prior = head1->prior;
		head2->next->prior->next = head2->next;
		head1->prior = head2->prior;
		head2->prior->next = head1;
		
		delete head2;
		printList(head1);
	}
}
int main() {
	test01();
	return 0;
}
void init(linklist& head) {
	linklist p = head;
	linklist l = head;
	for (int i = 0; i < 8; i++) {
		p->next = new LinkList;
		p = p->next;
		p->value = 10 * (i + 1);
		p->next = NULL;
		p->prior = l;
		l = l->next;
	}
	p->next = head;
	head->prior = p;
}
void printList(linklist& head) {
	linklist p = head->next;
	while (p != head)
	{
		cout << p->value << " ";
		p = p->next;
	}
	cout << endl;
	p = head->prior;
	while (p != head)
	{
		cout << p->value << " ";
		p = p->prior;
	}
	cout << endl;
}