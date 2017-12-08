#include<stdio.h>
#include<string.h>
#include<windows.h>
FILE*fi,*hsc;
char qu[200],ch,q[1000],ordi[100];
char chose,fifty[100];
int life_num=3,scan_code,code1=1,code2=1,code3=1,money=500;
int fifty_fifty()
{
    system("cls");
    printf("\nTwo options is:\n");
    printf("%s",fifty);
    printf("\nAns is\n");
    scanf("%c",&ch);
    getchar();
}
int snd_ti()
{
    system("cls");
    printf("Now u can give ans this question 2 times\nif 1st ans is wrong u can give another ans\n");
    scanf("%c",&ch);
    getchar();
    if(ch!=qu[0])
    {
        printf("Wrong ans\n   Press another option\n");
        scanf("%c",&ch);
        getchar();
    }
}
int persentage()
{
    system("cls");
    printf("\nThe result of ordeans votes:\n");
    printf("\n%s",ordi);
}
int life_line()
{
    system("cls");
    if(life_num>=1)
    {
        printf("you have %d active life line \n",life_num--);
    }
    if(life_num<0)
    {
        printf("You used all your life line\n");
    }
    if(code1==1)
        printf("press 1 for 50/50\n");
    if(code2==1)
        printf("press 2 for 2nd time answer\n");
    if(code3==1)
        printf("press 3 for Audience vote\n");
    scanf("%d",&scan_code);
    getchar();
    if(scan_code==1)
    {
        fifty_fifty();
        code1=0;
    }
    if(scan_code==2)
    {
        snd_ti();
        code2=0;
    }
    if(scan_code==3)
    {
        persentage();
        code3=0;
        scanf("%c",&ch);
        getchar();
    }
}
int play()
{
    int lifenumb=1,total=0;
    FILE*intro;
    char a[1000],ch1,ch5,l;
    intro=fopen("Instructions.txt","r");
    system("cls");
    while((ch1=fgetc(intro))!=EOF)
    {
        Sleep(20);
        printf("%c",ch1);
    }
    printf("\n\n\nPRESS ENTER TO CONTINUE.....\n");
    getchar();
    int i=0,f=1,high=0;

    fi=fopen("finalquestion.txt","r");
    system("cls");
    while(f)
    {
        i=0;
        while((ch=fgetc(fi)^209319)!=EOF)
        {
            if(ch=='$')
            {
                q[i++]='\n';
                continue;
            }
            if(ch=='#')break;

            q[i++]=ch;
        }
        q[i]='\0';
        i=0;
        while((ch=fgetc(fi)^209319)!='@')
        {
            qu[i++]=ch;
        }
        qu[i]='\0';

        i=0;
        while((ch=fgetc(fi)^209319)!='!')
        {
            fifty[i++]=ch;
        }
        fifty[i]='\0';
        i=0;
        while((ch=fgetc(fi)^209319)!='&')
        {
            ordi[i++]=ch;
        }
        ordi[i]='\0';
        l:
        printf("%s\n",q);
        if(lifenumb<4)
        {
            printf("\nEnter your ans: ");
            printf("\n                                           Life line");
            printf("\n                                           Press...");
            printf("\n                                          *        *    ");
            printf("\n                                            *    *       ");
            printf("\n                                               *        ");
            printf("\n                                            *     *     ");
            printf("\n                                          *         *  ");
        }
        scanf("%c",&ch);
        getchar();

        if(ch=='X'||ch=='x')
        {
            if(lifenumb>=4)
            {
                system("cls");
                printf("you used all your life lines\nIf u want to play press Y or N for not\n");
                scanf("%c",&ch5);
                getchar();
                if(ch5=='Y'||ch5=='y')
                    goto l;
                    if(ch5=='N'||ch5=='n')
                    {
                        printf("BETTER LUCK NEXT TIME");
                        return 0;
                    }

            }
            else
            {
            life_line();
            lifenumb++;
            }

        }
        getchar();
        system("cls");
        if(ch==qu[0])
        {
            system("cls");
            printf("Your ans is Right\n");
            f=1;
            money=money*2;
            if(money==4000)
                money=5000;
            if(money==40000)
                money=50000;
            if(money==400000)
                money=500000;
            if(money==4000000)
                money=5000000;
        }
        else
        {
            printf("Wrong ans\n");
            printf("Correct ans is: %s\n",qu);
            f=0;

        }
        if(money==5000&&f!=0)
        {
            total=money;
            printf("Congratulation.....\nyou have cross level 1\nNow %d taka is yours...\nif u want to continue the game press Y or for not press N\n",money);
            scanf("%c",&chose);
            getchar();
            if(chose=='Y'||chose=='y')
                f=1;
            if(chose=='N'||chose=='n')
                f=0;
        }
        if(money==50000&&f!=0)
        {
            total=money;
            printf("Congratulation.....\nyou have cross level 2\nNow %d taka is yours...\nif u want to continue the game press Y or for not press N\n",money);
            scanf("%c",&chose);
            getchar();
            if(chose=='Y'||chose=='y')
                f=1;
            if(chose=='N'||chose=='n')
                f=0;
        }
        if(money==500000&&f!=0)
        {
            total=money;
            printf("Congratulation.....\nyou have cross level 3\nNow %d taka is yours...\nif u want to continue the game press Y or for not press N\n",money);
            scanf("%c",&chose);
            getchar();
            if(chose=='Y'||chose=='y')
                f=1;
            if(chose=='N'||chose=='n')
                f=0;
        }
        if(money==5000000&&f!=0)
        {
            total=money;
            printf("Congratulation.....\nyou have cross level 4\nNow %d taka is yours...\nif u want to continue the game press Y or for not press N\n",money);
            scanf("%c",&chose);
            getchar();
            if(chose=='Y'||chose=='y')
                f=1;
            if(chose=='N'||chose=='n')
                f=0;
        }
        if(money==10000000&&f!=0)
        {
            total=money;
            FILE*cong;
            char co[500],cho;
            cong=fopen("congrats.txt","r");
            while((cho=fgetc(cong))!=EOF)
            {
                Sleep(20);
                printf("%c",cho);
            }
            f=0;
        }
    }
    printf("You get %d taka from this game.",total);
    if(f==0&&money!=10000000)
    {
        getchar();
        system("cls");
        printf("sorry.........\nYou lost the game..\nGood luck for next time...");
    }
    return 0;
}
void developer()
{
    FILE*info;
    char a[500],ch;
    system("cls");
    info=fopen("information.txt","r");
    while((ch=fgetc(info))!=EOF)
    {
        Sleep(40);
        printf("%c",ch);
    }
}
int gm_info()
{
    FILE*info;
    char a[500],chin;
    system("cls");
    info=fopen("gameinfo.txt","r");
    while((chin=fgetc(info))!=EOF)
    {
        Sleep(40);
        printf("%c",chin);
    }
}
int main()
{
    char a,b,c,d;
    printf("Chose your choice.\n\n\nPress 1 for play game.\npress 2 for know about tnis game.\nPress 3 to know about the game Developer.\nPress 4 to Exit\n");
    scanf("%c",&a);
    getchar();
    if(a=='1')
        play();
    if(a=='3')
        developer();
    if(a=='2')
        gm_info();
    if(a==4)
        return 0;
}
