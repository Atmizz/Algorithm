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
const int MaxN = 3e6+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int T, n, q, a[MaxN][70], cnt[MaxN], num;
int Get_(char x) {
  if(x >= 'A' && x <= 'Z') return x - 'A';
  else if(x >= 'a' && x <= 'z') return x - 'a' + 26;
  else return x - '0' + 52;
}
void Insert(std :: string str) {
  int p = 0, len = str.length();
  for(int i = 0; i < len; ++ i) {
    int x = Get_(str[i]);
    if(!a[p][x]) a[p][x] = ++ num;
    p = a[p][x];
    cnt[p] ++;
  }
}
int Find(std :: string str) {
  int p = 0, len = str.length();
  for(int i = 0; i < len; ++ i){
      int x = Get_(str[i]);
      if(!a[p][x]) return 0;
      p = a[p][x];
  }
  return cnt[p];
}
int main() {
  T = read();
  while(T --) {
    for(int i = 0; i <= num; ++ i)
      for(int j = 0; j <= 68; ++ j)
        a[i][j] = 0;
    for(int i = 0; i <= num; ++ i) cnt[i] = 0;
    num = 0; n = read(); q = read();
    for(int i = 1; i <= n; ++ i) {
      std :: string str;
      std :: cin >> str; Insert(str);
    }
    for(int i = 1; i <= q; ++ i) {
      std :: string str;
      std :: cin >> str;
      printf("%d\n", Find(str));
    }
  }
  return 0;
}