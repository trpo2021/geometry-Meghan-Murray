#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    short int n, i, j;
    char m1[10] = "circle";
    char m2[10];
    int x, y, r, S, P;
    printf("How many figures do you work with?\n");
    scanf("%hd", &n);
    int Xc[n], Yc[n], Rc[n];
    printf("Enter name of figures: ");
    for (i = 1; i <= n; i++) {
        scanf("%s", m2);
        if (strcmp(m1, m2) == 0) {
            printf("Enter coordinates x and y of the center: ");
            scanf("%d", &x);
            Xc[i] = x;
            scanf("%d", &y);
            Yc[i] = y;
            printf("Enter radius: ");
            scanf("%d", &r);
            Rc[i] = r;
            S = 3.14 * pow(r, 2);
            P = 2 * 3.14 * r;
            printf("\nCircle %d \n S = %d \n P = %d\n\n", i, S, P);
            for (j = 1; j < i; j++) {
                if ((Rc[j] + Rc[i])
                    > (sqrt((pow(Xc[i] - Xc[j], 2) + pow(Yc[i] - Yc[j], 2))))) {
                    printf("intersections: ");
                    printf("Circle %d\n", j);
                }
            }
            if (i != n)
                printf("Enter name of figures: ");
        } else
            printf("Error\n");
    }
    return 0;
}
