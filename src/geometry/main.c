#include "libgeometry/geometry.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int max_str = 80, size_string;
    char* input_str = NULL;
    input_str = calloc(max_str, sizeof(char));
    char* string = NULL;
    char* string_2 = NULL;

    printf("Circle 1:");
    fgets(input_str, max_str, stdin);
    size_string = correct_str(input_str);
    if (size_string < 0) {
        out_error(size_string);
        return -1;
    }

    string = calloc(size_string, sizeof(char));
    str_copy(input_str, string);
    free(input_str);
    //    output(string);
    input_str = calloc(max_str, sizeof(char));

    printf("Circle 2:");
    fgets(input_str, max_str, stdin);
    size_string = correct_str(input_str);
    if (size_string < 0) {
        out_error(size_string);
        return -1;
    }
    string_2 = calloc(size_string, sizeof(char));
    str_copy(input_str, string_2);
    free(input_str);
    //    output(string_2);

    double p = perimeter(string);
    printf("perimeter #1 = %.3f\n", p);
    double s = area(string);
    printf("area #1 = %.3f\n", s);

    double p_2 = perimeter(string_2);
    printf("perimeter #2 = %.3f\n", p_2);
    double s_2 = area(string_2);
    printf("area #2 = %.3f\n", s_2);

    int result = intersection(string, string_2);
    if (result == 1) {
        printf("circles intersect \n");
    } else if (result == 2) {
        printf("circles not intersect \n");
    }

    free(string);
    free(string_2);
    return 0;
}
