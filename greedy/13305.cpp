#include <iostream>
#include <vector>


using namespace std;

int main(){
    
    int t;cin>>t;
    vector <int> city(t);
    vector <int> dis(t-1);
    for(int i=0;i<t-1;i++){
        cin>>dis[i];
    }
    for(int i=0;i<t;i++){
        cin>>city[i];
    }
    int a=0;
    int b=1;
    long long cost=0;
    
    while(b<t){
        long long sum=0;
        while(city[a]<city[b]&&b<t){
            sum=sum+dis[b];
            b++;
        }
        cost=cost+city[a]*(sum+dis[a]);
        a=b;
        b=a+1;
    }
    cout<<cost;
}