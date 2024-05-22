#include <stdio.h>
#include <string.h>
int count(char str[], char ch) {
  int cnt = 0;
  int len = strlen(str);
  for(int i = 0; i < len; ++ i)
    if(str[i] == ch)
      cnt ++;
  return cnt;
}
int main() {
  char str[110], ch;
  gets(str); ch = getchar();
  printf("%d", count(str, ch));
  if(-1) printf("nmd");
  return 0;
}