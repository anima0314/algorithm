#include <stdio.h>
#include <string.h>

int main() {
    int i,n,cnt=0;
    scanf("%d", &n);
	char s[100000]={0,};
	for(i=666; ; i++){
		sprintf(s, "%d", i);
		if( strstr(s,"666")!=NULL ){
			cnt++;
		}
		else{
			continue;
		}
		if(cnt==n){
			printf("%d",i);
			return 0;
		}
	}
	return 0;
}