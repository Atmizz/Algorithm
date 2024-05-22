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
const int MaxN = 1e6 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int T, n;
int main() {
  T = read();
  while(T --) {
    n = read();
    std :: vector <int> a1, a2, a3;
    for(int i = 1; i <= n; ++ i) {
      int m = read(), x = read();
      if(x == 0) continue;
      if(x == 1) a2.push_back(m);
      else if(x == 11) a3.push_back(m);
      else a1.push_back(m);
    }
    std :: sort(a1.begin(), a1.end());
    std :: sort(a2.begin(), a2.end());
    std :: sort(a3.begin(), a3.end());
    int ans = INF;
    if(a1.size() && a2.size()) ans = min(ans, a1[0] + a2[0]);
    if(a3.size()) ans = min(ans, a3[0]);
    printf("%d\n", ans == INF ? -1 : ans);
  }
  return 0;
}