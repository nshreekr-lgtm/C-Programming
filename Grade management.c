#include <stdio.h>

char grade(float p)
{
    if (p >= 90)
        return 'A';
    else if (p >= 75)
        return 'B';
    else if (p >= 60)
        return 'C';
    else if (p >= 50)
        return 'D';
    else
        return 'F';
}

int main()
{
    int n, i, j;
    float marks[10][3], total, percentage;
    char name[10][20];

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter name: ");
        scanf("%s", name[i]);

        total = 0;

        for (j = 0; j < 3; j++)
        {
            printf("Enter mark: ");
            scanf("%f", &marks[i][j]);
            total = total + marks[i][j];
        }

        percentage = total / 3;

        printf("Total = %.2f\n", total);
        printf("Percentage = %.2f\n", percentage);
        printf("Grade = %c\n", grade(percentage));
    }

    return 0;
}