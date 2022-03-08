#include "../../include/my.h"

static int is_sep(char c, char *seps)
{
    for (int i = 0; seps[i]; i++)
        if (c == seps[i])
            return (1);
    return (0);
}

static char *split_and_store(char const *src, char *seps)
{
    char *string;
    int i = 0;
    int len = 0;

    for (i = 0; !is_sep(src[i], seps) && src[i] != '\0'; i++)
        len++;
    string = malloc(sizeof(char) * (len + 1));
    i = -1;
    for (i = 0; !is_sep(src[i], seps) && src[i] != '\0'; i++)
        string[i] = src[i];
    string[i] = 0;
    return string;
}

char **my_split(char const *str, char *seps)
{
    char **result;
    int index = 0;
    int wc = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if ((i == 0 || is_sep(str[i - 1], seps)) && !is_sep(str[i], seps))
            wc++;
    result = malloc(sizeof(char *) * (wc + 1));
    for (int i = 0; str[i] != '\0'; i++)
        if ((i == 0 || is_sep(str[i - 1], seps)) && !is_sep(str[i], seps)) {
            result[index] = split_and_store(&(str[i]), seps);
            index++;
        }
    result[index] = 0;
    return result;
}
