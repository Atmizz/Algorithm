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
const int MaxN = 2e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n;
std :: unordered_set <std :: string> s;
char str[MaxN];
std :: string trans(int x) {
  std :: string ss = "";
  if(x == 0) return "0";
  while(x) {
    ss = char((x % 10) + 48) + ss;
    x /= 10;
  } return ss;
}
int main() {
  n = read(); scanf("%s", str);
  int x = 0, y = 0;
  s.insert(trans(x) + "," + trans(y));
  for(int i = 0; i < n; ++ i) {
    if(str[i] == 'R') x ++;
    else if(str[i] == 'L') x --;
    else if(str[i] == 'U') y ++;
    else y --;
    if(s.count(trans(x) + "," + trans(y))) {
      std :: cout << "Yes";
      return 0;
    }
    s.insert(trans(x) + "," + trans(y));
  } std :: cout << "No";
  return 0;
}