//트리순회
#include <iostream>
using namespace std;

typedef struct Node {
	char data;
	int left;
	int right;
}Node;

Node tree[30];
//전위순회
void preorder(int temp) {
	if(temp==-18)	return;	
	cout<<tree[temp].data;
	preorder(tree[temp].left);
	preorder(tree[temp].right);
}
//중위순회
void inorder(int temp) {
	if(temp==-18)	return;
	inorder(tree[temp].left);
	cout<<tree[temp].data;
	inorder(tree[temp].right);
}
//후위순회
void postorder(int temp) {
	if(temp==-18)	return;
	postorder(tree[temp].left);
	postorder(tree[temp].right);
	cout<<tree[temp].data;
}

void input(){
	int N;
	cin>>N;
	char temp,left,right;
	for(int i=0;i<N;i++){
		cin>>temp>>left>>right;
		tree[temp-64].data = temp;
		tree[temp-64].left = left-64;
		tree[temp-64].right = right-64;
	}
}

int main() {
	//입력
	input();
	//계산시작
	preorder(1);
	cout<<"\n";
	inorder(1);
	cout<<"\n";
	postorder(1);
	
    return 0;
}