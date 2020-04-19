#include <stdio.h>
#include <string.h>

void reverseString(char* s);
int main(void) {
  char s[] = "ABCDEF 123 apple"; // 총 16글자 (공백까지 포함하여, 16바이트)
  // 문자열 순서 거꾸로 뒤집기
  reverseString(s);
  // 뒤집어진 문자열 출력
  printf("%s\n", s);
  // 출력 결과: elppa 321 FEDCBA
  return 0;
}

void reverseString(char* s) {
  size_t size = strlen(s);
  char temp;

  for (size_t i = 0; i < size / 2; i++) {
    temp = s[i];
    s[i] = s[(size - 1) - i];
    s[(size - 1) - i] = temp;
  }
}