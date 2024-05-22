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
const int MaxN = 2020;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
char s1[MaxN], s2[MaxN];
int dp[MaxN][MaxN];
int main() {
  scanf("%s %s", s1 + 1, s2 + 1);
  int len1 = strlen(s1+1), len2 = strlen(s2+1);
  for(int i = 1; i <= len1; ++ i) dp[i][0] = i;
  for(int i = 1; i <= len2; ++ i) dp[0][i] = i;
  for(int i = 1; i <= len1; ++ i)
    for(int j = 1; j <= len2; ++ j)
      if(s1[i] == s2[j]) dp[i][j] = dp[i-1][j-1];
      else dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
  printf("%d", dp[len1][len2]);
  return 0;
}