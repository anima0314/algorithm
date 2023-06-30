#include <stdio.h>
#include <cstring>
int stack[21]={0,};
int top_ = -1;

void push(char x){
	stack[++top_] = x;
};
int pop(){
	if(top_==-1){
		return 0;
	}
	printf("%c",stack[top_--]);
	return 1;
};

int main(void){
	int N,len;
	char s[1001]={0,};
	scanf("%d",&N);
	getchar();		//버퍼에 '\n'문자가 들어있어서 아래 scanf를 실행하면서 
	for(int i=0;i<N;i++) {	//개행문자가 들어가버려서 바로 끝나는 문제가 있었음.
		scanf("%[^\n]%*c", s);
		len = strlen(s);
		for(int k=0; k<len; k++){
			if(k==len-1){
				push(s[k]);
				while(pop()!=0){}
				top_=-1;
				continue;
			}
			if(s[k]==' '){
				while(pop()!=0){}
				printf(" ");
				top_=-1;
				continue;
			}
			push(s[k]);
		}
		printf("\n");
	}
	return 0;
}
