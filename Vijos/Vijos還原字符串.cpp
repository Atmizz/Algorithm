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
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n;
std :: string ans;
void Check(std :: string str1, std :: string str2, std :: string str3) {
  std :: string s = ""; int k;
  for(int i = n - 1; i >= 0; -- i) s += str1[i];
  k = (str2[0] - s[0] + 26) % 26;
  if((s[0] - k + 26 - 'a') % 26 == str3[0] - 'a') ans = s;
}
int main() {
	std :: string str1, str2, str3;
  n = read();
  std :: cin >> str1 >> str2 >> str3;
  Check(str1, str2, str3); Check(str2, str1, str3);
  Check(str1, str3, str2); Check(str2, str3, str1);
  Check(str3, str1, str2); Check(str3, str2, str1);
  std :: cout << ans;
	return 0;
}