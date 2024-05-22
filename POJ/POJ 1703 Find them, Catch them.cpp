#include <bits/stdc++.h>
#define gc getchar()
#define ll long long
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
const int MaxN = 1e6+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int T, n, m, pa[MaxN];
int Find(int x) { return pa[x] == x ? pa[x] : pa[x] = Find(pa[x]);}
void unity(int u, int v) { u = Find(u); v = Find(v); pa[u] = v;}
int main() {
  T = read();
  while(T --) {
    n = read(); m = read();
    for(int i = 1; i <= n * 2; ++ i) pa[i] = i;
    for(; m; -- m) {
      char ch; std :: cin >> ch;
      int u = read(), v = read(), pau, pav, paun, pavn;
      pau = Find(u); pav = Find(v); paun = Find(u + n); pavn = Find(v + n);
      if(ch == 'A') {
        if(pau == pav || pavn == paun) printf("In the same gang.\n");
        else if(pau == pavn || pav == paun) printf("In different gangs.\n");
        else printf("Not sure yet.\n");
      } else unity(u, v + n), unity(v, u + n);
    }
  }
  return 0;
}