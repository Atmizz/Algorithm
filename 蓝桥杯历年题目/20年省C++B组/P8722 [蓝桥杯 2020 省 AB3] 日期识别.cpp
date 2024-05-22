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
const int MaxN = 0;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
std :: string str;
int main() {
  std :: cin >> str;
  int m, d;
  if(str[0] == 'J' && str[1] == 'a') m = 1;
  else if(str[0] == 'F') m = 2;
  else if(str[0] == 'M' && str[2] == 'r') m = 3;
  else if(str[1] == 'p') m = 4;
  else if(str[2] == 'y') m = 5;
  else if(str[1] == 'u' && str[2] == 'n') m = 6;
  else if(str[2] == 'l') m = 7;
  else if(str[1] == 'u') m = 8;
  else if(str[0] == 'S') m = 9;
  else if(str[0] == 'O') m = 10;
  else if(str[0] == 'N') m = 11;
  else m = 12;
  d = (str[3] - 48) * 10 + str[4] - 48;
  printf("%d %d", m, d);
  return 0;
}