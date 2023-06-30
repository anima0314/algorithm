//알파벳 개수
#include <iostream>
#include <cstring>
using namespace std;

int main(){
	string S;
	int len;
	while( getline(cin,S) ){
		int arr[4]={0,0,0,0}; //소문자, 대문자, 숫자, 공백
		len = S.size();
		for(int i=0;i<len;++i){
			if(S[i]>='a' && S[i]<='z')
				arr[0]++;
			else if(S[i]>='A' && S[i]<='Z')
				arr[1]++;
			else if(S[i]>='0' && S[i]<='9')
				arr[2]++;
			else{
				arr[3]++;
			}
		}
		
		cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<arr[3]<<"\n";
	}
	return 0;
}