//팰린드롬수
#include <iostream>
using namespace std;


void solve(){
	string str;
	int size;
	bool flag;
	while(true){
		cin>>str;
		size = str.size();
		flag = true;
		if( size == 1 && str[0] == '0'){
			break;
		}
		int i=0;
		while(i<size/2){
			if(str[i]==str[size-i-1]){
				i++;
			}
			else{
				flag=false;
				break;
			}
		}
		if(flag==true)cout<<"yes\n";
		else cout<<"no\n";
	}
}

int main() {
	//계산시작
	solve();	
    return 0;
}