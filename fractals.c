#include "fractals.h"

int main(int argc, char **argv)
{
    replace_t data;

    if (check_error(argc, argv))
        return (84);
    get_arguments(argv, &data);
    generate_fractal(&data);
    return (0);
}
