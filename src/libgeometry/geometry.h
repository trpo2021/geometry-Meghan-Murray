#pragma once

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int skip_space(char input_str[], int i);
int check_point(char input_str[], int i, int* k);
int check_rad(char input_str[], int i, int* k);
int correct_str(char input_str[]);
void output(char* output_str);
void str_copy(char input_str[], char* output_str);
double perimeter(char* output_str);
double area(char* output_str);
double get_radius(char* output_str);
double get_point(char* output_str, int i);
void out_error(int x);
int intersection(char* output_str, char* output_str_2);
