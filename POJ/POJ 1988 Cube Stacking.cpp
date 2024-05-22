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
int n, pa[MaxN], val[MaxN];
int Find(int x) {
  if(pa[x] == x) return pa[x];
  int tmp = pa[x]; pa[x] = Find(pa[x]);
  if(tmp != pa[x]) val[x] += val[tmp];
  return pa[x];
}
int main() {
  n = read();
  for(int i = 1; i <= 30000; ++ i) pa[i] = i, val[i] = 1;
  for(int i = 1; i <= n; ++ i) {
    char ch; std :: cin >> ch;
    int u = read(), v, Pa_u, Pa_v;
    Pa_u = Find(u);
    if(ch == 'M') {
      v = read(); Pa_v = Find(v);
      pa[Pa_u] = Pa_v;
      int temp = val[Pa_v]; val[Pa_v] += val[Pa_u]; val[Pa_u] = temp;
    } else {
      if(u == Pa_u) printf("%d\n", 0);
      else printf("%d\n", val[u]);
    }
  }
  return 0;
}