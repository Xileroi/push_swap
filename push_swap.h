typedef struct s_stack
{
    struct s_pile *pile_a;
    struct s_pile *pile_b;
}  t_stack;

typedef struct s_pile
{
    int valeur;
    struct s_pile *next;
} t_pile ;

/*
{1, *}->
{5, *}->            
{4, *}->            
{9, *}NULL


B
{8, *}->
{3, *}->           
{2, *}NULL

*/