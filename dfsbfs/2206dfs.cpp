#include <iostream>
#include <string>
using namespace std;

//이건 아마 맞은듯 하지만 시간초과이다.ㅎ;;거지같은거

int arr[1001][1001]={};
int n,m;//y,x
int minnum=10000000;
int before=2;

int tmp=0;
void dfs(int y,int x,int cnt){
    if(y==n-1&&x==m-1){
        if(cnt<minnum){
            minnum=cnt;
        }
    }else{
        if(0<=y&&y<n&&0<=x&&x<m){
            if(arr[y][x]==0){
                if(before==2){
                    arr[y][x]=2;
                    before=2;
                    dfs(y,x+1,cnt+1);
                    before=2;
                    dfs(y+1,x,cnt+1);
                    before=2;
                    dfs(y,x-1,cnt+1);
                    before=2;
                    dfs(y-1,x,cnt+1);
                    arr[y][x]=0;
                }else{//before==3인경우
                    arr[y][x]=3;
                    before=3;
                    dfs(y,x+1,cnt+1);
                    before=3;
                    dfs(y+1,x,cnt+1);
                    before=3;
                    dfs(y,x-1,cnt+1);
                    before=3;
                    dfs(y-1,x,cnt+1);
                    arr[y][x]=0;
                }  
            }else if(arr[y][x]==1&&before==2){
                arr[y][x]=3;
                before=3;
                dfs(y,x+1,cnt+1);
                before=3;
                dfs(y+1,x,cnt+1);
                before=3;
                dfs(y,x-1,cnt+1);
                before=3;
                dfs(y-1,x,cnt+1);
                arr[y][x]=1;
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            arr[i][j]=int(s[j])-int('0');
        }
    }
    dfs(0,0,1);
    if(minnum==10000000){
        cout<<-1;
    }else{cout<<minnum;}
}