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
const int MaxN = 10001;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int len, num[4];
char ex[4] = {'G', 'P', 'L', 'T'};
std :: string str;
int main() {
  std :: cin >> str; int len = str.length();
  for(int i = 0; i < len; ++ i) {
    if(str[i] == 'G' || str[i] == 'g') num[0] ++;
    else if(str[i] == 'P' || str[i] == 'p') num[1] ++;
    else if(str[i] == 'L' || str[i] == 'l') num[2] ++;
    else if(str[i] == 'T' || str[i] == 't') num[3] ++;
  }
  while(1) {
    if(!num[0] && !num[1] && !num[2] && !num[3]) break;
    for(int i = 0; i < 4; ++ i)
      if(num[i]) std :: cout << ex[i], num[i] --;
  }
  return 0;
}