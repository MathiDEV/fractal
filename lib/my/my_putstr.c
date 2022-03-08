#include "../../include/my.h"

void my_putstr(char *str, int std)
{
    write(std, str, my_strlen(str));
}

void my_putstr_len(char *str, int len)
{
    write(1, str, len);
}
