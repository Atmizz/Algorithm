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
void solve() {
  std :: string str;
  std :: cin >> str;
  int n = str.length();
  str = '!' + str;
  std :: vector <int> sum0(n+2), sum1(n+2);
  for(int i = 1; i <= n; ++ i) {
    sum0[i] = sum0[i-1] + (str[i] == '0');
    sum1[i] = sum1[i-1] + (str[i] == '1');
  }
  sum0[n+1] = sum0[n];
  sum1[n+1] = sum1[n];
  std :: vector <int> pos;
  pos.push_back(0);
  for(int i = 1; i <= n; ++ i) {
    if(str[i] == '0') {
      pos.push_back(i);
    }
  }
  pos.push_back(n+1);
  int m = pos.size();

  auto check = [=](int x) -> bool {
    for(int i = 0; i < m - 1; ++ i) {
      int j = std :: min(i + x + 1, m - 1);
      // deb(i); deb(j); deb(pos[j])
      // deb(sum1[pos[i]] + sum1[n+1] - sum1[pos[j]]);
      if(sum1[pos[i]] + sum1[n+1] - sum1[pos[j]] <= x) {
        return true;
      }
    }
    return false;
  };
  int l = 0, r = n, ans;
  while(l <= r) {
    int mid = (l + r) >> 1;
    // deb(mid)
    if(check(mid)) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
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