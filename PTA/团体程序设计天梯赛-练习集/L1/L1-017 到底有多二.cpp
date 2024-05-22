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
const int MaxN = 66;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
std :: string str;
double ans;
int main() {
  std :: cin >> str;
  double f1 = 1, f2 = 1, s = 0;
  int len = str.length();
  if(str[0] == '-') f1 = 1.5;
  if(str[len-1] % 2 == 0) f2 = 2.0;
  for(int i = 0; i < len; ++ i)
    if(str[i] == '2') s ++;
  if(str[0] == '-') len --;
  ans = 100.0 * (s / len) * f1 * f2;
  printf("%.2lf%%", ans);
  return 0;
}