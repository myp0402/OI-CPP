#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,k,q,tt;
// 计划个数 查询数量 等待时间
struct task{
    int t,c;
    //t时刻进入，需要c
} p[N];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++){
        scanf("%d%d",&p[i].t,&p[i].c);
    }
    for(int i=0;i<m;i++){
        tt=0;
        scanf("%d",&q);
        for(int j=0;j<n;j++){
            if(q+k<=p[j].t&&p[i].t-(q+k)<p[j].c) tt++;
        }
        printf("%d",tt);
    }
}