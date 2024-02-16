#include <stdio.h>

int main(void)
{
    char answer[50];
    printf("What's your name?\n");
    scanf("%s", answer);
    printf("Hello, %s!\n", answer);
    return 0;
}
