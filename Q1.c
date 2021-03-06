#include "answers.h"
#include "addFunc.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *Q1(char*word, char*text)
{
    ////length calculating
    int word_length = strlen(word);
    int text_length = strlen(text);

    //word gio
    int sum1 = 0;
    for (int i = 0; i < word_length; i++)
    {
        int cur = word[i];
        cur = gio(cur);
        sum1 += cur;
    }

    int start = 0;
    int end = 0;
    char *c = malloc(sizeof(char) * 780);
    memset(c, 0, strlen(c));

    while (end <= text_length)
    {
        int sum = sum2(text, start, end);
        while (start == end && gio(text[start]) == 0)
        {
            start++;
            end++;
            sum = sum2(text, start, end);
        }
        if (sum < sum1)
        {
            end++;
        }
        if (sum > sum1)
        {
            start++;
            end = start;
        }
        if (sum == sum1)
        {
            int i = start;
            for (; i < end; i++)
            {
                char ch = text[i];
                strncat(c, &ch, 1);
            }

            char ch = '~';
            strncat(c, &ch, 1);
            i--;
            start++;
            end = start;
        }
    }
    c[strlen(c) - 1] = '\0';
    return c;
}
