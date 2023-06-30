#include <stdio.h>
#include <string.h>

int stack[10001]={0,};
int top_ = -1;
	
void push(int x){
	top_++;
	stack[top_] = x;
};
void pop(){
	if(top_==-1){
		printf("-1\n");
		return;
	}
	printf("%d\n",stack[top_--]);
};
void size(){
	printf("%d\n",top_+1);
};
void empty(){
	if(top_>=0)printf("0\n");
	else printf("1\n");
};
void top(){
	if(top_==-1){
		printf("-1\n");
		return;
	}
	printf("%d\n",stack[top_]);
};

int main() {
	int max,num=0;
	scanf("%d",&max);
	char method[20];
	for(int i=0;i<max;i++){
		scanf("%s",method);
		if(strcmp(method,"push")==0){
			scanf("%d",&num);
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
		else top();
	}
    return 0;
}