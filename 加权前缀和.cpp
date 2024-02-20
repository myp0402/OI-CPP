#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
#define int long long
int a[N],s[N],n,m,l,r,t,tt;

signed main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<m;i++){
        tt=0;
        scanf("%d",&t);
        scanf("%d%d",&l,&r);
        for(int j=l;j<=r;j++){
            tt+=a[j]*j;
        }
        printf("%d",tt);
    }
    return 0;
}