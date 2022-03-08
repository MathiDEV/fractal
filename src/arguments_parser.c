#include "fractals.h"

int get_height(char const *str)
{
    int result = 0;

    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == '@')
            result += 1;
    }
    return result + 1;
}

int get_width(char const *str)
{
    int result;

    for (result = 0; str[result] != '@' && str[result] != '\0'; result += 1);
    return result;
}

void get_arguments(char **argv, replace_t *replacement)
{
    replacement->height = get_height(argv[2]);
    replacement->width = get_width(argv[2]);
    replacement->hash_replace = my_split(argv[2], "@");
    replacement->point_replace = my_split(argv[3], "@");
    replacement->n_iter = my_getnbr(argv[1]);
}
