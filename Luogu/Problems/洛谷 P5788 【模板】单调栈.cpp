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
const int MaxN = 3e6+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
std :: stack <int> s;
int a[MaxN], f[MaxN], n;
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i) a[i] = read();
  for(int j = n; j >= 1; -- j) {
    while((!s.empty()) && a[s.top()] <= a[j]) s.pop();
    f[j] = s.empty() ? 0 : s.top();
    s.push(j);
  }
  for(int i = 1; i <= n; ++ i) printf("%d ", f[i]);
  return 0;
}