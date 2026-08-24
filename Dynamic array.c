#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *a, n, i, max, min;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    a = (int *)malloc(n * sizeof(int));

    if(a == NULL)
    {
        printf("Memory not allocated");
        return 0;
    }

    printf("Enter elements:\n");

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    max = min = a[0];

    for(i = 0; i < n; i++)
    {
        if(a[i] > max)
            max = a[i];

        if(a[i] < min)
            min = a[i];
    }

    printf("Maximum = %d\n", max);
    printf("Minimum = %d\n", min);

    free(a);

    return 0;
}
