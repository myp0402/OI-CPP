#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N],tt;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(a[i]<a[j]&&a[i]<a[k]&&a[j]<a[k]){
                    tt++;
                }
            }
        }
    }
    printf("%d",tt);
    return 0;
}