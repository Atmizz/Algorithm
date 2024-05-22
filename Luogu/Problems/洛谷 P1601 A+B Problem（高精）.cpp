#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define gc getchar()
typedef long long ll;
inline ll read() {
  ll s = 0, f = 1; char ch = gc;
  for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
  for(; ch >= '0' && ch <= '9'; ch = gc)
  s = (s << 1) + (s << 3) + (ch ^ 48);
  return s * f;
}
inline int abs(int a) {return a < 0 ? -a : a;}
inline int min(int a, int b) {return a < b ? a : b;}
const int MaxN = 100;
const int Mod = 1e4;
const int INF = 2147483647;
int n, m;
struct HP {
  int p[540], len;
  HP() {
    memset(p, 0, sizeof p);
    len = 0;
  }
  void read() {
		std :: string str; std :: cin >> str;
		int l = str.length();
		if(l % 4)
			for(int i = 1; i <= 4 - l % 4; ++ i)
				str = "0" + str;
		//  std :: cout << str << '\n';
		l = str.length();
		for(int i = l-1; i > 0; i -= 4)
			p[++len] = str[i] - 48 + (str[i-1] - 48) * 10 + (str[i-2] - 48) * 100 + (str[i-3] - 48) * 1000;
  }
  void print() {
    printf("%d", p[len]);
    for(int i = len - 1; i >= 1; -- i)
      if(p[i] == 0) printf("0000");
      else {
        for(int k = 10; k * p[i] < Mod; k *= 10)
          printf("0");
        printf("%d", p[i]);
      }
  }
}a, b, ans;
HP operator + (const HP &a, const HP &b) {
  HP c; c.len = std :: max(a.len, b.len); int x = 0;
  for(int i = 1; i <= c.len; ++ i) {
    c.p[i] = a.p[i] + b.p[i] + x;
    x = c.p[i] / Mod, c.p[i] %= Mod;
  }
  if(x > 0) c.p[++c.len] = x;
  return c;
}
HP operator * (const HP &a, const HP &b) {
  HP c; c.len = std :: max(a.len, b.len);
  for(int i = 1; i <= a.len; ++ i) {
    int x = 0;
    for(int j = 1; j <= b.len; ++ j) {
      c.p[i+j-1] += a.p[i] * b.p[j] + x;
      x = c.p[i+j-1] / Mod;
      c.p[i+j-1] %= Mod;
    }
    c.p[i+b.len] = x;
  } c.len = a.len + b.len;
  while(c.p[c.len] == 0 && c.len > 1) c.len --;
  return c;
}
HP operator - (const HP &x, const HP &y) {
  HP c, a = x, b = y; c.len = std :: max(a.len, b.len);
  for(int i = 1; i <= a.len; ++ i) {
    if(a.p[i] < b.p[i]) {
      a.p[i+1] --;
      a.p[i] += Mod;
    }
    c.p[i] += (a.p[i] - b.p[i]);
  }
  while(c.p[c.len] == 0 && c.len > 1) c.len --;
  return c;
}
int main() {
  a.read(); b.read();
	ans = a + b; ans.print();
  return 0;
}