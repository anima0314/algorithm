//마인크래프트
#include <iostream>
#include <limits.h>
using namespace std;

int arr[257] = {0,}; 
int N,M,B;

int top=0,bottom=256;

void input(){
	cin>>N>>M>>B; // 행 열 블럭수
	int total,temp;
	for(int i=0;i< N*M ;i++){
		cin>>temp;
		arr[temp]++;
		if(top<temp) top=temp;		//최대 높이
		if(bottom>temp) bottom=temp;	//최소 높이
	}
}

void solve(){
	int ktemp = top;		//현재 땅높이
	int Ttime = INT_MAX; 	//최소시간
	int Ttemp;				//최소시간의 땅높이
	int block = B;	//블럭수
	while(ktemp != bottom-1){
		block = B;
		int time=0;	//현재 높이에서 걸린시간
		for(int i=0; i<=256; ++i){
			if(i>ktemp){	//높은거
				time += arr[i] * (i-ktemp) * 2;
				block += arr[i] * (i-ktemp);
			}
			else if(i<ktemp){//낮은거
				time += arr[i] * (ktemp-i);
				block -= arr[i] * (ktemp-i);
			}
			else{	//같은거
				continue;
			}
		}
		
		if(block>=0){		//블럭이 음수면 안됨
			if(Ttime>time){	//
				Ttime=time;
				Ttemp=ktemp;
			}
		}
		ktemp--;//낮은 층
	}
	cout<<Ttime<<" "<<Ttemp; //출력 = 시간 땅높이
}

int main() {
	//입력
	input();
	//계산시작
	solve();
	//출력
	
    return 0;
}