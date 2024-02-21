#include <set>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <vector>
#include <bitset>
#include <cstdio>
#include <cctype>
#include <string>
#include <cstring>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std ;

#define rep(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define Rep(i, a, b) for (int (i) = (a) - 1; (i) < (b); (i)++)
#define REP(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define clr(a) memset(a, 0, sizeof(a))
#define Sort(a, len, cmp) sort(a + 1, a + len + 1, cmp)
#define ass(a, sum) memset(a, sum, sizeof(a))

#define ls ((rt) << 1)
#define rs ((rt) << 1 | 1)
#define lowbit(x) (x & -x)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define ENDL cout << endl
#define SZ(x) ((int)x.size())

typedef long long ll ;
typedef unsigned long long ull ;
typedef vector <int> vi ;
typedef pair <int, int> pii ;
typedef pair <ll, ll> pll ;

const int N = 2010 ;
const double eps = 1e-8 ;
const int iinf = INT_MAX ;
const ll linf = 2e18 ;
const double dinf = 1e30 ;
const int MOD = 1000000007 ;

inline int read(){
    int X = 0, w = 0 ;
	char ch = 0 ;
    while (!isdigit(ch)) { w |= ch == '-' ; ch = getchar() ; }
    while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar() ;
    return w ? - X : X ;
}

void write(int x){
     if (x < 0) putchar('-'), x = - x ;
     if (x > 9) write(x / 10) ;
     putchar(x % 10 + '0') ;
}

void print(int x) {
	cout << x << endl ;
	exit(0) ;
}

void PRINT(string x) {
	cout << x << endl ;
	exit(0) ;
}

void douout(double x){
	 printf("%lf\n", x + 0.0000000001) ;
}