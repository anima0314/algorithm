#include <stdio.h>
#include <string.h>
//선택 정렬

void sort(int a[],int n){
	int max,temp;
	int k;
	for(int i=n-1;i>=0;i--){
		max=-1001;
		for(int j=i;j>=0;j--){
			if(max<a[j]){
				max=a[j];
				k=j;
			}
		}
		temp=a[i];
		a[i]=a[k];
		a[k]=temp;
	}
	return;
}
int main() {
	int arr[1001]={0,};
    int n,num=0;
    scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &num);
		arr[i]=num;
	}
	
	sort(arr,n);
	
	for(int i=0;i<n;i++){
		printf("%d\n",arr[i]);
	}
	return 0;
}