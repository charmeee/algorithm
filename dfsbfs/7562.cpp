#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int arr[301][301]={};

//테스트케

//한변
//현재있는칸
//이동하려는 칸
int dx[]={1,1,2,2,-1,-1,-2,-2};
int dy[]={2,-2,1,-1,2,-2,1,-1};
int n;
int sa,sb;//출발
int da,db;//도착

queue<pair<int,int>> q;

void bfs(int visited[][301]){
    while (!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        int before=visited[y][x];
        for(int i=0;i<8;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||n<=nx||ny<0||n<=ny){continue;}
            if(visited[ny][nx]!=0){continue;}
            q.push(make_pair(nx,ny));
            visited[ny][nx]=before+1;
            if(nx==da&&ny==db){return ;}
        }
    }
}

int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int visited[301][301]={};
        cin>>n;
        cin>>sa>>sb;
        cin>>da>>db;
        if(sa==da&&sb==db){
            cout<<0<<endl;
        }else{
            q.push(make_pair(sa,sb));
            visited[sb][sa]=1;
            bfs(visited);
            cout<<visited[db][da]-1<<endl;
        }
        while (!q.empty()){q.pop();}
        
    }
}