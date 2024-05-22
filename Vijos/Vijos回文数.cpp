#include <bits/stdc++.h>
#define gc getchar()
#define ll long long
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
int n, a[MaxN], b[MaxN], ans;
std :: string str;
void dfs(int Num) {
//  std :: cout << Num << '\n';
//  for(int i = a[0]; i >= 1; -- i) std :: cout << a[i]; puts("");
  if(Num > 30 || ans == -1) {ans = -1; return ;}
  bool fg = 1;
  for(int i = 1; i <= a[0] / 2; ++ i)
    if(a[i] != a[a[0]-i+1]) {
     fg = 0; break;
    }
/*
123456
654321
12345
54321
*/


  if(fg) return;
  ans ++;
  for(int i = 1; i <= a[0]; ++ i)
    b[i] = a[a[0]-i+1];//, std :: cout << a[0]-i+1 << " " << i << " " << a[a[0]-i+1] << " " << b[i] <<'\n';
 /* 
  for(int i = 1; i <= a[0]; ++ i) std :: cout << a[i];
  
  puts("");

  for(int i = 1; i <= a[0]; ++ i) std :: cout << b[i];
  puts("");
*/
  int x = 0, c;
  for(int i = 1; i <= a[0]; ++ i) {
    c = a[i] + b[i] + x;
    a[i] = c % n; x = c / n;
  }
  if(x) a[0] ++, a[a[0]] = x;
  dfs(Num+1);
}
int main() {
  n = read(); std :: cin >> str;
  int len = str.length(); a[0] = len;
  if(n == 16) 
    for(int i = len - 1; i >= 0; -- i) {
      if(str[i] >= '0' && str[i] <= '9') a[len-i] = str[i] - '0';
      else a[len-i] = str[i] - 'A' + 10;
    } else
    for(int i = len-1; i >= 0; -- i)
      a[len-i] = str[i] - '0';
  dfs(1);
  if(ans == -1) printf("Impossible!");
  else printf("STEP=%d", ans);
	return 0;
}
/*
0123456
6543210

123456
654321
*/