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

class CubeNets
{
public:

 vector< vector<string>  >all;

void init()
{
     string a1[]= {"..#.", "####", "..#."};
     vector<string> v1( a1 , a1 + sizeof(a1)/sizeof(string) );
     all.pb(v1);

     string a2[]= {"..#.", "####", "...#"};
     vector<string> v2( a2 , a2 + sizeof(a2)/sizeof(string) );
     all.pb(v2);

     string a3[]= {"...#", "####", "...#"};
     vector<string> v3( a3 , a3 + sizeof(a3)/sizeof(string) );
     all.pb(v3);

     string a4[]= {"..#.", "####", ".#.."};
     vector<string> v4( a4 , a4 + sizeof(a4)/sizeof(string) );
     all.pb(v4);

     string a5[]={"..#.", "####", "#..."};
     vector<string> v5( a5 , a5 + sizeof(a5)/sizeof(string) );
     all.pb(v5);

     string a6[]= {"...#", "####", "#..."};
     vector<string> v6( a6 , a6 + sizeof(a6)/sizeof(string) );
     all.pb(v6);

     string a7[]= {"###..", "..###"};
     vector<string> v7( a7 , a7 + sizeof(a7)/sizeof(string) );
     all.pb(v7);

     string a8[]= {"##..", ".###", "..#."};
     vector<string> v8( a8 , a8 + sizeof(a8)/sizeof(string) );
     all.pb(v8);

     string a9[]= {"##..", ".###", "...#"};
     vector<string> v9( a9 , a9 + sizeof(a9)/sizeof(string) );
     all.pb(v9);

     string a10[]= {"..#.", "###.", "..##"};
     vector<string> v10( a10 , a10 + sizeof(a10)/sizeof(string) );
     all.pb(v10);

     string a11[]= {"##..", ".##.", "..##"} ;
     vector<string> v11( a11 , a11 + sizeof(a11)/sizeof(string) );
     all.pb(v11);


}

vector<string> transpose( vector<string> in)
{
       vector<string> ans(in[0].sz);

        for(int i=0;i<ans.sz;i++)
             ans[i]=string( in.sz ,'.');

       for(int i=0;i<in.sz;i++)
         for(int j=0;j<in[0].sz;j++)
           ans[j][i]=in[i][j];

        return ans;
}

vector<string> rotat( vector<string> in)
{
    vector<string> ans;
     ans.resize(in[0].sz);

     for(int i=0;i<ans.sz;i++)
          ans[i]=string(in.sz,'.');

     for(int i=0;i<in.sz;i++)
         for(int j=0;j<in[0].sz;j++)
            ans[j][in.sz-i-1]=in[i][j];

       return ans;
}


bool cool( vector<string> in)
{
       for(int k=0;k<all.sz;k++)
       {
             vector<string> curr=all[k];

                  for(int x=-10;x<10;x++)
                     for(int y=-10;y<10;y++)
                       {
                          int mila=0;

                          for(int i=0;i<in.sz;i++)
                             for(int j=0;j<in[0].sz;j++)
                              {
                               int a=i+x,b=j+y;

                               if( (a < 0) || (a>=curr.sz) || (b < 0) || (b >=curr[0].sz) )
                                 continue;

                               if( in[i][j]==curr[a][b])
                                    if( in[i][j]=='#')
                                       mila++;
                              }

                          if(mila==6)
                             return true;
                         }
       }

       return false;
}

string isCubeNet(vector <string> fig)
{
    init();

    for(int i=0;i<all.sz;i++,cout<<endl)
         for(int j=0;j<all[i].sz;j++)
           cout<<all[i][j]<<" ";

    if( cool(fig) )
          return "YES";

    fig=rotat(fig);
        if( cool(fig) )
          return "YES";

     fig=rotat(fig) ;
         if( cool(fig) )
          return "YES";

       fig=rotat(fig) ;
         if( cool(fig) )
          return "YES";

      fig=transpose(fig);
         if( cool(fig) )
          return "YES";

          fig=rotat(fig);
        if( cool(fig) )
          return "YES";

     fig=rotat(fig) ;
         if( cool(fig) )
          return "YES";

       fig=rotat(fig) ;
         if( cool(fig) )
          return "YES";

        return "NO";
}


};


double test0() {
	string t0[] = {"..#.",
 "####",
 "..#."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	CubeNets * obj = new CubeNets();
	clock_t start = clock();
	string my_answer = obj->isCubeNet(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "YES";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"###",
 "###"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	CubeNets * obj = new CubeNets();
	clock_t start = clock();
	string my_answer = obj->isCubeNet(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "NO";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"..#.",
"####",
".#.."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	CubeNets * obj = new CubeNets();
	clock_t start = clock();
	string my_answer = obj->isCubeNet(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "YES";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"##..",
 ".##.",
 "..##"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	CubeNets * obj = new CubeNets();
	clock_t start = clock();
	string my_answer = obj->isCubeNet(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "YES";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string t0[] = {"####",
 "...#",
 "...#"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	CubeNets * obj = new CubeNets();
	clock_t start = clock();
	string my_answer = obj->isCubeNet(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "NO";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
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
	
	time = test3();
	if (time < 0)
		errors = true;
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
