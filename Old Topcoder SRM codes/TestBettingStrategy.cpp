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

class TestBettingStrategy
{
public:

double memo[55][1005][15];
bool done[55][1005][15];
int goalSum ,rounds;
double win;

double solve( int curr , int tot , int on)
{
    if( tot >= goalSum)
    {
        return 1.0;
    }

    if( curr==1+rounds)
    {
        return 0.0;
    }

    if( done[curr][tot][on])
        return memo[curr][tot][on];

    double ans=0.0;

    //win
     ans+=win*solve(curr+1,tot+(1<<on),0);

     //lost
     if( tot -(1<<on) >= ( 1<<(on+1) ) )
        ans+=(1.0-win)*solve(curr+1,tot-(1<<on) , on+1);

     done[curr][tot][on]=true;

     return memo[curr][tot][on]=ans;
}



double  winProbability(int initSum, int goalSum, int rounds, int prob)
{
     win=(double)prob/(100.00);

     cout<<win<<endl;

     this->goalSum=goalSum;
     this->rounds=rounds;

     memset(done,0,sizeof(done));

     return solve(1,initSum,0);
}

};


double test0() {
	int p0 = 10;
	int p1 = 11;
	int p2 = 4;
	int p3 = 50;
	TestBettingStrategy * obj = new TestBettingStrategy();
	clock_t start = clock();
	double my_answer = obj->winProbability(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 0.875;
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
	int p0 = 10;
	int p1 = 20;
	int p2 = 20;
	int p3 = 50;
	TestBettingStrategy * obj = new TestBettingStrategy();
	clock_t start = clock();
	double my_answer = obj->winProbability(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 0.3441343307495117;
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
	int p0 = 10;
	int p1 = 20;
	int p2 = 10;
	int p3 = 90;
	TestBettingStrategy * obj = new TestBettingStrategy();
	clock_t start = clock();
	double my_answer = obj->winProbability(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 0.34867844010000015;
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
	int p0 = 24;
	int p1 = 38;
	int p2 = 24;
	int p3 = 60;
	TestBettingStrategy * obj = new TestBettingStrategy();
	clock_t start = clock();
	double my_answer = obj->winProbability(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 0.5940784635646947;
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
