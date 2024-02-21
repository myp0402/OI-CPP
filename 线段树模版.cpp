#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
int n,m,a[N];
int _p;
struct SegementTree{
    int l,r;
    ll mmin,tag,ssum;
    #define l(x) t[x].l
    #define r(x) t[x].r
    #define mmin(x) t[x].mmin
    #define ssum(x) t[x].ssum
    #define tag(x) t[x].tag
}t[N*4];

void build(int p,int l,int r){
    l(p)=l,r(p)=r;
    if(l==r){
        mmin(p)=a[l];
        ssum(p)=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    ssum(p)=ssum(p*2)+ssum(p*2+1);
    mmin(p)=min(mmin(p*2),mmin(p*2+1));
}

void push_down(int p){
    if(tag(p)){
        ssum(p*2)+=(long long)tag(p)*(r(p*2)-l(p*2)+1);
        ssum(p*2+1)+=(long long)tag(p)*(r(p*2+1)-l(p*2+1)+1);
        mmin(p*2)=mmin(p*2)+tag(p);
        mmin(p*2+1)=mmin(p*2+1)+tag(p);
        tag(p*2)+=tag(p);
        tag(p*2+1)+=tag(p);
        tag(p)=0;
    }
}

ll query_min(int p,int l,int r){
    if(l<=l(p) && r>=r(p)) return mmin(p);
	push_down(p);
    int mid=(l(p)+r(p))/2;
    ll val=2000000;
    if(l<=mid) val=min(val,query_min(p*2,l,r));
    if(r>mid) val=min(val,query_min(p*2+1,l,r));
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
        mmin(p)=mmin(p)+v;
        tag(p)+=v;
        return;
    }
    push_down(p);
    int mid=(l(p)+r(p))/2;
    if(l<=mid) modify(p*2,l,r,v);
    if(r>mid) modify(p*2+1,l,r,v);
    mmin(p)=min(mmin(p*2),mmin(p*2+1));
    ssum(p)=ssum(p*2)+ssum(p*2+1);
}

signed main(){


    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    build(1,1,n);
    for(int i=0;i<m;i++){
        int op,l,r;
        scanf("%d%d%d",&op,&l,&r);
        if(op==1){
            scanf("%d",&_p);
            modify(1,l,r,_p);
        }
        else printf("%lld\n",query_sum(1,l,r));
    }
    return 0;
}
