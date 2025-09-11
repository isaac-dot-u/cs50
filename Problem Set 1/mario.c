#include <cs50.h>
#include <stdio.h>

void print_pyramid(int h);
void print_row(int i, int h);

int main(void)
{
    int height;
    do
    {
        height = get_int("Height? ");
    }
    while (height < 1 || height > 30);

    print_pyramid(height);
}

void print_pyramid(int h)
{
    for(int i = 1; i <= h; i++)
    {
        print_row(i, h);
    }
}

void print_row(int i, int h)
{
    for(int j = 0; j < h - i; j++)
    {
        printf(" ");
    }
    for(int j = 0; j < i; j++)
    {
        printf("#");
    }
    printf("  ");
    for(int j = 0; j < i; j++)
    {
        printf("#");
    }
    printf("\n");
}
