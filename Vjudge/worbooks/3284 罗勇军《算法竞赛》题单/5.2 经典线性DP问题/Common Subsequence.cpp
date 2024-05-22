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
char s1[MaxN], s2[MaxN];
int dp[MaxN][MaxN];
int main() {
  while(scanf("%s", s1+1) != -1 && scanf("%s", s2+1) != -1) {
    memset(dp, 0, sizeof dp);
    int len1 = strlen(s1+1), len2 = strlen(s2+1);
    for(int i = 1; i <= len1; ++ i)
      for(int j = 1; j <= len2; ++ j)
        if(s1[i] == s2[j]) dp[i][j] = dp[i-1][j-1] + 1;
        else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    printf("%d\n", dp[len1][len2]);
  }
  return 0;
}