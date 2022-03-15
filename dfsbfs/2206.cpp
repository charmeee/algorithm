#include <iostream>
#include <queue>
#include <utility>
#include <string>
using namespace std;


int arr[1001][1001]={};
int visited[1001][1001][2]={};
int t=1;
int n,m;//y,x
int cnt=0;

struct point{
    int px,py,pblock;
};
queue<point> q;

void bfs(){
    int dx[]={-1,0,1,0};
    int dy[]={0,-1,0,1};
    while(!q.empty()){
        int tmp =0;
        for(int i=0;i<t;i++){
            int x=q.front().px;
            int y=q.front().py;
            int block=q.front().pblock;
            int before=visited[y][x][block];
            q.pop();
            //cout<<cnt<<"::  "<<y<<"/"<<x<<"  block:"<<block<<"  숫자:"<<visited[y][x][block]<<endl;
            if(block==0){
                for(int j=0;j<4;j++){
                    int nx=x+dx[j];
                    int ny=y+dy[j];
                    if(nx<0||m<=nx||ny<0||n<=ny){
                        continue;
                    }
                    if(arr[ny][nx]==0&&visited[ny][nx][0]==0){
                        visited[ny][nx][0]=before+1;//벽 부시기전 
                        q.push({nx,ny,0});
                        tmp++;
                    }
                    if(arr[ny][nx]==1&&visited[ny][nx][0]==0){
                        visited[ny][nx][1]=before+1;//벽 부시기 후 
                        q.push({nx,ny,1});
                        tmp++;
                    }
                }
            }else{//block==1인경우 즉 벽부시고 난후
                for(int j=0;j<4;j++){
                    int nx=x+dx[j];
                    int ny=y+dy[j];
                    if(nx<0||m<=nx||ny<0||n<=ny){
                        continue;
                    }
                    if(arr[ny][nx]==0&&visited[ny][nx][1]==0){
                        visited[ny][nx][1]=before+1;
                        q.push({nx,ny,1});
                        tmp++;
                    }
                }
            }
        }
        t=tmp;
        if(tmp!=0){
            cnt++;
        }
    }
}

int main(){
    cin>>n>>m;//y,x
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            arr[i][j]=int(s[j])-int('0');
        }
    }
    q.push({0,0,0});
    visited[0][0][0]=1;visited[0][0][1]=1;
    bfs();
    if(visited[n-1][m-1][0]==0&&visited[n-1][m-1][1]==0){
        cout<<-1;
    }else if(visited[n-1][m-1][0]==0||visited[n-1][m-1][1]==0){
        cout<<visited[n-1][m-1][0]+visited[n-1][m-1][1];
    }else{
        if(visited[n-1][m-1][0]>visited[n-1][m-1][1]){
            cout<<visited[n-1][m-1][1];
        }else{cout<<visited[n-1][m-1][0];}
        
    }
}