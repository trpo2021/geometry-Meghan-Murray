#include "geometry.h"

double get_radius(char* output_str)
{
    int i = 0;
    double radius;
    while (output_str[i] != ',') {
        i++;
    }
    i += 2;
    if (output_str[i] == '-') {
        return -1;
    }
    radius = atof(&output_str[i]);
    return radius;
}

double perimeter(char* output_str)
{
    double radius;
    double p;
    radius = get_radius(output_str);
    if (radius < 0) {
        return -1;
    }
    p = 2 * M_PI * radius;
    return p;
}

double area(char* output_str)
{
    double radius;
    double s;
    radius = get_radius(output_str);
    if (radius < 0) {
        return -1;
    }
    s = M_PI * radius * radius;
    return s;
}

double get_point(char* output_str, int i)
{
    double point = atof(&output_str[i]);
    return point;
}

void intersection(char* string, char* string_2)
{
    double x_1, y_1, x_2, y_2, D;
    double radius, radius_2;
    int i = 1;
    x_1 = get_point(string, i);
    while (string[i] != ' ') {
        i++;
    }
    y_1 = get_point(string, i);
    radius = get_radius(string);

    i = 1;
    x_2 = get_point(string_2, i);
    i++;
    while (string_2[i] != ' ') {
        i++;
    }
    y_2 = get_point(string_2, i);
    radius_2 = get_radius(string_2);

    D = sqrt((pow (x_2 - x_1, 2))+(pow (y_2 - y_1, 2)));
    if (D <= radius + radius_2){
	printf("Circles match\n");}
	else if (D > radius + radius_2) {
    printf("Circles no match\n");}
}

