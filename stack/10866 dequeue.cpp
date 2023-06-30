#include <stdio.h>
#include <string.h>
using namespace std;

int dequeue[20001]={0,};
int front_ = 10000;
int rear_ = 10000;
	
void push_front(int x){
	dequeue[--front_] = x;
};
void push_back(int x){
	dequeue[rear_++] = x;
};
void pop_front(){
	if(front_==rear_){
		printf("-1\n");
		return;
	}
	printf("%d\n",dequeue[front_++]);
};
void pop_back(){
	if(front_==rear_){
		printf("-1\n");
		return;
	}
	printf("%d\n",dequeue[--rear_]);
};
void size(){
	printf("%d\n",rear_ - front_);
};
void empty(){
	if(front_==rear_)printf("1\n");
	else printf("0\n");
};
void front(){
	if(front_ == rear_){
		printf("-1\n");
		return;
	}
	printf("%d\n",dequeue[front_]);
};
void back(){
	if(front_==rear_){
		printf("-1\n");
		return;
	}
	printf("%d\n",dequeue[rear_-1]);
};

int main() {
	int max,num=0;
	scanf("%d",&max);
	char method[20];
	for(int i=0;i<max;i++){
		scanf("%s",method);
		if(strcmp(method,"push_front")==0){
			scanf("%d",&num);
			push_front(num);
		}
		else if(strcmp(method,"push_back")==0){
			scanf("%d",&num);
			push_back(num);
		}
		else if(strcmp(method,"pop_front")==0){
			pop_front();
		}
		else if(strcmp(method,"pop_back")==0){
			pop_back();
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
		else if(strcmp(method,"back")==0){
			back();
		}
	}
    return 0;
}