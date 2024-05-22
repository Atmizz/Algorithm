#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define gc getchar()
typedef long long ll;
inline int read() {
  int s = 0, f = 1; char ch = gc;
  for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
  for(; ch >= '0' && ch <= '9'; ch = gc)
    s = (s << 1) + (s << 3) + (ch ^ 48);
  return s * f;
}
inline int abs(int a) {return a < 0 ? -a : a;}
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
const int MaxN = 1e4 + 20;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, g, k, ans;
struct Node {
  std :: string email;
  int score;
  friend bool operator < (Node a, Node b) {
    return a.score == b.score ? a.email < b.email : a.score > b.score;
  }
}a[MaxN];
int main() {
  n = read(); g = read(); k = read();
  for(int i = 1; i <= n; ++ i) {
    std :: cin >> a[i].email; a[i].score = read();
    if(a[i].score >= g) ans += 50;
    else if(a[i].score >= 60) ans += 20;
  } std :: sort(a + 1, a + 1 + n);
  std :: cout << ans << '\n';
  int cnt = 0;
  for(int i = 1; i <= n; ++ i) {
    if(a[i].score != a[i-1].score) cnt = i;
    if(cnt > k) break;
    std :: cout << cnt << ' ' << a[i].email << ' ' << a[i].score << '\n';
  }
  return 0;
}