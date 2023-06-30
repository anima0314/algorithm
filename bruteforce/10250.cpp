//ACM호텔
#include <iostream>
using namespace std;

void solve(){
	int T,H,W,N; //테스트수, 층수, 방수, 몇번째 손님
	cin>>T;
	int w; //몇번째 방까지 진행했는지
	while(T-->0){
		w=1;
		cin>>H>>W>>N;
		while(N>H){
			N = N-H;
			w++;
		}
		if(w<10)
			cout<<N<<"0"<<w<<"\n";
		else
			cout<<N<<w<<"\n";
		
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//계산시작
	solve();
	//출력
	
    return 0;
}