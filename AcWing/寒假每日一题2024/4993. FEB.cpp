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
  str = "0" + str;
  int odd = 0, even = 0, ans = 0, fixed = 0;
  if(str[1] == 'F' && )
  for(int i = 1; i <= n; ++ i) {
    if(str[i] == str[i-1] && str[i] != 'F') {
      fixed ++;
      continue;
    }
    if(str[i] == 'F') {
      int cnt = 0, j = i;
      while(str[j] == 'F') {
        cnt ++;
        j ++;
      }
      if()
      i = j - 1;
    }
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