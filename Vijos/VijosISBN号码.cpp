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
int main() {
	std :: cin >> str; int ans = 0, cnt = 1, len = str.length();
  for(int i = 0; i < len - 1; ++ i)
    if(str[i] != '-') ans += cnt * (str[i] - '0'), cnt ++;
  ans %= 11; char ch;
  if(ans == 10) ch = 'X';
  else ch = char(ans + '0');
  if(ch == str[len-1]) printf("Right");
  else {
    std :: cout << str[0] << '-';
    for(int i = 2; i <= 4; ++ i) std :: cout << str[i];
    std :: cout << '-';
    for(int i = 6; i <= 10; ++ i) std :: cout << str[i];
    std :: cout << '-'; std :: cout << ch;
  }
	return 0;
}