#include <stdio.h>

typedef unsigned int AGE;

void show_age(AGE a) {
  printf("show age: %u\n", a);
}

void find_age(AGE a) {
  if(a == 100){
    printf("Found age 100\n");
  } else {
    printf("age %u not found.\n", a);
  }
}

void print_char(char a) {
  putchar(a);
}

int main(int argc, const char * argv[]) {
  AGE age;
  age = 100;
  show_age(age);
  find_age((AGE)100);
  find_age((AGE)211);
  find_age((AGE)507);  
  print_char('D');
  print_char('N');
  print_char('A');
  print_char('\n');  
  return 0;
}
