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
const int MaxN = 1e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int T, n, m, num[MaxN], sum1[MaxN], sum2[MaxN], ans1[MaxN], ans2[MaxN];
int main() {
  T = read();
  while(T --) {
    n = read(); m = read();
    std :: vector <int> x;
    int cnt1 = 0, cnt2 = 0;
    for(int i = 1; i <= n; ++ i) {
      int u = read();
      if(u == -1) cnt1 ++;
      else if(u == -2) cnt2 ++;
      else x.push_back(u);
    }
    if(x.empty()) {
      printf("%d\n", min(m, cnt1 + cnt2));
      continue;
    }
    for(int i = 0; i <= n + 1; ++ i)
      num[i] = sum1[i] = sum2[i] = ans1[i] = ans2[i] = 0;
    for(auto u : x) num[u] = 1;
    for(int i = 1; i <= n; ++ i) sum1[i] = sum1[i-1] + num[i];
    for(int i = n; i >= 1; -- i) sum2[i] = sum2[i+1] + num[i];
    for(int i = 1; i <= n; ++ i)
      ans1[i] = max(ans1[i-1], )
  }
  return 0;
}