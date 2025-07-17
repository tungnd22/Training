#ifndef PRACTICE_H
#define PRACTICE_H

typedef union income_t
{
    char    s_val[7];   // anxin, antrom
    int     i_val;      // congnhan

} income_t;

typedef struct someone_t
{
    char        type[9];
    income_t    income;
    void        (*p_action)(struct someone_t);
    
} someone_t;

void cadge (someone_t person);
void stole (someone_t person);
void work  (someone_t person);
void create_person (someone_t * p_person);

#endif // PRACTICE_H