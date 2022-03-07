#include <iostream>
#include <queue>
#include <utility>

using namespace std;
int arr[1001][1001];
int n,m;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int cnt=0;
int t=0;

queue<pair<int,int>> q;

void bfs(){
    while(!q.empty()){
        int tmp=0;
        bool check =false;
        for(int j=0;j<t;j++){
            int a=q.front().first;//x
            int b=q.front().second;//y
            q.pop();
            for(int i=0;i<4;i++){
                int nx=a+dx[i];
                int ny=b+dy[i];
                if(nx<0||n<=nx||ny<0||m<=ny){
                    continue;
                }
                if(arr[ny][nx]==-1){
                    continue;
                }
                if(arr[ny][nx]==0){
                    q.push(make_pair(nx,ny));
                    arr[ny][nx]=1; 
                    check=true;
                    tmp++;
                }
            }
        }
        t=tmp;
        if(check){
            cnt++;
        }
    }
}
int main(){
    cin>>n>>m;//x y
    for(int i=0;i<m;i++){//y
        for(int j=0;j<n;j++){//x
            cin>>arr[i][j];
            if(arr[i][j]==1){
                q.push(make_pair(j,i));
                t++;
            }
        }
    }
    bfs();

    bool check=true;

    for(int i=0;i<m;i++){//y
        for(int j=0;j<n;j++){//x
            if(arr[i][j]==0){
                check=false;
            }
        }
    }
    if(check){
        cout<<cnt;
    }else{
        cout<<-1;
    }
}