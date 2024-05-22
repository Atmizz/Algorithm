#include <bits/stdc++.h>
#define gc getchar()
typedef long long ll;
const int MaxN = 1e6 + 200;
inline int abs(int x) {return x < 0 ? -x : x;}
inline max(int a, int b) {return a > b ? a : b;}
inline min(int a, int b) {return a < b ? a : b;}
inline int read() {
  int s = 0, f = 1; char ch = gc;
  for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
  for(; ch >= '0' && ch <= '9'; ch = gc)
      s = (s << 1) + (s << 3) + (ch ^ 48);
  return s * f;
}
int main() {
	while(1) {
		char ch[205];
		gets(ch);
		if(ch[0] == '0' && (int(ch[1]) == 13)) break;
	}
}