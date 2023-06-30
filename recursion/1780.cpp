#include <iostream>
using namespace std;

int N;
int pic[2188][2188]={0,};
int s_1=0, s0=0, s1=0;

void paperdiv(int x,int y,int m){
	bool al_1=true, al0=true, al1=true;
	for(int i=y; i<y+m; ++i){
		for(int j=x; j<x+m; ++j){
			if(pic[i][j]==1){
				al0=false;
				al_1=false;
			}
			else if(pic[i][j]==0){
				al1=false;
				al_1=false;
			}
			else if(pic[i][j]==-1){
				al0=false;
				al1=false;
			}
		}
	}
	
	if(al0){
		++s0;
		return;
	}
	if(al1){
		++s1;
		return;
	}
	if(al_1){
		++s_1;
		return;
	}
	
	m/=3;
	
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			paperdiv(x+m*i, y+m*j, m);
		}
	}
}


int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			cin>>pic[i][j];
		}
	}
	paperdiv(0,0,N);
	
	cout<<s_1<<"\n"
		<<s0<<"\n"
		<<s1;
}