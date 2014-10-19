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

typedef long long ll;

class ExtendedDominoes
{
public:

long long  countCycles(vector <string> pieces)
{
	ll dp[20];

	dp[0]=0;
	dp[1]=0;
	dp[2]=1;

	for(int i=3;i<=10;i++)
          if(i&1)
            dp[i]=0;
          else
             dp[i]=(ll)(i-1)*dp[i-2];

          int deg[20]; memset(deg , 0, sizeof(deg) );

          for(int i=0;i<pieces.size();i++)
          {
              deg[ pieces[i][0]-'0' ]++;
              deg[ pieces[i][1]-'0' ]++;
          }

          ll ans=1;

          for(int i=0;i<10;i++)
            if( deg[i] )
             ans*=dp[ deg[i] ];

        return ans;
}

};

double test0() {
	string t0[] = {"12","25","45","24","28","18"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ExtendedDominoes * obj = new ExtendedDominoes();
	clock_t start = clock();
	long long my_answer = obj->countCycles(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 3LL;
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
	string t0[] = {"01","12","23","34","45"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ExtendedDominoes * obj = new ExtendedDominoes();
	clock_t start = clock();
	long long my_answer = obj->countCycles(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 0LL;
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
	string t0[] = {"09","12","24","14","57","79","05"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ExtendedDominoes * obj = new ExtendedDominoes();
	clock_t start = clock();
	long long my_answer = obj->countCycles(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 1LL;
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
	string t0[] = {"34","35","36","37","45","46","47","56","57","67"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ExtendedDominoes * obj = new ExtendedDominoes();
	clock_t start = clock();
	long long my_answer = obj->countCycles(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 243LL;
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
