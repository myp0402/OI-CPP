#include<stdio.h>
#define max(x,y) x>y?x:y
#define MAXN 1010
int v[MAXN],m[MAXN],w[MAXN],f[MAXN][MAXN];
int N,V,M;

int main(){
    scanf("%d%d%d",&V,&M,&N);
    for(int i=1;i<=N;i++) scanf("%d%d%d",&v[i],&m[i],&w[i]);
    for(int i=1;i<=N;i++)
        for(int j=V;j>=v[i];j--)
            for(int k=M;k>=m[i];k--)
                f[j][k]=max(f[j][k], f[j-v[i]][k-m[i]]+w[i]);
    printf("%d",f[V][M]);
    return 0;
}
