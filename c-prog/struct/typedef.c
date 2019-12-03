#include <stdio.h>

int main(void) {
  typedef char * String;


  String str = "Hello, My name is John.\n";

  String arr[] = {"Hello", "This is", "John"};

  printf("%s", str);

  for(int i = 0; i < 3; i++)
    printf("%s", arr[i]);

  return 0;
}
