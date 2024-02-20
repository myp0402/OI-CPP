#include<bits/stdc++.h>
using namespace std;
int n,m,q,a[1010][1010],s[1010][1010],ax,ay,bx,by;
int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
        }
    for(int i=0;i<q;i++){
        scanf("%d%d%d%d",&ax,&ay,&bx,&by);
        printf("%d",s[bx][by]-s[bx][ay-1]-s[ax-1][by]+s[ax-1][ay-1]);
    }
}