#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int t;
int min_sum=0;

void find(int size,int before,vector<vector<int> > v){
    if (size==t)
    {
        /* code */
    }else{
        int min_index=min_element(v[size].begin(),v[size].end())-v[size].begin();
        cout<<"작은 인덱스"<<min_index<<endl;
        if(min_index!=before){
            cout<<"작은 인덱스"<<v[size][min_index]<<endl;
            min_sum=min_sum+v[size][min_index];
            find(size+1,min_index,v);
        }
    }
    
}

int main(){
    cin>>t;
    vector<vector<int> > v(t,vector<int>(3));//먼저나오는게 [rgb][줄] 후가 칸
    for(int i=0;i<t;i++){
        for(int j=0;j<3;j++){
            cin>>v[i][j];
        }
    }
    find(0,-1,v);

    cout<<min_sum;
}