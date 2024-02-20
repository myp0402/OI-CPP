#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
const int N=150;
int a[N][N],qzh[N][N],ans;

int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n) rep(j,1,n){
        scanf("%d",a[i][j]);
        qzh[i][j]=qzh[i][j-1]+a[i][j];
    }
    rep(y1,0,n-1) rep(y2,y1+1,n){
        int tmpmax=0;
        rep(k,1,n){
            int ak=qzh[k][y2]-qzh[k][y1];
            tmpmax=max(0,tmpmax)+ak;
            ans=max(ans,tmpmax);
        }
    }
    printf("%d",ans);
}