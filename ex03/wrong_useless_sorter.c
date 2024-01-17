#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

char *trim_space(char *str)
{
    int i = -1;
    int j = 0;
    int newLen = 0;

    while (str && str[++i])
        if(!isspace(str[i]))
            newLen ++;

    char *trimed_str = malloc((newLen + 1) * sizeof(char));
    if (!trimed_str)
        exit(0);

    i = 0;

    while (str && str[i])
    {
        if (!isspace(str[i]) && j <= newLen)
        {
            trimed_str[j] = str[i];
            j ++;
        }
        i ++;
    }
    return(trimed_str);
}

int find_smallest_ascii(char *str) 
{
    int i = 0;
    int j;
    int index_of_smallest = 0;

    while (str && str[i])
    {
        j = i + 1;
        while(str && str[j])
        {
            if (str[j] < str[i])
            {
                index_of_smallest = j;
                break;
            }
            else if (j == strlen(str) - 1)
                return (i);
        }
        i ++;
    }
    return(index_of_smallest);
}

char *cut_smallest_ascii_from_string(char *strToCut, char *stringToFillWithCut, int smallestAsciiIndex)
{
    int i = -1;
    int j = strlen(stringToFillWithCut);
    int k = 0;
    char *cutStr = NULL;
    int smallestAsciiOccurences = 0;
    
    while (strToCut && strToCut[++i])
        if(strToCut[i] == strToCut[smallestAsciiIndex])
            smallestAsciiOccurences ++;

    cutStr = malloc((strlen(strToCut) - smallestAsciiOccurences + 1) * sizeof(char));
    if (!cutStr)
        exit(0);
    bzero(cutStr, strlen(strToCut));

    i = 0;
    while (strToCut && strToCut[i])
    {
        if (strToCut[i] == strToCut[smallestAsciiIndex])
        {
            stringToFillWithCut[j] = strToCut[i];
            j ++;
        }
        else
        {
            cutStr[k] = strToCut[i];
            k ++;
        }
        i ++;
    }
    return(cutStr);
}

char *arg_is_alpha_and_space(char *arg)
{
    int i = 0;

    while (arg && arg[i])
    {
        if (!isalpha(arg[i]) && !isspace(arg[i]))
        {
            dprintf(2, "The string passed as an argument can only contain alphabetic characters and white spaces\n");
            exit (2);
        }
        i ++;
    }
}

char *useless_sorter(char *str)
{
    int i = 0;
    int j = 1;
    char *sortedStr = malloc((strlen(str) + 1) * sizeof(char));
    if (sortedStr)
        exit(0);
    char *strCpy = strdup(str);
    int smallestAsciiIndex = 0;
    bzero(sortedStr, strlen(str) + 1);

    strCpy = trim_space(strCpy);
    while (strlen(strCpy) > 0)
    {
        smallestAsciiIndex = find_smallest_ascii(strCpy);
        strCpy = cut_smallest_ascii_from_string(strCpy, sortedStr,smallestAsciiIndex);
    }
    return (sortedStr);

}

int main (int ac, char **av)
{
    
    char *uselessly_sorted_str;
    if (ac != 2)
    {
        dprintf(2, "This program only take up to one argument, a string\n");
        exit(1);
    }

    arg_is_alpha_and_space(av[1]);

    uselessly_sorted_str = useless_sorter(av[1]);

    printf("here it is : %s\n", uselessly_sorted_str);
    free(uselessly_sorted_str);
    return (0);
}