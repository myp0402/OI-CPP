#include<bits/stdc++.h>
using namespace std;
const int MOD=1e6+7;
int n,V;
int v=1,s;
int f[2010]={1};
int main(){
    scanf("%d%d",&n,&V);
    for(int i=0;i<n;i++){
		scanf("%d",&s);
        for(int j=V;j>=v;j--){
            for(int k=1;k<=s&&k*v<=j;k++)
                f[j]=(f[j]+f[j-k*v])%MOD;
        }
    }
    printf("%d",f[V]%MOD);
}
