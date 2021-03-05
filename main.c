#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    short int n, i, j;
    char shape[20] = "circle";
    char line[20];
    int x, y, r, S, P;
    printf("How many figures do you work with?\n");
    if (!scanf("%hd", &n)) {
        printf("Error. The entered value is not a number\n");
    } else {
        int Xc[n], Yc[n], Rc[n];
        printf("Enter name of figures: ");
        for (i = 1; i <= n; i++) {
            scanf("%s", line);
            if (strcmp(shape, line) == 0) {
                printf("Enter coordinates x and y of the center: ");
                if (!scanf("%d %d", &x, &y)) {
                    printf("Error. The entered value is not a number\n");
                    return 0;
                } else {
                    Xc[i] = x;
                    Yc[i] = y;
                }
                printf("Enter radius: ");
                if ((!scanf("%d", &r)) || (r <= 0)) {
                    printf("Error. Enter a positive number\n");
                    return 0;
                } else {
                    Rc[i] = r;
                    S = 3.14 * pow(r, 2);
                    P = 2 * 3.14 * r;
                    printf("\nCircle %d \n S = %d \n P = %d\n\n", i, S, P);
                    for (j = 1; j < i; j++) {
                        if ((Rc[j] + Rc[i]) > (sqrt(
                                    (pow(Xc[i] - Xc[j], 2)
                                     + pow(Yc[i] - Yc[j], 2))))) {
                            printf("intersections: ");
                            printf("Circle %d\n", j);
                        }
                    }
                }
                if (i != n)
                    printf("Enter name of figures: ");
            } else {
                printf("Error. Enter the correct name e.g. 'circle'\n");
                return 0;
            }
        }
    }
    return 0;
}
