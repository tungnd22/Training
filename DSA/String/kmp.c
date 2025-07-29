#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100000

void create_lps(char * pat, int * lps)
{
    int i = 1;
    int len = 0;

    lps[0] = 0;
    while (pat[i] != 0)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else if (len == 0)
        {
            lps[i] = 0;
            i++;
        }
        else 
        {
            len = lps[len - 1];
        }
    }
}

void * search(char * pat, char * txt, int * res, int * occ)
{
    int size = 0;
    int pat_cnt = 0;
    int txt_cnt = 0;
    int pat_size = strlen(pat);
    int txt_size = strlen(txt);

    int lps[pat_size];
    create_lps(pat, lps);

    while (txt_cnt < txt_size)
    {
        if (txt[txt_cnt] == pat[pat_cnt])
        {
            if (pat_cnt == pat_size - 1)
            {
                res[size] = txt_cnt - pat_cnt;
                size++;
                pat_cnt = lps[pat_cnt - 1];
            }
            else
            {
                txt_cnt++;
                pat_cnt++;
            }
        }
        else if (pat_cnt == 0)
        {
            txt_cnt++;
        }
        else
        {
            pat_cnt = lps[pat_cnt - 1];
        }
    }
    *occ = size; // Number of occurrences
}

int main()
{
    char txt[MAX_LEN + 1];
    char pat[MAX_LEN + 1];

    scanf("%s", pat);
    scanf("%s", txt);
    
    int occ;
    int res[strlen(txt)]; 
    search(pat, txt, res, &occ);

    printf("%d", occ);

    return 0;
}