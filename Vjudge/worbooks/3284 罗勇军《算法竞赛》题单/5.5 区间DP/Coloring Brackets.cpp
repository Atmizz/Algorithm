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
const int MaxN = 730;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, pos[MaxN];
ll dp[MaxN][MaxN][3][3], ans; 
char str[MaxN];
void prepare() {
  std :: stack <int> s;
  for(int i = 1; i <= n; ++ i)
    if(str[i] == '(') s.push(i);
    else pos[s.top()] = i, s.pop();
  memset(dp, -1, sizeof dp);
}
/*
0 null
1 blue
2 red
*/
ll dfs(int l, int r, int c1, int c2) {
  if(dp[l][r][c1][c2] != -1) return dp[l][r][c1][c2];
  dp[l][r][c1][c2] = 0;
  if(l + 1 == r) return dp[l][r][c1][c2] = ((c1 > 0) != (c2 > 0));
  if(pos[l] == r) {
    if((c1 > 0) == (c2 > 0)) return 0;
    for(int i = 0; i < 3; ++ i) 
      for(int j = 0; j < 3; ++ j)
        if((i == 0 || i != c1) && (j == 0 || j != c2))
          dp[l][r][c1][c2] = (dp[l][r][c1][c2] + dfs(l+1, r-1, i, j)) % Mod;
    return dp[l][r][c1][c2];
  }
  for(int i = 0; i < 3; ++ i)
    for(int j = 0; j < 3; ++ j)
      if((i == 0 && j == 0) || i != j)
        dp[l][r][c1][c2] = (dp[l][r][c1][c2] + dfs(l, pos[l], c1, i) * dfs(pos[l]+1, r, j, c2) % Mod) % Mod;
  return dp[l][r][c1][c2];
}
int main() {
  scanf("%s", str + 1); n = strlen(str + 1); prepare();
  for(int i = 0; i < 3; ++ i)
    for(int j = 0; j < 3; ++ j)
      ans = (ans + dfs(1, n, i, j)) % Mod;
  printf("%lld", ans % Mod);
  return 0;
}