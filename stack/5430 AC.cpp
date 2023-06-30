#include <stdio.h>
#include <string.h>
using namespace std;

int dequeue[100001]={0,};
int front_ = 0;	//백으로만 푸쉬해서 0으로 초기화
int rear_ = 0;	//프런트도 푸쉬하면 배열길이에 절반으로 초기화

void clear(){//덱 초기화
	front_ = 0;
	rear_ = 0;
}
void push_back(int x){//rear에 삽입
	dequeue[rear_++] = x;
}
int pop_front(){//앞에서 출력
	if(front_==rear_){
		return 0;
	}
	return dequeue[front_++];
}
int pop_back(){//뒤에서 출력
	if(front_==rear_){
		return 0;
	}
	return dequeue[--rear_];
}
int empty(){//비었는지
	if(front_==rear_) return 1;
	else return 0;
}

int main() {
	int max,arcnt,len;
	int tmp,i,flag=0;
	bool error=false;
	char method[100001];
	char arr[600005];
	scanf("%d",&max);		//케이스 수
	int cnt;
	for(max; 0<max; max--){
		scanf("%s",method);	//명령어 입력
		scanf("%d",&arcnt);	//배열의 수 입력
		scanf("%s",arr);	//배열 입력
		
		cnt=arcnt;
		//덱 초기화
		clear();
		//뒤집기 초기화
		flag = 0;	//홀수면 뒤가 시작 짝수면 앞이시작
		//에러여부 초기화
		error=false;
		//arr파싱부분
		i = 1;
		tmp = 0;
		while(arr[i]!=']'){	//']'가 아닐때
			if(arr[i]>47&&arr[i]<58){	//숫자면
				tmp=tmp*10+arr[i]-48;
			}
			else{		//숫자가 아니면 == ,면
				push_back(tmp); //tmp푸쉬하고 초기화
				tmp=0;
			}
			i++;
		}
		push_back(tmp);
		
		//메소드 실행부분
		len=strlen(method);
		for(int i=0;i<len;i++){
			if(method[i]=='R'){
				flag++;
				//printf("R\n");
			}
			else if(method[i]=='D' && flag % 2 == 0){
				if(pop_front()==0){
					error = true;
					break;
				}
				cnt--;
				//printf("D\n");
			}
			else if(method[i]=='D' && flag % 2 == 1){
				if(pop_back()==0){
					error = true;
					break;
				}
				cnt--;
				//printf("D\n");
			}	
		}
		if(error==true){//에러가 나면 출력하고 다시시작
			printf("error\n");
			continue;
		}
		//printf("메소드실행완\n");
		
		//결과출력부분
		printf("[");
		if(flag%2==0){//앞에서부터 출력
			// for(cnt;cnt>0;cnt--){
			// 	printf("%d",pop_front());
			// 	if(cnt == 1){
			// 		break;
			// 	}
			// 	printf(",");
			// }
			
			while(empty() == 0){//덱이 빌때까지 출력
				printf("%d",pop_front());
				if(empty() == 1){
					break;
				}
				printf(",");
			}
		}
		else{	//뒤에서부터 출력
			// for(cnt;cnt>0;cnt--){
			// 	printf("%d",pop_back());
			// 	if(cnt == 1){
			// 		break;
			// 	}
			// 	printf(",");
			// }
			
			while(empty() == 0){
				printf("%d",pop_back());
				if(empty() == 1){
					break;
				}
				printf(",");
			}
		}
		printf("]\n");
	}
    return 0;
}