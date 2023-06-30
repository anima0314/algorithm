#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
	long long S,sum=0;
	int i;
	cin>>S;
	for(i=1; sum<S; i++){
		sum += i;
		if(S<=sum){
			if(S==sum) break;
			i--;
			break;
		}
	}
	cout << i;
	
	return 0;
}
