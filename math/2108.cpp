//통계학
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> vec;
int arr[8001]={0,};

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//입력
	int N,sum=0;
	cin>>N;
	int temp=0;
	for(int i=0; i<N; ++i){
		cin>>temp;
		vec.push_back(temp);
		sum+=temp;
		++arr[temp+4000];
	}
	sort(vec.begin(), vec.end());	
	int min=8000;
	int max=-8000;
	
	int same=0;
	bool k=false;
	int num;
	int freq=0;
	for(int i=0;i<8001;++i){
		if(arr[i]!=0){
			//범위
			if(min>i){
				min=i;
			}
			if(max<i){
				max=i;
			}
			//최빈값
			if(arr[i]>freq){
				same=1;
				freq=arr[i];
				num=i-4000;
			}
			else if(arr[i]==freq && same==1){
				num=i-4000;
				freq=arr[i];
				same++;
			}
		}
	}
	
	int mean = round( (double)sum/N );
	
	//출력
	cout<< mean <<"\n";	//산술평균
	cout<< vec[N/2] <<"\n";	//중앙값
	cout<< num <<"\n";	//최빈값
	cout<< max-min <<"\n";	//범위
    return 0;
}