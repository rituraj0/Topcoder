#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <fstream>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
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

#define print(a) cout<<(#a)<<" = "<<a<<"  ";
#define println(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );

vector <string> parse(string s, string c)
{
  int len = c.length(), p = -len, np;
  vector <string> ans;

  do
    {
      np = s.find(c, p+len);
      ans.push_back(s.substr(p+len, np - p - len));
      p = np;
    }
  while (p != string::npos);

  return ans;
}


/*Solution code starts here */

class MarbleMachine
{
public:

    ll am[65][65] , bm[65][65] , cm[65][65] , em[61][65][65] , rm[65][65];

    int id( int x, int y)
    {
        return x*8+y;
    }

    void multiply( ll c[65][65] , ll a[65][65] , ll b[65][65])
    {
        fill(rm,0);

        for(int i=0;i<65;i++)
             for(int j=0;j<65;j++)
             {
               ll tp=0;
                for(int k=0;k<65;k++)
                     tp+=a[i][k]*b[k][j];

                rm[i][j]=tp;
             }

             memcpy(c,rm,sizeof(rm));
    }

    void power(int ex)
    {
         if(ex==0)
         {
            fill(cm,0);
            for(int i=0;i<65;i++)
                 cm[i][i]=1;
            return;
         }

         if( ex&1)
         {
            power(ex-1);
            multiply(cm,cm,am);
         }
         else
         {
             power(ex/2);
             multiply(cm,cm,cm);
         }
    }


long long maxMarbles(vector <string> layout, vector <string> actions, int t)
{
     for(int st=0;st<60;st++)
     {
         fill(am,0);
         am[64][64]++;

           for(int i=0;i<layout.sz;i++)
             for(int j=0;j<layout[0].sz;j++)
           {
               int curr=layout[i][j]-'0';
               char ch=actions[curr][ st%(actions[curr].sz) ];

               if( ('0' <= ch) && (ch <='9') )
               {
                    am[ id(i,j) ][ id(i,j)]++;
                    am[ id(i,j) ][64]+=(ch-'0');
               }
               else if( ch=='D')
                ;
               else
               {
                    int dx=0,dy=0;
                    if(ch=='N') dx=-1;

                    if( ch=='S')dx=1;

                    if( ch=='W') dy=-1;

                    if( ch=='E') dy=1;

                    int x=i+dx;
                    int y=j+dy;

                    if( (x>=0) && (x < layout.sz) && (y >=0) && (y < layout[0].sz ) )
                          am[ id(x,y) ][ id(i,j) ]++;

               }
           }

           memcpy( em[st],am,sizeof(am));
     }

     fill(am,0);

     for(int i=0;i<65;i++)
         am[i][i]=1;

     for(int i=0;i<60;i++)
         multiply(am,em[i],am);

     power(t/60);

     for(int i=0;i<(t%60);i++)
         multiply(cm,em[i],cm);

     ll ans=0;

     for(int i=0;i<64;i++)
          ans=max( ans , cm[i][64]);

     return ans;

}

};


double test0() {
	string t0[] = {
"0101",
"1010",
"0101"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"4","5353"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int p2 = 5;
	MarbleMachine * obj = new MarbleMachine();
	clock_t start = clock();
	long long my_answer = obj->maxMarbles(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 21LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"011112"}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"1E","E","0"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int p2 = 1000;
	MarbleMachine * obj = new MarbleMachine();
	clock_t start = clock();
	long long my_answer = obj->maxMarbles(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 498LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {
"01",
"32"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"1E","SSDSS","W","00000W"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int p2 = 23;
	MarbleMachine * obj = new MarbleMachine();
	clock_t start = clock();
	long long my_answer = obj->maxMarbles(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 3LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
