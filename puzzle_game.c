#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<conio.h>
#include<time.h>

void  generateMatrix(int arr[4][4])
{
    int n=15;
    int num[n],i,j;
    for(i=0;i<15;i++)
    num[i]=i+1;



    srand(time(NULL));           // for random number generation

    int lastIndex=n-1,index;

    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
           {
               if(lastIndex>=0)
                {
	               index=rand()%(lastIndex+1);
                    arr[i][j]=num[index];
                   num[index]=num[lastIndex--];
                }
            }
       arr[i-1][j-1]=0;

}

void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;

}

int winsit(int arr[][4])
{
    int i,j,k=1;
    for(i=0;i<4;i++)
   {
        for(j=0;j<4;j++,k++)
        if(arr[i][j]!=k && k!=16)
        break;

   }
        if(i==3&&j==3)
        return 1;
        return 0;
}


int pressedkey()
{
	char c;
	c=getch();

	return c;
}
void RuleOfGame(int arr[][4])
{
    system("cls");
    int x;
    int i,j,k=1;
    printf("                 RULE OF THIS GAME                 \n");
    printf("\n1.You can move only 1 step at a time by pressing key ");
    printf("\nMove Up   : by Up arrow key");
    printf("\nMove Down : by Down arrow key");
    printf("\nMove Left : by Left arrow key");
    printf("\nMove Right: by Right arrow key");

    printf("\n2.You can move number at empty position only ");
    printf("\n");
    printf("\n3.For each valid move : your total number of move will decreased by 1 \n");
    printf("4.Wining situation : ");
    printf("number in a 4*4 matrix should be in order from 1 to 15 ");
    printf("\n\n            winning situation:         \n");

    printf("----------------------\n");
    for(i=0;i<4;i++)
   {
       for(j=0;j<4;j++)
    {
       // printf("%-2d  ",k++);

        if(i==3&&j==3)
        printf("   ");
        else
        printf("%-2d  ",k++);

    }
    printf("\n");
   }

    printf("----------------------\n");
    printf("\n5.You can exit the game at any time by pressing 'E' or 'e' ");


    printf("\nSo Try to win in minimum no of move \n");
    printf("\n         Happy gaming , Good Luck\n");

    printf("\nEnter any key to start.....   : ");
    x=pressedkey();
}


int shiftUp(int arr[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            if(arr[i][j]==0)
            break;
        if(j<4)
        break;
    }
      if(i==3)                 // shifting not possible
        return 0;
        swap(&arr[i][j],&arr[i+1][j]);
        return 1;               // shift up success
}

int shiftDown(int arr[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            if(arr[i][j]==0)
            break;
        if(j<4)
        break;
    }
      if(i==0)                 // shifting not possible
        return 0;
         swap(&arr[i][j],&arr[i-1][j]);    // swap numbers

        return 1;               // shift up success
}

int shiftRight(int arr[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            if(arr[i][j]==0)
            break;
        if(j<4)
       break;
    }
      if(j==0)                 // shifting not possible
        return 0;
             swap(&arr[i][j],&arr[i][j-1]);

        return 1;               // shift up success
}

int shiftLeft(int arr[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            if(arr[i][j]==0)
            break;
        if(j<4)
        break;
    }
      if(j==3)                 // shifting not possible
        return 0;
                swap(&arr[i][j],&arr[i][j+1]);
        return 1;               // shift up success
}


void displayMatrix(int arr[][4])
{
    int i,j;
    printf("----------------------\n");
    for(i=0;i<4;i++)
   {
       for(j=0;j<4;j++)
    {   if(arr[i][j]!=0)
        printf("%2d ",arr[i][j]);
        else
        printf("   ");
    }
    printf("\n");
   }

    printf("----------------------\n");
}




int main()
{
	int Arr[4][4];
	char Player_name[30];
	int i,j;

	int maxTry=50;

	printf("Enter your Name::-\n");
	gets(Player_name);







	system("cls");

	  while(1)
    {             generateMatrix(Arr);
                  RuleOfGame(Arr);

          while(!winsit(Arr))     // checking for winning situation
        {
               system("cls");
               if(!maxTry)
                break;

               printf("\n\n  WELCOME  %s  ,  MOVE REMAINING : %d\n\n",Player_name,maxTry);

              displayMatrix(Arr);


            int key=pressedkey();

        switch(key)
        {
            case 69:                  // ascii of E

            case 101:                 // ascii of e
                        printf("\n     Thanks for Playing ! \n");
                        printf("\nHit 'Enter' to exit the game \n");
                        pressedkey();
                        exit(0);


            case 72:          // arrow up
                        if(shiftUp(Arr))
                        maxTry--;
                        break;
            case 80:          // arrow down
                        if(shiftDown(Arr))
                        maxTry--;
                        break;
            case 77:            // arrow  right
                        if(shiftRight(Arr))
                        maxTry--;
                        break;
            case 75:             // arrow left
                        if(shiftLeft(Arr))
                        maxTry--;
                        break;
            default:

                       printf("\n\n       Not Allowed ");
        }

        }
        if(!maxTry)
         printf("\n\a          YOU LOSE !          \a\a\n");
         else
         { printf("\n\a!!!!!!!!!!!!!Congratualization !!!!!!!!!!!!!\n\a");
           printf("\a               You have Won      \a\a\a ");
         }
         char check;
        printf("\nwant to play again ? \n");
        printf("enter 'y' to play again:  ");
        scanf("%c",&check);
        if(check!='y' && check!='Y')
            break;

    }
    return 0;



}
