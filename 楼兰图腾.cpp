#include<bits/stdc++.h>
using namespace std;
#define repe(i,a,b) for(int i=(a);i<=(b);++i)
const int N=2*1e5;
int n;
int64_t a[N],t[N];
int lowbit(int x){
    return x&-x;
}
void add(int idx,int k){
    for(int i=(idx);i<=(n);(i)+=lowbit(i)) t[i]+=k;
}
int sum(int idx){
    int ans=0;
    for(int i=(idx);i;(i)-=lowbit(i)) ans+=t[i];
    return ans;
}
int main(){
    scanf("%d",&n);
    repe(i,1,n) scanf("%lld",&a[i]);
    
}

