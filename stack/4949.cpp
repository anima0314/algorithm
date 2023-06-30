//균형잡힌 세상
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	char str[103];
	while(1){
		scanf("%[^\n]%*c", str);
		if(str[0]==46){
			break;
		}
		vector<char> stk;
		bool flag = true;
		for(int i=0;i<=100;i++){
			if(str[i]==46){
				break;
			}
			if(str[i]=='('||str[i]=='['){ // '(' 거나 '['면
				stk.push_back(str[i]);
			}
			else if(str[i]==')'){	// ')'면
				if(stk.empty()){	//스택이 비어있으면 나가기
					flag =false;
					break;
				}
				if(stk.back()=='('){
					stk.pop_back();
				}
				else{
					flag =false;
					break;
				}
			}
			else if(str[i]==']'){	// ']'면
				if(stk.empty()){	//스택이 비어있으면 나가기
					flag =false;
					break;
				}
				if(stk.back()=='['){
					stk.pop_back();
				}
				else{
					flag =false;
					break;
				}
			}
		}
		if(flag && stk.empty()){
			cout<<"yes\n";
		}
		else{
			cout<<"no\n";
		}
	}
    return 0;
}