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
const int MaxN = 5;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, ans;
int main() {
  n = read();
  while(n --) {
    ans = 1; int dp[5] = {0};
    char str[5];
    scanf("%s", str + 1); str[0] = '-';
    std :: sort(str + 1, str + 5);
    for(int i = 1; i <= 4; ++ i) {
      dp[i] = 1;
      if(str[i] == str[i-1]) dp[i] = dp[i-1] + 1;
      ans = max(ans, dp[i]);
    }
    // std :: cout << ans << ' ';
    if(ans == 1 || ans == 2) std :: cout << 4 << '\n';
    else if(ans == 3) std :: cout << "6\n";
    else std :: cout << "-1\n";
  }
  return 0;
}