#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    // get height from user
    do
    {
        height = get_int("Height: ");
    }
    while (height > 8 || height < 1);

    // each row from top to bottom
    for (int a = 0; a < height; a++)
    {
        // space in front
        for (int space = a; space < height - 1; space++)
        {
            printf(" ");
        }
        // left pyramid
        for (int b = -1; b < a; b++)
        {
            printf("#");
        }
        printf("\n");
    }
}