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

class PaintingBoards
{
public:


double minimalTime(vector <int> bl, vector <int> ps)
{
     int n=bl.size(),m=ps.sz;
     double ans=(1<<30);

     int next[55][55];
     int dp[1<<16];

     double lo=0,hi=(1<<20);

     for(int it=0;it<100;it++)
     {
         double mid=(lo+hi)/2.0;

         for(int id=0;id<m;id++)
             for(int i=0;i<=n;i++)
              {
               double sm=0;
               int k=i;

               for( ; (k<n) && (sm+bl[k] <= mid*ps[id] );k++ )
                   sm+=bl[k];

                next[id][i]=k;
              }

         fill(dp,-1);
         dp[0]=0;

         for(int mask=0;mask<(1<<m);mask++)
                if( dp[mask]>=0)
                    {
                     for(int i=0;i<m;i++)
                       if( (mask&(1<<i))==0)
                         dp[mask|(1<<i)]=max( dp[mask|(1<<i)] , next[i][ dp[mask] ] );
                    }

         if( dp[(1<<m)-1] >=n )
         {
            ans=mid;
            hi=mid;
         }
         else
         {
             lo=mid;
         }

     }

     return ans;

}

};


double test0() {
	int t0[] = {5,3,2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2,3,5};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PaintingBoards * obj = new PaintingBoards();
	clock_t start = clock();
	double my_answer = obj->minimalTime(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 1.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {1,2,1,4,2,1,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,2,3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PaintingBoards * obj = new PaintingBoards();
	clock_t start = clock();
	double my_answer = obj->minimalTime(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 2.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {40, 46, 82, 89, 33, 46, 3, 50, 95, 
81, 69, 40, 94, 93, 90, 98, 17, 34, 
45, 18, 93, 28, 43, 38, 35};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {49, 51, 35, 27, 48, 36, 54, 10};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PaintingBoards * obj = new PaintingBoards();
	clock_t start = clock();
	double my_answer = obj->minimalTime(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 4.686274509803922;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {3,3,20};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {9,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PaintingBoards * obj = new PaintingBoards();
	clock_t start = clock();
	double my_answer = obj->minimalTime(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 2.888888888888889;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
