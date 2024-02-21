#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug() puts("QWQ");
const int N=2e5+10;
int M,a[N];
long long D,_n,_t;
int idx=1;
struct SegementTree{
    int l,r;
    ll mmax,tag,ssum;
    #define l(x) t[x].l
    #define r(x) t[x].r
    #define mmax(x) t[x].mmax
    #define ssum(x) t[x].ssum
    #define tag(x) t[x].tag
}t[N*4];

void build(int p,int l,int r){
    l(p)=l,r(p)=r;
    if(l==r){
        mmax(p)=a[l];
        ssum(p)=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    ssum(p)=ssum(p*2)+ssum(p*2+1);
    mmax(p)=max(mmax(p*2),mmax(p*2+1));
}

void push_down(int p){
    if(tag(p)){
        ssum(p*2)+=(long long)tag(p)*(r(p*2)-l(p*2)+1);
        ssum(p*2+1)+=(long long)tag(p)*(r(p*2+1)-l(p*2+1)+1);
        mmax(p*2)=mmax(p*2)+tag(p);
        mmax(p*2+1)=mmax(p*2+1)+tag(p);
        tag(p*2)+=tag(p);
        tag(p*2+1)+=tag(p);
        tag(p)=0;
    }
}

ll query_max(int p,int l,int r){
    if(l<=l(p) && r>=r(p)) return mmax(p);
	push_down(p);
    int mid=(l(p)+r(p))/2;
    ll val=-2000000;
    if(l<=mid) val=max(val,query_max(p*2,l,r));
    if(r>mid) val=max(val,query_max(p*2+1,l,r));
    return val;
}

ll query_sum(int p,int l,int r){
	if(l<=l(p) && r>=r(p)) return ssum(p);
    push_down(p);
	int mid=(l(p)+r(p))/2;
	ll val=0;
	if(l<=mid) val += query_sum(p*2,l,r);
	if(r>mid) val += query_sum(p*2+1,l,r);
	return val;
}

void modify(int p,int l,int r,int v){
    if(l<=l(p) && r>=r(p)){
        ssum(p)+=(long long)v*(r(p)-l(p)+1);
        mmax(p)=mmax(p)+v;
        tag(p)+=v;
        return;
    }
    push_down(p);
    int mid=(l(p)+r(p))/2;
    if(l<=mid) modify(p*2,l,r,v);
    if(r>mid) modify(p*2+1,l,r,v);
    mmax(p)=min(mmax(p*2),mmax(p*2+1));
    ssum(p)=ssum(p*2)+ssum(p*2+1);
}

signed main(){

    freopen("roll.in","r",stdin);
    freopen("roll.out","w",stdout);

    scanf("%d%lld",&M,&D);
    // for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    // build(1,1,n);
    for(int i=0;i<M;i++){
        char op;
        int L;
        debug();
        scanf("%c",&op);
        
        if(op=='Q'){
            scanf("%d",&L);
            // _t=query_max(1,1,L);
            printf("%lld\n",_t);
        }
        else{
            scanf("%lld",&_n);
            modify(1,idx,idx,(_n+_t)%D);
            idx++;
        }
    }
    return 0;
}
