#include<string.h>
#include<stdio.h>
#include<stdbool.h>

/*Solution code starts here */

char in[100009];
char tx[1009];

int aval[30];
int req[30];

int test,n,m;

bool mila,cool;

int i,j,t;

int main()
{


   scanf("%d",&test);

   for( t=0;t<test;t++)
   {


        scanf("%s",tx);
        m=strlen(tx);


         scanf("%s",in);
         n=strlen(in);

        if(n<m)
        {
            printf("NO");
            continue;
        }

        for( i=0;i<26;i++)
        {
            req[i]=0;
            aval[i]=0;
        }



        for( i=0;i<m;i++)
        {
            req[ tx[i]-'a']++;
        }


         mila=false;

        for( i=0;i<n;i++)
        {
               if( i-m >=0)
               {
                   aval[ in[i-m] -'a']--;
               }

               aval[ in[i] -'a' ]++;

                cool=true;

                 for(j=0;j<26;j++)
                 {
                      if( aval[j]<req[j] )
                      {
                          cool=false;
                          break;
                      }
                 }

                 if(cool)
                 {
                     mila=true;
                     break;
                 }
        }

        if(mila)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }

   }

 return 0;

}
