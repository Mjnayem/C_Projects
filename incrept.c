#include<stdio.h>
#include<string.h>
int main()
{
    FILE *in,*de;
    char ch;
    in=fopen("QUESTION1.txt","r");
    de=fopen("finalquestion.txt","w");
    while((ch=fgetc(in))!=EOF)
    {
        fprintf(de,"%c",ch^209319);

    }
    return 0;
}
