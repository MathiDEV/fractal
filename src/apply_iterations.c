#include "fractals.h"

int free_chartable(char **chartable, int len)
{
    for (int i = 0; i < len; i++)
        free(chartable[i]);
    free(chartable);
}

int my_pow(int n, int p)
{
    int temp = n;

    if (p == 0)
        return (1);
    for (int i = 1; i < p; i++)
        n *= temp;
    return (n);
}

char **init_chartable(vec_t *size)
{
    char **result = malloc(sizeof(char *) * size->y);
    for (int i = 0; i < size->y; i++)
        result[i] = malloc(sizeof(char) * size->x);
    return result;
}

void append_pattern(replace_t *data, char **chrtbl, char patrn, vec_t *corner)
{
    char **pattern = (patrn == '#' ? data->hash_replace : data->point_replace);

    for (int y = 0; y < data->height; y++)
        for (int x = 0; x < data->width; x++)
            chrtbl[y + corner->y][x + corner->x] = pattern[y][x];
}

char **apply_iterations(replace_t *data, char **last_table, int iter)
{
    int p_iter = iter - 1;
    vec_t size = {my_pow(data->width, iter), my_pow(data->height, iter)};
    vec_t p_size = {my_pow(data->width, p_iter), my_pow(data->height, p_iter)};
    vec_t topleft;
    char **result;

    if (iter > data->n_iter)
        return (last_table);
    result = init_chartable(&size);
    for (int y = 0; y < p_size.y; y++)
        for (int x = 0; x < p_size.x; x++) {
            topleft.x = x * data->width;
            topleft.y = y * data->height;
            append_pattern(data, result, last_table[y][x], &topleft);
        }
    free_chartable(last_table, p_size.y);
    return (apply_iterations(data, result, iter + 1));
}
