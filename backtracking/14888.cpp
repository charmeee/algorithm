#include <iostream>
//#include <algorithm>
//https://blockdmask.tistory.com/178
//#include <cmath>//round 반올림림
//#include <string>
#include <vector>

using namespace std;

vector<int> v;
int Oper[4];
int maxn=-1000000001;
int minn=1000000001;
int cnt=0;


int cal(int i,int sum,int size){
    int tmp=0;
    int j;
    for(j=0;j<4;j++){
        tmp=tmp+Oper[j];
        if(i<=tmp){break;}
    }
    if(j==0){
        return sum+v[size+1];
    }
    if(j==1){
        return sum-v[size+1];
    }
    if(j==2){
        return sum*v[size+1];
    }
    if(j==3){
        return sum/v[size+1];
    }
    return 0;
}

void put_Oper(int size,int sum,vector<int> b){


    if(size==cnt){
        if(sum > maxn){maxn=sum;}
        if(sum < minn){minn=sum;}
    }else{
        for(int i=0;i<cnt;i++){
            if(b[i]==0){
                b[i]=1;
                int aftersum=cal(i+1,sum,size);
                put_Oper(size+1,aftersum,b);
                b[i]=0;
            }
        }
    }

}

int main(){
    int r,n;

    cin>>r;
    for(int i=0;i<r;i++){
        cin>>n;
        v.push_back(n);
    }
    for(int i=0;i<4;i++){
        cin>>Oper[i];
        cnt=cnt+Oper[i];
    }
    vector<int> b(cnt);
    int sum=v[0];
    put_Oper(0,sum,b);
    cout<<maxn<<'\n'<<minn;
}
