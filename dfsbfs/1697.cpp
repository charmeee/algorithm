#include <iostream>
#include <queue>
using namespace std;

int arr[200001]={};
int a,b;
int t=1;
int cnt=0;
queue<int> q;


void bfs(){
    bool check=true;
    while(check){
        int tmp=0;
        for(int i=0;i<t;i++){
            int x=q.front();
            q.pop();
            if(0<=x-1&&arr[x-1]==0){
                q.push(x-1);tmp++;
                arr[x-1]=1;
                if(x-1==b){check=false;break;}
            }
            if(x+1<=200000&&arr[x+1]==0){
                q.push(x+1);tmp++;
                arr[x+1]=1;
                if(x+1==b){check=false;break;}
            }
            if(2*x<=200000&&arr[2*x]==0){
                q.push(2*x);tmp++;
                arr[2*x]=1;
                if(2*x==b){check=false;break;}
            }
        }
        t=tmp;
        if(tmp!=0){
            cnt++;
        }
    }
}

int main(){
    cin>>a>>b;
    q.push(a);
    arr[a]=1;
    if(a!=b){
        bfs();
    }
    cout<<cnt;
}