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
const int N = 34444;
int a[N];
bool check(int x, int y) {
  int s[10] = {0}, t[10] = {0};
  while(x) {
    s[x % 10] ++;
    x /= 10;
  }
  while(y) {
    t[y % 10] ++ ;
    y /= 10;
  }
  for(int i = 0; i < 10; ++ i) {
    if(s[i] != t[i]) return false;
  }
  return true;
}
void solve() {
  for(int i = 1000; i <= 3333; ++ i) {
    a[i] =  i * i;
  }
  for(int i = 1000; i <= 3333; ++ i) {
    int cnt = 0;
    for(int j = i + 1; j <= 3333; ++ j) {
      if(i != j && check(a[i], a[j])) {
        std :: cout << i << ' ' << j << ' ' << a[i] << ' ' << a[j] << '\n';
        cnt ++;
      }
    }
    if(cnt >= 6) {
      std :: cout << "OKOK\n";
      break;
    }
  }
}
int main() {
  //freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);
  std :: ios :: sync_with_stdio(false);
  std :: cin.tie(0);
  std :: cout.tie(0);
  int T = 1;
  //std :: cin >> T; 
  while(T --) solve();
  return 0;
}