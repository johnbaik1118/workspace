#include <stdio.h>

void show_age(char a) {
  printf("show age: %u\n", a);
}

void find_age(char a) {
  if(a == 100){
    printf("Found age 100\n");
  } else {
    printf("age %u not found.\n", (unsigned char)a);
  }
}

void print_char(char a) {
  putchar(a);
}

int main(int argc, const char * argv[]) {
  char age;
  age = 100;
  show_age(age);
  find_age((char)100);
  find_age((char)222);
  find_age((char)507);
  print_char('D');
  print_char('N');
  print_char('A');
  print_char('\n');
  return 0;
}
