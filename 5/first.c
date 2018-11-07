#include<stdio.h>
#include<ctype.h>
 
void first(char[], char);
void append(char[], char);
 
int n;
char production[25][25];
 
int main()
{
      char option, ch, array[25];
      int i;
      printf("\nEnter the number of productions: ");
      scanf(" %d", &n);
      for(i = 0; i < n; i++)
      {
            printf("\nEnter production[%d]: ", i + 1);
            scanf(" %s", production[i]);
      }
      do
      {
            printf("\nEnter a value to find first: ");
            scanf(" %c", &ch);
            first(array, ch);
            printf("\nFIRST[%c] = {", ch);
            for(i = 0; array[i] != '\0'; i++)
            {        
                  printf(" %c ", array[i]);
            }
            printf("}\n");
            printf("\nPress [Y/y] to continue: ");
            scanf(" %c", &option);
      }while(option == 'y' || option == 'Y');
      return 0;
}
 
void first(char* array, char ch)
{
      int i, j, k;
      char temp[20];
      int flag;

      temp[0] = '\0';
      array[0] = '\0';

      if(!(isupper(ch)))
      {
            append(array, ch);
            return ;
      }
      for(i = 0; i < n; i++)
      {
            if(production[i][0] == ch)
            {
                  if(production[i][2] == '$') 
                  {
                        append(array, '$');
                  }
                  else
                  {
                        j = 2;
                        while(production[i][j] != '\0')
                        {
                              flag = 0;
                              first(temp, production[i][j]);
                              for(k = 0; temp[k] != '\0'; k++)
                              {
                                    append(array,temp[k]);
                              }
                              for(k = 0; temp[k] != '\0'; k++)
                              {
                                    if(temp[k] == '$')
                                    {
                                          flag = 1;
                                          break;
                                    }
                              }
                              if(!flag)
                              {
                                    break;
                              }
                              j++;
                        }
                  }     
            }
      }
      return;
}
 
void append(char array[], char value)
{
      int i;
      for(i = 0; array[i] != '\0'; i++)
      {
            if(array[i] == value)
            {
                  return;
            }
      }
      array[i] = value;
      array[i + 1] = '\0';
}