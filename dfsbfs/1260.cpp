#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m;//정점,간선,시작번호
int visited1[1001]={};
int visited2[1001]={};
int arr[1001][1001]={};
queue<int> q;

void dfs_search(int s){
    cout<<s<<' ';
    visited1[s]=1;
    for(int i=1;i<=n;i++){
        if(arr[s][i]==1&&visited1[i]==0){
            dfs_search(i);
        }
    }
}

void bfs_search(int s){
    q.push(s);
    while(!q.empty()){
        int p=q.front();
        q.pop();
        if(visited2[p]==0){
            cout<<p<<' ';
        }
        visited2[p]=1;
        for(int i=1;i<=n;i++){
            if(arr[p][i]==1&&visited2[i]==0){
                q.push(i);
            }
        }
    }
    

}

int main(){
    int s;
    cin>>n>>m>>s;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        arr[a][b]=1;
        arr[b][a]=1;
    }
    dfs_search(s);
    cout<<endl;
    bfs_search(s);
}