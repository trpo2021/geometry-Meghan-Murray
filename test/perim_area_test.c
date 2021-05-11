#include "ctest.h"
#include "libgeometry/geometry.h"

CTEST(perimeter, type_integer)
{
    char str_input[] = "circle(1 1, 10)";
    double expect = 62.832;

    double result = perimeter(str_input);
    ASSERT_EQUAL(expect, result);
}

CTEST(perimeter, type_double)
{
    char str_input[] = "circle(1 5.2, 24.12)";
    double expect = 151.550;

    double result = perimeter(str_input);
    ASSERT_DBL_NEAR_TOL(expect, result, 0.001);
}

CTEST(area, type_integer)
{
    char str_input[] = "circle(1 5, 22)";
    double expect = 1520.531;

    double result = area(str_input);
    ASSERT_EQUAL(expect, result);
}

CTEST(area, type_double)
{
    char str_input[] = "circle(4.3 0, 0.321)";
    double expect = 0.323;

    double result = area(str_input);
    ASSERT_DBL_NEAR_TOL(expect, result, 0.001);
}

CTEST(get_radius, type_integer)
{
    char str_input[] = "circle(1 54, 4)";
    double expect = 4;

    double result = get_radius(str_input);
    ASSERT_EQUAL(expect, result);
}

CTEST(get_radius, type_double)
{
    char str_input[] = "circle(0 0, 4.23)";
    double expect = 4.23;

    double result = get_radius(str_input);
    ASSERT_DBL_NEAR_TOL(expect, result, 0.001);
}

CTEST(get_point, type_integer_point_1)
{
    char str_input[] = "circle(55 1, 23)";
    int i = 7;
    double expect = 55;

    double result = get_point(str_input, i);
    ASSERT_EQUAL(expect, result);
}

CTEST(get_point, type_double_point_1)
{
    char str_input[] = "circle(2.543 12, 235)";
    int i = 7;
    double expect = 2.543;

    double result = get_point(str_input, i);
    ASSERT_DBL_NEAR_TOL(expect, result, 0.001);
}

CTEST(get_point, negative_type_double_point_1)
{
    char str_input[] = "circle(-8.52 12, 235)";
    int i = 7;
    double expect = -8.52;

    double result = get_point(str_input, i);
    ASSERT_DBL_NEAR_TOL(expect, result, 0.001);
}

CTEST(get_point, type_integer_point_2)
{
    char str_input[] = "circle(55 9, 23)";
    int i = 10;
    double expect = 9;

    double result = get_point(str_input, i);
    ASSERT_EQUAL(expect, result);
}

CTEST(get_point, type_double_point_2)
{
    char str_input[] = "circle(2.43 56.34, 235)";
    int i = 12;
    double expect = 56.34;

    double result = get_point(str_input, i);
    ASSERT_DBL_NEAR_TOL(expect, result, 0.001);
}

CTEST(get_point, negative_type_double_point_2)
{
    char str_input[] = "circle(-8.52 -1.2, 235)";
    int i = 13;
    double expect = -1.2;

    double result = get_point(str_input, i);
    ASSERT_DBL_NEAR_TOL(expect, result, 0.001);
}

CTEST(intersection, circles_intersect)
{
    char str_input[] = "circle(0 0, 76)";
    char str_input_2[] = "circle(52 13, 23)";
    double expect = 1;

    double result = intersection(str_input, str_input_2);
    ASSERT_EQUAL(expect, result);
}

CTEST(intersection, circles_not_intersect)
{
    char str_input[] = "circle(14 33, 5)";
    char str_input_2[] = "circle(54 124, 2)";
    double expect = 2;

    double result = intersection(str_input, str_input_2);
    ASSERT_EQUAL(expect, result);
}

CTEST(intersection, circles_intersect_double)
{
    char str_input[] = "circle(0.5 54.22, 54.345)";
    char str_input_2[] = "circle(1.234 45.432, 23.99)";
    double expect = 1;

    double result = intersection(str_input, str_input_2);
    ASSERT_EQUAL(expect, result);
}

CTEST(intersection, circles_not_intersect_double)
{
    char str_input[] = "circle(10.43 0.4, 5.3)";
    char str_input_2[] = "circle(54.76 123.98, 29.2)";
    double expect = 2;

    double result = intersection(str_input, str_input_2);
    ASSERT_EQUAL(expect, result);
}

CTEST(intersection, circles_intersect_negative)
{
    char str_input[] = "circle(-14 0.4, 5.3)";
    char str_input_2[] = "circle(-5.76 -3, 29.2)";
    double expect = 1;

    double result = intersection(str_input, str_input_2);
    ASSERT_EQUAL(expect, result);
}

CTEST(intersection, circles_not_intersect_negative)
{
    char str_input[] = "circle(-10 -0.4, 5)";
    char str_input_2[] = "circle(54.76 -123, 29.2)";
    double expect = 2;

    double result = intersection(str_input, str_input_2);
    ASSERT_EQUAL(expect, result);
}
