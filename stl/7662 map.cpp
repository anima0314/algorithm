#include <iostream>
#include <map>
using namespace std;
map<long long,int> m;
map<long long,int>::iterator iter;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int N=0,T=0;
	cin>>N;
	long long num;
	char ch;
	
	while(N>0){
		cin>>T;
		for(int i=0;i<T;++i){
			cin>>ch>>num;
			if(ch=='I'){
				//이미 map에 들어있으면 값을 증가
				if(m.find(num)!=m.end()){
					m[num]++;
				}
				//없으면 map에 입력
				else{
					m.insert({num,1});
				}
			}
			if(ch=='D' && !m.empty()){	//삭제
				if(m.empty()){
					continue;
				}
				else if(num==1){	//가장 큰값 삭제
					iter=m.end();
					iter--;
					if(iter->second>1){
						iter->second--;
					}
					else{
						m.erase(iter->first);
					}
				}
				else{	//가장 작은값 삭제
					iter=m.begin();
					if(iter->second>1){
						iter->second--;
					}
					else{
						m.erase(iter->first);
					}
				}
			}
		}
		//map이 비어있음
		if(m.empty()){
			cout<<"EMPTY"<<"\n";
		}
		else {
			//큰값 출력
			iter=m.end();
			iter--;
			cout<<iter->first<<" ";
			//작은값 출력
			cout<<m.begin()->first<<"\n";	
		}
		
		//map 초기화
		m.clear();
		//반복
		--N;
	}
	
	return 0;
}