#include <stdio.h>
#include <string.h>

int queue[10001]={0,};
int front_ = 0;
int rear_ = 0;
	
void push(int x){
	queue[rear_++] = x;
};
void pop(){
	if(front_==rear_){
		printf("-1\n");
		return;
	}
	printf("%d\n",queue[front_++]);
};
void size(){
	printf("%d\n",rear_-front_);
};
void empty(){
	if(front_==rear_)printf("1\n");
	else printf("0\n");
};
void front(){
	if(front_==rear_){
		printf("-1\n");
		return;
	}
	printf("%d\n",queue[front_]);
};
void back(){
	if(front_==rear_){
		printf("-1\n");
		return;
	}
	printf("%d\n",queue[rear_-1]);
};

int main() {
	int max,num=0;
	scanf("%d",&max);
	char method[20];
	for(int i=0;i<max;i++){
		scanf(" %s",method);
		if(strcmp(method,"push")==0){
			scanf(" %d",&num);
			push(num);
		}
		else if(strcmp(method,"pop")==0){
			pop();
		}
		else if(strcmp(method,"size")==0){
			size();
		}
		else if(strcmp(method,"empty")==0){
			empty();
		}
		else if(strcmp(method,"front")==0){
			front();
		}
		else back();
	}
    return 0;
}