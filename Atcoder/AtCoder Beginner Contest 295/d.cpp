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
const int MaxN = 1e6 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int len, a[10], cnt[10][2], ans;
int main() {
  std :: string str; std :: cin >> str; len = str.length();
  for(int i = 0; i <= 9; ++ i) cnt[i][0] ++;
  for(int i = 0; i < len; ++ i) {
    a[str[i]-48] ++;
    cnt[str[i]-48][(str[i]-48)%2] ++;
  }
  for(int i = 0; i <= 9; ++ i)

  return 0;
}