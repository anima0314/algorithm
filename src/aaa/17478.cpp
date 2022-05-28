#include <stdio.h>

int rec=0;
void printbar(int rec);
void recur(int N);

int main() {
    int N;
    scanf("%d",&N);
	printf("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n");
	
	recur(N);
	return 0;
}

void printbar(int rec){
	for(int i=0; i<rec; i++)
		printf("____");
}

void recur(int N){
	printbar(rec);
	printf("\"재귀함수가 뭔가요?\"\n");
	if(N<=0) {
		printbar(rec);
		printf("\"재귀함수는 자기 자신을 호출하는 함수라네\"\n");
	}
	else{
		printbar(rec);
		printf("\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n");
		printbar(rec);
		printf("마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n");
		printbar(rec);
		printf("그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n");
		rec++;
		recur(N-1);	//N--를 해서 무한루프에빠졌음.
	}
	printbar(rec);
	rec--;
	printf("라고 답변하였지.\n");
	return;
}