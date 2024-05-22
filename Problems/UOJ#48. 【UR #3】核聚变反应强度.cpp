#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cstdlib>
#include <map>
#include <set>
#define ls k << 1
#define rs k << 1 | 1
#define gc getchar()
typedef long long ll;
inline ll read() {
  ll s = 0, f = 1; char ch = gc;
  for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
  for(; ch >= '0' && ch <= '9'; ch = gc)
    s = (s << 1) + (s << 3) + (ch ^ 48);
  return s * f;
}
inline int abs(int a) {return a < 0 ? -a : a;}
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
const int MaxN = 1e6+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
ll a[MaxN], n;
std :: vector <ll> Prime;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
void Prepare(ll x) {
  for(ll i = 2; i * i <= x; ++ i) {
    if(!(x % i)) Prime.push_back(i);
    while(!(x % i)) x /= i;
  } if(x > 1) Prime.push_back(x);
}
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i) a[i] = read();
  Prepare(a[1]); printf("%lld ", a[1] / Prime[0]);
//  for(int i = 0; i < Prime.size(); ++ i) printf("%d ", Prime[i]);
  for(int i = 2; i <= n; ++ i) {
    ll g = gcd(a[1], a[i]);
    if(g == 1) printf("-1 ");
    else {
      for(int i = 0, sz = Prime.size(); i < sz; ++ i)
        if(!(g % Prime[i])) {printf("%lld ", g / Prime[i]); break;}
    }
  }
  return 0;
}