#include "fractals.h"

static void display_fractal(replace_t *data, char **fractal)
{
    vec_t dims;

    dims.x = my_pow(data->width, data->n_iter);
    dims.y = my_pow(data->height, data->n_iter);
    for (int y = 0; y < dims.y; y++) {
        my_putstr_len(fractal[y], dims.x);
        my_putchar('\n');
    }
}

void generate_fractal(replace_t *data)
{
    char **fractal = init_chartable(&(vec_t){1, 1});

    fractal[0][0] = '#';
    fractal = apply_iterations(data, fractal, 1);
    display_fractal(data, fractal);
    free_chartable(fractal, my_pow(data->height, data->n_iter));
    free_chartable(data->hash_replace, data->height);
    free_chartable(data->point_replace, data->height);
}
