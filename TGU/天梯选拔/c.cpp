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
char str[MaxN];
int x, y, z, pos1, pos2;
int f(int x, int y, int z, char ch) {
  if(ch == '+') {
    if(x == -1) return z - y;
    else if(y == -1) return z - x;
    else return x + y;
  } else {
    if(x == -1) return y + z;
    else if(y == -1) return x - z;
    else return x - y;
  }
}
int main() {
  gets(str); int len = strlen(str);
  char ch = '*';
  for(int i = 0; i < len; ++ i)
    if(str[i] == '-' || str[i] == '+') pos1 = i, ch = str[i];
    else if(str[i] == '=') pos2 = i;
  // std :: cout << pos1 << ' ' << pos2 << '\n';
  for(int i = 0; i < pos1; ++ i)
    if(str[i] == ' ') continue;
    else if(str[i] == '?') {
      x = -1; break;
    } else x = x * 10 + str[i] - 48;
  for(int i = pos1 + 1; i < pos2; ++ i)
    if(str[i] == ' ') continue;
    else if(str[i] == '?') {
      y = -1; break;
    } else y = y * 10 + str[i] - 48;
  for(int i = pos2 + 1; i < len; ++ i)
    if(str[i] == ' ') continue;
    else if(str[i] == '?') {
      z = -1; break;
    } else z = z * 10 + str[i] - 48;
  // std :: cout << x << ' ' << y << ' ' << z << '\n';
  printf("%d", f(x, y, z, ch));
  return 0;
}
/*
3      - ？ =    2

*/