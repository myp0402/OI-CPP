#include<bits/stdc++.h>
using namespace std;
int n;
vector v;
int main(){
    scanf("%d",&n);
    v.push_back(n);
    while(n>1){
        if(n%2==0) n/=2;
        else n=n*3+1;
        v.push_back(n);
    }
    reverse(v.begin(),v.end());
    for(int i:v){
        printf("%d ",i);
    }
}