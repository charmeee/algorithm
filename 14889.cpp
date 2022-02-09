#include <iostream>
//#include <algorithm>
//https://blockdmask.tistory.com/178
//#include <cmath>//round 반올림림
//#include <string>
#include <vector>

using namespace std;

int arr[20][20]={};
int n;
int _min=-1;



void mkTeam(int t,int size,vector<int> v){
    vector<int> star;
    vector<int> link;
    int diff;
    int starsum=0;int linksum=0;
    if(size==n/2){
        for(int i=0;i<n;i++){
            if(v[i]==0){
                star.push_back(i);
            }else{link.push_back(i);}
        }
        for(int i=0;i<n/2;i++){
            for(int j=0;j<n/2;j++){
                starsum=starsum+arr[star[i]][star[j]];
                linksum=linksum+arr[link[i]][link[j]];
            }
        }
        if(starsum>linksum){diff=starsum-linksum;}else{diff=linksum-starsum;}
        if(_min==-1||diff<_min){
            _min=diff;
        }
    }else{
        for(int i=t;i<n;i++){
            if(v[i]==0){
                v[i]=1;
                mkTeam(i,size+1,v);
                v[i]=0;
            }
        }
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];        
        }
    }
    vector<int> v(n);
    mkTeam(0,0,v);
    cout<<_min;
}