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
  int n, m, len;
  std :: cin >> n >> m;
  std :: string str;
  std :: cin >> str;
  len = str.length();
  int sx = 1, sy = 1, x = 1, y = 1, maxx = 1, maxy = 1;
  for(int i = 0; i < len; ++ i) {
    if(str[i] == 'U') {
      if(x > 1) {
        x --;
      } else if(maxx < n) {
        maxx ++;
        sx ++;
      } else {
        break;
      }
    } else if(str[i] == 'D') {
      if(x < n) {
        x ++;
        maxx = std :: max(maxx, x);
      } else {
        break;
      }
    } else if(str[i] == 'L') {
      if(y > 1) {
        y --;
      } else if(maxy < m) {
        maxy ++;
        sy ++;
      } else {
        break;
      }
    } else {
      if(y < m) {
        y ++;
        maxy = std :: max(maxy, y);
      } else {
        break;
      }
    }
  }
  std :: cout << sx << ' ' << sy << '\n';
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