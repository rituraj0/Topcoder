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

class SchoolTrip
{
public:

int n;
double memo[1000][1<<6][6];
double prob[10];


int next( int mask , int p)
{
      if( mask&(1<<p) )
         return p;

       return next(mask , (p+1)%n );
}

double solve( int it , int mask , int p)
{
     if( (it==0) || (__builtin_popcount(mask)==1) )
          return 0;

     if( memo[it][mask][p] > -1)
         return memo[it][mask][p];

    double ans= memo[it][mask][p]=1e100;

      for(int i=0;i<n;i++)
          if( mask&(1<<i) )
             if(i!=p)
      {

           double tp=1.0;
                  tp+=solve(it-1, mask , next(mask,(p+1)%n )) * (100.0-prob[p])/100.0;
                   tp+=solve(it-1, mask-(1<<i) , next( mask-(1<<i) , (p+1)%n ) )*prob[p]/100.0;

                   ans=min(ans,tp);
      }

       return memo[it][mask][p]=ans;
}

double duration(vector <int> probability)
{
   n=probability.sz;

   for(int i=0;i<n;i++)
     prob[i]=probability[i];

    fill(memo,-1);

    return solve(999,(1<<n)-1,0);
}

};


double test0() {
	int t0[] = {100,23};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	SchoolTrip * obj = new SchoolTrip();
	clock_t start = clock();
	double my_answer = obj->duration(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 1.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int t0[] = {50,50};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	SchoolTrip * obj = new SchoolTrip();
	clock_t start = clock();
	double my_answer = obj->duration(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 2.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int t0[] = {25,50,75};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	SchoolTrip * obj = new SchoolTrip();
	clock_t start = clock();
	double my_answer = obj->duration(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 3.892383478590375;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int t0[] = {100,100,100,42,11};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	SchoolTrip * obj = new SchoolTrip();
	clock_t start = clock();
	double my_answer = obj->duration(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 4.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
