#include <stdio.h>
#include <math.h>
bool sushu(int x) {
  if(x == 1 || x == 0) return false;
  // 0 1不是素数，需要特判
  for(int i = 2; i < x; ++ i) // 判断是否为素数
    if(x % i == 0) return false;
  return true;
}
int main() {
  int a[5], ans[5], cnt = 0;
  // a为输入数组
  // ans为答案数组
  // cnt为素数个数
  for(int i = 0; i < 5; ++ i)
    scanf("%d", &a[i]);
  for(int i = 0; i < 5; ++ i)
    if(sushu(a[i])) // 判断是否为素数， 是就是true，不是就是false
      ans[cnt] = a[i], cnt ++; // 统计答案
  for(int i = 0; i < cnt; ++ i) // 输出答案数组
    printf("%d ", ans[i]);
  return 0;
}