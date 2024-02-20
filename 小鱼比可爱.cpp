#include<bits/stdc++.h>
using namespace std;
int a[110],n,tt;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        tt=0;
        for(int j=0;j<i;j++){
            if(a[j]<a[i]) tt++;
        }
        printf("%d ",tt);
    }
}