#include <stdio.h>
#include <string.h>
//버블 정렬
void sort(int a[],int n){
	int temp;
	for(int i=0;i<n-1;i++){
		for(int j=0; j<n-i-1; j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
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