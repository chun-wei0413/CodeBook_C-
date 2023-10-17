#include<iostream>
#include<cstring>
#include<deque>
#define N 100
using namespace std;

typedef pair<int ,int>p;
int visited[N][N]={0};
char g[N][N];
deque<p>path;
int dis=-2;
int n;

void dfs(int x, int y){
    visited[x][y]=1;
    path.push_back(make_pair(x,y));
    if(x==n-2&&y==n-2){//²×¤î±ø¥ó
        if(dis==-1){
            dis=path.size()-1;
        }
        else{
            if(path.size()-1<dis){
                 dis=path.size();
            }
        }
    }
    if(visited[x+1][y]==0&&g[x+1][y]=='.'&&x<n){
        dfs(x+1,y);
        visited[x+1][y]=0;
        path.pop_back();
    }
        if(visited[x-1][y]==0&&g[x-1][y]=='.'&&x-1>=0){
        dfs(x-1,y);
        visited[x-1][y]=0;
        path.pop_back();
    }
        if(visited[x][y+1]==0&&g[x][y+1]=='.'&&y<n){
        dfs(x,y+1);
        visited[x][y+1]=0;
        path.pop_back();
    }
        if(visited[x][y-1]==0&&g[x][y-1]=='.'&&y-1>=0){
        dfs(x,y-1);
        visited[x][y-1]=0;
        path.pop_back();
    }
}


int main(){
    //memset(g, 0, sizeof g);
    memset(visited, 0, sizeof visited);
    cin>>n;
    for(int i=0; i<n;i++){
        for(int j=0; j<n; j++){
            cin>>g[i][j];
        }
    }
    dfs(1,1);
    if(dis==-2)
        cout<<"No solution"<<endl;
    else{
        cout<<dis<<endl;
    }
    return 0;
}

