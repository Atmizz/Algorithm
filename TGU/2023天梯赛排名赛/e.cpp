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
int n;
void operator2(int a, int b) {
  std :: string str = "";
  int cnt[10] = {0}, vis[10] = {0};
  while(b) {
    str = char(b%10 + 48) + str;
    b /= 10;
  }
  while(a) {
    str = char(a%10 + 48) + str;
    a /= 10;
  }
  int len = str.length();
  for(int i = 0; i < len; ++ i)
    cnt[str[i]-48] ++;
  for(int i = 0; i < len; ++ i)
    if(!vis[str[i]-48]) {
      std :: cout << str[i] << cnt[str[i]-48];
      vis[str[i]-48] = 1;
    }
}
void operator3(int s) {
  int h = 0, mi = 0;
  mi = s / 60; h = mi / 60;
  s = s % 60; mi %= 60; h %= 24;
  // std :: cout << h << ' ' << mi << ' ' << s << '\n';
  if(h) std :: cout << h;
  if((h && !mi) || mi) std :: cout << mi;
  std :: cout << s;
}
int main() {
  n = read();
  while(n --) {
    std :: string op; int a, b;
    std :: cin >> op; a = read(), b = read();
    std :: cout << a << op << b << '=';
    if(op == "!!") {
      printf("%d%d", a+b, abs(a-b));
    } else if(op == "??") {
      operator2(a, b);
    } else {
      operator3(a + b);
    }
    puts("");
  }
  return 0;
}