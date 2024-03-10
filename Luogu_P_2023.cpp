#include<stdio.h>

#define ll long long
#define N 100010
#define debug() puts("QWQ")
#define debug2() puts("我已出舱，感觉良好")
int flag,n,q,MOD,x,y,k,a[N];

struct node{
    int l,r;
    ll sum,add,mul;
    #define l(x) t[x].l
    #define r(x) t[x].r
    #define ssum(x) t[x].sum
    #define aadd(x) t[x].add
    #define mmul(x) t[x].mul
}t[N*4];

void eval(int p,int add,int mul){
    ssum(p)=(mul*ssum(p)%MOD+(ll)add*(r(p)-l(p)+1))%MOD;
    mmul(p)=mul*mmul(p)%MOD;
    aadd(p)=(mul*aadd(p)%MOD+add)%MOD;
}

void pushup(int p){
    ssum(p)=(ssum(p*2)%MOD+ssum(p*2+1)%MOD)%MOD;
}

void pushdown(int p){
    eval(p*2,aadd(p),mmul(p));
    eval(p*2+1,aadd(p),mmul(p));
    aadd(p)=0;
    mmul(p)=1;
}

void build(int p,int l,int r){
    l(p)=l,r(p)=r,mmul(p)=1;
    if(l==r){
        ssum(p)=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    pushup(p);
}

int query(int p,int l,int r){
    if(l<=l(p)&&r>=r(p)){
        return ssum(p);
    }
    pushdown(p);
    ll val=0;
    int mid=(l(p)+r(p))/2;
    if(l<=mid){
        val=query(p*2,l,r)%MOD;
    }
    if (r>mid){
        val=(val+query(p*2+1,l,r))%MOD;
    }
    return val;
}

void modify(int p,int l,int r,int add,int mul){
    if(l<=l(p)&&r>=r(p)){
        eval(p,add,mul);
        return;
    }
    pushdown(p);
    int mid=(l(p)+r(p))/2;
    if(l<=mid){
        modify(p*2,l,r,add,mul);
    }
    if (r>mid){
        modify(p*2+1,l,r,add,mul);
    }
    pushup(p);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("roll.in","r",stdin);
    freopen("roll.out","w",stdout);
#endif
    scanf("%d%d",&n,&MOD);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&q);
    build(1,1,n);
    while(q--){
        scanf("%d%d%d",&flag,&x,&y);
        if(flag==1){
            scanf("%d",&k);
            modify(1,x,y,0,k);
        }
        else if(flag==2){
            scanf("%d",&k);
            modify(1,x,y,k,1);
        }
        else{
            printf("%lld\n",query(1,x,y));
        }
    }
    return 0;
}