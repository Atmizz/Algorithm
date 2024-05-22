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
std :: string str;
int main() {
  n = read();
  while(n --) {
    getline(std :: cin, str); int len = str.length(), pos;
    for(int i = 0; i < len; ++ i)
      if(str[i] == ',') {
        pos = i; break;
      }
    bool fg1 = 1, fg2 = 1;
    if(str[pos-1] == 'g' && str[pos-2] == 'n' && str[pos-3] == 'o') fg1 = 0;
    if(str[len-2] == 'g' && str[len-3] == 'n' && str[len-4] == 'o') fg2 = 0;
    if(fg1 || fg2) printf("Skipped\n");
    else {
      int cnt = 0; len --;
      while(cnt < 3) {
        if(str[len] == ' ') cnt ++;
        len --;
      }
      for(int i = 0; i <= len; ++ i) std :: cout << str[i];
      printf(" qiao ben zhong.\n");
    }
  }
  return 0;
}