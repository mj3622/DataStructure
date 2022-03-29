#include<iostream>
using namespace std;
struct HuffmanTree {
	int value;
	int parent;
	int left;
	int right;
};
typedef HuffmanTree* ht;
void CreatHuffmanTree(ht& t, int size);
void SelectTwoMin(ht& t, int size, int& min1, int& min2);
int main() {
	ht HT = NULL;
	// 7 19 2 6 32 3 21 10
	CreatHuffmanTree(HT, 8);
	for (int i = 1; i < 16; i++) {
		cout << HT[i].value << "\t" << HT[i].parent << "\t" << HT[i].left << "\t" << HT[i].right << endl;
	}
}
//创造一棵哈夫曼树
void CreatHuffmanTree(ht& t, int size) {
	int length = 2 * size - 1;
	t = new HuffmanTree[length + 1];
	//初始化
	for (int i = 0; i <= length; i++) {
		t[i].left = 0;
		t[i].right = 0;
		t[i].parent = 0;
		t[i].value = 0;
	}
	//赋权重
	for (int i = 1; i <= size; i++) {
		int iValue = 0;
		cin >> iValue;
		t[i].value = iValue;
	}
	//构造树
	for (int i = size + 1; i <= length; i++) {
		int min1;
		int min2;
		SelectTwoMin(t, i - 1, min1, min2);
		t[i].left = min1;
		t[i].right = min2;
		t[i].value = t[min1].value + t[min2].value;
		t[min1].parent = i;
		t[min2].parent = i;
	}
}
void SelectTwoMin(ht& t, int size, int& min1, int& min2) {
	int minValue1 = 111111;
	int minValue2 = 111111;
	for (int i = 1; i <= size; i++) {
		if (t[i].value < minValue1 && t[i].parent==0) {
			minValue2 = minValue1;
			minValue1 = t[i].value;
			min2 = min1;
			min1 = i;
		}
		else if (t[i].value < minValue2 && t[i].parent == 0) {
			minValue2 = t[i].value;
			min2 = i;
		}
	}
}