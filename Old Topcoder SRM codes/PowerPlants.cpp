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


int val( char in)
{
     if( '0' <=in && in<='9')
          return (in-'0');

     return (in-'A'+10);
}

int cost[20][20];
int memo[1<<17];

class PowerPlants
{
public:

int n;

int req;


int solve(int in)
{
      if( __builtin_popcount(in) >= req )
          return 0;

       if( memo[in]!=-1)
         return memo[in];

       int ans=(1<<28);

       for(int i=0;i<n;i++)
           if( in &(1<<i) )
       {
                for(int j=0;j<n;j++)
                      if( (in&(1<<j))==0 )
                {
                        int nw=in+(1<<j);
                        int tp=solve(nw)+cost[i][j];

                        ans=min( ans , tp);
                }
       }

       return  memo[in]=ans;
}


int minCost(vector <string> connectionCost, string plantList, int numPlants)
{
    n=plantList.sz;

    for(int i=0;i<n;i++)
         for(int j=0;j<n;j++)
           cost[i][j]=val( connectionCost[i][j] );

    int curr=0;

    for(int i=0;i<n;i++)
          if( plantList[i]=='Y')
            curr+=(1<<i);

     req=numPlants;

     fill( memo , -1);

           for(int i=(1<<n)-1;i>=0;i--)
           solve(i);

     return  solve(curr);


}

};


double test0() {
	string t0[] = {"024",
 "203",
 "430"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string p1 = "YNN";
	int p2 = 3;
	PowerPlants * obj = new PowerPlants();
	clock_t start = clock();
	int my_answer = obj->minCost(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 5;
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
	string t0[] = {"0AB",
 "A0C",
 "CD0"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string p1 = "YNN";
	int p2 = 3;
	PowerPlants * obj = new PowerPlants();
	clock_t start = clock();
	int my_answer = obj->minCost(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 21;
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
	string t0[] = {"1ABCD",
 "35HF8",
 "FDM31",
 "AME93",
 "01390"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string p1 = "NYNNN";
	int p2 = 5;
	PowerPlants * obj = new PowerPlants();
	clock_t start = clock();
	int my_answer = obj->minCost(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 14;
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
double test3() {
	string t0[] = {"012",
 "123",
 "234"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string p1 = "NNY";
	int p2 = 2;
	PowerPlants * obj = new PowerPlants();
	clock_t start = clock();
	int my_answer = obj->minCost(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 2;
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
double test4() {
	string t0[] = {"1309328",
 "DS2389U",
 "92EJFAN",
 "928FJNS",
 "FJS0DJF",
 "9FWJW0E",
 "23JFNFS"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string p1 = "YYNYYNY";
	int p2 = 4;
	PowerPlants * obj = new PowerPlants();
	clock_t start = clock();
	int my_answer = obj->minCost(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 0;
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
double test5() {
	string t0[] = {"01","20"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string p1 = "YN";
	int p2 = 2;
	PowerPlants * obj = new PowerPlants();
	clock_t start = clock();
	int my_answer = obj->minCost(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1;
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
	
	time = test3();
	if (time < 0)
		errors = true;
	
	time = test4();
	if (time < 0)
		errors = true;
	
	time = test5();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
