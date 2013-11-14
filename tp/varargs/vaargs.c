#include <stdio.h>
#include <stdarg.h>

struct ex2
{
  char c;
  int i;
  short int s;
};

struct ex3
{
  int i;
  short int s;
  char c;
};

void fct(int param1, struct ex2 param2, char* param3)
{
  int* ptr_param1;
  int i;

  ptr_param1 = &param1;
  i = 0;
  while(i < 5)
  {
    if(i == 3)
      printf("Adresse : %p  valeur : %hd\n", ptr_param1, *ptr_param1);
    else if(i == 4)
      printf("Adresse : %p  valeur : %s\n", ptr_param1, *ptr_param1);
    else
      printf("Adresse : %p  valeur : %d\n", ptr_param1, *ptr_param1);
    ptr_param1++;
    i = i + 1;
  }
}

int my_vaarg(char* s, ...)
{
  int result;
  int temp;
  va_list ap;

  result = 0;
  va_start(ap, s);
  while(*s)
  {
    if(*s == '$')
    {
      temp = va_arg(ap, int);
      result = result + temp;
    }
    s++;
  }
  va_end(ap);
  return result;
}

int main()
{
  int res;

  struct ex2 s = {'c', 2, 2};
  //struct ex3 s = {2, 2, 'c'};
  fct(1, s, "test");
  printf("here");
  res = my_vaarg("$$$$", 1, 2, 3, 4);
  printf("Res %d should == 10", res);
  return (0);
}