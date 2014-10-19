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
#define Y second
#define X first

#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)

const double pi     =   acos(-1.0);
const double eps    =   1e-8;

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

class CollectingPayment
{
public:

    bool done[60][60];
    double memo[60][60];
    double power[60];
    double dp[60];
    double in[370];

    double fee,rate;

    double solve( int curr , int prev )
    {

       if( curr==53)
       {
           double sum=dp[curr]-dp[prev];
             sum-=fee;



             return max(0.00,sum*power[1]);
       }

       if( done[curr][prev] )
          return memo[curr][prev];

       double ans=0.0;

       //commit here
        double tp=(dp[curr]-dp[prev]-fee)*power[54-curr];
               tp=max(0.0,tp);

               tp+=solve(curr+1,curr);

               ans=max(ans,tp);

        //next
          ans=max( ans , solve(curr+1,prev ) );


          done[curr][prev]=true;

          return memo[curr][prev]=ans;
}



double  maximumProfit(vector <int> earn, vector <int> det , int fee, int rate)
{
   this->fee=(double)fee;
   this->rate=(double)rate;

   power[0]=1.0;
   double x=(1.0+((double)rate/1000.00) );

   for(int i=1;i<=55;i++)
    {power[i]=x*power[i-1];
    }

   for(int i=0;i<earn.size();i++)
     in[ det[i] ]=(double)earn[i];

    dp[0]=0.0;
    dp[1]=in[1];

    for(int cn=2;cn<=53;cn++)
    {
          int low=1+(cn-2)*7+1;
          int hi=1+(cn-1)*7;

          double tp=0.0;

            for(int i=low;i<=hi;i++)
                  tp+=in[i];

           dp[cn]=dp[cn-1] + tp;
    }

   memset(done,0,sizeof(done));

   return solve(1,0);


}

};


double test0() {
	int t0[] = {300,290,320,150};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {120,124,200,202};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 40;
	int p3 = 10;
	CollectingPayment * obj = new CollectingPayment();
	clock_t start = clock();
	double my_answer = obj->maximumProfit(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 1325.1174146859212;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {300,290,320,150};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,122,243,365};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 40;
	int p3 = 10;
	CollectingPayment * obj = new CollectingPayment();
	clock_t start = clock();
	double my_answer = obj->maximumProfit(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 1240.733092976253;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {300,290,320,150};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,122,243,365};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 200;
	int p3 = 10;
	CollectingPayment * obj = new CollectingPayment();
	clock_t start = clock();
	double my_answer = obj->maximumProfit(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 868.6;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {150};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {365};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 50;
	int p3 = 100;
	CollectingPayment * obj = new CollectingPayment();
	clock_t start = clock();
	double my_answer = obj->maximumProfit(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 110.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int t0[] = {1000,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {155,365};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 100;
	int p3 = 100;
	CollectingPayment * obj = new CollectingPayment();
	clock_t start = clock();
	double my_answer = obj->maximumProfit(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 17274.90824619758;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	int t0[] = {1,346,7,346,345,3,453,5,346,3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,2,7,34,74,163,200,250,352,360};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 0;
	int p3 = 0;
	CollectingPayment * obj = new CollectingPayment();
	clock_t start = clock();
	double my_answer = obj->maximumProfit(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 1855.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test6() {
	int t0[] = {1,346,7,346,345,3,453,5,346,354,25,23,354,235,235};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,7,34,74,98,154,163,178,200,210,250,279,325,352,360};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 50;
	int p3 = 10;
	CollectingPayment * obj = new CollectingPayment();
	clock_t start = clock();
	double my_answer = obj->maximumProfit(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 3693.6800093457805;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
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
	
	time = test5();
	if (time < 0)
		errors = true;
	
	time = test6();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
