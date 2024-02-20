#include<bits/stdc++.h>
using namespace std;
const int W=5010,N=210;
int n,mem[N][W],dp[N][W],t,w[N],v[N],m,f[W],g[W];
//1.dfs 2.记忆化搜索 3.递推
int dfs(int x,int spv){
	if(mem[x][spv]){
		return mem[x][spv];
	}
	if(spv==0 || x>n){
		return 0;
	}
	if(w[x]>spv){
		mem[x][spv]=dfs(x+1,spv);
	}else{
		mem[x][spv]=max(dfs(x+1,spv-w[x])+v[x],dfs(x+1,spv));
	}
	return mem[x][spv];
}
int main(){
	cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>w[i]>>v[i];
	}
	//cout<<dfs(1,m);
	//1.逆推 f[i][j]  i-n j
	for(int i=n;i>=1;i--){  //物品  
		for(int j=0;j<=m;j++){
			if(w[i]>j) dp[i][j]=dp[i+1][j];
			else dp[i][j]=max(dp[i+1][j], dp[i+1][j-w[i]]+v[i]);
		}
	}
	//2.顺推 f[i][j]  1-i j
	for(int i=1;i<=n;i++){  //物品  
			for(int j=0;j<=m;j++){
				if(w[i]>j) dp[i][j]=dp[i-1][j];
				else dp[i][j]=max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]);
			}
		}
		
	//3.空间优化
	for(int i=1;i<=n;i++){  //物品  
		for(int j=w[i];j<=m;j++){
			 f[j]=max(g[j], g[j-w[i]]+v[i]);
		}
		memcpy(g,f,sizeof(f));
	}
	
	//4.空间优化
		for(int i=1;i<=n;i++){  //物品  
			for(int j=m;j>=w[i];j--){
				 f[j]=max(f[j], f[j-w[i]]+v[i]);
			}
		}
	cout<<f[m];
	return 0;
}
