#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> v;
vector<pair<string,float>> w;

int main(void){
	int vlen, wlen;
	string s;
	
	//테스트
	// int cnt=10;
	// for(int i=0;i<cnt;i++){
	// 	getline(cin, s, '\n');
	// 	if (cin.eof()==true) break;
	// 	v.push_back(s);
	// }
	
	while(1){
		getline(cin, s, '\n');
		if (cin.eof()==true) break;
		v.push_back(s);
	}
	
	vlen = v.size();
	sort(v.begin(),v.begin() + vlen);
	
	w.push_back({v[0],1});
	for(int i=1; i<vlen; i++){
		if(v[i]==v[i-1]){
			w.back().second++;
		}
		else w.push_back({v[i],1}); 
	}
	
	wlen = w.size();
	for(int i=0; i<wlen; i++){
		cout<<w[i].first;
		printf(" %.4f\n", w[i].second / vlen * 100);
	}
	
	return 0;
}
