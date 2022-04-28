#include<iostream>
#include<fstream>
#include<vector>
#include<time.h>
using namespace std;
#define FILENAME "Sort.txt"
vector<int> v;			//存数据
long long int CmpCnt = 0;	//记录比较次数
long long int SwapCnt = 0;	//记录交换次数
void getInformation();	//从文件中读取数据
void setData();			//自动生成测试数据
void FastSort(int left, int right);	//快排
void ReNew();			//结束快排更新文件

int main() {
	setData();
	getInformation();
	FastSort(0, v.size() - 1);
	ReNew();
}
void getInformation() {
	//打开文件
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) {
		cout << "文件打开失败" << endl;
	}
	else {
		cout << "你需要获取大于多少的排序结果？" << endl;
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
	//加入1000个1~10000的数据
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
		cout << "文件打开失败" << endl;
	}
	else {
		ofs << endl;
		ofs << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		ofs << "比较次数：" << CmpCnt << endl;
		ofs << "交换次数：" << SwapCnt << endl;
		ofs << "排序结果：" << endl;
		for (int val : v)
			ofs << val << " ";
	}
	ofs.close();
	cout << "文件排序完成，已经信息更新至文件中" << endl;
	cout << "比较次数：" << CmpCnt << endl;
	cout << "交换次数：" << SwapCnt << endl;
}