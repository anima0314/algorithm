#include <stdio.h>
#include <string.h>

class Queue{
	private:
		int queue[5001]={};
		int front= 0;
		int rear= 0;
	public:
		Queue(int x){
			for(int i=0; i<x; i++){
				queue[i]=i+1;
			}
			this->rear = x;
		}
		void push(int x){
			queue[rear++ % 5001] = x;
		}
		int pop(){
			if(front % 5001 == rear % 5001){
				return -1;
			}
			return queue[front++ % 5001];
		}
};

int main() {
	int N,K,c;
	scanf("%d %d",&N ,&K);
	Queue que = Queue(N);
	
	printf("<");
	for(int i=0;i<N;i++){
		c=K-1;
		while(c > 0){
		que.push(que.pop());
		c--;
		}
		printf("%d",que.pop());
		if(i != N-1){
			printf(", ");
		}
	}
	printf(">");
	
    return 0;
}