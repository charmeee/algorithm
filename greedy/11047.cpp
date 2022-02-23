
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;cin>>t; int n;cin>>n;
    vector <int> v(t);
    for(int i=0;i<t;i++){
        cin>>v[i];
    }
    int cnt=0;
    for(int i=v.size()-1;i>-1;i--){
        if(n>=v[i]){
            int a=n/v[i];
            cnt=cnt+a;
            n=n%v[i];
        }
    }
    cout<<cnt<<endl;
}