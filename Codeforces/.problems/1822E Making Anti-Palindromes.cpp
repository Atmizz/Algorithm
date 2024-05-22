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
int n;
std :: string str;
void solve() {
  std :: cin >> n >> str;
  if(n & 1) {
    std :: cout << -1 << '\n';
    return ;
  }
  std :: map <char, int> m;
  for(int i = 0; i < n; ++ i) {
    m[str[i]] ++ ;
    if(m[str[i]] > (n >> 1)) {
      std :: cout << -1 << '\n';
      return ;
    }
  }
  int cnt = 0, c[30] = {0};
  for(int i = 0; i * 2 < n; ++ i) {
    if(str[i] == str[n-i-1]) {
      cnt ++;
      c[str[i]-'a'] ++;
    }
  }
  for(int i = 0; i < 26; ++ i) {
    if(c[i] * 2 >= cnt) {
      std :: cout << c[i] << '\n';
      return ;
    }
  }
  std :: cout << ((cnt + 1) >> 1) << '\n';
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