#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define gc getchar()
typedef long long ll;
inline ll read() {
  ll s = 0, f = 1; char ch = gc;
  for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
  for(; ch >= '0' && ch <= '9'; ch = gc)
    s = (s << 1) + (s << 3) + (ch ^ 48);
  return s * f;
}
inline int abs(int a) {return a < 0 ? -a : a;}
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
const int MaxN = 5e4 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
ll n, ans;
int main() {
  n = read();
  std :: vector <ll> last;
  for(int i = 1; i <= n; ++ i) {
    ll h = read();
    std :: vector <ll> res; res.push_back(h);
    while(h != 1ll) {
      h = sqrt(abs(h >> 1) + 1);
      res.push_back(h);
    }
    if(last.empty()) ans += res.size() - 1;
    for(int j = 0; j < res.size(); ++ j) {
      auto pos = std :: lower_bound(last.begin(), last.end(), res[j]);
      if(pos != last.end() && res[j] == *pos) {
        ans = ans + (res.size() - (pos - last.begin() + 1));
        break;
      }
    } last = res; std :: reverse(last.begin(), last.end());
  } printf("%lld", ans);
  return 0;
}