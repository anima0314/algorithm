//체스판 다시 필하기
#include <iostream>
using namespace std;

char chess[51][51];
int N,M;
int m=10000;

int wcheck(int oi, int oj){
	int temp=0;
	for(int i=0;i<8;++i){
		for(int j=0;j<8;++j){
			if((i+j)%2==0){
				if(chess[oi+i][oj+j]!='W'){
					temp++;
				}
			}
			else{
				if(chess[oi+i][oj+j]!='B'){
					temp++;
				}
			}
		}
	}
	return temp;
}

int bcheck(int oi, int oj){
	int temp=0;
	for(int i=0;i<8;++i){
		for(int j=0;j<8;++j){
			if((i+j)%2==0){
				if(chess[oi+i][oj+j]!='B'){
					++temp;
				}
			}
			else{
				if(chess[oi+i][oj+j]!='W'){
					++temp;
				}
			}
		}
	}
	return temp;
}

void input(){	
	cin>>N>>M;
	for(int i=0;i<N;++i){
		cin>>chess[i];	
	}
}

void solve(){
	int btemp=0;
	int wtemp=0;
	for(int i=0;i<=N-8;++i){
		for(int j=0;j<=M-8;++j){
			//칠해야하는 타일
			btemp = bcheck(i,j);
			wtemp = wcheck(i,j);
			
			//타일 최소값 찾기
			m = (m<btemp) ? m : btemp;
			m = (m<wtemp) ? m : wtemp;
		}
	}
	
	cout<<m<<"\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//입력
	input();
	//계산시작
	solve();
	//출력
	
    return 0;
}