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
const int MaxN = 1e6 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
std :: string str;
int T;
int main() {
  T = read();
  while(T --) {
    std :: cin >> str;
    int len = str.length(), cnt = 0, flag = 0, num[27] = {0};
    for(int i = 0; i < len; ++ i)
      if(str[i] != str[len-i-1]) {
        flag = 1; break;
      } else
        if(!num[str[i]-'a']) num[str[i]-'a'] ++, cnt ++;
    if(flag == 0 && cnt == 1) printf("-1\n");
    else if(flag == 0 && cnt > 1) printf("%d\n", len - 1);
    else printf("%d\n", len);
  }
  return 0;
}