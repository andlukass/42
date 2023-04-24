int s_specifier(char *str)
{
    int index;

    index = 0;
    while (str[index])
    {
        write(1, &str[index], 1);
        index++;
    }
    return (index);
}