#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl '\n'
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 60;
int dp[N], n;
std :: string str;
void solve() {
  std :: cin >> n >> str;
  str = '0' + str;
  int ans = 0;
  for(int i = 2; i <= n; ++ i) {
    dp[i] = 0;
    if(str[i] == '.') {
      if(i - 1 >= 1 && str[i-1] != '*') {
        dp[i] = std :: max(dp[i], dp[i-1]);
      }
      else if(i - 2 >= 1 && str[i-2] != '*') {
        dp[i] = std :: max(dp[i], dp[i-2]);
      }
    }
    if(str[i] == '@') {
      if(i - 1 >= 1 && str[i-1] != '*') {
        dp[i] = std :: max(dp[i], dp[i-1] + 1);
      }
      else if(i - 2 >= 1 && str[i-2] != '*') {
        dp[i] = std :: max(dp[i], dp[i-2] + 1);
      }
    }
    if(dp[i] == 0 && str[i-1] == '*' && str[i] == '*') {
      break;
    }
    ans = std :: max(dp[i], ans);
  }
  std :: cout << ans << '\n';
}
int main() {
  //freopen("1.in", "r", stdin);
  //freopen("1.out", "w", stdout);
  std :: ios :: sync_with_stdio(false);
  std :: cin.tie(0);
  std :: cout.tie(0);
  int T = 1;
  std :: cin >> T; 
  while(T --) solve();
  return 0;
}