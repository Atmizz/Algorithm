#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cstdlib>
#include <map>
#include <set>
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
const int MaxN = 1e6+300;
const int Mod = 1e9;
const int INF = 2147483647;
int n;
int main() {
  n = read();
  if(n == 1) {printf("-1"); return 0;}
  printf("%d %d %d", n, n+1, n * (n + 1));
  /*
  for(int i = 1; i * n <= Mod; ++ i) {
    int x = i * n;
    int sum = 2 * x / n - 1;// printf("x : %d sum :%d\n",x, sum);
    for(int j = 2; j <= sqrt(x); ++ j)
      if(x % j == 0 && sum - (x / j) > 0) {
        int sum1 = sum - (x / j);// printf("sum1 : %d\n", sum1);
        if(sum1 == 1 || sum == x / j) continue; 
        if(x % sum1 == 0) {printf("%d %d %d", min(j, x/sum1), max(j, x/sum1), x); return 0;}
      }
  } printf("-1");
  */
  return 0;
}