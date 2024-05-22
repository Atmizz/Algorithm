#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define gc getchar()
#define int long long
typedef long long ll;
inline int read() {
  int s = 0, f = 1; char ch = gc;
  for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
  for(; ch >= '0' && ch <= '9'; ch = gc)
    s = (s << 1) + (s << 3) + (ch ^ 48);
  return s * f;
}
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
const int MaxN = 5e8 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
void solve(int n) {
  int q;
  for(int i = 2; i <= 64; ++ i) {
    q = std :: pow(n, 1.0 / i);
    if(q < 2) break;
    int sum = 0, k = 1;
    for(int j = 0; j <= i; ++ j) sum += k, k *= q;
    if(sum == n) break;
  }
  if(q < 2) printf("NO\n");
  else printf("YES\n");
}
signed main() {
  int T = read();
  while(T --) {
    int n = read();
    solve(n);
  }
  return 0;
}