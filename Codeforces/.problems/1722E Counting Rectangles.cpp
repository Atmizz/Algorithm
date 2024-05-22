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
const int N = 1010;
const int M = 1e5 + 20;
i64 sum[N][N];
int n, q;
void solve() {
  std :: cin >> n >> q;
  for(int i = 1; i <= N - 10; ++ i) {
    for(int j = 1; j <= N - 10; ++ j) {
      sum[i][j] = 0;
    }
  }
  for(int i = 1; i <= n; ++ i) {
    int h, w;
    std :: cin >> h >> w;
    sum[h][w] += h * w;
  }
  for(int i = 1; i <= N - 10; ++ i) {
    for(int j = 1; j <= N - 10; ++ j) {
      sum[i][j] = sum[i][j] + sum[i][j-1] + 
        sum[i-1][j] - sum[i-1][j-1];
    }
  }
  while(q --) {
    int hs, ws, hb, wb;
    std :: cin >> hs >> ws >> hb >> wb;
    // deb(sum[hb-1][wb-1]);
    // deb(sum[hs][ws]);
    std :: cout << sum[hb-1][wb-1] - sum[hs][wb-1] - sum[hb-1][ws] + sum[hs][ws] << '\n';
  }
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