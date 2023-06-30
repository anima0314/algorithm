//이분 그래프
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> g[20002];//c++벡터는 신이야
int vi[20002];

int n, k;
//bfs구현
int bfs(int s, int color){
    queue<int> q;
    vi[s] = color;
    q.push(s);
    while(!q.empty()){
        int p = q.front();
        q.pop();

        for(int i = 0; i < g[p].size(); i++){
            if(!vi[g[p][i]]){
                vi[g[p][i]] = vi[p] * -1;
                q.push(g[p][i]);
            }else{
                if(vi[g[p][i]] == vi[p]){//탈출조건
                    return 0;
                }
            }
        }
    }

    return 1;
}

int solve(){
    cin >> n >> k;
    for(int i = 0; i <= n; i++){
        vi[i] = 0;
        g[i].clear();
    }


    for(int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for(int i = 0; i <= n; i++){
        if(g[i].size() > 0 && !vi[i]){
            if(!bfs(i, 1)){//bfs가 0이면 0리턴
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        if(solve()){
            cout << "YES\n";//결과가 1이면 
        }else{
            cout << "NO\n";//결과가 0이면
        }

    }
    return 0;
}