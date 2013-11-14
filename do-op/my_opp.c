#include <my.h>
#include <s_opp.h>
#include <my_opp.h>

void my_add(int a, int b)
{
  my_put_nbr(a + b);
}

void my_sub(int a, int b)
{
  my_put_nbr(a - b);
}

void my_mul(int a, int b)
{
  my_put_nbr(a * b);
}

void my_div(int a, int b)
{
  if(b != 0)
    my_put_nbr(a / b);
  else
    my_putstr("Stop : division by zero");
}

void my_mod(int a, int b)
{
  if(b != 0)
    my_put_nbr(a % b);
  else
    my_putstr("Stop : modulo by zero");
}

void my_usage(int a, int b)
{
  int i;

  i = 0;
  my_putstr("error : only [ ");
  while(i < 5)
  {
    my_putstr(gl_opptab[i].opp);
    my_putchar(' ');
    i = i + 1;
  }
  my_putstr("] are supported");
}