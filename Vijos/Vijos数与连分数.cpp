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
const int MaxN = 5e5 + 200;
const int Mod = 11;
const int INF = 2147483647;
std :: string str;
int len;
void Part_1() {
  double a = 0; int x = len - 1;double y = 0;
  while(str[x] != '[') {
    x --; int z = 1;
    if(str[x] >= '0' && str[x] <= '9') {
      while(str[x] >= '0' && str[x] <= '9') {
        y = y + (str[x] - '0') * z, z *= 10;
        x --;
      } printf("%.3lf\n", y);
      y = 1.000 / y;
    }
  } printf("%.3lf\n", 1.000 / y);
  a = y * 10000.0; int t = a, gcd = std :: __gcd(t, 10000);
  printf("%d/%d\n", t / gcd, 10000/gcd);
}
void Part_2() {
  int x, y = 1;
  double a = 0, b = 0, c;
  for(int i = 0; i < len; ++ i)
    if(str[i] == '/') x = i;
  for(int i = x - 1; i >= 0; -- i) a = a + (str[i] - '0') * y, y *= 10;
  y = 1;
  for(int i = len - 1; i > x; -- i) b = b + (str[i] - '0') * y, y *= 10;
  c = a / b; printf("[%.0lf;", c); c -= (int) c;
  int num = 2;
  c = 1.000 / c; 
  printf("%.0lf", c);
  c -= (int) c;
  while(c > 1e-4) {
    c = 1.000 / c; 
    printf(",%.0lf", c);
    c -= (int) c;
    num ++;
    if(num >= 100) break;
  } printf("]\n");
}
int main() {
  while(getline(std :: cin, str)) {
    len = str.length();
    if(str[0] == '[') Part_1();
    else Part_2();
  }
	return 0;
}