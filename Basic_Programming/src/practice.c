/*
"3. Thực hành code C basic (áp dụng các coding convention):
    Viết chương trình C thực hiện việc sau:
    Có 3 kiểu người: ăn xin, ăn trộm và công nhân. 
    Định nghĩa một kiểu someone_t là một struct đại diện cho 1 người gồm các trường sau:
    - type: là một chuỗi kí tự lưu kiểu người: ""anxin"", ""antrom"", ""congnhan""
    - income: là một trường lưu thông tin thu nhập của người đó. Nếu type:
        + anxin: thì income là chuỗi kí tự có giá trị ""tuytam""
        + antrom: thì income là chuỗi kí tự có giá trị ""henxui""
        + congnhan: thì income là số nguyên 2 bytes có giá trị là 500000
    - p_action: là một con trỏ hàm (với biến đầu vào có kiểu someone_t) trỏ tới công việc của mỗi người.  Nếu type:
        + anxin: thực hiện hàm cadge():n ra chuỗi ""lam on lam phuoc""
        + antrom: thực hiện hàm stole(): in ra chuỗi ""!!!""
        + congnhan: thực hiện hàm work(): in ra income của người này
    Hàm main() thực hiện việc sau:
    - Tạo ngẫu nhiên N người thuộc có kiểu someone_t và lưu vào mảng có kích thước MAX_PEOPLE(cần được define). 
    - Duyệt mảng trên và thực hiện hàm p_action của mỗi người, các chuỗi đầu ra được in lần lượt vào file ""output.txt"""
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/worker.h"

#define MAX_PEOPLE 100

// typedef union income_t
// {
//     char    s_val[7];   // anxin, antrom
//     int     i_val;      // congnhan
    
// } income_t;

// typedef struct someone_t
// {
//     char        type[9];
//     income_t    income;
//     void        (*p_action)(struct someone_t);
    
// } someone_t;


// char   g_action_msg[17];
// char * g_type_list[] = {"anxin", "antrom", "congnhan"};


// void cadge (someone_t person);
// void stole (someone_t person);
// void work  (someone_t person);
// void create_person (someone_t * p_person, char * p_type);


int main()
{
    int number_people;
    someone_t people[MAX_PEOPLE];


    printf("Nhap so nguoi: ");
    fflush(stdin);
    scanf("%d", &number_people);
    
    for (int counter = 0; counter < number_people; counter++)
    {
        create_person(&people[counter]);
    }

    for (int counter = 0; counter < number_people; counter++)
    {
        printf("%s ", people[counter].type);
        people[counter].p_action(people[counter]);
    }
        
    return 0;
}


// void cadge (someone_t person)
// {
//     strcpy(g_action_msg, "lam on lam phuoc");
//     printf("%s\n", g_action_msg);
// }

// void stole (someone_t person)
// {
//     strcpy(g_action_msg, "!!!");
//     printf("%s\n", g_action_msg);
// }

// void work (someone_t person)
// {
//     sprintf(g_action_msg, "%d", person.income.i_val);
//     printf("%s\n", g_action_msg);
// }

// void create_person (someone_t * p_person, char * p_type)
// {
//     strcpy(p_person->type, p_type);
    
//     if (0 == strcmp(p_person->type, "anxin"))
//     {
//         strcpy(p_person->income.s_val, "tuytam");
//         p_person->p_action = cadge;
//     }
    
//     else if (0 == strcmp(p_person->type, "antrom"))
//     {
//         strcpy(p_person->income.s_val, "henxui");
//         p_person->p_action = stole;
//     }
    
//     else if (0 == strcmp(p_person->type, "congnhan"))
//     {
//         p_person->income.i_val = 500000;
//         p_person->p_action = work;
//     }
// }
