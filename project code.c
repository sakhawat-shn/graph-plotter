#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int x[100],y[100],c;                                              //global variable and array.

int draw(int *point)                                             //user defined funcion
                                                                                    //wint a pointer variable.
{
    int X,Y,i,n_x,pwr=*point;
    char str[40]="small Y=1 unit,small X=0.1 unit.";             //string.

    float valu,ix;
    for(Y=25;Y>=-25;Y--)                                        //for loop.
    {
        for(X=-70;X<=70;X++)                                    //for loop to X & Y variable to make the graph.
        {
            if(Y==18&&X>37)
            {
                printf("%c",str[X-38]);
                continue;
            }
            else if(X==0)
            {
                if(Y%10==0)
                {
                    printf("-");
                }
                else
                {
                    printf("|");
                }

                continue;
            }
            else if(Y==0)
            {
                if(X%10==0)
                {
                    printf("|");
                }
                else
                {printf("_");}
                continue;
            }
            valu=0;
            ix=(float)X/10;
            for(i=0;i<pwr;i++)
            {
                valu=valu+(float)x[i]*pow(ix,i+1)+(float)y[i]*pow(Y,i+1);
            }
            valu=valu+(float)c;

            n_x=10*valu;
            if(n_x==1||n_x==-1){n_x=0;}



            if(n_x==0)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }


        }
        printf("\n");
    }
}


int main()
{
    int pw,i;
    char cmd='Y',ch;
    for(;!(cmd=='N'||cmd=='n');)                                        //for loop
    {
        system("cls");
        printf("Please input the equation degree.\n");
        scanf("%d",&pw);
        for(i=0;i<pw;i++)
        {
            printf("Input coefficient of X^%d\n",i+1);
            scanf("%d",&x[i]);
            printf("Input coefficient of Y^%d\n",i+1);
            scanf("%d",&y[i]);
        }
        printf("Input conostant C\n");
        scanf("%d",&c);

        draw(&pw);                                                      //call by reference.
        printf("Do you want o draw another graph ?\nInput Y/N....");
        scanf(" %c",&cmd);



    }
    return 0;
}
