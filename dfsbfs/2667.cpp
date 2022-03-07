#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int compu[25][25]={};
int t;
int cnt=0;
int tmp=0;
vector <int> v;

bool dfs(int a,int b){
    if(compu[a][b]==1&&0<=a&&a<t&&0<=b&b<t){
        compu[a][b]=0;
        tmp++;
        dfs(a-1,b);//위
        dfs(a+1,b);//아래
        dfs(a,b+1);//우
        dfs(a,b-1);//좌
        
        return true;
    }
    return false;
    
}

int main(){
    cin>>t;
    for(int i=0;i<t;i++){
        string s;
        cin>>s;
        for(int j=0;j<t;j++){
            compu[i][j]=int(s[j])-int('0');
        }
    }
    for(int i=0;i<t;i++){
        for(int j=0; j<t; j++){
            if(dfs(i,j)==true){
                cnt++;
                v.push_back(tmp);
                tmp=0;
            } 
        }
    }
    sort(v.begin(),v.end());
    cout<<cnt<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
}