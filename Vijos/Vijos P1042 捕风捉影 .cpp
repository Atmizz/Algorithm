#include <bits/stdc++.h>
#define gc getchar()
#define ll long long
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
const int MaxN = 1e8+200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, Prime[MaxN], Is_Prime[MaxN], cnt;
bool Check(int x) {
  std :: string str = "";
  while(x) {
    str = char((x % 10) + '0') + str;
    x /= 10;
  } int len = str.length(); bool fg = 1;
  for(int i = 0; i < len / 2; ++ i)
    if(str[i] != str[len-i-1]) {fg = 0; break;}
  if(fg) return true;
  return false;
}
void Calc() {
  for(int i = 2; i <= m; ++ i) {
    if(!Is_Prime[i]) Prime[++cnt] = i;
    for(int j = 1; j <= cnt && Prime[j] * i <= m; ++ j) {
      Is_Prime[i * Prime[j]] = 1;
      if(!(i % Prime[j])) break;
    }
  }
}
int main() {
  n = read(); m = read(); 
  n = min(n, 1e7); m = min(m, 1e7); Calc();
  for(int i = n; i <= m; ++ i)
    if(!Is_Prime[i])
      if(Check(i)) printf("%d\n", i);
  return 0;
}