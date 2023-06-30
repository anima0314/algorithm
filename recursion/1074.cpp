#include <iostream>
#include <cmath>
using namespace std;

int find(int N,int r,int c){
	if (N==0)
        return 0;
	//초항은 계산해줄 필요없음
	int half = pow(2,N-1);
	if( r<half && c<half ){
		return find(N-1,r,c);
	}
	else if( r<half && c>=half ){
		return half*half+find(N-1,r,c-half);
	}
	else if( r>=half && c<half ){
		return 2*half*half+find(N-1,r-half,c);
	}
	else{
		return 3*half*half+find(N-1,r-half,c-half);
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N,r,c;
	cin>>N>>r>>c;
	
	cout<<find(N,r,c)<<"\n";
	return 0;
}