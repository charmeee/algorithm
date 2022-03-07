#include <iostream>
#include <vector>

using namespace std;

int cnt;
int m,n,k;
bool dfs(int arr[][50],int x,int y){
    if(arr[x][y]==1&&0<=x&&x<m&&0<=y&y<n){
        arr[x][y]=0;
        dfs(arr,x-1,y);
        dfs(arr,x+1,y);
        dfs(arr,x,y-1);
        dfs(arr,x,y+1);
        return true;
    }
    return false;
}


int main(){
    int t;cin>>t;
    
    for(int j=0;j<t;j++){
        cin>>m>>n>>k;
        int arr[50][50]={};
        cnt=0;
        for(int i=0;i<k;i++){
            int a,b;
            cin>>a>>b;//x,y
            arr[a][b]=1;
        }
        for(int i=0;i<m;i++){
            for(int l=0;l<n;l++){
                if(dfs(arr,i,l)==true){
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;

    }
    
}