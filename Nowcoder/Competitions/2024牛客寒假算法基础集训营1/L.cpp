#include <cstdio>
#include <iostream>
int main() {
  int T;
  std :: cin >> T;
  while(T --) {
    int c, d, h, w;
    std :: cin >> c >> d >> h >> w;
    std :: cout << w * c * 3 << '\n';
  }
}