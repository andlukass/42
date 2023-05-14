#include "get_next_line.h"

char* ft_teste()
{
    char *teste;
    teste = malloc(sizeof(char) * 10);
    teste = strcpy(teste, "123456789");
    return teste;
}

int main()
{
    char t[30] = "123456789";
    int fd = open("teste.txt", O_RDONLY);
    char *line;

    read(fd, t, 5);
	
    printf("%s", t);
    return 0;
}
