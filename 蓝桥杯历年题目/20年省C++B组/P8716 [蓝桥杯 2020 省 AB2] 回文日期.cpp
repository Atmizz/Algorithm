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
bool fg1, fg2;
// 1 3 5 7 8 10 12
bool check(int year, int month, int day) {
  if(month == 0 || month > 12 || day == 0 || day > 31) return false;
  if(month == 2) {
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
      if(day > 29) return false;
    } else 
      if(day > 28) return false;
  }
  if((month == 4 || month == 6 || month == 9 || month == 11) && day == 31) return false;
  return true;
}
std :: string makeup(int x) {
  std :: string res = "";
  while(x) res = char(x%10+48) + res, x /= 10;
  if(res.length() == 3) res = "0" + res;
  return res;
}
void check1(int year) {
  int month = (year % 10) * 10 + (year % 100) / 10;
  int day = year / 1000 + ((year / 100) % 10) * 10;
  std :: string s1 = makeup(year), s2 = makeup(month*100+day), s3 = s2;
  std :: reverse(s2.begin(), s2.end());
  if(s1 != s2) return;
  if(!check(year, month, day)) return;
  std :: cout << s1 << s3 << '\n'; fg1 = 1;
}
void check2(int year) {
  if(year / 1000 != (year % 100) / 10 || (year % 1000) / 100 != year % 10) return ;
  int month = (year % 10) * 10 + (year % 100) / 10;
  int day = year / 1000 + ((year / 100) % 10) * 10;
  std :: string s1 = makeup(year), s2 = makeup(month*100+day), s3 = s2;
  std :: reverse(s2.begin(), s2.end());
  if(s1 != s2) return ;
  if(!check(year, month, day)) return ;
  std :: cout << s1 << s3 << '\n'; fg2 = 1;
}
int main() {
  std :: cin >> str;
  int year = (str[0] - 48) * 1000 + (str[1] - 48) * 100 + (str[2] - 48) * 10 + str[3] - 48;
  for(int i = year+1; i <= 9999; ++ i) {
    if(!fg1) check1(i);
    if(!fg2) check2(i);
    if(fg1 && fg2) break;
  }
  return 0;
}