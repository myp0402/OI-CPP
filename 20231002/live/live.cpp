#include <bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int n,w,s[N],q[N];
void f(){
    for(int i=0;i<N;i++) q[i]=0;
}
bool cmp(int x, int y){
    return x>y;
}
int mmax(int x){
    f();
    for(int i=0;i<x;i++){
        q[i]=s[i];
    }
    sort(q,q+x,cmp);
    if((((x*w)/100)-1)<0){
        return s[0];
    }
    return q[max(0,(x*w)/100)-1];
}
int main(){
    // freopen("live.in","r",stdin);
    // freopen("live.out","w",stdout);
    scanf("%d%d",&n,&w);
    for(int i=0;i<n;i++){
        scanf("%d",&s[i]);
    }
    for(int i=0;i<n;i++){
        printf("%d ",mmax(i+1));
    }
    return 0;
}