#include <iostream>
#include <queue>
#include <utility>
#include <string>
using namespace std;

queue<pair<int,int>> q;
int arr1[1001][1001]={};
int t=1;
int n,m;//y,x
int cnt=0;

void bfs(){
    int dx[]={-1,0,1,0};
    int dy[]={0,-1,0,1};
    while(!q.empty()){
        int tmp =0;
        for(int i=0;i<t;i++){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            //cout<<cnt<<"::  "<<y<<"/"<<x<<"  t:"<<t<<"  숫자:"<<arr1[y][x]<<endl;
            if(arr1[y][x]==2){
                bool check=true;
                for(int j=0;j<4;j++){
                    int nx=x+dx[j];
                    int ny=y+dy[j];
                    if(nx<0||m<=nx||ny<0||n<=ny){
                        continue;
                    }
                    if(arr1[ny][nx]==0){
                        arr1[ny][nx]=2;//벽 부시기전 ->2
                        q.push(make_pair(nx,ny));
                        tmp++;
                    }
                    if(arr1[ny][nx]==1){
                        arr1[ny][nx]=3;//벽 부시기 후 ->3
                        q.push(make_pair(nx,ny));
                        tmp++;
                    }
                }
            }else{//arr1[y][x]==3인경우 즉 벽부시고 난후
                for(int j=0;j<4;j++){
                    int nx=x+dx[j];
                    int ny=y+dy[j];
                    if(nx<0||m<=nx||ny<0||n<=ny){
                        continue;
                    }
                    if(arr1[ny][nx]==0){
                        arr1[ny][nx]=3;
                        q.push(make_pair(nx,ny));
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
            arr1[i][j]=int(s[j])-int('0');
        }
    }
    q.push(make_pair(0,0));
    arr1[0][0]=2;
    bfs1();
    if(arr1[n-1][m-1]!=0){
        cout<<cnt+1;
    }else{
        cout<<-1;
    }
    
    
}