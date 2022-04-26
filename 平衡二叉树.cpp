#include<iostream>
#include<vector>
using namespace std;
//�������Ķ���
struct BinaryTree
{
	int val;
	BinaryTree* left;
	BinaryTree* right;
	BinaryTree() : val(0), left(NULL), right(NULL) {}
};
typedef BinaryTree* bt;
//����һ��AVL��
bt CreatAVL();
//������������������ӽ��
void AddToBST(bt& root, int value);
//��ȡroot�����
int getDepth(bt& root);
//������������ת��Ϊƽ�������
void balanceBST(bt& root);
//������������������õ�һ������
void LDRTravel(bt& root);
//�ؽ�AVL��
bt ReBuild(int left, int right);
//���Ժ���
void testLDR(bt root);
void testDLR(bt root);
vector<int> BSTNodeValue;
int main() {
	bt t = CreatAVL();
	testLDR(t);
	cout << endl;
	testDLR(t);
	return 0;
}
bt CreatAVL() {
	bt root = NULL;
	cout << "��������ǰҪ¼��������ݣ�" << endl;
	int cnt;
	cin >> cnt;
	int temp;
	for (int i = 0; i < cnt; i++) {
		cin >> temp;
		AddToBST(root, temp);
	}
	balanceBST(root);
	return root;
}
void AddToBST(bt& root, int value) {
	bt p = root;
	bt pre = root;
	while (p)
	{
		pre = p;
		if (p->val < value)p = p->right;
		else if (p->val > value)p = p->left;
		else {
			cout << "��⵽�ظ����ݣ����ʧ��" << endl;
			return;
		}
	}
	if (!pre) {
		root = new BinaryTree;
		root->val = value;
	}
	else {
		if (pre->val > value) {
			pre->left = new BinaryTree;
			pre->left->val = value;
		}
		else {
			pre->right = new BinaryTree;
			pre->right->val = value;
		}
	}
}
int getDepth(bt& root) {
	if (!root) return 0;
	return 1 + max(getDepth(root->left), getDepth(root->right));
}
void balanceBST(bt& root) {
	BSTNodeValue.clear();
	LDRTravel(root);
	root = ReBuild(0, BSTNodeValue.size() - 1);
}
void LDRTravel(bt& root) {
	if (!root) return;
	LDRTravel(root->left);
	BSTNodeValue.push_back(root->val);
	LDRTravel(root->right);
}
bt ReBuild(int left, int right) {
	int mid = (left + right) >> 1;
	bt p = new BinaryTree;
	p->val = BSTNodeValue[mid];
	if (left <= mid - 1) p->left = ReBuild(left, mid - 1);
	if (right >= mid + 1) p->right = ReBuild(mid + 1,right);
	return p;
}

void testDLR(bt root) {
	if (!root) return;
	cout << root->val << " ";
	testDLR(root->left);
	testDLR(root->right);
}
void testLDR(bt root) {
	if (!root) return;
	testLDR(root->left);
	cout << root->val << " ";
	testLDR(root->right);
}