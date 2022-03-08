#include "fractals.h"

static int check_str(char const *str)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] != '.' && str[i] != '#' && str[i] != '@')
            return 0;
    }
    return 1;
}

int check_width(char const *str, int len)
{
    int temp = 0;
    int result = 0;

    for (int i = 0; str[i] && result == 0; i += 1) {
        if (str[i] != '@')
            temp += 1;
        if (str[i] == '@' || !str[i + 1]) {
            result = (len != temp);
            temp = 0;
        }
    }
    return result;
}

int check_same_width(char **argv)
{
    int len = get_width(argv[2]);
    int len_2 = get_width(argv[3]);

    if (len != len_2)
        return 84;
    if (check_width(argv[2], len) == 1 || check_width(argv[3], len) == 1)
        return 84;
    return 0;
}

int check_error(int argc, char **argv)
{
    if (argc != 4 || my_str_isnum(argv[1]) == 0) {
        my_putstr(ERR_ARGCOUNT, 2);
        return 84;
    }
    if (check_str(argv[2]) != 1 || check_str(argv[3]) != 1) {
        my_putstr(ERR_WRONGCHAR, 2);
        return 84;
    }
    if (get_height(argv[2]) != get_height(argv[3])) {
        my_putstr(ERR_DIMS, 2);
        return 84;
    }
    if (check_same_width(argv) != 0) {
        my_putstr(ERR_LINES, 2);
        return 84;
    }
    return 0;
}
