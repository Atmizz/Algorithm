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
const int N = 110;
const int M = 2e5 + 20;
int n, a[N], f[M];
void solve() {
  std :: cin >> n;
  int sum = 0;
  for(int i = 1; i <= n; ++ i) {
    std :: cin >> a[i];
    sum += a[i];
  }
  if(sum & 1) {
    std :: cout << 0;
    return ;
  }
  f[0] = 1;
  for(int i = 1; i <= n; ++ i) {
    for(int j = sum; j >= a[i]; -- j) {
      f[j] |= f[j-a[i]];
    }
  }
  bool flag = f[sum/2];
  if(!flag) {
    std :: cout << 0;
    return ;
  }
  std :: cout << 1 << '\n';
  int ans, minn = INF;
  for(int i = 1; i <= n; ++ i) {
    int cnt = 0;
    while(!(a[i] & 1)) {
      a[i] /= 2;
      cnt ++;
    }
    if(cnt < minn) {
      minn = cnt;
      ans = i;
    }
  }
  std :: cout << ans;
}
int main() {
  //freopen("1.in", "r", stdin);
  //freopen("1.out", "w", stdout);
  std :: ios :: sync_with_stdio(false);
  std :: cin.tie(0);
  std :: cout.tie(0);
  int T = 1;
  //std :: cin >> T; 
  while(T --) solve();
  return 0;
}