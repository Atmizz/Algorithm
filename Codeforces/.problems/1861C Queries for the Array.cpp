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
// const int N = ;
void solve() {
  std :: string str;
  std :: cin >> str;
  int n = str.length();
  int minnus = 0, pos = 0, maxxsd = 0;
  for(int i = 0; i < n; ++ i) {
    if(str[i] == '+') {
      pos ++;
    } else if(str[i] == '-') {
      pos --;
      maxxsd = std :: min(maxxsd, pos);
      if(pos < minnus) {
        minnus = 0;
      }
    } else if(str[i] == '1') {
      maxxsd = std :: max(maxxsd, pos);
    } else {
      if(pos < 2) {
        std :: cout << "NO\n";
        return ;
      }
      if(minnus == 0 || minnus > pos) {
        minnus = pos;
      }
    }
    if(minnus <= maxxsd && minnus != 0) {
      std :: cout << "NO\n";
      return ;
    }
  }
  std :: cout << "YES\n";
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