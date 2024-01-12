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
    trimed_str[j] = 0;
    return(trimed_str);
}

int find_smallest_ascii(char *str) 
{
    int i = 0;
    int j = 1;
    int index_of_smallest = 0;

    while (str && str[i])
    {

        while(str && str[j])
        {
            if (str[j] < str[i])
            {
                index_of_smallest = j;
                i = j;
                j ++;
                break;
            }
            j ++;
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
        if(smallestAsciiIndex != i && strToCut[i] == strToCut[smallestAsciiIndex])
            smallestAsciiOccurences ++;

    cutStr = malloc((strlen(strToCut) - smallestAsciiIndex + 1) * sizeof(char));
    bzero(cutStr, strlen(strToCut) - smallestAsciiIndex + 1);

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
            printf("k : %d, len : %d\n", k, strlen(strToCut) - smallestAsciiIndex + 1);
            k ++;
        }
        i ++;
    }
    // maybe remove this free
    free(strToCut);
    return(cutStr);
}

char *arg_is_alpha_and_space(char *arg)
{
    int i = 0;

    while (arg && arg[i])
    {
        if (!isalpha(arg[i]) && !isspace(arg[i]))
        {
            dprintf(2, "The string passed as an argument can only contain alphabetic characters and white spaces");
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
    char *strCpy = strdup(str);
    int smallestAsciiIndex = 0;
    bzero(sortedStr, strlen(str) + 1);

    strCpy = trim_space(strCpy);
    while (strlen(strCpy) > 0)
    {
        smallestAsciiIndex = find_smallest_ascii(strCpy);
        strCpy = cut_smallest_ascii_from_string(strCpy, sortedStr,smallestAsciiIndex);
    }
    free(strCpy);
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