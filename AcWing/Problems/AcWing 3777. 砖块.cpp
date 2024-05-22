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
const int MaxN = 1e6+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int T, n, Str[205];
std :: string str;
std :: vector <int> ans1, ans2;
int main() {
  T = read();
  while(T -- ) {
    n = read(); std :: cin >> str;
    for(int i = 0; i < n; ++ i)
      if(str[i] == 'W') Str[i] = 0;
      else Str[i] = 1;
    ans1.clear();
    for(int i = 0; i < n - 1; ++ i)
      if(Str[i] == 1) Str[i] ^= 1, Str[i+1] ^= 1, ans1.push_back(i+1);
    // for(int i = 0; i < n; ++ i) printf("%d ", Str[i]); puts("");
    if(Str[n-1] == 0) {
      if(!ans1.size()) printf("0");
      else {
        printf("%d\n", ans1.size());
        for(int i = 0; i < ans1.size(); ++ i) printf("%d ", ans1[i]);
      }
      puts(""); continue;
    }
    for(int i = 0; i < n; ++ i)
      if(str[i] == 'W') Str[i] = 0;
      else Str[i] = 1;
    ans2.clear();
    for(int i = 0; i < n - 1; ++ i)
      if(Str[i] == 0) Str[i] ^= 1, Str[i+1] ^= 1, ans2.push_back(i+1);
    // for(int i = 0; i < n; ++ i) printf("%d ", Str[i]); puts("");
    if(Str[n-1] == 1) {
      if(!ans2.size()) printf("0");
      else {
        printf("%d\n", ans2.size());
        for(int i = 0; i < ans2.size(); ++ i) printf("%d ", ans2[i]);
      }
      puts(""); continue;
    } printf("-1\n");
  }
  return 0;
}