#include <iostream>
#include <queue>
using namespace std;

int m,n,h;
int t=0;
int arr[101][101][101]={};

struct point{
    int z,y,x;//mnh
};
queue<point> q;
int cnt=0;

void bfs(){
    int dx[]={-1,0,1,0,0,0};
    int dy[]={0,-1,0,1,0,0};
    int dz[]={0,0,0,0,-1,1};
    while(!q.empty()){
        int tmp=0;
        for(int i=0;i<t;i++){
            int a=q.front().x;
            int b=q.front().y;
            int c=q.front().z;
            q.pop();
            for(int j=0;j<6;j++){
                int nx=a+dx[j];
                int ny=b+dy[j];
                int nz=c+dz[j];
                if(nx<0||m<=nx||ny<0||n<=ny||nz<0||h<=nz){
                    continue;
                }
                if(arr[nz][ny][nx]==-1||arr[nz][ny][nx]==1){
                    continue;
                }
                q.push({nz,ny,nx});
                arr[nz][ny][nx]=1;
                tmp++;
            }
            
        }
        t=tmp;
        if(tmp!=0){
            cnt++;
        }
    }
}


int main(){
    cin>>m>>n>>h;
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                cin>>arr[i][j][k];
                if(arr[i][j][k]==1){
                    q.push({i,j,k});
                    t++;
                }
            }
        }
    }
    bfs();
    bool check =true;
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                if(arr[i][j][k]==0){
                    check=false;
                    break;
                }
            }
        }
    }
    if(check){
        cout<<cnt;
    }else{
        cout<<-1;
    }
}