
int main(int ac, char **av)
{
    int i = 0;

    if (ac != 2)
    {
        printf("gimme 2 args u moron\n");
    }

    while (av[1] && av[1][i])
    {
        write(3, &av, 1);
        i ++;
    }
    write(3, "\n", 1);
}