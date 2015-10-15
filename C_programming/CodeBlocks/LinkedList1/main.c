#include <stdio.h>
#include <stdlib.h>

struct student_data
{
    char name[25];
    char id[11];
    int contact;
    struct student_data *next;
};

typedef struct student_data stu_struct;

void take_input_stu_data(stu_struct *working);
void add_stu_data_first(stu_struct *working, int *total);
void add_stu_data_middle(stu_struct *working, int *total);
void add_stu_data_last(stu_struct *working, int *total);
void rem_stu_data(int *total);
void list_all(int *total);

struct student_data *head;

int main()
{
    int menu_input, total_num=0;
    struct student_data *current;
    head=NULL;
    current=(struct student_data *)malloc(sizeof(stu_struct));

    while(1)
    {
        puts("1. Input new data");
        puts("2. Remove existing student data");
        puts("3. List all student data");
        puts("4. Exit");
        printf("Number of student data entered : %d\n", total_num);
        printf("Input your choice : ");
        scanf("%d", &menu_input);

        switch(menu_input)
        {
        case 1:
        {
            system("cls");
            take_input_stu_data(current);
            system("cls");
            puts("1. Add to the first");
            puts("2. Add in the middle");
            puts("3. Add to the last");
            printf("Choose : ");
            scanf("%d", &menu_input);

            switch(menu_input)
            {
            case 1:
            {
                system("cls");
                add_stu_data_first(current, &total_num);
                system("pause");
                system("cls");
                current=(struct student_data *)malloc(sizeof(stu_struct));
                break;
            }
            case 2:
            {
                system("cls");
                add_stu_data_middle(current, &total_num);
                system("pause");
                system("cls");
                current=(struct student_data *)malloc(sizeof(stu_struct));
                break;
            }
            case 3:
            {
                system("cls");
                add_stu_data_last(current, &total_num);
                system("pause");
                system("cls");
                current=(struct student_data *)malloc(sizeof(stu_struct));
                break;
            }
            }
            break;
        }
        case 2:
        {
            system("cls");
            rem_stu_data(&total_num);
            system("pause");
            system("cls");
            break;
        }
        case 3:
        {
            system("cls");
            list_all(&total_num);
            system("pause");
            system("cls");
            break;
        }
        case 4:
        {
            return 0;
        }
        }
    }

    return 0;
}


void take_input_stu_data(stu_struct *working)
{
    puts("Input student name:");
    scanf("%s", working->name);
    puts("Input student ID:");
    scanf("%s", working->id);
    puts("Input contact no:");
    scanf("%d", &working->contact);
    working->next=NULL;
}

void add_stu_data_first(stu_struct *working, int *total)
{

    if(head == NULL)
    {
        head=working;
    }
    else
    {
        working->next=head;
        head=working;
    }
    *total=(*total)+1;
}

void add_stu_data_last(stu_struct *working, int *total)
{
    stu_struct *curr=head;

    if(head == NULL)
    {
        head=working;
    }
    else
    {
        while(curr->next != NULL)
        {
            curr=curr->next;
        }
        curr->next=working;
    }
    *total=(*total)+1;
}

void add_stu_data_middle(stu_struct *working, int *total)
{
    stu_struct *curr=head;
    stu_struct *prev=NULL;
    int index=0, i;
    if(*total == 0)
    {
        puts("No data available...The input will the first one.\n");
        add_stu_data_first(working, total);
    }
    else
    {
        printf("Input where you want to put the data: %d positions available\n", *total);
        do
        {
            scanf("%d", &index);
            if(index<0 || index>(*total))
            {
                puts("Position is out of range. Please input again...");
            }
            else
            {
                break;
            }
        }
        while(1);
        for(i=1; i<index; i++)
        {
            prev=curr;
            curr=curr->next;
        }
        prev->next=working;
        working->next=curr;
        *total=(*total)+1;
    }
}

void rem_stu_data(int *total)
{
    stu_struct *curr=head;
    stu_struct *prev=NULL;

    int index, i;
    if(*total == 0)
    {
        puts("No data to remove...");
    }
    else
    {
        printf("Input where you want to put the data: %d positions available\n", *total);
        do
        {
            scanf("%d", &index);
            if(index<0 || index>(*total))
            {
                puts("Position is out of range. Please input again...");
            }
            else
            {
                break;
            }
        }
        while(1);
    }
    if(index == 1)
    {
        head=head->next;
        free(curr);
        *total=(*total)-1;
    }
    else
    {
        for(i=1; i<index; i++)
        {
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        free(curr);
        *total=(*total)-1;
    }
}

void list_all(int *total)
{

    stu_struct *curr;
    curr=head;

    if(*total == 0)
    {
        puts("No data is entered yet...");
    }
    else
    {
            while(curr != NULL)
        {
            puts("Input student name:");
            printf("%s\n", curr->name);
            puts("Input student ID:");
            printf("%s\n", curr->id);
            puts("Input contact no:");
            printf("%d\n\n\n", curr->contact);
            curr=curr->next;
    }
    }
}
