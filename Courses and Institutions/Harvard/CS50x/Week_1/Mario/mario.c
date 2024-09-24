#include <stdio.h>

int main(void)
{
    int height;
    int spaces;
    do
    {
        scanf("%d", &height);
    } while (height <= 0);

    for (int i = 0; i <= height; i++)
    {
        spaces = height - i;
        for (int j = spaces; j > 0; j--)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("  "); // This is the space between
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
