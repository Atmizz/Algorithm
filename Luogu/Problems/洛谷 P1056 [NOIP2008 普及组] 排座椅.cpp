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
const int MaxN = 1020;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int m, n, k, l, d;
std :: vector <int> ansx, ansy;
struct Node {
  int id, val;
  friend bool operator < (Node a, Node b) {
    return a.val > b.val;
  }
}x[MaxN], y[MaxN];
int main() {
  m = read(), n = read(), k = read(), l = read(), d = read();
  for(int i = 1; i <= MaxN; ++ i) x[i].id = y[i].id = i;
  for(int i = 1; i <= d; ++ i) {
    int x_1 = read(), y_1 = read(), x_2 = read(), y_2 = read();
    if(x_1 == x_2) y[min(y_1, y_2)].val ++;
    else x[min(x_1, x_2)].val ++;
  }
  std :: sort(x + 1, x + 1 + MaxN);
  std :: sort(y + 1, y + 1 + MaxN);
  for(int i = 1; i <= k; ++ i)
    ansx.push_back(x[i].id);
  for(int i = 1; i <= l; ++ i)
    ansy.push_back(y[i].id);
  std :: sort(ansx.begin(), ansx.end());
  std :: sort(ansy.begin(), ansy.end());
  for(int i = 0; i < ansx.size(); ++ i)
    printf("%d ", ansx[i]); puts("");
  for(int i = 0; i < ansy.size(); ++ i)
    printf("%d ", ansy[i]);
  return 0;
}