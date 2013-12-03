#ifndef EVALEXPR_H_
# define EVALEXPR_H_

# define OP_OPEN_PARENT_IDX 0
# define OP_CLOSE_PARENT_IDX 1
# define OP_PLUS_IDX 2
# define OP_SUB_IDX 3
# define OP_NEG_IDX 3
# define OP_MULT_IDX 4
# define OP_DIV_IDX 5
# define OP_MOD_IDX 6

int is_expr_valid(char* expr, char* base, char* operators);
int is_operator(char token, char* operators);
int is_operator_prioritary(char op_1, char op_2, char* operators);
int is_operand(char* token, char* base);
int is_parenthesis(char token, char* operators, int open);
char** expr_to_tab(char* expr, char* base, char* operators);
int eval_expr(char* str);
int count_expr_tokens(char* expr, char* base, char* operators);
char** expr_to_npi(char** expr_tab, char* base, char* operators);
int check_base(char* b);
int check_ops(char* ops);
int str_uniq_char(char* s);

#endif