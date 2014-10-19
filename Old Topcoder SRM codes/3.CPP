#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz size()
#define bg begin()
#define en end()
#define Y second
#define X first
typedef long long ll;
#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)
const double pi     =   acos(-1.0);
const double eps    =   1e-8;
#define print(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );
/*Solution code starts here */



 int n;
 string in[200];

 map<char,int> mapa;

bool num[10],col[10];

int main()
{
 ios_base::sync_with_stdio(0);


 mapa['R']=0;
 mapa['G']=1;
 mapa['B']=2;
 mapa['Y']=3;
 mapa['W']=4;

  cin>>n;

  fill(num ,0); fill( col,0);

  for(int i=0;i<n;i++)
    { cin>>in[i];

      col[ mapa[ in[i][0] ] ]=true;
      num[ in[i][1]-'1' ]=true;
    }



  int ans=10;

  for(int a=0;a<(1<<5);a++)//num
     for(int b=0;b<(1<<5);b++)//col

    {

        vector<string> temp(n,"..");

           for(int i=0;i<n;i++)
           {
               int req=in[i][1] - '1';
               if(a&(1<<req))
                 temp[i][1]=in[i][1];

                 req=mapa[ in[i][0] ];
                if( b&(1<<req))
                 temp[i][0]=in[i][0];
           }

         bool cool=true;

           for(int i=0;i<n;i++)
             for(int j=i+1;j<n;j++)
             {
               if( in[i]==in[j])
                continue;
               if( temp[i]==temp[j])
                  cool=false;
             }

        if( cool)
            ans=min( ans , __builtin_popcount(a) + __builtin_popcount(b) );

    }


    cout<<ans<<endl;





 return 0;

}
