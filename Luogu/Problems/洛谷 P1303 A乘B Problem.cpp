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
const int MaxN = 1e4;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
std :: string str1, str2;
int a[MaxN], b[MaxN], ans[MaxN];
int main() {
  std :: cin >> str1 >> str2;
  int len1 = str1.length(), len2 = str2.length(), len = len1 + len2, x = 0;
  for(int i = 0; i < len1; ++ i) a[len1-i] = str1[i] - '0';
  for(int i = 0; i < len2; ++ i) b[len2-i] = str2[i] - '0';
  for(int i = 1; i <= len1; ++ i) {
    x = 0;
    for(int j = 1; j <= len2; ++ j) {
      ans[i+j-1] += a[i] * b[j] + x;
      x = ans[i+j-1] / 10;
      ans[i+j-1] %= 10;
    }
    ans[i+len2] = x;
  }
  while(ans[len] == 0 && len > 1) len --;
  for(int i = len; i >= 1; -- i) printf("%d", ans[i]);
  return 0;
}