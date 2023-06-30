//집합
#include <iostream>
using namespace std;

class Set{
public:
	int S=0;
	void add(int x){
		S = S|(1<<x);
	}
	void remove(int x){
		S = S&(~(1<<x));
	}
	void check(int x){
		if(S&(1<<x))
			cout<<1<<"\n";
		else
			cout<<0<<"\n";
	}
	void toggle(int x){
		if(S&(1<<x))
			S = S&(~(1<<x));
		else
			S = S|(1<<x);
	}
	void all(){
		S=2097150;
	}
	void empty(){
		S=0;
	}
	
};

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N;
	//입력
	cin>>N;
	Set set = Set();
	//계산시작
	char str[10];
	int x;
	for(int i=0;i<N;++i){
		cin>>str;
		if(str[1]=='d'){
			cin>>x;
			set.add(x);
		}
		else if(str[1]=='e'){
			cin>>x;
			set.remove(x);
		}
		else if(str[1]=='h'){
			cin>>x;
			set.check(x);
		}
		else if(str[1]=='o'){
			cin>>x;
			set.toggle(x);
		}
		else if(str[1]=='l'){
			set.all();
		}
		else if(str[1]=='m'){
			set.empty();
		}
	}
	//출력
	
    return 0;
}