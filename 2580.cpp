
#include <iostream>
//#include <algorithm>
//https://blockdmask.tistory.com/178
//#include <cmath>//round 반올림림
//#include <string>
#include <vector>
//#include <map>//https://life-with-coding.tistory.com/305

using namespace std;

struct Data{
  int x;int y;
};

int arr[9][9]={};
vector<Data> v;

int count(int chk[]){
    int tmp=0;
    int cnt=0;
    for(int i=0;i<9;i++){
        if(chk[i]==0){cnt++;tmp=i+1;}
    }
    if(cnt==1){return tmp;}else{return 0;}
}

int check(int x,int y){
    int a,b,cx,cy;
    int tmp=0;
    int chk[9]={0,};
    for(int i=0;i<9;i++){//가로세로 검사.
        if(arr[x][i]!=0){//가로
            a=arr[x][i]-1;
            chk[a]=1;
        }
        if(arr[i][y]!=0){//세로
            b=arr[i][y]-1;
            chk[b]=1;
            
        }
    }
    tmp=count(chk);
    if(tmp!=0){return tmp;}
    cx=x/3;cy=y/3;
    for(int i=0;i<3;i++){for(int j=0;j<3;j++){
        int k=arr[3*cx+i][3*cy+j]-1;
        if(k>-1){
            chk[k]=1;
        }  
    }}
    tmp=count(chk);
    if(tmp!=0){return tmp;}else{return 0;}
    
}


int main(){
  int result;
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      scanf("%d",&arr[i][j]);
      if(arr[i][j]==0){
        v.push_back( {i,j} );
      }
    }
  }

  while(v.size()){
    for(int i=0;i<v.size();i++){
        result=check(v[i].x,v[i].y);
        if(result!=0){
            arr[v[i].x][v[i].y]=result;
            v.erase(v.begin()+i);
            i--;
            
        }
        
    }

  }
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
        printf("%d ",arr[i][j]);
    }
    printf("\n");
  }
}