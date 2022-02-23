//https://kim6394.tistory.com/67

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;cin>>t;
    vector <vector <int> > v(t, vector <int>(2,0));
    int cnt=0;
    int max=0;
    for(int i=0;i<t;i++){
        int start;int end;
        cin>>start;cin>>end;
        if(start==end){cnt++;}
        else{v[i][0]=start;v[i][1]=end;}
        if(max<end){max=end;}
    }
    vector <int> time(max+2);
    int max1=0;
    for(int i=0;i<t;i++){
        if(v[i][1]!=0){
            for(int j=v[i][0];j<v[i][1];j++){
                time[j]++;
                if(max1<time[j]){max1=time[j];}
            }        
        }
    }
    cout<<max1<<endl;
    for(int j=1;j<=max1;j++){
        bool check =false;
        int start;int end;
        for(int i=0;i<max+1;i++){
            if(time[i]==j){
                if(!check){start=i;}
                bool check=true;
                if(time[i+1]!=j){
                    end=i;
                    
                }
            }
        }
    }
    
}