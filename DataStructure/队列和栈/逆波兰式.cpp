#include<iostream>
#include<stack>
using namespace std;
// 9+(3-1)*3+10/2
int main() {
	string tar;	//接收表达式
	cin >> tar;
	stack<char> s;
	for (int i = 0; tar[i]; i++) {
		if (tar[i] >= '0' && tar[i] <= '9') {
			cout << tar[i];
		}
		else if (!s.empty()&&(tar[i] == '+' || tar[i] == '-') && (s.top() == '*' || s.top() == '/')) {
			while (!s.empty())
			{
				cout << s.top();
				s.pop();
			}
			s.push(tar[i]);
		}
		else {
			s.push(tar[i]);
				if (s.top() == ')') {
					s.pop();
						while (s.top() != '(')
						{
							cout << s.top();
								s.pop();
						}
					s.pop();
				};
		}
	}
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
	return 0;
}