#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start = 0;
    while(start < 9){
        start = get_int("Enter Start Size :");
    }
    // TODO: Prompt for end size
    int end;
    do{
        end = get_int("Enter End Size :");
    }
    while(!(end > start));
    // TODO: Calculate number of years until we reach threshold
    int yrs = 0;

    while(start < end){
        start = start + (start/3) - (start/4);
        yrs++;
    }

    // TODO: Print number of years
    printf("Years: %i", yrs);
}
