#include "geometry.h"

int skip_space(char input_str[], int i)
{
    while (input_str[i] == ' ') {
        i++;
    }
    return i;
}

void out_error(int x)
{
    switch (x) {
    case 1:
        printf("Circles match: not intersect\n");
        break;
    case 2:
        printf("Circles don't touch: not intersect\n");
        break;
    case 3:
        printf("Circles touch at one point: not intersect\n");
        break;
    case 4:
        printf("Circles intersect\n");
        break;
    case -1:
        printf("Error: expected 'circle'\n");
        break;
    case -2:
        printf("Error: expected '('\n");
        break;
    case -3:
        printf("Error: expected 'number or , '\n");
        break;
    case -4:
        printf("Error: expected ')'\n");
        break;
    case -5:
        printf("Error: unexpected token\n");
        break;
    case -6:
        printf("Error: expected '<double>'\n");
        break;
    case -7:
        printf("Error: expected '<unsigned double>'\n");
        break;
    default:
        printf("Input is correct\n(case insensitive and ignoring "
               "whitespace)\n");
        break;
    }
}

int check_point(char input_str[], int i, int* k)
{
    int j = 0;
    if (input_str[i] == '-') {
        i++;
        (*k)++;
    }
    if (isdigit(input_str[i]) == 0) {
        return -6;
    }
    while ((isdigit(input_str[i]) > 0) || (input_str[i] == '.')) {
        if ((input_str[i] == '.') && (j == 0)) {
            j = i;
        }
        i++;
        (*k)++;
        if ((input_str[i] == '.') && (j > 0)) {
            return -6;
        }
    }
    if ((input_str[j] == '.') && (isdigit(input_str[j + 1]) == 0)) {
        return -6;
    }
    return i;
}

int check_rad(char input_str[], int i, int* k)
{
    int j = 0;
    if (isdigit(input_str[i]) == 0) {
        return -7;
    }
    while ((isdigit(input_str[i]) > 0) || (input_str[i] == '.')) {
        if ((input_str[i] == '.') && (j == 0)) {
            j = i;
        }
        i++;
        (*k)++;
        if ((input_str[i] == '.') && (j > 0)) {
            return -6;
        }
    }
    if ((input_str[j] == '.') && (isdigit(input_str[j + 1]) == 0)) {
        return -6;
    }
    return i;
}

int correct_str(char input_str[])
{
    char check_str[] = {'c', 'i', 'r', 'c', 'l', 'e'};
    int i = 0, k = 0, g = 0;
    i = skip_space(input_str, i);
    for (; (input_str[i] != '(') && (isalpha(input_str[i]) > 0);
         i++, k++, g++) {
        if (check_str[g] != (tolower(input_str[i]))) {
            return -1;
        }
    }
    i = skip_space(input_str, i);
    if (input_str[i] != '(') {
        return -2;
    } else {
        i++;
        k++;
    }
    i = skip_space(input_str, i);
    i = check_point(input_str, i, &k);
    if (i == -1) {
        return -1;
    }
    k++;
    i = skip_space(input_str, i);
    i = check_point(input_str, i, &k);
    if (i == -1) {
        return -1;
    }
    i = skip_space(input_str, i);
    if (input_str[i] != ',') {
        return -3;
    } else {
        i++;
        k++;
    }
    k++;
    i = skip_space(input_str, i);
    i = check_rad(input_str, i, &k);
    if (i == -1) {
        return -1;
    }
    i = skip_space(input_str, i);
    if (input_str[i] != ')') {
        return -4;
    } else {
        i++;
        k++;
    }
    i = skip_space(input_str, i);
    if (input_str[i] != '\n') {
        return -5;
    }
    return k;
}

void str_copy(char input_str[], char* output_str)
{
    int i = 0, j;
    i = skip_space(input_str, i);
    for (j = 0; (input_str[i] != '(') && (input_str[i] != ' '); i++, j++) {
        output_str[j] = input_str[i];
    }
    output_str[j] = '(';
    j++;
    while ((input_str[i] != '-') && (isdigit(input_str[i]) == 0)) {
        i++;
    }
    for (; input_str[i] != ' '; i++, j++) {
        output_str[j] = input_str[i];
    }
    output_str[j] = ' ';
    j++;
    i = skip_space(input_str, i);
    for (; (input_str[i] != ',') && (input_str[i] != ' '); i++, j++) {
        output_str[j] = input_str[i];
    }
    output_str[j] = ',';
    j++;
    output_str[j] = ' ';
    j++;
    i = skip_space(input_str, i);
    if (input_str[i] == ',') {
        i++;
    }
    i = skip_space(input_str, i);
    for (; (input_str[i] != ')') && (input_str[i] != ' '); i++, j++) {
        output_str[j] = input_str[i];
    }
    output_str[j] = ')';
    j++;
    output_str[j] = '\0';
}
void output(char* output_str)
{
    fputs(output_str, stdout);
    printf("\n");
}
