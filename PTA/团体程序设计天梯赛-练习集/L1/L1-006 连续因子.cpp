#include <bits/stdc++.h>
#include <cmath>
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
const int MaxN = 1e6 + 300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n;
std :: vector <int> ans;
int main() {
  n = read(); int nn = sqrt(n);
  // std :: cout << nn;
  for(int i = 2; i <= nn; ++ i) {
    int cnt = i, m = n;
    std :: vector <int> x;
    while(m % cnt == 0) x.push_back(cnt), m /= cnt, cnt ++;
    if(x.size() > ans.size()) ans = x;
  }
  if(ans.size() == 0) ans.push_back(n);
  int sz = ans.size();
  printf("%d\n%d", sz, ans[0]);
  for(int i = 1; i < sz; ++ i) printf("*%d", ans[i]);
  return 0;
}