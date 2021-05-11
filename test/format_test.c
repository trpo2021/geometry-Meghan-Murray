#include "ctest.h"
#include "libgeometry/geometry.h"

CTEST(correct_str, correct_input)
{
    char str_input[] = "circle(1 2, 3)\n";
    int expect = 14;

    int result = correct_str(str_input);
    ASSERT_EQUAL(expect, result);
}

CTEST(correct_str, skip_space)
{
    char str_input[] = " circle  ( 1   2 ,   3  )   \n";
    int expect = 14;

    int result = correct_str(str_input);
    ASSERT_EQUAL(expect, result);
}

CTEST(correct_str, possible_input)
{
    char str_input[] = "(1 2, 3)\n";
    int expect = 8;

    int result = correct_str(str_input);
    ASSERT_EQUAL(expect, result);
}

CTEST(correct_str, wrong_parenthesis)
{
    char str_input[] = "circle )1 2, 3)\n";
    int exp1 = -1;
    int exp2 = -7;

    int result = correct_str(str_input);
    ASSERT_INTERVAL(exp2, exp1, result);
}

CTEST(correct_str, extra_comma)
{
    char str_input[] = "circle (1, 2, 3)\n";
    int exp1 = -1;
    int exp2 = -7;

    int result = correct_str(str_input);
    ASSERT_INTERVAL(exp2, exp1, result);
}

CTEST(correct_str, no_comma)
{
    char str_input[] = "circle (1 2 3)\n";
    int exp1 = -1;
    int exp2 = -7;

    int result = correct_str(str_input);
    ASSERT_INTERVAL(exp2, exp1, result);
}

CTEST(correct_str, extra_point)
{
    char str_input[] = "circle (1.3.4 2, 3)\n";
    int exp1 = -1;
    int exp2 = -7;

    int result = correct_str(str_input);
    ASSERT_INTERVAL(exp2, exp1, result);
}

CTEST(correct_str, negative_radius)
{
    char str_input[] = "circle (1 2, -3)\n";
    int exp1 = -1;
    int exp2 = -7;

    int result = correct_str(str_input);
    ASSERT_INTERVAL(exp2, exp1, result);
}

CTEST(correct_str, instead_comma_point)
{
    char str_input[] = "circle (1 2. 3)\n";
    int exp1 = -1;
    int exp2 = -7;

    int result = correct_str(str_input);
    ASSERT_INTERVAL(exp2, exp1, result);
}

CTEST(correct_str, wrong_parenthesis_end)
{
    char str_input[] = "circle (1 2, 3(\n";
    int exp1 = -1;
    int exp2 = -7;

    int result = correct_str(str_input);
    ASSERT_INTERVAL(exp2, exp1, result);
}

CTEST(correct_str, negative_points)
{
    char str_input[] = "circle (-1 -2, 3)\n";
    int expect = 16;

    int result = correct_str(str_input);
    ASSERT_EQUAL(expect, result);
}

CTEST(correct_str, type_double)
{
    char str_input[] = "circle (1.2 2.4, 3.51)\n";
    int expect = 21;

    int result = correct_str(str_input);
    ASSERT_EQUAL(expect, result);
}

CTEST(correct_str, wrong_word)
{
    char str_input[] = "cirle(1 2, 3)\n";
    int exp1 = -1;
    int exp2 = -7;

    int result = correct_str(str_input);
    ASSERT_INTERVAL(exp2, exp1, result);
}

CTEST(correct_str, uppercase)
{
    char str_input[] = "CIRCLE(1 2, 3)\n";
    int expect = 14;

    int result = correct_str(str_input);
    ASSERT_EQUAL(expect, result);
}

CTEST(correct_str, wrong_word_2)
{
    char str_input[] = "rle(1 2, 3)\n";
    int exp1 = -1;
    int exp2 = -7;

    int result = correct_str(str_input);
    ASSERT_INTERVAL(exp2, exp1, result);
}

CTEST(correct_str, one_letter_uppercase)
{
    char str_input[] = "ciRcle(1 2, 3)\n";
    int expect = 14;

    int result = correct_str(str_input);
    ASSERT_EQUAL(expect, result);
}

CTEST(correct_str, large_value)
{
    char str_input[] = "circle(10  -20, 300)\n";
    int expect = 19;

    int result = correct_str(str_input);
    ASSERT_EQUAL(expect, result);
}

CTEST(str_copy, correct_input)
{
    char str_input[] = "circle (1 2, 3)";
    char str_expect[] = "circle(1 2, 3)";

    char result[15];
    str_copy(str_input, result);
    ASSERT_STR(str_expect, result);
}

CTEST(str_copy, skip_space)
{
    char str_input[] = " circle  ( 1   2 ,   3  )   \n";
    char str_expect[] = "circle(1 2, 3)";

    char result[15];
    str_copy(str_input, result);
    ASSERT_STR(str_expect, result);
}

CTEST(str_copy, large_value)
{
    char str_input[] = " circle(10  -20, 300)";
    char str_expect[] = "circle(10 -20, 300)";

    char result[20];
    str_copy(str_input, result);
    ASSERT_STR(str_expect, result);
}

CTEST(str_copy, uppercase)
{
    char str_input[] = "CIRCLE(1 2, 3)";
    char str_expect[] = "CIRCLE(1 2, 3)";

    char result[20];
    str_copy(str_input, result);
    ASSERT_STR(str_expect, result);
}
