#include <stdio.h>
void hanoi(int n, int f, int m, int e);
int main()
{
    int n, s=1;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        s*=2;
	}
	s-=1;
    printf("%d\n",s);
    hanoi(n,1,2,3);
}

void hanoi(int n, int a, int b, int c)
{
    if(n==1) printf("%d %d\n", a, c);
    else{
    hanoi(n-1,a,c,b);
    printf("%d %d\n", a, c);
    hanoi(n-1,b,a,c);
    }
}