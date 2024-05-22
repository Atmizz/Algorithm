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
std :: string str;
int n, t;
int main() {
  n = read(); t = read();
  std :: cin >> str;
  while(t --)
    for(int i = 0; i < n; ++ i)
      if(str[i] == 'B' && str[i+1] == 'G') std :: swap(str[i], str[i+1]), ++ i;
  std :: cout << str;
  return 0;
}