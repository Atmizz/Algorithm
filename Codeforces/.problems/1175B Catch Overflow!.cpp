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
const int N = 1e5 + 20;
std :: string str[N];
int x[N], n;
void solve() {
  std :: cin >> n;
  i64 ans = 0;
  i64 inf = 4294967295LL;
  for(int i = 1; i <= n; ++ i) {
    std :: cin >> str[i];
    if(str[i] == "for") {
      std :: cin >> x[i];
    }
  }
  i64 maxx = 1LL << 32;
  std ::  stack <i64> s;
  s.push(1);
  for(int i = 1; i <= n; ++ i) {
    if(str[i] == "for") {
      s.push(std :: min(s.top() * x[i], maxx));
    } else if(str[i] == "add") {
      ans += s.top();
      if(ans > inf) break;
    } else {
      s.pop();
    }
  }

  if(ans <= inf) {
    std :: cout << ans;
  } else {
    std :: cout << "OVERFLOW!!!";
  }
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