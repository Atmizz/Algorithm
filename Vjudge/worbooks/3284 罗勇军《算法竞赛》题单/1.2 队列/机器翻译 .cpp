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
int n, m, ans;
bool vis[MaxN];
std :: queue <int> q;
int main() {
  m = read(); n = read();
  for(int i = 1; i <= n; ++ i) {
    if(q.size() > m) vis[q.front()] = 0, q.pop();
    int x = read();
    if(vis[x]) continue;
    ans ++; vis[x] = 1; q.push(x);
  } printf("%d", ans);
  return 0;
}