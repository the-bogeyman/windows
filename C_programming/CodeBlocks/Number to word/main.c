#include <stdio.h>
#include <stdlib.h>

void convert(unsigned int in);
void word(unsigned int in);

int main()
{
    unsigned int input,tmp;

    printf("Type any number to convert : ");
    scanf("%d",&input);
    if(input > 9999999)
    {
        tmp=input%10000000;
        tmp=(input-tmp)/10000000;
        convert(tmp);
        if(tmp != 0)
        {
            printf("Crore ");
        }
        convert(input%10000000);
    }
    else
    {
        convert(input);
    }
    printf("\n\n");
    system("pause");
	return 0;
}

void convert(unsigned int in)
{
    unsigned int tmp;
    if(in > 99999)
    {
        tmp=in%100000;
        tmp=(in-tmp)/100000;
        word(tmp);
        if(tmp != 0)
        {
            printf("Lakh ");
        }
    }
    in=in%100000;
    if(in > 999)
    {
        tmp=in%1000;
        tmp=(in-tmp)/1000;
        word(tmp);
        if(tmp != 0)
        {
            printf("Thousand ");
        }
    }
    in=in%1000;
    if(in > 99)
    {
        tmp=in%100;
        tmp=(in-tmp)/100;
        word(tmp);
        if(tmp != 0)
        {
            printf("Hundred ");
        }
    }
    in=in%100;
    if(in > 0 && in < 100)
    {
        tmp=in;
        word(tmp);
    }
}

void word(unsigned int in)
{
    const char word_group[28][10]={
        "One",
        "Two",
        "Three",
        "Four",
        "Five",
        "Six",
        "Seven",
        "Eight",
        "Nine",
        "Ten",
        "Eleven",
        "Twelve",
        "Thirteen",
        "Fourteen",
        "Fifteen",
        "Sixteen",
        "Seventeen",
        "Eighteen",
        "Nineteen",
        "Twenty",
        "Thirty",
        "Forty",
        "Fifty",
        "Sixty",
        "Seventy",
        "Eighty",
        "Ninety"
    };
    unsigned int a,b;
    if(in <= 20 && in >0)
    {
        printf("%s ", word_group[in-1]);
    }
    else if(in > 20 && in < 100)
    {

        b=in%10;
        a=(in-b)/10;
        if(a > 0 && a <=9)
        {
            printf("%s ",word_group[17+a]);
        }
        if(b > 0 && b <=9)
        {
            printf("%s ", word_group[b-1]);
        }
    }
}
