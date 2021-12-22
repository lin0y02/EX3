#include "addFunc.h"
#include "answers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define TXT 1024
#define WORD 30

char *Q3(char *word, char *text)
{
    ////////ans dec
    char *answer = malloc(sizeof(char) * 780);
    memset(answer, 0, strlen(answer));

    /////////pointers declaration
    int start = 0;
    ///////////checker dec
    char *copy = malloc(sizeof(char) * strlen(word));
    strcpy(copy, word);
    /////////running thru the txt
    int stop = strlen(text);
    for (int i = 0; i < stop; i++)
    {
        char cur = text[i];
        if (cur == ' ')
        {
            continue;
        }
        //////////char is currect count it
        if (strchr(copy, cur) != NULL)
        {
            ///////delete cur char from copy
            del(copy, cur);
        }
        else
        {
            if (strchr(word, cur) != NULL)
            {
                start++;
                ///////delete cur char from copy
                i = start;
                //deletechar(copy, cur);
            }
            else
            {
                start = i;
            }
            strcpy(copy, word);

        }
        if ((copy != NULL) && (copy[0] == '\0')) //////////we fount word
        {
            char *concat = malloc(sizeof(char) * 780);
            if(start==0)
            {
                strncpy(concat, text + start, i - start+1);
            }
            else
            {
                strncpy(concat, text + start + 1, i - start);
            }
            cur = concat[0];
            while (cur == ' ')
            {
                del(concat, cur);
                cur = concat[0];
               start++;
            }
            strcat(answer, concat);
            strcat(answer, "~");
            start++;
            i = start;
            strcpy(copy, word);
        }
    }
    answer[strlen(answer) - 1] = '\0';
    return answer;
}
