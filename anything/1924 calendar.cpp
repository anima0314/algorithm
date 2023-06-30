#include <iostream>
#include <string>
using namespace std;

string ddday[7]={"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int x,y;
	cin>>x>>y;
	int i=1,j=1;
	int day=1;
	while(1){
		if(x==i&&y==j){
			cout<<ddday[day]<<"\n";
			break;
		}

		day++;
		if(day%8==7){	//요일초기화
			day=0;
		}
		
		j++;
		if(j==29){	//2월
			if(i==2){
				j=1;
				i++;
			}
		}
		if(j==31){	//30일까지 있을때
			if(i==4||i==6||i==9||i==11){
				j=1;
				i++;
			}
		}
		if(j==32){	//31일까지 있을때
			j=1;
			i++;
		}
	}
	return 0;
}