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
const int N = 4e5 + 20;
int n, pos;
std :: string str;
void solve() {
  std :: cin >> n >> str;
  int res = 0, b = 0; pos = 0;
  for(int i = 0; i < n; ++ i) {
    res += str[i] - '0';
  }
  std :: string ans = "0";
  for(int i = n - 1; i >= 0; -- i) {

    int r = res, c = 0;
    for(int j = b ++; r; ++ j) {
      if(j > pos) {
        pos = j;
        ans += char(r % 10 + '0');
        r /= 10;
        continue;
      }
      c = (r % 10) + ans[j] - '0';
      ans[j] = c % 10 + '0';
      r = r / 10 + c / 10;
    }

    res = res - str[i] + '0';
  }
  for(int i = pos; i >= 0; -- i) {
    std :: cout << ans[i];
  }
  std :: cout << '\n';
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