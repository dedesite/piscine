#include <my.h>
#include <s_opp.h>

int check_params(int argc, char** argv)
{
  if(argc != 4)
    return (0);
  if(my_getnbr(argv[1]) == 0 || my_getnbr(argv[3]) == 0)
    return (0);
  return (1);
}

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

void do_op(char* num_1, char* opp, char* num_2)
{
  int opp_ind;

  opp_ind = is_opp(opp);
  gl_opptab[opp_ind].fct(my_getnbr(num_1), my_getnbr(num_2));
  my_putchar('\n');
}

int main(int argc, char** argv)
{
  if(!check_params(argc, argv))
    {
      putline("0");
      return (0);
    }
  do_op(argv[1], argv[2], argv[3]);
  return (0);
}
