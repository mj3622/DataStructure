#include<iostream>
using namespace std;
int BF(string sub, string pat) {
	int s = 0;		//������ָ��
	int p = 0;		//ģʽ����ָ��
	int sSize = sub.size();
	int pSize = pat.size();
	while (s<sSize&&sSize>=pSize)
	{
		if (sub[s] == pat[p]) {
			while (sub[s++] == pat[p++])
			{
				if (p == pSize)return s - p;	//���ҵ��������׸��ַ���string�е�λ�ã��׸�λ����0��
			}
			s = s - p;
			p = 0;
		}
		s++;
	}
	return -1;
}
int main() {
	string substring;		//����
	string patternstring;	//ģʽ��

	cout << "����������:" << endl;
	cin >> substring;
	cout << "������ģʽ��:" << endl;
	cin >> patternstring;
	int pos = BF(substring, patternstring);
	cout << pos << endl;
	if (pos != -1)cout << substring[pos];
}