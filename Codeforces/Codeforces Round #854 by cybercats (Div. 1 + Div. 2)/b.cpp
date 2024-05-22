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
const int MaxN = 110;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, t, minn, maxx, minpos, maxpos;
int main() {
  t = read();
  while(t --) {
    n = read(); minn = INF; maxx = -INF; std :: vector <int> a(n);
    for(int i = 0; i < n; ++ i) a[i] = read();
  
    if(std :: count(a.begin(), a.end(), a[0]) == n) {
      std :: cout << 0 << '\n';
      continue;
    }
    if(std :: count(a.begin(), a.end(), 1) > 0) {
      std :: cout << -1 << '\n';
      continue;
    }

    std :: vector <std :: pair<int, int> > ans;
    while(1) {
      maxx = -INF, minn = INF;
      for(int i = 0; i < n; ++ i) {
        if(a[i] > maxx) maxx = a[i], maxpos = i;
        if(a[i] < minn) minn = a[i], minpos = i;
      }
      // std :: cout << minn << ' ' << maxx << '\n';
      if(minn == maxx) break;
      a[maxpos] = (int)ceil((double)maxx / (double)minn);
      ans.push_back(std :: make_pair(maxpos + 1, minpos + 1));
    } std :: cout << ans.size() << '\n';
    for(auto u : ans)
      printf("%d %d\n", u.first, u.second);
  }
  return 0;
}