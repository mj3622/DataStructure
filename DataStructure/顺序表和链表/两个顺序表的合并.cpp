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
}LinkList;
typedef LinkList* linklist;
void initList1(linklist& head) {
	head->next = new LinkList;
	linklist p = head->next;
	for (int i = 0; i < 8; i++) {
		p->value = 10 * (i + 1);
		p->next = new LinkList;
		p = p->next;
	}
	p->next = NULL;
}
void initList2(linklist& head) {
	head->next = new LinkList;
	linklist p = head->next;
	for (int i = 0; i < 6; i++) {
		p->value = 5 * (i + 1);
		p->next = new LinkList;
		p = p->next;
	}
	p->next = NULL;
}
void printList(linklist& head) {
	linklist p = head->next;
	while (p->next){
		cout << p->value << "  ";
		p = p->next;
	}
	cout << endl;
}
//返回新链表的头指针
linklist& addList(linklist& head1, linklist& head2) {
	linklist head = new LinkList;
	head->next = new LinkList;

	linklist p = head->next;
	linklist p1 = head1->next;
	linklist p2 = head2->next;
	while (p1->next != NULL && p2->next != NULL)
	{
		if (p1->value == p2->value) {
			p->value = p1->value;
			p1 = p1->next;
			p2 = p2->next;
			p->next = new LinkList;
			p = p->next;
			p->next = NULL;
		}
		else if(p1->value > p2->value) {
			p->value = p2->value;
			p2 = p2->next;
			p->next = new LinkList;
			p = p->next;
			p->next = NULL;
		}
		else if (p1->value < p2->value) {
			p->value = p1->value;
			p1 = p1->next;
			p->next = new LinkList;
			p = p->next;
			p->next = NULL;
		}
	}
	if (p1->next != NULL) {
		while (p1->next)
		{
			p->value = p1->value;
			p1 = p1->next;
			p->next = new LinkList;
			p = p->next;
			p->next = NULL;
		}
	}
	else {
		while (p2->next)
		{
			p->value = p2->value;
			p2 = p2->next;
			p->next = new LinkList;
			p = p->next;
			p->next = NULL;
		}
	}
	return head;
}
int main() {

	linklist head1 = new LinkList;
	linklist head2 = new LinkList;
	initList1(head1);
	initList2(head2);
	cout << "合并前:" << endl;
	printList(head1);
	printList(head2);
	cout << "合并后:" << endl;
	printList(addList(head1, head2));
	
	return 0;
}