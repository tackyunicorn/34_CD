#include<stdio.h> 
#include<ctype.h>
#include<string.h>
 
int n, x = 0;
char production[10][10], result[10];
 
void first(char ch);
void follow(char ch);
void append(char ch);
 
int main()
{
      int i;
      char option, ch;
      printf("\nEnter the number of productions: ");
      scanf(" %d", &n);
      for(i = 0; i < n; i++)
      {
            printf("\nEnter production[%d]: ", i + 1);
            scanf(" %s", production[i]);
      }
      do
      {
            x = 0;
            printf("\nEnter the value to find follow: ");
            scanf(" %c", &ch);
            follow(ch);
            printf("\nFOLLOW[%c]{ ", ch);
            for(i = 0; i < x; i++)
            {
                  printf(" %c ", result[i]);
            }
            printf("}\n");
            printf("\nPress [Y/y] to continue: ");
            scanf(" %c", &option);
      }while(option == 'y' || option == 'Y');
      return 0;
}
 
void follow(char ch)
{
      int i, j;
      int length = strlen(production[i]);
      if(production[0][0] == ch)
      {
            append('$');
      }
      for(i = 0; i < n; i++)
      {
            for(j = 2; j < length; j++)
            {
                  if(production[i][j] == ch)
                  {
                        if(production[i][j + 1] != '\0')
                        {
                              first(production[i][j + 1]);
                        }
                        if(production[i][j + 1] == '\0' && ch != production[i][0])
                        {     				
                              follow(production[i][0]);
                        }
                  }
            }
      }
}
 
void first(char ch)
{
      int i, k;
      if(!(isupper(ch)))
      {
            append(ch);
      }
      for(k = 0; k < n; k++)
      {
            if(production[k][0] == ch)
            {
                  if(production[k][2] == '$') 
                  {
                        follow(production[i][0]);
                  }
                  else if(islower(production[k][2]))
                  {
                        append(production[k][2]);
                  }
                  else 
                  {
                        first(production[k][2]);
                  }
            }
      }
}
 
void append(char ch)
{
      int i;
      for(i = 0; i <= x; i++)
      {
            if(result[i] == ch)
            {
                  return;
            }
      }
      result[x++] = ch;
}