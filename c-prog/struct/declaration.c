struct People
{
  char name[12];
  unsigned short int age;
  float height;
  float weight;
};

void main(void) {
  struct People data;
  struct People friend_list[64];
  struct People *p;

  data.age = 20;
  data.height = 175.1;

  friend_list[3].age = 21;

  (*p).age = 25;
  p->age   = 25; // 동일한 표현
}

typedef struct People Person;
