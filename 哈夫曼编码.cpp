#include<iostream>
#include<fstream>
using namespace std;
#define FILENAME "article.txt"
#define LETTERNUM 26
struct HuffmanTree {
	int weight;
	char value;
	int parent;
	int left;
	int right;
	string code;
};
typedef HuffmanTree* ht;
void calLetterCnt(int* LetterCnt, string text);			//ͳ��ÿ����ĸ���ֵ�˳��
void creatHuffmanTree(ht& t, int size, int* LetterCnt);	//�����������
void SelectTwoMin(ht& t, int size, int& min1, int& min2);//ѡ��������С��ֵ
void creatHuffmanCode(ht& t, int size);					//���������������
string TranslateHuffmanCode(ht& t, int size, string text);//����
string TranslateText(ht& t, string text);		//ת���ɹ�������
char CodeCompare(ht& t, int size, string tar);			//ƥ���������
int main() {
	string text;
	int LetterCnt[26] = { 0 };
	//���ļ��ж����ַ���
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ʧ��" << endl;
	}
	else {
		//���ܶ�����
		while (ifs >> text);
		ifs.close();
	}
	calLetterCnt(LetterCnt, text);	//ͳ��

	ht tree = NULL;
	creatHuffmanTree(tree, LETTERNUM, LetterCnt);
	creatHuffmanCode(tree, LETTERNUM);
	////�������
	//for (int i = 1; i < 2 * LETTERNUM; i++) {
	//	cout << tree[i].value << "\t" << tree[i].code << "\t\t\t" << tree[i].weight << "\t" << tree[i].parent << "\t" << tree[i].left << "\t" << tree[i].right << endl;
	//}
	string ans = TranslateText(tree, text);
	string temp = TranslateHuffmanCode(tree, LETTERNUM,ans);
	cout << temp;
}
void calLetterCnt(int* LetterCnt, string text) {
	for (char ch : text) {
		LetterCnt[(int)ch - 'a']++;
	}
}
void creatHuffmanTree(ht& t, int size, int* LetterCnt) {
	//��ʼ����ʹ�����Խṹ��¼��������
	int length = 2 * size - 1;		//�������Ĵ�С
	t = new HuffmanTree[length + 1];
	for (int i = 1; i <= length; i++) {
		t[i].left = 0;
		t[i].right = 0;
		t[i].parent = 0;
		t[i].weight = 0;
		t[i].value = 0;
	}
	//��ֵ
	for (int i = 1; i <= size; i++) {
		t[i].value = (char)('a' + i - 1);
		t[i].weight = LetterCnt[i - 1];
	}
	//������
	for (int i = size + 1; i <= length; i++) {
		int min1, min2;
		SelectTwoMin(t, i - 1, min1, min2);
		t[i].left = min1;
		t[i].right = min2;
		t[i].weight = t[min1].weight + t[min2].weight;
		t[min1].parent = i;
		t[min2].parent = i;
	}
}
void SelectTwoMin(ht& t, int size, int& min1, int& min2) {
	const int MIN = 32768;
	int minValue1 = MIN;
	int minValue2 = MIN;
	for (int i = 1; i <= size; i++) {
		if (t[i].weight < minValue1 && t[i].parent == 0) {
			minValue2 = minValue1;
			minValue1 = t[i].weight;
			min2 = min1;
			min1 = i;
		}
		else if (t[i].weight < minValue2 && t[i].parent == 0) {
			minValue2 = t[i].weight;
			min2 = i;
		}
	}
}
void creatHuffmanCode(ht& t,int size) {
	for (int i = 1; i <= size; i++) {
		int front = i;
		int findParent = t[i].parent;
		while (findParent != 0)
		{
			t[findParent].left == front ? t[i].code.insert(t[i].code.begin(), '0') : t[i].code.insert(t[i].code.begin(), '1');
			front = findParent;
			findParent = t[findParent].parent;
		}
	}
}
string TranslateHuffmanCode(ht& t, int size, string text) {
	string ans = "";
	for (int i = 0; i < text.length(); i++) {
		string temp = "";
		temp += text[i];
		while (CodeCompare(t, size, temp) == '!')
		{
			i++;
			temp += text[i];
		}
		ans += CodeCompare(t, size, temp);
	}
	return ans;
}
char CodeCompare(ht& t, int size, string tar) {
	for (int i = 1; i <= size; i++) {
		if (tar == t[i].code)	return t[i].value;
	}
	return '!';	//��ʾû���ҵ�
}
string TranslateText(ht& t, string text) {
	string ans = "";
	for (char ch : text) {
		ans += t[ch - 'a' + 1].code;
	}
	return ans;
}
