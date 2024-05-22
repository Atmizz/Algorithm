#include <bits/stdc++.h>
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
const int MaxN = 1e6 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
ll n, m, c;
struct Node {
  ll u, v, dis;
  friend bool operator < (Node a, Node b) {
    return a.dis < b.dis;
  }
}a[MaxN];
ll pa[MaxN];
ll Find(ll x) {
  return x == pa[x] ? pa[x] : pa[x] = Find(pa[x]);
}
bool check(int x) {
  for(ll i = 1; i <= n; ++ i) pa[i] = i;
  ll cnt = 0, sum = c, num = 0;
  std :: vector <ll> b;
  for(int i = 1; i <= m; ++ i) {
    ll s = Find(pa[a[i].u]), r = Find(pa[a[i].v]);
    if(s == r) continue;
    pa[s] = r; num ++;
    if(a[i].dis <= x) continue; 
    b.push_back(a[i].dis);
    if(num == n - 1) break;
  }
  for(int i = b.size() - 1; i >= 0; -- i) {
    sum -= (++cnt) * b[i];
    if(sum < 0) return false;
  }
  return true;
}
int main() {
  n = read(); m = read(); c = read();
  for(int i = 1; i <= m; ++ i)
    a[i].u = read(), a[i].v = read(), a[i].dis = read();
  std :: sort(a + 1, a + 1 + m);
  ll l = 0, r = 1e9 + 200, mid;
  while(l < r) {
    mid = (l + r) >> 1;
    if(check(mid)) r = mid;
    else l = mid + 1;
  } printf("%lld", r);
  return 0;
}