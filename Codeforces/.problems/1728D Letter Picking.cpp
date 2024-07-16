#include <bits/stdc++.h>
//#pragma GCC optimize ("O3")
#define nl '\n'
#define ls k << 1
#define rs k << 1 | 1
#define pb push_back
#define sz(x) (int)x.size()
#define mk std :: make_pair
#define PII std :: pair <int, int>
#define PIL std :: pair <int, i64>
#define PLL std :: pair <i64, i64>
#define DEB std :: cout << "ok" << '\n';
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
typedef unsigned long long ull;
template <class T>
T max(T a, T b) {
  return a > b ? a : b;
}
template <class T>
T min(T a, T b) {
  return a < b ? a : b;
}
template <class T>
T abs(T a) {
  return a < 0 ? -a : a;
}
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 2020;
void solve() {
  std :: string s;
  std :: cin >> s;
  int n = sz(s);
  bool ok = true;
  for(int i = 0; i < n / 2; ++ i) {
    if(s[i] != s[n-i-1]) {
      ok = false;
    }
  }
  // for(int i = 1; i < n / 2; ++ i) {
  //   if(s[i] < s[i-1]) {
  //     ok = false;
  //   }
  // }
  if(ok) {
    std :: cout << "Draw\n";
    return ;
  }
  std :: vector dp(n + 1, std :: vector <int> (n + 1));
  s = '0' + s;
  for(int len = 2; len <= n; ++ len) {
    for(int i = 1; i <= n; ++ i) {
      int j = i + len - 1;
      if(j > n) {
        break;
      }
      dp[i][j] |= (dp[i][j-1] | dp[i+1][j]);
      if(!(len & 1)) {
        if((s[i] < s[i+1] && s[i] < s[j]) || (s[j] < s[i] && s[j] < s[j-1])) {
          dp[i][j] = 1;
        }
      }
      // std :: cout << i << ' ' << j << ' ' << dp[i][j] << nl;
    }
  }
  std :: cout << (dp[1][n] ? "Alice\n" : "Bob\n");
}
int main() {
  //freopen("1.in", "r", stdin);
  //freopen("1.out", "w", stdout);
  std :: ios :: sync_with_stdio(false);
  std :: cin.tie(0);
  std :: cout.tie(0);
  int _ = 1;
  std :: cin >> _; 
  while(_ --) solve();
  return 0;
}