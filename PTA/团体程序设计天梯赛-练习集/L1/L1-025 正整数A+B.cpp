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
int cnt = 0;
int calc(int l, int r) {
  int sum = 0;
  for(int i = l; i <= r; ++ i)
    sum = sum * 10 + str[i] - 48;
  return sum;
}
int main() {
  getline(std :: cin, str);
  int len = str.length();
  int a1 = -1, a2 = -1, b1 = -1, b2 = -1, i = 0;
  for(; i < len; ++ i)
    if(isdigit(str[i])) {
      if(a1 == -1) a1 = i;
    } else if(str[i] == ' ') {
      a2 = i - 1; break;
    }
  b1 = i + 1, b2 = len - 1;
  bool flag1 = 1, flag2 = 1;
  int x1 = 0, x2 = 0;
  for(int j = a1; j <= a2; ++ j)
    if(!isdigit(str[j])) {
      flag1 = 0; break;
    }
  for(int j = b1; j <= b2; ++ j)
    if(!isdigit(str[j])) {
      flag2 = 0; break;
    }
  if(flag1) x1 = calc(a1, a2);
  if(flag2) x2 = calc(b1, b2);
  if(a1 > 0 || x1 > 1000|| x1 == 0) flag1 = 0;
  if(flag2 && (x2 > 1000 || x2 == 0)) flag2 = 0;
  if(flag1) std :: cout << x1;
  else std :: cout << "?";
  std :: cout << " + ";
  if(flag2) std :: cout << x2;
  else std :: cout << "?";
  std :: cout << " = ";
  if(flag1 && flag2) std :: cout << x1 + x2;
  else std :: cout << "?";
  return 0;
}