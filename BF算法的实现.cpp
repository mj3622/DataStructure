#include<iostream>
using namespace std;
int BF(string sub, string pat) {
	int s = 0;		//主串的指针
	int p = 0;		//模式串的指针
	int sSize = sub.size();
	int pSize = pat.size();
	while (s<sSize&&sSize>=pSize)
	{
		if (sub[s] == pat[p]) {
			while (sub[s++] == pat[p++])
			{
				if (p == pSize)return s - p;	//若找到，返回首个字符在string中的位置（首个位置是0）
			}
			s = s - p;
			p = 0;
		}
		s++;
	}
	return -1;
}
int main() {
	string substring;		//主串
	string patternstring;	//模式串

	cout << "请输入主串:" << endl;
	cin >> substring;
	cout << "请输入模式串:" << endl;
	cin >> patternstring;
	int pos = BF(substring, patternstring);
	cout << pos << endl;
	if (pos != -1)cout << substring[pos];
}