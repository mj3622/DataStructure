#include<iostream>
using namespace std;
int KMP(string sub, string pat){
	//先计算出模式串的nxt[]数组

	int sSize = sub.size();
	int pSize = pat.size();
	int* nxt = new int[pSize];		//记录的数据为当该字符未能成功匹配是，返回到字串的位置

	//寻找nxt数组
	/*
	* 测试用例
	bbababbababc
	ababc

	bacbababaabcbab
	ababaca
	*/
	for (int i = 0; i < pSize; i++) {
		if (i == 0 || i == 1) {
			nxt[i] = 0;			//前两个一定都是0
		}
		else {
			int now = nxt[i - 1];
			if (now == 0) {
				nxt[i] = (pat[i - 1] == pat[0] ? 1 : 0);	//如过前面是nxt为0，则只会是0和1
			}
			else {
				//如不是，则根据nxt的值看是否可以提供有用信息
				while (pat[i - 1] != pat[now]) {
					now = nxt[now];
					if (now == 0)break;		//防止死循环
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
				return sptr - pptr;		//说明成功找到
			}
			if (sptr >= sSize)break;	//防止死循环
		}
		pptr = nxt[pptr];
		if (pptr == 0)sptr++;
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
	int pos = KMP(substring, patternstring);
	cout << pos << endl;
	//如果找到则输出首字符
	if (pos != -1)cout << substring[pos];

}