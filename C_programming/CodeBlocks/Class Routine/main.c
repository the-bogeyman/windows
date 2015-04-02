#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "routine.h"

int main()
{
    int day;
    char decision;

    day=get_day();
    print_start_msg();
    if(day == 0)
    {
        print_error();
    }
    else
    {
        routine_header();
        show_routine(day);
        if(day == 7);
        {
            day=0;
        }
        printf("\n\n\tTomorrow's Routine :\n\n");
        routine_header();
        show_routine(day+1);
    }
    printf("\n\nPress 1 to see the full routine, or any other key to exit...\n");
    decision=getch();
    if(decision == '1')
    {
        system("cls");
        routine_header();
        show_full_routine();
        printf("\n\nPress any key to continue...");
        getch();
    }
    return 0;
}
