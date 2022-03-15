#include <iostream>
#include <vector>
#include <queue>
// 내생각에는 이거 유니온 문제임;>응아니야 문제이해를 잘못함
//분리 되어있어도는 됨.ㅇㅇ. 근데연
using namespace std;

queue<int> q;
int n,l;//node line
bool bfs(vector< vector<int>> &v, vector<int> &visited,int num){
    q.push(num);
    visited[num]=1;
    while(!q.empty()){
        int x=q.front();//노드숫자
        int y=visited[x];//그노드의 방문햇는지 여부(-1)와 엇갈리는지 여부(1과 0로 구분됨).
        q.pop();
        for(int i=0;i<v[x].size();i++){//연결되어있는거
            int k=v[x][i];//연결되어있는점
            if(visited[k]==-1){//방문안했을시
                q.push(k);
                visited[k]=(y+1)%2;
            }else{//방문햇을시
                if(y==visited[k]){return false;}
            }
        }
    }
    return true;
}

int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>l;
        vector< vector<int>> v(n+1);
        vector<int> visited(n+1,-1);
        for(int j=0;j<l;j++){
            int a,b;
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        bool check=true;
        for(int i=1;i<n+1;i++){
            if(visited[i]==-1){
                if(!bfs(v,visited,i)){
                    cout<<"NO"<<endl;
                    check=false;
                    break;
                };
            }
        }
        if(check){
            cout<<"YES"<<endl;
        }
        while(!q.empty()){q.pop();}
    }
    
}