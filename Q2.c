#include "answers.h"
#include "addFunc.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* Q2(char* word,char* text)
{
    ////length calculating
    int word_length = strlen(word);
    //int tlength = strlen(txt);


    //// create word in the length of the accepted word
    char *atbash=malloc(sizeof(char) * word_length);
    ////calculate atbash
    int i=0;

    while(word[i]!='\0')
    {
        if(word[i]>='a' && word[i]<='z')
        {
            atbash[i]='z'+'a'-word[i];
        }
        if(word[i]>='A' && word[i]<='Z')
        {
            atbash[i]='Z'+'A'-word[i];
        }
        i++;
    }
    ////create reverse atbash
    char* Ratbash= strrev(atbash);

    if(strcmp("",atbash)==0 && strcmp("",Ratbash)==0)
    {
        return "";
    }


    char *answer= malloc(sizeof(char) * 780);
    memset(answer, 0, strlen(answer));
    int stop = strlen(text);
    for (i = 0;i<stop;)
    {
        if (strstr(&text[i], atbash) != NULL && strstr(&text[i], Ratbash) != NULL)
        {
            int a = strstr(&text[i], atbash)-&text[i];
            int r = strstr(&text[i], Ratbash)-&text[i];
            if(a < r)
            {
                strcat(answer,atbash);
                i= a;
                i+=word_length - 1;

            }
            else
            {
                strcat(answer,Ratbash);
                i= r;
                i+= word_length-1;
            }
        }

        else if (strstr(&text[i], atbash) != NULL)
        {
            int a = strstr(&text[i], atbash)-&text[0];
            strcat(answer,atbash);
            i= a;
            i+= word_length-1;
        }
        else if (strstr(&text[i], atbash) != NULL)
        {
            int r = strstr(&text[i], Ratbash)-&text[i];
            strcat(answer,Ratbash);
            i= r;
            i+= word_length-1;
        }
        else
        {
            break;
        }
        strcat(answer,"~");
    }
    answer[strlen(answer) - 1] = '\0';
    return answer;
}
