
#include <iostream>
//#include <algorithm>
//https://blockdmask.tistory.com/178
//#include <cmath>//round 반올림림
//#include <string>
#include <vector>
//#include <map>//https://life-with-coding.tistory.com/305

//처음 chk라는 배열에 수를넣고 비교하며 숫자가 있는지 비교했으나. 그것보다 그냥 1-9를 넣어서 비교하고 넘기는게 더빠르다.중간에 넘길 수 있어서..
//이게 여러가지 되는거일때도 된다는식으로 해야해서 하나넣어보고 다음꺼 다음꺼 다음꺼 이런식으로 해서 안되면 패스 요런식으로해야함,..

using namespace std;

struct Data{
  int x;int y;
};

int arr[9][9]={};
vector<Data> v;
bool found=false;

bool check(int x,int y,int t){
  int cx,cy;
  for(int i=0;i<9;i++){//가로세로 검사.
    if(arr[x][i]==t){//가로
      return false;
    }
    if(arr[i][y]==t){//세로
      return false;
    }
  }
  cx=x/3;cy=y/3;
  for(int i=0;i<3;i++){for(int j=0;j<3;j++){
    if(arr[3*cx+i][3*cy+j]==t){return false;}     
    }
  }
  return true;
}

int sudoku(int n) {
  if(n==v.size()){
    for(int i=0;i<9;i++){
      for(int j=0;j<9;j++){
          printf("%d ",arr[i][j]);
      }
    printf("\n");
    }
    found=true;
    return 0;
  }
  for(int j=1;j<10;j++){
    if(check(v[n].x,v[n].y,j)){
      arr[v[n].x][v[n].y]=j;
      sudoku(n+1);
    }
    if(found){
      return 0;
    }
    arr[v[n].x][v[n].y]=0;//찾았으면 앞에서 종료되었을 거임.
  }
  return 0;
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
  sudoku(0);
}