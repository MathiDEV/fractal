#ifndef MY_H_
    #define MY_H_
    #include <stdlib.h>
    #include <unistd.h>
    int my_strlen(char const *str);
    void my_putstr(char *str, int std);
    void my_putstr_len(char *str, int len);
    int my_getnbr(char const *str);
    void my_putchar(char c);
    char **my_split(char const *str, char *seps);
    int my_str_isnum(char const *str);
#endif
