#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[N],mem[N];
int dfs(int x);

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(a,0,sizeof(int)*N);
        memset(mem,0,sizeof(int)*N);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        printf("%d\n",dfs(0));
    }
    return 0;
}

int dfs(int x){
    if(x>=n) return 0;
    if(mem[x]) return mem[x];
    mem[x]=max(dfs(x+2)+a[x],dfs(x+1));
    return mem[x];
}