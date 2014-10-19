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

class ConnectTheCities
{
public:

int memo[55][105];

int cr;
int dist;

vector<int> pos;
int n;//pos.sz

int solve(int curr , int last)
{

      if( curr==n)
      {
           if( last + cr < dist)
            return (1<<20);

            return 0;
      }

      if( memo[curr][last]!=-1)
         return memo[curr][last];

    int ans=1<<20;

    for(int i=0; i<=dist;i++)
         if( abs(last-i) <=cr )
          ans=min( ans , solve(curr+1 , i) + abs(i-pos[curr]) );


     return memo[curr][last]=ans;

}

int minimalRange(int distance, int funds, vector <int> position)
{
    pos=position;

    dist=distance;

    sort(pos.begin(),pos.end());

    n=pos.size();


     for(cr=0;cr<=dist;cr++)
     {
         fill(memo,-1);
         int tp=solve(0,0);

         if( tp <= funds )
             return cr;
     }

     return -1;

}

};


double test0() {
	int p0 = 10;
	int p1 = 5;
	int t2[] = { 3, 7, 9 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ConnectTheCities * obj = new ConnectTheCities();
	clock_t start = clock();
	int my_answer = obj->minimalRange(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 3;
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
	int p0 = 20;
	int p1 = 100;
	int t2[] = { 0, 0, 0, 0 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ConnectTheCities * obj = new ConnectTheCities();
	clock_t start = clock();
	int my_answer = obj->minimalRange(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 4;
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
	int p0 = 63;
	int p1 = 19;
	int t2[] = { 34, 48, 19, 61, 24 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ConnectTheCities * obj = new ConnectTheCities();
	clock_t start = clock();
	int my_answer = obj->minimalRange(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 12;
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
