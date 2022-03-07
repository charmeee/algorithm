#include <iostream>

using namespace std;

int compu[101][101]={};
int visited[101]={};
int n;
int v=-1;
void dfs(int s){
    visited[s]=1;
    v++;
    for(int i=1;i<=n;i++){
        if(compu[s][i]==1&&visited[i]==0){
            dfs(i);
            
        }
    }
}

int main(){
    int t;//컴퓨터의 개수, 쌍
    cin>>n>>t;
    for(int i=0;i<t;i++){
        int a,b;
        cin>>a>>b;
        compu[a][b]=1;
        compu[b][a]=1;
    }
    dfs(1);
    cout<<v;
}