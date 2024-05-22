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
int a, b;
int main() {
  a = read(), b = read();
  if((a >= 0 && a <= 11) || (a == 0 && b == 0) || (a == 12 && b == 0)) {
    printf("Only ");
    if(a < 10) std :: cout << '0';
    std :: cout << a << ':';
    if(b < 10) std :: cout << '0';
    std :: cout << b;
    printf(".  Too early to Dang.");
  } else {
    if(b) a ++; a -= 12;
    for(int i = 1; i <= a; ++ i)
      std :: cout << "Dang";
  }
  return 0;
}