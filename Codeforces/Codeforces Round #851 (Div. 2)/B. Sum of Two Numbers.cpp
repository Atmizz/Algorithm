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
const int MaxN = 1e6+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n;
void devideInteger(int x) {
  std :: string str = "";
  int ans[2] = {0}, flag = 0;
  while(x) {
    str = char(x % 10 + 48) + str;
    x /= 10;
  }
  for(int i = 0; i < str.length(); ++ i)
    if((str[i] - '0') % 2) ans[flag] = ans[flag] * 10 + (str[i] - 48) / 2 + 1, flag ^= 1, ans[flag] = ans[flag] * 10 + (str[i] - 48) / 2;
    else ans[0] = ans[0] * 10 + (str[i] - '0') / 2, ans[1] = ans[1] * 10 + (str[i] - '0') / 2;
  printf("%d %d\n", ans[0], ans[1]);
}
int main() {
  n = read();
  while(n --) {
    int x = read();
    if(x % 2) devideInteger(x);
    else printf("%d %d\n", x / 2, x / 2);
  }
  return 0;
}