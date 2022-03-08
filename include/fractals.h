#ifndef FRACTALS_H_
    #define FRACTALS_H_
    #include "my.h"
    #define ERR_ARGCOUNT "Usage: \n\t./fractals <n> <pattern1> <pattern2>\n"
    #define ERR_WRONGCHAR "Your patterns must contain only (#.@)\n"
    #define ERR_DIMS "Your patterns must have the same height and width\n"
    #define ERR_LINES "All your lines must have the same length\n"
    typedef struct replacements {
        char **hash_replace;
        char **point_replace;
        int n_iter;
        int width;
        int height;
    } replace_t;
    typedef struct vector {
        int x;
        int y;
    } vec_t;
    void my_putchar(char c);
    char **my_split(char const *str, char *seps);
    int check_error(int argc, char **argv);
    void get_arguments(char **argv, replace_t *replacement);
    char **init_chartable(vec_t *size);
    char **apply_iterations(replace_t *data, char **last_table, int iter);
    void generate_fractal(replace_t *data);
    int my_pow(int n, int p);
    int free_chartable(char **chartable, int len);
    int get_width(char const *str);
    int get_height(char const *str);
#endif
