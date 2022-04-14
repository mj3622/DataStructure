#include<iostream>
using namespace std;
int KMP(string sub, string pat){
	//�ȼ����ģʽ����nxt[]����

	int sSize = sub.size();
	int pSize = pat.size();
	int* nxt = new int[pSize];		//��¼������Ϊ�����ַ�δ�ܳɹ�ƥ���ǣ����ص��ִ���λ��

	//Ѱ��nxt����
	/*
	* ��������
	bbababbababc
	ababc

	bacbababaabcbab
	ababaca
	*/
	for (int i = 0; i < pSize; i++) {
		if (i == 0 || i == 1) {
			nxt[i] = 0;			//ǰ����һ������0
		}
		else {
			int now = nxt[i - 1];
			if (now == 0) {
				nxt[i] = (pat[i - 1] == pat[0] ? 1 : 0);	//���ǰ����nxtΪ0����ֻ����0��1
			}
			else {
				//�粻�ǣ������nxt��ֵ���Ƿ�����ṩ������Ϣ
				while (pat[i - 1] != pat[now]) {
					now = nxt[now];
					if (now == 0)break;		//��ֹ��ѭ��
				}
				if (now == 0) {
					nxt[i] = (pat[i - 1] == pat[0] ? 1 : 0);
				}
				else {
					nxt[i] = now + 1;
				}
			}
		}
		/*cout << nxt[i] << " ";*/
	}
	//cout << endl;
	int pptr = 0;
	for (int sptr = 0; sptr < sSize; ) {
		while (sub[sptr] == pat[pptr])
		{
			sptr++;
			pptr++;
			if (pptr == pSize) {
				return sptr - pptr;		//˵���ɹ��ҵ�
			}
			if (sptr >= sSize)break;	//��ֹ��ѭ��
		}
		pptr = nxt[pptr];
		if (pptr == 0)sptr++;
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
	int pos = KMP(substring, patternstring);
	cout << pos << endl;
	//����ҵ���������ַ�
	if (pos != -1)cout << substring[pos];

}