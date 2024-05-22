#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define gc getchar()
typedef long long ll;
inline int read() {
  int s = 0, f = 1; char ch = gc;
  for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
  for(; ch >= '0' && ch <= '9'; ch = gc)
    s = (s << 1) + (s << 3) + (ch ^ 48);
  return s * f;
}
inline int abs(int a) {return a < 0 ? -a : a;}
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
const int MaxN = 150;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, k, pa[MaxN];
std :: unordered_set <int> em[MaxN];
int Find(int x) {
  return x == pa[x] ? x : pa[x] = Find(pa[x]);
}
void Unity(int u, int v) {
  u = Find(u); v = Find(v); pa[u] = v;
}
int main() {
  n = read(); m = read(); k = read();
  for(int i = 1; i <= n; ++ i) pa[i] = i;
  for(int i = 1; i <= m; ++ i) {
    int u = read(), v = read(), opt = read();
    if(opt == 1) Unity(u, v);
    else em[u].insert(v), em[v].insert(u);
  }
  for(int i = 1; i <= k; ++ i) {
    int u = read(), v = read();
    int fu = Find(u), fv = Find(v);
    // std :: cout << u << ' ' << em[u].count(v) << ' ' << v << ' ' << em[v].count(u) << '\n';
    if(fu == fv && !(em[u].count(v)) && !(em[v].count(u))) std :: cout << "No problem\n";
    if(fu == fv && em[u].count(v) && em[v].count(u)) std :: cout << "OK but...\n";
    if(fu != fv && em[u].count(v) && em[v].count(u)) std :: cout << "No way\n";
    if(fu != fv && !(em[u].count(v)) && !(em[v].count(u))) std :: cout << "OK\n";
  }
  return 0;
}