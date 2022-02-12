#include <iostream>
#include <vector>

using namespace std;

long d[100]={};


int main(){
    d[0]=1;d[1]=1;d[2]=1;d[3]=2;d[4]=2;
    int n=50;
    int t;cin>>t;
    for(int j=0;j<t;j++){
        int n;cin>>n;
        for(int i=5;i<n;i++){
            d[i]=d[i-1]+d[i-5];
        }
        cout<<d[n-1]<<endl;
    }
    
}