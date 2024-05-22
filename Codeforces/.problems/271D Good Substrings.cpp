#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define ull unsigned long long
#define PII std :: pair<int, int>
#define endl '\n'
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const ull base = 131;
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1800;
std :: string str, p;
bool a[27];
int k;
void solve() {
  std :: cin >> str >> p >> k;
  for(int i = 0; i < 26; ++ i) {
    a[i] = p[i] - '0';
  }
  int n = str.length();
  std :: set <ull> s;
  for(int i = 0; i < n; ++ i) {
    ull x = 0; int m = 0;
    for(int j = i; j < n; ++ j) {
      x = x * base + str[j] - 'a' + 1;
      if(!a[str[j]-'a']) m ++;
      if(m > k) break;
      if(s.find(x) == s.end()) {
        s.insert(x);
      }
    }
  }
  std :: cout << s.size();
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