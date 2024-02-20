#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,V;
int v,w,s;
int f[2010],vv[N],ww[N],cnt;
int main(){
    scanf("%d%d",&n,&V);
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&v,&w,&s);
        for(int k=1;k<=s;k*=2){
            cnt++;
            vv[cnt]=k*v;
            ww[cnt]=k*w;
            s-=k;
        }
        if(s){
            cnt++;
            vv[cnt]=s*v;
            ww[cnt]=s*w;
        }
    }
    for(int i=1;i<=cnt;i++){
        for(int j=V;j>=vv[i];j--){
            f[j]=max(f[j],f[j-vv[i]]+ww[i]);
        }
    }
    printf("%d",f[V]);
}