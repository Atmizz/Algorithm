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
const int MaxN = 1100;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m;
struct Node {
  std :: string id;
  int cnt1, cnt2;
  friend bool operator < (Node a, Node b) {
    return a.cnt1 < b.cnt1;
  }
}t[MaxN];
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i) {
    std :: cin >> t[i].id;
    t[i].cnt1 = read(); t[i].cnt2 = read();
  } std :: sort(t + 1, t + 1 + n);
  m = read();
  for(int i = 1; i <= m; ++ i) {
    int x = read(); std :: cout << t[x].id;
    printf(" %d\n", t[x].cnt2);
  }
  return 0;
}