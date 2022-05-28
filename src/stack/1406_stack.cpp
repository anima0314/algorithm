#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;

int main() {
	char s[600001];
	scanf("%s",s);
	stack<char> left, right;	//양쪽에 스택을 두면서 진행
	int len = strlen(s);
	for (int i=0; i<len; i++) {
		left.push(s[i]);
	}
	int num;
	scanf("%d",&num);
	char ch,c;
	for(int i=0; i<num; i++) {
		scanf(" %c",&ch);
		if (ch == 'L') {
			if (!left.empty()) {
				right.push(left.top());
				left.pop();
			}
		}
		else if (ch == 'D') {
			if (!right.empty()) {
				left.push(right.top());
				right.pop();
			}
		}
		else if (ch == 'B') {
			if (!left.empty()) {
				left.pop();
			}
		} 
		else if (ch == 'P') {
			scanf(" %c",&c);
			left.push(c);
		}
	}
	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}
	while (!right.empty()) {
		printf("%c",right.top());
		right.pop();
	}
	printf("\n");
	return 0;
}