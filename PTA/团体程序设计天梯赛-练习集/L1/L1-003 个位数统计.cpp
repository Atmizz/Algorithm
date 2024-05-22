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
const int MaxN = 1010;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
std :: string str;
int cnt[10];
int main() {
  std :: cin >> str;
  for(int i = 0; i < str.length(); ++ i)
    cnt[str[i]-48] ++;
  for(int i = 0; i <= 9; ++ i)
    if(cnt[i]) std :: cout << i << ':' << cnt[i] << '\n';
  return 0;
}