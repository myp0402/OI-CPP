#include<bits/stdc++.h>
using namespace std;
int a[10],n,vis[11];
void dfs(int pos){
    if(pos==n+1){
        for(int i=0;i<=n;i++) printf("%5d",a[i]);
        puts("");
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            a[pos]=i;
            dfs(pos+1);
            vis[i]=0;
        }
    }
}
int main(){
    scanf("%d",&n);
    dfs(1);
}