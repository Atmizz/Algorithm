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
const int MaxN = 10100;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m;
std :: vector <int> ans;
std :: priority_queue <int, std :: vector <int>, std :: less <int> > q;
int f(int a, int b, int c, int x) {
  return a * x * x + b * x + c;
}
int main() {
  n = read(); m = read();
  int a = read(), b = read(), c = read();
  for(int i = 1; i <= m; ++ i)
    q.push(f(a, b, c, i));
  for(int i = 2; i <= n; ++ i) {
    a = read(), b = read(), c = read();
    for(int j = 1; j <= m; ++ j) {
      int y = f(a, b, c, j);
      if(y < q.top()) q.pop(), q.push(y);
      else break;
    }
  }
  while(q.size()) ans.push_back(q.top()), q.pop();
  for(int i = m-1; i >= 0; -- i)
    std :: cout << ans[i] << ' ';
  return 0;
}