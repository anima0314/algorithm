#include <iostream>
#include <queue>
using namespace std;

class student{
	public:
	string name;
	int kor, eng, mat;
	
	student(){
		name="a";
		kor=1;
		eng=1;
		mat=1;
	}
	student(string my, int a,int b,int c){
		this->name = my;
		this->kor = a;
		this->eng = b;
		this->mat = c;
	}	
	bool operator < (const student a)const {
		if(this->kor != a.kor){
			return this->kor < a.kor;		
		}
		else{
			if( this->eng!=a.eng){
				return this->eng > a.eng;
			}
			else{
				if(this->mat!=a.mat){
					return this->mat < a.mat;
				}
				else{
					return this->name > a.name;
				}
			}
		}	
	}
};

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	cin>>N;
	priority_queue<student> pq;
	string name;
	int kor,eng,mat;
	for(int i=0;i<N;++i){
		cin>>name>>kor>>eng>>mat;
		pq.push( student(name,kor,eng,mat) );
	}
	student st;
	while(!pq.empty()){
		st = pq.top();
		pq.pop();
		cout<<st.name<<"\n";
	}
	return 0;
}