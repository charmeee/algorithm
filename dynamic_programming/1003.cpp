#include <iostream>
#include <vector>

using namespace std;

int cnt0;
int cnt1;
int d[40][2]={};




int main(){
    d[0][0]=1;d[0][1]=0;
    d[1][0]=0;d[1][1]=1;
    d[2][0]=1;d[2][1]=1;
    d[3][0]=1;d[3][1]=2;

    int t;cin>>t;
    for(int i=0;i<t;i++){
        int n;cin>>n;
        for(int i=4;i<=n;i++){
            d[i][0]=d[i-1][0]+d[i-2][0];
            d[i][1]=d[i-1][1]+d[i-2][1];
        }
        cout<<d[n][0]<<' '<<d[n][1]<<endl;
    }
}