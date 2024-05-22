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
const int MaxN = 1010;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int a[7], dp[MaxN], ans;
int w[7] = {0, 1, 2, 3, 5, 10, 20};
int main() {
  for(int i = 1; i <= 6; ++ i) a[i] = read();
  for(int i = 1; i <= 6; ++ i)
    for(int j = 1000; j >= w[i]; -- j)
      for(int k = 1; k <= a[i] && j >= w[i] * k; ++ k)
        dp[j] = max(dp[j], dp[j-k*w[i]] + w[i] * k);
  for(int i = 1; i <= 1000; ++ i)
    if(dp[i] == i) ans ++;
  printf("Total=%d", ans);
  return 0;
}