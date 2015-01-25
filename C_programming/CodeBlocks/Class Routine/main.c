#include <stdio.h>
#include <stdlib.h>
#include "routine.h"

int main()
{
    int day;
    day=get_day();
    print_start_msg();
    if(day == 0)
    {
        print_error();
    }
    else
    {
        show_routine(day);
    }
    printf("\n\n");
    system("pause");
    return 0;
}
