//https://kim6394.tistory.com/67

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Data
{
    int start;
    int end;
};

bool cmp(const Data &a,const Data &b){
    if(a.end==b.end){
        return a.start<b.start;
    }
    return a.end<b.end;
}

int main(){
    int t;cin>>t;
    vector <Data> d;
    int cnt=0;
    for(int i=0;i<t;i++){
        int s;int e;
        cin>>s>>e;
        d.push_back({s,e});
    }
    sort(d.begin(),d.end(),cmp);
    int last=0;

    for(int i=0;i<d.size();i++){
        if(last<=d[i].start){
            cnt++;
            last=d[i].end;
        }
    }
    cout<<cnt;
}