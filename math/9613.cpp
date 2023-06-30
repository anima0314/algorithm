//GCD합
#include <iostream>
#include <vector>
using namespace std;

int GCD(int a, int b){
    if(b==0)return a;
    else return GCD(b,a%b);
}

vector<int> v;

int main() {
	int T,n,a,b;
	cin>>T;			//테스트 케이스 수 T
	while(T--){
		long long sum=0;	//합이 int 범위를 넘어설 수 있다고함.
		cin>>n;		//항의 수 n
		int i=0;
		while(i<n){
			cin>>a; //입력값받기
			v.push_back(a);
			for(int j=0;j<i;j++){
				b = v[j];
				//최대공약수 구하고 sum에 더하기
				sum += GCD(a,b);
			}
			i++;
		}	
		cout<<sum<<"\n";
		v.clear();
	}
	return 0;
}