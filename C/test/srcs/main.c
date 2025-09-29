#include <stdio.h>

int ft_strlen(char *str)

{
    int i;
    i = 0;
    while (str[i])
        i++;
    return i;
}

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    char *str = "Hello, World!";
    printf("%d\n", ft_strlen(str));
    return 0;
}