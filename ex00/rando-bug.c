#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "rando-bug.h"


int main ()
{
    int rando;
    int i = 0;
    char *str;
    time_t t;

    srand((unsigned) time(&t));
    rando = rand();

    if (rando % 9 == 0)
    {
        str = NEUF;
    }
    else if (rando % 8 == 0)
    {
        str = HUIT;
    }
    else if (rando % 7 == 0)
    {
        str = SEPT;
    }
    else if (rando % 6 == 0)
    {
        str = SIX;
    }
    else if (rando % 5 == 0)
    {
        str = CINQ;
    }
    else if (rando % 4 == 0)
    {
        str = QUATRE;
    }
    else if (rando % 3 == 0)
    {
        str = TROIS;
    }
    else if (rando % 2 == 0)
    {
        str = DEUX;
    }
    else if (rando % 1 == 0)
    {
        str = UN;
    }
    
    while (str[i])
    {
        write(1, &str[i], 1);
        i ++;
    }
    write(1, "\n", 1);
}