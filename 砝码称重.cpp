#include<bits/stdc++.h>
using namespace std;
const int M[]={1,2,3,5,10,20};
int a,b,c,d,e,f,tt;
bool bkt[10000];
int main(){
    cin >> a >>b >>c >> d>> e>> f;
    for(int i=0;i<a;i++) for(int j=0;j<b;j++) for(int k=0;k<c;k++) for(int l=0;l<d;l++) for(int m=0;m<e;m++) for(int n=0;n<f;n++){
        bkt[i+j+k+l+m+n]=1;
    }
    for(int i=0;i<10000;i++){
        if(bkt[i]) tt++;
    }
    cout << tt;
    return 0;
}