#include<stdio.h>
void sPrint (char* number, int a)
{
   if(a == 3)
   {
       switch(number[0])
        {
           case 48:
           break;
           case 49:
           printf("One ");
           break;
           case 50:
           printf("Two ");
           break;
           case 51:
           printf("Three ");
           break;
           case 52:
           printf("Four ");
           break;
           case 53:
           printf("Five ");
           break;
           case 54:
           printf("Six ");
           break;
           case 55:
           printf("Seven ");
           break;
           case 56:
           printf("Eight ");
           break;
           case 57:
           printf("Nine ");
           break;
        }
        if(number[0]!=48)
        printf("Hundred");
        if(number[1]!=49)
        {
        switch(number[1])
        {
           case 50:
           printf(" Twenty");
           break;
           case 51:
           printf(" Thrity");
           break;
           case 52:
           printf(" Forty");
           break;
           case 53:
           printf(" Fifty");
           break;
           case 54:
           printf(" Sixty");
           break;
           case 55:
           printf(" Seventy");
           break;
           case 56:
           printf(" Eighty");
           break;
           case 57:
           printf(" Ninety");
           break;
        }
        if(number[2]!=48)
        switch(number[2])
        {
           case 49:
           printf(" One");
           break;
           case 50:
           printf(" Two");
           break;
           case 51:
           printf(" Three");
           break;
           case 52:
           printf(" Four");
           break;
           case 53:
           printf(" Five");
           break;
           case 54:
           printf(" Six");
           break;
           case 55:
           printf(" Seven");
           break;
           case 56:
           printf(" Eight");
           break;
           case 57:
           printf(" Nine");
           break;
        }
       }
       if(number[1] == 49)
       {
           if(number[2] == 48)
           {
               printf(" Ten");
           }
           else if(number[2] == 49)
           {
               printf(" Eleven");
           }
           else if(number[2] == 50)
           {
               printf(" Twelve");
           }
           else if(number[2] == 51)
           {
               printf(" Thirteen");
           }
           else if(number[2] == 52)
           {
               printf(" Fourteen");
           }
           else if(number[2] == 53)
           {
               printf(" Fifteen");
           }
           else if(number[2] == 54)
           {
               printf(" Sixteen");
           }
           else if(number[2] == 55)
           {
               printf(" Seventeen");
           }
           else if(number[2] == 56)
           {
               printf(" Eighteen");
           }
           else if(number[2] == 57)
           {
               printf(" Nineteen");
           }
       }
   }
   else if(a ==2 )
   {
       if(number[0]!=49)
       {
        switch(number[0])
        {
           case 50:
           printf("Twenty ");
           break;
           case 51:
           printf("Thrity ");
           break;
           case 52:
           printf("Forty ");
           break;
           case 53:
           printf("Fifty ");
           break;
           case 54:
           printf("Sixty ");
           break;
           case 55:
           printf("Seventy ");
           break;
           case 56:
           printf("Eighty ");
           break;
           case 57:
           printf("Ninety ");
           break;
        }
        if(number[1]!=48)
        switch(number[1])
        {
           case 49:
           printf("One");
           break;
           case 50:
           printf("Two");
           break;
           case 51:
           printf("Three");
           break;
           case 52:
           printf("Four");
           break;
           case 53:
           printf("Five");
           break;
           case 54:
           printf("Six");
           break;
           case 55:
           printf("Seven");
           break;
           case 56:
           printf("Eight");
           break;
           case 57:
           printf("Nine");
           break;
        }
       }
       if(number[0] == 49)
       {
           if(number[1] == 48)
           {
               printf("Ten");
           }
           else if(number[1] == 49)
           {
               printf("Eleven");
           }
           else if(number[1] == 50)
           {
               printf("Twelve");
           }
           else if(number[1] == 51)
           {
               printf("Thirteen");
           }
           else if(number[1] == 52)
           {
               printf("Fourteen");
           }
           else if(number[1] == 53)
           {
               printf("Fifteen");
           }
           else if(number[1] == 54)
           {
               printf("Sixteen");
           }
           else if(number[1] == 55)
           {
               printf("Seventeen");
           }
           else if(number[1] == 56)
           {
               printf("Eighteen");
           }
           else if(number[1] == 57)
           {
               printf("Nineteen");
           }
       }
   }
   else if(a == 1)
   {
       switch(number[0])
        {
           case 49:
           printf("One");
           break;
           case 50:
           printf("Two");
           break;
           case 51:
           printf("Three");
           break;
           case 52:
           printf("Four");
           break;
           case 53:
           printf("Five");
           break;
           case 54:
           printf("Six");
           break;
           case 55:
           printf("Seven");
           break;
           case 56:
           printf("Eight");
           break;
           case 57:
           printf("Nine");
           break;
        }
   }
}
void Exprint (int a)
{
    if(a == 4)
    {
        printf("Billion ");
    }
    else if(a == 3)
    {
        printf("Million ");
    }
    else if(a == 2)
    {
        printf("Thousand ");
    }
}
void Print (char* number, int a)
{
   if(a == 3)
   {
       switch(number[0])
        {
           case 48:
           break;
           case 49:
           printf("One ");
           break;
           case 50:
           printf("Two ");
           break;
           case 51:
           printf("Three ");
           break;
           case 52:
           printf("Four ");
           break;
           case 53:
           printf("Five ");
           break;
           case 54:
           printf("Six ");
           break;
           case 55:
           printf("Seven ");
           break;
           case 56:
           printf("Eight ");
           break;
           case 57:
           printf("Nine ");
           break;
        }
        if(number[0]!=48)
        printf("Hundred ");
        if(number[1]!=49)
        {
        switch(number[1])
        {
           case 50:
           printf("Twenty ");
           break;
           case 51:
           printf("Thrity ");
           break;
           case 52:
           printf("Forty ");
           break;
           case 53:
           printf("Fifty ");
           break;
           case 54:
           printf("Sixty ");
           break;
           case 55:
           printf("Seventy ");
           break;
           case 56:
           printf("Eighty ");
           break;
           case 57:
           printf("Ninety ");
           break;
        }
        if(number[2]!=48)
        switch(number[2])
        {
           case 49:
           printf("One ");
           break;
           case 50:
           printf("Two ");
           break;
           case 51:
           printf("Three ");
           break;
           case 52:
           printf("Four ");
           break;
           case 53:
           printf("Five ");
           break;
           case 54:
           printf("Six ");
           break;
           case 55:
           printf("Seven ");
           break;
           case 56:
           printf("Eight ");
           break;
           case 57:
           printf("Nine ");
           break;
        }
       }
       if(number[1] == 49)
       {
           if(number[2] == 48)
           {
               printf("Ten ");
           }
           else if(number[2] == 49)
           {
               printf("Eleven ");
           }
           else if(number[2] == 50)
           {
               printf("Twelve ");
           }
           else if(number[2] == 51)
           {
               printf("Thirteen ");
           }
           else if(number[2] == 52)
           {
               printf("Fourteen ");
           }
           else if(number[2] == 53)
           {
               printf("Fifteen ");
           }
           else if(number[2] == 54)
           {
               printf("Sixteen ");
           }
           else if(number[2] == 55)
           {
               printf("Seventeen ");
           }
           else if(number[2] == 56)
           {
               printf("Eighteen ");
           }
           else if(number[2] == 57)
           {
               printf("Nineteen ");
           }
       }
   }
   else if(a ==2 )
   {
       if(number[0]!=49)
       {
        switch(number[0])
        {
           case 50:
           printf("Twenty ");
           break;
           case 51:
           printf("Thrity ");
           break;
           case 52:
           printf("Forty ");
           break;
           case 53:
           printf("Fifty ");
           break;
           case 54:
           printf("Sixty ");
           break;
           case 55:
           printf("Seventy ");
           break;
           case 56:
           printf("Eighty ");
           break;
           case 57:
           printf("Ninety ");
           break;
        }
        if(number[1]!=48)
        switch(number[1])
        {
           case 49:
           printf("One ");
           break;
           case 50:
           printf("Two ");
           break;
           case 51:
           printf("Three ");
           break;
           case 52:
           printf("Four ");
           break;
           case 53:
           printf("Five ");
           break;
           case 54:
           printf("Six ");
           break;
           case 55:
           printf("Seven ");
           break;
           case 56:
           printf("Eight ");
           break;
           case 57:
           printf("Nine ");
           break;
        }
       }
       if(number[0] == 49)
       {
           if(number[1] == 48)
           {
               printf("Ten ");
           }
           else if(number[1] == 49)
           {
               printf("Eleven ");
           }
           else if(number[1] == 50)
           {
               printf("Twelve ");
           }
           else if(number[1] == 51)
           {
               printf("Thirteen ");
           }
           else if(number[1] == 52)
           {
               printf("Fourteen ");
           }
           else if(number[1] == 53)
           {
               printf("Fifteen ");
           }
           else if(number[1] == 54)
           {
               printf("Sixteen ");
           }
           else if(number[1] == 55)
           {
               printf("Seventeen ");
           }
           else if(number[1] == 56)
           {
               printf("Eighteen ");
           }
           else if(number[1] == 57)
           {
               printf("Nineteen ");
           }
       }
   }
   else if(a == 1)
   {
       switch(number[0])
        {
           case 49:
           printf("One ");
           break;
           case 50:
           printf("Two ");
           break;
           case 51:
           printf("Three ");
           break;
           case 52:
           printf("Four ");
           break;
           case 53:
           printf("Five ");
           break;
           case 54:
           printf("Six ");
           break;
           case 55:
           printf("Seven ");
           break;
           case 56:
           printf("Eight ");
           break;
           case 57:
           printf("Nine ");
           break;
        }
   }
}
int main()
{
   char number[10];
   for(int i = 0;i<10;i++)
   {
       number[i] = 'a';
   }
   scanf("%s",number);
   int len = 0;
   for(int i = 0;i<10;i++)
   {
       if(number[i] != 'a' && number[i] != '\0')
       {
           len++;
       }
       else
       {
           break;
       }
   }
   int a = 0;
   if(len>9)
   {
       a = 4;
   }
   else if(len>6)
   {
       a = 3;
   }
   else if(len>3)
   {
       a = 2;
   }
   else
   {
       a = 1;
   }
   int b = len % 3;
   
   if(b == 2||b ==1)
   {
       if(len<3)
       {
            sPrint(number,b);
       }
       else
       {
           Print(number,b);
       }
       Exprint(a);
       a--;
   }
   char num1[3];
   char num2[3];
   char num3[3];
   if(a == 3)
   {
       for(int i = 0;i<3;i++)
       {
           num1[i] = number[i+b]; 
       }
       Print(num1,3);
       Exprint(a--);
       for(int i = b+3;i<b+6;i++)
       {
           num2[i-b-3] = number[i];
       }
       Print(num2,3);
       Exprint(a--);
       for(int i = b+6;i<b+9;i++)
       {
           num3[i-b-6] = number[i];
       }
       sPrint(num3,3);
       Exprint(a--);
   }
    else if(a == 2)
   {
       for(int i = 0;i<3;i++)
       {
           num1[i] = number[i+b]; 
       }
       Print(num1,3);
       Exprint(a--);
       for(int i = b+3;i<b+6;i++)
       {
           num2[i-b-3] = number[i];
       }
       sPrint(num2,3);
       Exprint(a--);
   }
   else if(a ==1)
   {
       for(int i = 0;i<3;i++)
       {
           num1[i] = number[i+b]; 
       }
       sPrint(num1,3);
       Exprint(a--);
   }
}