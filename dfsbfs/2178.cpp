#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <utility>

using namespace std;

queue<pair<int,int>> q;
int n,m;
int arr[100][100]={};


void bfs(){
    // if(0<=a&&a<n&&0<=b&&b<m&&arr[a][b]==1){
    //     q.push(make_pair(a,b));
    //     cout<<q.front()<<endl;
    //     q.pop;
    //     bfs(a-1,b);
    //     bfs(a+1,b);
    //     bfs(a,b+1);
    //     bfs(a,b-1);
    // }
    
    while(!q.empty()){
        int a=q.front().first;
        int b=q.front().second;
        q.pop();
        if(1<=a&&a<n+1&&0<=b&&b<m&&arr[a-1][b]==1){
            q.push(make_pair(a-1,b));
            arr[a-1][b]=arr[a][b]+1; 
            
        }
        if(-1<=a&&a<n-1&&0<=b&&b<m&&arr[a+1][b]==1){
            q.push(make_pair(a+1,b));
            arr[a+1][b]=arr[a][b]+1; 
            
        }
        if(0<=a&&a<n&&1<=b&&b<m+1&&arr[a][b-1]==1){
            q.push(make_pair(a,b-1));
            arr[a][b-1]=arr[a][b]+1; 
        }
        if(0<=a&&a<n&&-1<=b&&b<m-1&&arr[a][b+1]==1){
            q.push(make_pair(a,b+1));
            arr[a][b+1]=arr[a][b]+1; 
            
        }
    }
}

int main(){
    cin >>n>>m;
    for(int i=0;i<n;i++){
        string str;
        cin >>str;
        for(int j=0;j<m;j++){
            arr[i][j]=int(str[j])-int('0');
        }
    }
    q.push(make_pair(0,0));
    bfs();
    cout<<arr[n-1][m-1];
}