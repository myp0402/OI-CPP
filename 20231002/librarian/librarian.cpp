#include <bits/stdc++.h>
using namespace std;
// int n,q,b[1010],e[8]={1,10,100,1000,10000,100000,1000000,10000000};
// struct reader{
//     int l,c;
// }r[1010];
// int len(int x){
//     int cnt=0;
//     while(x/10){
//         cnt++;
//     }
//     return cnt;
// }
// int main(){
//     cin >> n >> q;
//     for(int i=0;i<n;i++){
//         cin >> b[i];
//     }
//     for(int i=0;i<q;i++){
//         cin >> r[i].l >> r[i].c;
//     }
//     sort(b,b+n);
//     // for(int i=0;i<n;i++){
//     //     cout << b[i] << " ";
//     // }
//     for(int i=0;i<q;i++){
//         if(r[i].l<len(b[0])||r[i].l>len(b[n-1])){
//             cout << -1 << endl;
//             continue;
//         }
//         for(int j=0;j<n;j++){
//             if(r[i].c==b[j]%e[r[i].l+1]){
//                 cout << b[j] << endl;
//                 continue;
//             }
//         }
//         cout << -1 << endl;
//     }
//     return 0;
// }
int n,q,book[1100],len[1100],no[1100];

int main(){
    // freopen("librarian.in","r",stdin);
    // freopen("librarian.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) 
        scanf("%d",&book[i]);
    for(int i=1;i<=q;i++) {
        scanf("%d%d",&len[i],&no[i]);
        int tmp=pow(10,len[i]), min=10000001;
        for(int j=1; j<=n; j++) 
            if(book[j]%tmp==no[i] && book[j]<min)
                min = book[j];
        if(min != 10000001)
            printf("%d\n",min);
            // cout << min << endl;
        else
            printf("-1");
    }
    return 0;
}