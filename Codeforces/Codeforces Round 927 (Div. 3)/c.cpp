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
const int N = 2e5 + 20;
int n, m, a[N];
std :: string s;
void solve() {
  std :: cin >> n >> m;
  for(int i = 1; i <= n; ++ i) {
    std :: cin >> a[i];
  }
  std :: cin >> s;
  int l = 1, r = n, res;
  std :: vector <int> ans;
  for(int i = 0; i < n - 1; ++ i) {
    if(s[i] == 'L') l ++;
    else r --;
  }
  res = a[l] % m;
  ans.push_back(res);
  for(int i = n - 2; i >= 0; -- i) {
    if(s[i] == 'L') {
      res = res * a[--l] % m;
    } else {
      res = res * a[++r] % m;
    }
    ans.push_back(res);
  }
  for(int i = n - 1; i >= 0; -- i) {
    std :: cout << ans[i] << ' ';
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