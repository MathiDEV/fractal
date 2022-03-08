#include "../../include/my.h"

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        if ((int)str[i] < 48 || (int)str[i] > 57)
            return 0;
    }
    return 1;
}
