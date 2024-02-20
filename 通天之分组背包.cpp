#include<bits/stdc++.h>
using namespace std;
int n,W;
int w,v,g,MAXg;
int dp[1100];
struct item{
    int w,v,g;
};
vector<item> items(1100);
int idx;

int main(){
    scanf("%d%d",&W,&n);
    for(int i=1;i<=n;++i){
		scanf("%d%d%d",&w,&v,&g);
        items[i]={w,v,g};
        MAXg=max(MAXg,g);
	}
    for(vector<item>::iterator it=items.begin();it!=items.end();it++){
        idx=(*it).g;
        for(int j=W;j>=0;j--){
			for(int k=1;k<=n && j>=items[k].w && items[k].g==idx;k++){
				dp[j]=max(dp[j],dp[j-items[k].w]+items[k].v);
			}
		}
    }
}