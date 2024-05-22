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
std :: string str;
int len;
std :: stack <int> s;
int main() {
  std :: cin >> str; len = str.length();
  for(int i = 0; i < len; ++ i) {
    if(str[i] >= '0' && str[i] <= '9') {
      int x = 0;
      while(str[i] >= '0' && str[i] <= '9') x = x * 10 + str[i] - 48, i ++;
      s.push(x);
    } else if(str[i] == '+') {
      int x = s.top(), y; s.pop(); y = s.top(); s.pop();
      s.push(x + y);
      // std :: cout << x << " " << y << " " << x + y << '\n';
    } else if(str[i] == '-') {
      int x = s.top(), y; s.pop(); y = s.top(); s.pop();
      s.push(y - x);
      // std :: cout << x << " " << y << " " << y - x << '\n';
    } else if(str[i] == '*') {
      int x = s.top(), y; s.pop(); y = s.top(); s.pop();
      s.push(y * x);
      // std :: cout << x << " " << y << " " << x * y << '\n';
    } else if(str[i] == '/') {
      int x = s.top(), y; s.pop(); y = s.top(); s.pop();
      s.push(y / x);
    }
  } printf("%d", s.top());
  return 0;
}