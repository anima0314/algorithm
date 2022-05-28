#include<iostream>
#include<stack>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    stack <int> stk;
    int arr[100001]={0};
    char s[200001]={0};

    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
	int k=0,z=0,i;
    for(i=1;i<=n;i++)
    {
        stk.push(i);
        s[k]='+';
        k++;

        if(stk.top()>arr[z])
        {
            cout << "NO";
            return 0;
        }

        while(!stk.empty()&&stk.top()==arr[z])
        {
            s[k]='-';
            k++;

            stk.pop();
            z++;
        }
    }

    if(i==n+1&&stk.empty())
    {
        for(int j=0;j<k;j++)
        {
            printf("%c\n",s[j]);
        }
        return 0;
    }
    else
    {
        printf("NO");	//NO출력
        return 0;
    }
}