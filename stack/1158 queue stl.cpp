#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

int main() {
	int N,K,c;
	scanf("%d %d",&N ,&K);
	queue<int> que;
	
	for(int i=1;i<=N;i++){
		que.push(i);
	}
	
	printf("<");
	for(int i=0;i<N;i++){
		c=K-1;
		while(c > 0){
			que.push(que.front());
			que.pop();
			c--;
		}
		printf("%d",que.front());
		que.pop();
		if(i != N-1){
			printf(", ");
		}
	}
	printf(">");
	
    return 0;
}