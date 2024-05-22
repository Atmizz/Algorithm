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
const int N = 3e5 + 20;
int n, k;
struct Node {
  int t, b;
  friend bool operator < (Node a, Node b) {
    return a.b == b.b ? a.t > b.t : a.b > b.b;
  }
}a[N];
void solve() {
  std :: cin >> n >> k;
  for(int i = 1; i <= n; ++ i) {
    std :: cin >> a[i].t >> a[i].b;
  }
  std :: sort(a + 1, a + 1 + n);
  std :: priority_queue <int, std :: vector <int>, std :: greater<int> > q;
  i64 sum = 0, ans = 0;
  for(int i = 1; i <= n; ++ i) {
    if(q.size() == k) {
      if(q.top() < a[i].t) {
        sum = sum - q.top() + a[i].t;
        q.pop(); q.push(a[i].t);
      }
    } else {
      q.push(a[i].t);
      sum += a[i].t;
    }
    ans = std :: max(ans, sum * a[i].b);
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