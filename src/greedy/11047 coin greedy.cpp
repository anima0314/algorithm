#include <stdio.h>
#include <string.h>

int main(void){
	int N,K,i=0;
	scanf("%d %d",&N, &K);
	int arr[N];
	for(i;i<N;i++){
		scanf("%d",&arr[i]);
	}
	int cnt=0,sum=0;
	for(i=N-1;i>=0;i--){
		while(arr[i]<=K){
			cnt = K / arr[i];
			K -= cnt * arr[i];
			sum+=cnt;
			if(K==0){
				break;
			}
		}
	}
	printf("%d",sum);
	
	return 0;
}
