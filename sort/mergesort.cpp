#include <stdio.h>
int tmp[100000]={0,};
void mergesort(int arr[], int p, int r);
void merge(int arr[], int p, int q, int r);

int main(void){
	int N;
	scanf("%d",&N);
	int arr[N] = {0,};
	for(int i=0;i<N;i++){
		scanf("%d", &arr[i]);		
	}
	
	mergesort(arr,0,N-1);
	for(int i=0;i<N;i++){
		printf("%d\n",arr[i]);	
	}
	
	return 0;
}
void mergesort(int arr[], int p, int r){
	if(p<r){
		int q=(p+r)/2;
		mergesort(arr,p,q);
		mergesort(arr,q+1,r);
		merge(arr,p,q,r);
	}
}

void merge(int arr[], int p, int q, int r){
	int i=p, j=q+1, t=1;
	if(p >= r) return;
	while(i<=q && j<=r){
		tmp[t++]= (arr[i]<=arr[j]) ? arr[i++] : arr[j++];
	}
	while(i<=q){
		tmp[t++]=arr[i++];
	}
	while(j<=r){
		tmp[t++] = arr[j++];
	}
	i=p;t=1;
	while(i<=r){
		arr[i++] = tmp[t++];
	}
}