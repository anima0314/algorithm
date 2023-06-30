#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main(void){
	map<string,float> m;
	string s;
	int count=0;
	
	//테스트
	// int cnt=10;
	// for(int i=0;i<cnt;i++){
	// 	getline(cin, s, '\n');
	// 	if (cin.eof()==true) break;
	// 	count++;
	// 	m[s]++;
	// }
	
	while(1){
		getline(cin, s, '\n');
		if (cin.eof()==true) break;
		++count;
		++m[s];
	}
	
	for(auto it=m.begin() ; it!=m.end(); ++it){
		cout<< it->first;
		printf(" %.4f\n", it->second/ count * 100);
	}
	
	return 0;
}