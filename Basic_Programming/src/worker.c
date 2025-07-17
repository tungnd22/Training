#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/worker.h"

char   g_action_msg[17];
char * g_type_list[] = {"anxin", "antrom", "congnhan"};

FILE * p_file;
const char * output_file = "./build/output.txt";


void cadge (someone_t person)
{
    strcpy(g_action_msg, "lam on lam phuoc");
    printf("%s\n", g_action_msg);
    p_file = fopen(output_file, "a");
    fprintf(p_file, "%s\n", g_action_msg);
    fclose(p_file);
}

void stole (someone_t person)
{
    strcpy(g_action_msg, "!!!");
    printf("%s\n", g_action_msg);
    p_file = fopen(output_file, "a");
    fprintf(p_file, "%s\n", g_action_msg);
    fclose(p_file);
}

void work (someone_t person)
{
    sprintf(g_action_msg, "%d", person.income.i_val);
    printf("%s\n", g_action_msg);
    p_file = fopen(output_file, "a");
    fprintf(p_file, "%s\n", g_action_msg);
    fclose(p_file);
}

void create_person (someone_t * p_person)
{
    strcpy(p_person->type, g_type_list[rand() % 3]);
    
    if (0 == strcmp(p_person->type, "anxin"))
    {
        strcpy(p_person->income.s_val, "tuytam");
        p_person->p_action = cadge;
    }
    
    else if (0 == strcmp(p_person->type, "antrom"))
    {
        strcpy(p_person->income.s_val, "henxui");
        p_person->p_action = stole;
    }
    
    else if (0 == strcmp(p_person->type, "congnhan"))
    {
        p_person->income.i_val = 500000;
        p_person->p_action = work;
    }

    p_file = fopen(output_file, "w");
    fclose(p_file);
}
