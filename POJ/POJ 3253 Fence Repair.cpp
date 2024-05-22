#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cstdlib>
#include <map>
#include <set>
#define gc getchar()
typedef long long LL;
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
const int MaxN = 1e6+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n;
LL ans = 0ll;
std :: priority_queue <int, std :: vector <int>, std :: greater <int> > q;
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i) {
    int x = read(); q.push(x);
  }
  if(q.size() == 1) ans += q.top(), q.pop();
  while(q.size() > 1) {
    int a = q.top(); q.pop();
    int b = q.top(); q.pop();
    ans += (a+b); q.push(a+b);
  } printf("%lld\n", ans);
  return 0;
}