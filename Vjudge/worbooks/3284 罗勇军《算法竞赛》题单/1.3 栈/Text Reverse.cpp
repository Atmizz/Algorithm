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
const int MaxN = 1010;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n;
char ch[MaxN];
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i) {
    memset(ch, 0, sizeof ch);
    gets(ch); int len = strlen(ch);
    std :: stack <char> s;
    for(int j = 0; j < len; ++ j) {
      if(ch[j] == ' ') {
        while(s.size()) std :: cout << s.top(), s.pop();
        std :: cout << ' ';
      } else s.push(ch[j]);
    } while(s.size()) std :: cout << s.top(), s.pop();
    puts("");
  }
  return 0;
}