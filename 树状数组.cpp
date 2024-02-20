#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5;
int a[N],t[N],n,m,x,y,q,op,c;
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
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&q);
        add(i,q);
    }
    for(int i=0;i<m;i++){
        scanf("%d",&op);
        if(op==1){
            scanf("%d%d",&x,&c);
            add(x,c);
        }
        else{
            scanf("%d%d",&x,&y);
            printf("%d",sum(y)-sum(x-1));
        }
    }
    return 0;
}

