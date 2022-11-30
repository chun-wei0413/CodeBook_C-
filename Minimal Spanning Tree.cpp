#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int p[100000];
struct dot{
    int s,e,cost;
};

bool cmp(dot a,dot b){
        return a.cost<b.cost;
}

int find1(int a){
        if(p[a]==a) return a;
        else{
            p[a]=find1(p[a]);//find ancester
        }
        return p[a];
}
void kru(int n,int m){
        dot tree[m];
        for(int i=0; i<n;i++) p[i]=i;
        for(int i=0; i<m;i++){
            cin>>tree[i].s>>tree[i].e>>tree[i].cost;
        }
        int cnt=0,ans=0;
        sort(tree,tree+m,cmp);
        int x,y;
        for(int i=0; i<m; i++){
            x=find1(tree[i].e);
            y=find1(tree[i].s);
            if(x==y) continue;
            else{
                p[y]=x;
                ans+=tree[i].cost;
                cnt++;
            }
        }
       if(cnt==n-1)//node=edge-1
            cout<<ans<<endl;
       else cout<<-1<<endl;
}

int main(){
    int n,m;
    while(cin>>n>>m){
        kru(n,m);
    }
    return 0;
}

