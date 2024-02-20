#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],s[N],n,m,l,r;

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++){
        scanf("%d",&a[i]);
        s[i]=s[i-1]+a[i];
    }
    for(int i=0;i<m;i++){
        scanf("%d%d",&l,&r);
        printf("%d",s[r]-s[l-1]);
    }
    return 0;
}