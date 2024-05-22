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
int n, a[6];
int main() {
  n = read(); a[0] = 1;
  for(int i = 1; i <= 7; ++ i) a[i] = a[i-1] * 10;
  while(n --) {
    int x = read(), cnt = 0;
    std :: vector < int > ans;
    ans.clear();
    while(x) {
      ans.push_back(x % 10);
      x /= 10; cnt ++;
    }
    for(int i = 0; i < ans.size(); ++ i) {
      ans[i] *= a[i];
      if(ans[i] == 0) cnt --;
    }
    printf("%d\n", cnt);
    for(int i = 0; i < ans.size(); ++ i)
      if(ans[i] != 0) printf("%d ", ans[i]);
    puts("");
  }
  return 0;
}