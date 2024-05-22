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
const int MaxN = 1200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n;
int main() {
  n = read();
  std :: string str;
  std :: cin >> str;
  for(int i = 0; i < n; ++ i)
    if(str[i] == '.') {
      if(str[i-1] != 'L' && str[i+1] != 'L') std :: cout << 'C';
      else std :: cout << '.';
    } else std :: cout << str[i];
  return 0;
}