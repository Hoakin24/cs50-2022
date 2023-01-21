#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // This will ask the user for their name.
    string name = get_string("What's your name? ");
    // This will greet the user with their name.
    printf("hello, %s\n", name);
}