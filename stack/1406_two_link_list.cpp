#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
	struct Node* prev = NULL;
	char data='\0';
	struct Node* next = NULL;
}Node;

Node* cursorL(Node* node);		//커서 왼쪽으로
Node* cursorD(Node* node);		//커서 오른쪽으로
Node* Insert(char value,Node* node);	//초기 데이터 삽입
void InsertLeft(char value, Node* node);//커서 왼쪽 문자 삽입
void DeleteLeft(Node* node);			//커서 왼쪽 문자 삭제
void printnode(Node* printnode);		//결과 출력

Node* cursorL(Node* node){	//커서 왼쪽으로
	if(node->prev->data=='\0') return node;
	return node->prev;
}
Node* cursorD(Node* node){	//커서 오른쪽으로
	if(node->data=='\0') return node;
	return node->next;
}
Node* Insert(char value,Node* node){	//초기 데이터 삽입
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = value;
	
	node->next = newNode;
	newNode->prev = node;
	return newNode;
}
void InsertLeft(char value, Node* node){	//커서 왼쪽 문자 삽입
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = value;
	
	node->prev->next=newNode;
	newNode->prev=node->prev;
	newNode->next=node;
	node->prev=newNode;
	
}
void DeleteLeft(Node* node){	//커서 왼쪽 문자 삭제
	if(node->prev->data=='\0') return;
	
	Node* temp=node->prev;
	temp->prev->next=node;
	node->prev=temp->prev;
	
	free(temp);
	return;
}
void printnode(Node* printnode){	//결과 출력
	while(printnode->next->data != '\0'){
		printnode = printnode->next;
		printf("%c",printnode->data);
	}
}

int main() {
	
	//초기데이터
	char arr[100001]={0,};
	Node* head = (Node*)malloc(sizeof(Node));
	Node* tail = (Node*)malloc(sizeof(Node));
	Node* cursor;
	
	scanf("%s", arr);
	getchar();
	int len = strlen(arr);
	cursor = Insert(arr[0],head);//헤드의 뒤에 데이터 삽입
	for(int i=1;i<len;i++){
		cursor = Insert(arr[i],cursor);
	}
	tail->prev = cursor;
	cursor->next=tail;
	cursor = cursorD(cursor);
	
	//명령어
	int n;
	char s,ch_;
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;i++){
		scanf("%c",&s);
		getchar();
		if(s=='L'){		//커서 왼쪽으로
			cursor = cursorL(cursor);
		}
		if(s=='D'){		//커서 오른쪽으로
			cursor = cursorD(cursor);
		}
		if(s=='B'){		//커서 왼쪽 문자 삭제
			DeleteLeft(cursor);
		}
		if(s=='P'){		//커서 왼쪽 문자 삽입
			scanf("%c",&ch_);
			getchar();
			InsertLeft(ch_,cursor);
		}
		//printnode(head);	//테스트하면서 중간과정확인	
		//printf("\n");
	}
	
	//출력
	printnode(head);
	
	return 0;
}