#include <stdio.h>
#include <string>
#include <cstring>

int top_ = -1;

void push(){
	top_++;
};
int pop(){
	if(top_<0){
		return 0;
	}
	top_--;
	return 1;
};

void stack(char* s, int len){
	for(int k=0;k<len;k++){
		if(s[k]=='('){
			push();
		}
		if(s[k]==')'){
			if(pop()==0){
				printf("NO\n");
				top_ = -1;
				return;
			}
		}
	}
	if(pop()==0){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	top_=-1;
	return;
}

int main() {
	int N,len;
	scanf("%d",&N);
	char s[51]={0,};
	for(int i=0 ;i<N;i++){
		scanf("%s",s);
		len=strlen(s);
		stack(s,len);
	}
    return 0;
}