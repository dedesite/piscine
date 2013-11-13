#include <my.h>
#include <s_opp.h>

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
  my_putstr("error : only [ + - / * % ] are supported");
}

#include <my_opp.h>

int is_opp(char* str)
{
  int i;

  i = 0;
  while(i < 5)
    {
      if(my_strcmp(str, gl_opptab[i].opp) == 0)
  return (i);
      i = i + 1;
    }
  return (i);
}

int check_params(int argc, char** argv)
{
  if(argc != 4)
    return (0);
  if(my_getnbr(argv[1]) == 0 || my_getnbr(argv[3]) == 0)
    return (0);
  return (1);
}

int main(int argc, char** argv)
{
  int opp_ind;

  if(!check_params(argc, argv))
    {
      putline("0");
      return (0);
    }
  opp_ind = is_opp(argv[2]);
  gl_opptab[opp_ind].fct(my_getnbr(argv[1]), my_getnbr(argv[3]));
  my_putchar('\n');
  return (0);
}
