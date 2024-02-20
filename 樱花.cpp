#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int hh1,hh2,mm1,mm2;
int f[N],vv[N],ww[N],cnt;
int v,w,s;
int n,V;
int main(){
    scanf("%d:%d %d:%d %d",&hh1,&mm1,&hh2,&mm2,&n);
    V=(hh2-hh1)*60+(mm2-mm1);
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&v,&w,&s);
        if(!s) s=1010;
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