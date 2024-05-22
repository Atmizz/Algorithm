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
int main() {
  int T = read();
  while(T --) {
    int n = read(), cnt = 3;
    if(n == 1) std :: cout << "1\n";
    else if(n == 2) std :: cout << "2 1\n";
    else {
      std :: vector <int> a(n+1);
      a[1] = 2; a[n] = 3; a[(n+1)>>1] = 1;
      for(int i = 1; i <= n; ++ i)
        if(!a[i]) a[i] = ++ cnt;
      for(int i = 1; i <= n; ++ i) std :: cout << a[i] << ' ';
      puts("");
    }
  }
  return 0;
}