//ROT13
#include <iostream>
#include <string>
using namespace std;

int main(){
	string n;
	getline(cin, n);
	char str[101]={0,};
	int len = n.size();
	
	for(int i=0;i<len;i++){
		if('A'<=n[i]&&n[i]<='M'){
			str[i] = n[i]+13;
		}
		else if('N'<=n[i]&&n[i]<='Z'){
			str[i] = n[i]-13;
		}
		else if('a'<=n[i]&&n[i]<='m'){
			str[i] = n[i]+13;
		}
		else if('n'<=n[i]&&n[i]<='z'){
			str[i] = n[i]-13;
		}
		else{
			str[i] = n[i];
		}
	}
	cout << str << "\n";
	return 0;
}