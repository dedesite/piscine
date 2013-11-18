#ifndef EVALEXPR_H_
# define EVALEXPR_H_

int is_expr_valid(char* expr, char* base, char* operators);
int is_operator(char* word, char* operators);
int is_operator_prioritary(char* op_1, char* op_2, char* operators);
int is_operand(char* word, char* base);
int is_parenthesis(char* word, char* operators, int open);
char** expr_to_tab(char* expr, char* base, char* operators);
int eval_expr(char* str);
int count_expr_words(char* expr, char* base, char* operators);
#endif