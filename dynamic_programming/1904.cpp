#include <iostream>
#include <vector>

using namespace std;

int cnt=0;

int aC(int a,int b){
    if(b==1){return a;}
    b--;
    return a*aC(a-1,b);
}

int Cb(int b){
    if(b==1){return 1;}
    return b*Cb(b-1);
}

int aCb(int a,int b){
    if(b>a/2){b=a-b;}
    if(b==0){return 1;}
    return aC(a,b)/Cb(b);
}



void count(int a,int b){
    if(a==0||b==0){
        cnt++;return;
    }
    for(int a)
}



int main(){
    int n;cin>>n;
    int t=n/2;
    for(int i=0;i<=t;i++){

        int a=i;//0의 개수
        int b=n-i*2;//1의 개수
        count(a,b);
    }
    cout<<cnt%15746;
}