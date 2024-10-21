#include<stdio.h>

void main()
{       
    int n,number,i,flag,low,high,middle,position;

     printf("\nenter the size of array\n");
     scanf("%d",&n);
     printf("Enter the number you want to search\n");
     scanf("%d",&number); 
     int num[n];
     printf("Enter The Elements Of arrya\n");
        for ( i = 0; i < n; i++)
         {
            scanf("%d",&num[i]);
         }
     low=0,high=n-1,flag=0;

 step5:if (low<=high)
     {
        middle=(low+high)/2;
     }
     else
        goto step8;
     
     if (num[middle]==number)
     {
        position=middle,flag=1;goto step8;
     }
     else if (number<num[middle])
     {
        high=middle-1;
     }
     else
        low=middle+1;
        goto step5;

step8:
      if (flag==1)
      {
        printf("Required Number is found at location  %d",position+1);
      }
      else
      {
        printf("required data not found");
      }
      
      
}
     
     
