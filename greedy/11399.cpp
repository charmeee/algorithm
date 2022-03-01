#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

//문제 제대로 안읽은게 레전드 ㅋ

using namespace std;

int main(){
    string s;
    vector <int> op;
    vector <int> v;
    cin>>s;
    
    
    int a=0;
    int b=0;
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]=='-'||s[i]=='+'){
            v.push_back(a);
            a=0;
            if(s[i]=='-'){
                op.push_back(b);
            }
            b++;
        }
        else{
            a=a*10;
            a=a+(int(s[i])-int('0'));
        }
    }
    v.push_back(a);
    int sum=v[0];
    for(int i = 1 ; i < v.size(); i++){
        if(op.size()!=0){
            if(i>op[0]){
                sum=sum-v[i];
            }else{
                sum=sum+v[i];
            }
        }else{
            sum=sum+v[i];
        }
        
    }
    cout<<sum;
    
    
}