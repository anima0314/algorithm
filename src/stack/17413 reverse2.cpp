#include <stdio.h>
#include <cstring>

int stack[100001]={0,};
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
	char s[100001];
	bool swch=false;//태그인지 아닌지 판별변수 태그속이면 true
	
	scanf("%[^\n]%*c", s);
	int len = strlen(s);
	
	for(int i=0;i<len;i++){
		if(s[i]=='<'&& top_==-1){ //stack이 비어있고 태그시작하면
			swch = true;
			printf("%c",s[i]);
			continue;
		}
		else if(s[i]=='>'){	//태그가끝나므로
			swch = false;	//false로
			printf("%c",s[i]);
			continue;
		}
		if(swch==true){		//태그속 문자 출력
			printf("%c",s[i]);
			continue;
		}
		else if(swch==false){	//태그밖일때
			//공백문자거나 태그시작이거나 문자열의 끝이면 stack출력
			if(s[i] == ' ' || s[i]=='<'||i==len-1){
				if(i==len-1){	//문자열끝이면 끝문자 푸쉬하고 출력
					push(s[i]);
				}
				while(pop()!=0){//스택 출력
				}
				top_=-1;
				if(s[i] == ' '){	//공백이었으면 공백 출력
					printf(" ");
				}
				if(s[i] == '<'){	//태그시작이면 <출력하고 swch true로
					swch = true;
					printf("%c",s[i]);
				}
				continue;
			}
			//이외의경우 스택에 푸쉬
			push(s[i]);
		}
	}
	return 0;
}
