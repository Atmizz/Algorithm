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
const int MaxN = 110;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
std :: string str;
int dp[MaxN][MaxN], n, num[MaxN];
bool check(int l, int r, int len) {
  for(int i = l; i <= r; ++ i)
    if(str[i] != str[(i-l)%len+l])
      return false;
  return true;
}
int main() {
  std :: cin >> str; n = str.length(); str = ' ' + str;
  for(int i = 1; i <= 9; ++ i) num[i] = 1;
  for(int i = 10; i <= 99; ++ i) num[i] = 2;
  num[100] = 3; memset(dp, 0x3f, sizeof dp);
  for(int i = 1; i <= n; ++ i) dp[i][i] = 1;
  for(int len = 2; len <= n; ++ len)
    for(int i = 1; i <= n; ++ i) {
      int j = i + len - 1;
      if(j > n) break;
      for(int k = i; k < j; ++ k)
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
      for(int k = i; k < j; ++ k) {
        int ll = k - i + 1;
        if(len % ll) continue;
        if(check(i, j, ll)) dp[i][j] = min(dp[i][j], dp[i][k] + 2 + num[len/ll]);
      }
    }
  printf("%d", dp[1][n]);
  return 0;
}