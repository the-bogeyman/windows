/******************************************************************************
* TTTTTTTTT H    H EEEEE    BBB    O   GGGG  EEEEE MM   MM     A     NN    N  *
*     T     H    H E        B  B  O O  G     E     M M M M    A A    N N   N  *
*     T     HHHHHH EEE  --- BBB  O   O G GGG EEE   M  M  M   AAAAA   N  N  N  *
*     T     H    H E        B  B  O O  G  GG E     M     M  A     A  N   N N  *
*     T     H    H EEEEE    BBB    O    GG G EEEEE M     M A       A N    NN  *
*                                                                             *
******************************************************************************/

/*
This source code is available for anyone to edit, rewrite or take any part of code for another program or project.
But please give me credit for my part of work in your project.
*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "routine.h"

#define DATE_LENTH 25
#define SOURCE_SITE "github.com/the-bogeyman"
#define EMAIL "ibrahim15-4739@diu.edu.bd"
#define VERSION 2

int get_day(void)
{
    time_t mytime;
    int i;
    char full_date[DATE_LENTH];
    mytime = time(NULL);
    strcpy(full_date,ctime(&mytime));
    for(i = 0; i < DATE_LENTH; i++)
    {
        if((full_date[i] == 'S' || full_date[i] == 's') && (full_date[i+1] == 'A' || full_date[i+1] == 'a') && (full_date[i+2] == 'T' || full_date[i+2] == 't'))
        {
            return 1;
        }
        if((full_date[i] == 'S' || full_date[i] == 's') && (full_date[i+1] == 'U' || full_date[i+1] == 'u') && (full_date[i+2] == 'N' || full_date[i+2] == 'n'))
        {
            return 2;
        }
        if((full_date[i] == 'M' || full_date[i] == 'm') && (full_date[i+1] == 'O' || full_date[i+1] == 'o') && (full_date[i+2] == 'N' || full_date[i+2] == 'n'))
        {
            return 3;
        }
        if((full_date[i] == 'T' || full_date[i] == 't') && (full_date[i+1] == 'U' || full_date[i+1] == 'u') && (full_date[i+2] == 'E' || full_date[i+2] == 'e'))
        {
            return 4;
        }
        if((full_date[i] == 'W' || full_date[i] == 'w') && (full_date[i+1] == 'E' || full_date[i+1] == 'e') && (full_date[i+2] == 'D' || full_date[i+2] == 'd'))
        {
            return 5;
        }
        if((full_date[i] == 'T' || full_date[i] == 't') && (full_date[i+1] == 'H' || full_date[i+1] == 'h') && (full_date[i+2] == 'U' || full_date[i+2] == 'u'))
        {
            return 6;
        }
        if((full_date[i] == 'F' || full_date[i] == 'f') && (full_date[i+1] == 'R' || full_date[i+1] == 'r') && (full_date[i+2] == 'I' || full_date[i+2] == 'i'))
        {
            return 7;
        }
    }
    return 0;
}

void show_routine(int day_num, char show_tom)
{
    printf("Day\t\tSubject\t\tTime\t\t\tRoom no.\n=======================================================================\n\n");
    switch(day_num)
    {
    case 1:
        {
            printf("Saturday\tPHY-113\t\t1:00pm-2:30pm\t\t101PP/104 PP\n");
            break;
        }
    case 2:
        {
            printf("Sunday\tMAT-111\t\t1:00pm-2:30pm\t\t501 AB\n");
            break;
        }
    case 3:
        {
            printf("=>>  No Class  <==\n");
            break;
        }
    case 4:
        {
            printf("=>>  No Class  <==\n");
            break;
        }
    case 5:
        {
            printf("Wednesday\tCSE-112\t\t8:30am-10:00am\t\t504 AB\n");
            printf("Wednesday\tMAT-111\t\t10:00am-11:30am\t\t306 AB\n");
            break;
        }
    case 6:
        {
            printf("Thursday\tCSE-112\t\t11:30am-1:00pm\t\tL-202 M\n");
            printf("Thursday\tENG-113\t\t2:30pm-4:00pm\t\t107 PP\n");
            printf("Thursday\tPHY-113\t\t4:00pm-5:30pm\t\t110 PP\n");
            break;
        }
    case 7:
        {
            printf("=>>  No Class  <==\n");
            break;
        }
    default:
        {
            print_error();
        }
    }
    if(show_tom == 'y')
    {
        printf("\n\n\tTomorrow's Routine :\n\n");
        show_routine(day_num+1,'n');
    }
}

void print_error(void)
{
    printf("\nERROR!!!\n\nOne or another function is not working properly...\n\n");
    printf("Please review latest code if possible at %s,\nor Email the developer at %s\n\n",SOURCE_SITE,EMAIL);
    system("pause");
    exit(0);
}

void print_start_msg(void)
{
    system("color 0a");
    printf("Class routine of DIU-40th batch-Section E.\n");
    printf("Version %d\n\n\tToday's Routine :\n\n",VERSION);
}
