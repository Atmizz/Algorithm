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
void printMonth(int x, bool flag) {
  if(x == 2) {
    if(flag) std :: cout << "29 ";
    else std :: cout << "28 ";
  }
  if(x == 1 || x == 3 || x == 5 || x == 7 || x == 8 || x == 10 || x == 12) std :: cout << "31 ";
  if(x == 4 || x == 6 || x == 9 || x == 11) std :: cout << "30 ";
}
int printDay(int month, int day, bool flag) {
  int sum = 0;
  if(month > 1) sum += 31;
  if(month > 2) sum += (flag == 1 ? 29 : 28);
  if(month > 3) sum += 31;
  if(month > 4) sum += 30;
  if(month > 5) sum += 31;
  if(month > 6) sum += 30;
  if(month > 7) sum += 31;
  if(month > 8) sum += 31;
  if(month > 9) sum += 30;
  if(month > 10) sum += 31;
  if(month > 11) sum += 30;
  return sum + day;
}
void printWeek(int year, int month, int day, bool flag) {
  int sumDay = 0;
  if(year > 400)
    sumDay += ((year / 400) * 146097), year %= 400;
  if(year > 100)
    sumDay += ((year / 100) * 36524), year %= 100;
  if(year > 4)
    sumDay += ((year / 4) * 1461), year %= 4;
  sumDay += (year - 1) * 365;
  sumDay %= 7;
  sumDay += printDay(month, day, flag);
  sumDay %= 7;
  // std :: cout << "sumday " << sumDay << " pintd " << printDay(month, day, flag) << '\n';
  if(sumDay == 0) sumDay = 7;
  printf("%d", sumDay);
}
int main() {
  std :: string str;
  std :: cin >> str;
  int year = (str[0] - 48) * 1000 + (str[1] - 48) * 100 + (str[2] - 48) * 10 + str[3] - 48;
  int month = (str[5] - 48) * 10 + str[6] - 48;
  int day = str[9] - 48 + (str[8] - 48) * 10;
  bool run = 0;
  if((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) run = 1;
  printf(run == 1 ? "366 " : "365 ");
  printMonth(month, run);
  std :: cout << printDay(month, day, run) << ' ';
  printWeek(year, month, day, run);
  return 0;
}