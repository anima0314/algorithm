#include <stdio.h>
using namespace std;

class coor{	//좌표저장 클래스
	public:
		int x;
		int y;
};
void merge(coor arr[], int p, int q, int r);
void mergesort(coor arr[], int p, int r);

coor tmp[100001];

void merge(coor arr[], int p, int q, int r){
	int i=p, j=q+1, t=0;
	
	while(i<=q && j<=r){
		if(arr[i].x<arr[j].x){	//x 작은 값 넣기
			tmp[t++]=arr[i++];
		}
		else if(arr[i].x>arr[j].x){
			tmp[t++]=arr[j++];
		}
		else{	//x가 같다면
			if(arr[i].y < arr[j].y){	//y 작은 값 넣기
				tmp[t++]=arr[i++];
			}
			else if(arr[i].y > arr[j].y){
				tmp[t++]=arr[j++];
			}
		}
	}
	//나머지 집어넣기
	while(i<=q){
		tmp[t++]=arr[i++];
	}
	while(j<=r){
		tmp[t++]=arr[j++];
	}
	//저장
	i=p;t=0;
	while(i<=r){
		arr[i++]=tmp[t++];
	}
}

void mergesort(coor arr[], int p, int r){
	if(p<r){
		int q=(p+r)/2;
		mergesort(arr,p,q);
		mergesort(arr,q+1,r);
		merge(arr,p,q,r);
	}
}

int main(void){
	int N;
	scanf("%d",&N);
	coor arr[N];
	for(int i=0;i<N;i++){
		scanf("%d %d",&arr[i].x, &arr[i].y);
	}
	
	mergesort(arr,0,N-1);
	
	for(int i=0;i<N;i++){
		printf("%d %d\n",arr[i].x,arr[i].y);
	}
	
	return 0;
}
