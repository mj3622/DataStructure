/*
作者：Minjer
联系方式：minjer@foxmail.com
一些声明：
1.目前status暂不支持自定义数据类型，且我自己只测试过整型，其他类型无法保证不出问题
2.虽然设有一定的保护措施，但还是有可能出现各种问题，若发现欢迎与我联系
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
//销毁单链表
void deleteList(linklist& head);
//判断链表是否为空
bool isEmpty(linklist& head);
//打印链表中所有的元素
void myPrint(linklist& head);
//初始化链表
void initList(linklist& head);
//清除链表
void clearList(linklist& head);
//获取链表的长度(循环链表不能用)
int getLength(linklist& head);
//在指定位置插入元素(返回值代表是否插入成功)
bool insertList(linklist& head, int pos);
//取出链表中的特定元素(按位置)	
status getPosList(linklist& head, int pos);
//取出链表中的特定元素(按值)	返回位置	未找到则返回0	只会返回第一次找到的值
int getValList(linklist& head, status value);

//初始化链表
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
//打印链表中所有的元素
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
		cout << "链表为空";
	}
	cout << endl;
}
//判断链表是否为空
bool isEmpty(linklist& head) {
	if (!head)return true;
	if (head->next) {
		return false;
	}
	else {
		return true;
	}
}
//销毁单链表
void deleteList(linklist& head) {
	linklist p = head;
	while (head->next) {
		head = head->next;
		delete p;
		p = head;
	}
	head = NULL;
}
//清除链表
void clearList(linklist& head) {
	if (!isEmpty(head)) {
		linklist p = head->next;
		linklist r = p->next;	//指向P的下一项
		head->next = NULL;		//对head置空
		while (r->next) {
			delete p;
			p = r;
			r = r->next;
		}
		delete p;
	}
}
//获取链表的长度(循环链表不能用)
int getLength(linklist& head) {
	int num = 0;	//记录长度
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
//在指定位置插入元素(返回值代表是否插入成功)
bool insertList(linklist& head, int pos) {
	status tar;
	cout << "请输入要插入的元素" << endl;
	cin >> tar;		 //记录要插入的元素
	if (pos > 0 && pos <= getLength(head) + 1) {
		linklist p = head->next;
		linklist l = head;		//指向p的前一个位置
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
//取出链表中的特定元素(按位置)
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
//取出链表中的特定元素(按值)
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
		return 0;	//代表没找到
	}
}
