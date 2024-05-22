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
const int MaxN = 1e4+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
std :: string str;
int len;
ll ans[MaxN], b, x;
int main() {
  std :: cin >> str; b = read();
  len = str.length();
  for(int i = 0; i < len; ++ i) {
    ans[i] = ll((x * 10 + str[i] - 48) / b);
    x = ll((x * 10 + str[i] - 48) % b);
  } x = 0;
  while(ans[x] == 0 && x < len - 1) x ++;
  for(int i = x; i < len; ++ i)
    printf("%d", ans[i]);
  return 0;
}