#include <stdio.h>
#include <string.h>

int main() {
    int V, E, sum=0;
    
	//정점 간선 선언
	scanf("%d %d",&V,&E);
	int graph[V][V]= {0,};
	
	//간선의 가중치 입력
	int a,b,c;
	for(int i=0;i<E;i++){
		scanf("%d %d %d",&a,&b,&c);
		graph[a-1][b-1]= c;
		graph[b-1][a-1]= c;
	}
	for(int i=0;i<V;i++){
		graph[i][i]= 1000001;
	}
	//프림 알고리즘
	int i,k,temp;
	int Vertax[V]={0,};
	for(i=0;i<V;i++){
		if(Vertax[i]>0){
				continue;	//이미 사용한 정점인지 확인
				printf("이미사용한 정점입니다.\n");
			}
		int min=1000001;
		for(k=0;k<V;k++){
			temp = graph[i][k];
			if(Vertax[k]>0){
				continue;	//이미 사용한 정점인지 확인
				printf("이미사용한 정점입니다.\n");
			}
			min = (min > temp) ? temp:min;
			Vertax[k]
			if(k==V-1) {
				sum += min;
				printf("%d\n",temp);
			}
		}
	}
	
	printf("%d\n",sum);
    return 0;
}

