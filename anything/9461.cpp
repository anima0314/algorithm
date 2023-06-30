#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N,M,tmp;
	cin>>N;
	long long P[101]= {1,1,1,2,2,3,4,5,7,9,12,0,0,};
	tmp=10;
	while(N>0){
		cin>>M;
		for(int i=tmp;i<M;++i){
			P[i]=P[i-1]+P[i-5];
		}
		tmp = (tmp<M)? M:tmp;
		cout<<P[M-1]<<"\n";
		--N;
	}
	return 0;
}