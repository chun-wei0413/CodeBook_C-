#include<iostream>
#include<vector>
using namespace std;
const int MAX = 1005;
vector<int> G[MAX];
int dp[MAX][2];
int n;
void dfs(int u, int b){
    dp[u][0]=dp[u][1]=0;
    for(int i=0; i<G[u].size();i++){
        int v = G[u][i];
        if(v==b) continue;

        dfs(v,u);
        dp[u][0]+=dp[v][1];
        dp[u][1]+=min(dp[v][0],dp[v][1]);
    }
    dp[u][1]++;
    //cout<<dp[u][1]<<endl;
}

int main(){
    int k,p;
    while(scanf("%d",&n)!=EOF&&n){
        for(int i=0; i<=n;i++) G[i].clear();
        for(int i=1; i<=n;i++){
            scanf("%d",&k);
            while(k--){
                scanf("%d",&p);
                G[i].push_back(p);
            }
        }
        dfs(1,-1);
        if(n==1) printf("1\n");
        else printf("%d\n", min(dp[1][0],dp[1][1]));
    }
    return 0;
}
