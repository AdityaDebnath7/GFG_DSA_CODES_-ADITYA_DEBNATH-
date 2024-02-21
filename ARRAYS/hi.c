#include <stdio.h>
int main()
{
    int n, a[100], flag = 1, j = 0, dc = 0, k;
    printf("enter the number of elements: \n");
    scanf("%d", &n);
    printf("\n enter %d ordered integers: \n", n);
    scanf("%d", &a[0]);
    do
    {
        scanf("%d", &k);
        if (k > a[j])
        {
            a[j + 1] = k;
            j++;
            if(!(flag))dc=0;
        }
        else if (k < a[j])
        {
            printf("enter a number which is greater than %d\n", a[j]);
            if(!(flag))dc=0;
        }
        else
        {
            if (flag || dc)
            {
                a[j + 1] = k;
                j++;
                flag = 0;
                dc++;
            }
            else printf("duplicates can be made for only one number\n");
        }
    } while (j < n);

    for (int j = 0; j < n; j++)
    {
        printf("%d", a[j]);
    }
}