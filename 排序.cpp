#include<iostream>
#include<fstream>
#include<vector>
#include<time.h>
using namespace std;
#define FILENAME "Sort.txt"
vector<int> v;			//������
long long int CmpCnt = 0;	//��¼�Ƚϴ���
long long int SwapCnt = 0;	//��¼��������
void getInformation();	//���ļ��ж�ȡ����
void setData();			//�Զ����ɲ�������
void FastSort(int left, int right);	//����
void ReNew();			//�������Ÿ����ļ�

int main() {
	setData();
	getInformation();
	FastSort(0, v.size() - 1);
	ReNew();
}
void getInformation() {
	//���ļ�
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ʧ��" << endl;
	}
	else {
		cout << "����Ҫ��ȡ���ڶ��ٵ���������" << endl;
		int tar;
		cin >> tar;
		int temp;
		while (ifs >> temp) {
			if (temp > tar)v.push_back(temp);
		}
		ifs.close();
	}
}
void setData() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	srand((unsigned)time(NULL));
	//����1000��1~10000������
	for (int i = 0; i < 1000000; i++) {
		ofs << rand() % 1000000 + 1;
		ofs << " ";
	}
	ofs.close();
}
void FastSort(int left = 0, int right = v.size() - 1) {
	if (left >= right)return;
	int low = left;
	int high = right;
	int val = v[left];
	while (high > low) {
		while (v[high] >= val && low < high) {
			CmpCnt++;
			high--;
		}
		v[low] = v[high];
		SwapCnt++;
		while (v[low] <= val && low < high) {
			CmpCnt++;
			low++;
		}
		v[high] = v[low];
		SwapCnt++;
	}
	v[low] = val;
	FastSort(left, low - 1);
	FastSort(high + 1,right);
}
void ReNew() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out | ios::app);
	if (!ofs.is_open()) {
		cout << "�ļ���ʧ��" << endl;
	}
	else {
		ofs << endl;
		ofs << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		ofs << "�Ƚϴ�����" << CmpCnt << endl;
		ofs << "����������" << SwapCnt << endl;
		ofs << "��������" << endl;
		for (int val : v)
			ofs << val << " ";
	}
	ofs.close();
	cout << "�ļ�������ɣ��Ѿ���Ϣ�������ļ���" << endl;
	cout << "�Ƚϴ�����" << CmpCnt << endl;
	cout << "����������" << SwapCnt << endl;
}