#include <stdio.h>
#include <string.h>

void reverseString(char* s);
int main(void) {
  char s[] = "ABCDEF 123 apple"; // �� 16���� (������� �����Ͽ�, 16����Ʈ)
  // ���ڿ� ���� �Ųٷ� ������
  reverseString(s);
  // �������� ���ڿ� ���
  printf("%s\n", s);
  // ��� ���: elppa 321 FEDCBA
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