#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/fractals.h"

void redirect_all_std (void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}



Test (generate_fractal, example_1, .init = redirect_all_std)
{
   replace_t data;
   char *argv[4];
   argv[0] = "";
   argv[1] = "0";
   argv[2] = "##@#.";
   argv[3] = "..@..";
   get_arguments(argv, &data);
   generate_fractal(&data);
   cr_assert_stdout_eq_str("#\n");
}

Test (generate_fractal, example_2, .init = redirect_all_std)
{
   replace_t data;
   char *argv[4];
   argv[0] = "";
   argv[1] = "1";
   argv[2] = "##@#.";
   argv[3] = "..@..";
   get_arguments(argv, &data);
   generate_fractal(&data);
   cr_assert_stdout_eq_str("##\n#.\n");
}

Test (generate_fractal, example_3, .init = redirect_all_std)
{
   replace_t data;
   char *argv[4];
   argv[0] = "";
   argv[1] = "2";
   argv[2] = "##@#.";
   argv[3] = "..@..";
   get_arguments(argv, &data);
   generate_fractal(&data);
   cr_assert_stdout_eq_str("####\n#.#.\n##..\n#...\n");
}


Test (check_error, wrong_iterations, .init = redirect_all_std)
{
   char *argv[4];
   argv[0] = "";
   argv[1] = "hello world";
   argv[2] = "##@#.";
   argv[3] = "..@..";
   check_error(4, argv);
   cr_assert_stderr_eq_str(ERR_ARGCOUNT);
}

Test (check_error, wrong_line, .init = redirect_all_std)
{
   char *argv[4];
   argv[0] = "";
   argv[1] = "3";
   argv[2] = "###@#.";
   argv[3] = "..@..";
   check_error(4, argv);
   cr_assert_stderr_eq_str(ERR_LINES);
}
