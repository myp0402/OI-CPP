#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5010;
int n,mem[N],dp[N];

int dfs(int x);

signed main(){
	scanf("%d",&n);
    dp[0]=1;dp[1]=1;
    for(int i=2;i<=n;i++) dp[i]=dp[i-1]+dp[i-2];
	printf("%d",dp[n]);
	return 0;
}

int dfs(int x){
	if(mem[x]) return mem[x];
	if(x==0||x==1) return 1;
	mem[x]=dfs(x-1)+dfs(x-2);
	return mem[x];
}
