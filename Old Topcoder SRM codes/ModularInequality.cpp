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
class ModularInequality
{
public:

ll P;
vector<ll> in;
int n;

bool cool(  ll tp)
{
    ll sum=0;

    for(int i=0;i<n;i++)
         sum+=abs(tp-in[i]);

    return (sum<=P);
}

int  countSolutions(vector <int> A, int _P)
{
     sort(A.begin(),A.end());
     n=A.size();

     for(int i=0;i<n;i++)
         in.pb( A[i] );

     this->P=_P;

     ll x=A[n/2];

     if(!cool(x))
        return 0;

    ll up=x;

    //checking for up
    ll lo=x,hi=(1LL<<50);

    while( lo <= hi)
    {

        ll mid=(lo+hi)/2;

        if( cool(mid) )
        {
            up=max(up,mid);
            lo=mid+1;
        }
       else
       {
            hi=mid-1;
       }

    }

   //Chcking for dwons

   ll down=x;

    lo=-(1LL<<50) ;
    hi=x;

    while( lo <=hi )
    {
        ll mid=(lo+hi)/2;

        if( cool(mid) )
        {
            down=min( down , mid);
            hi=mid-1;
        }
        else
        {
            lo=mid+1;
        }
    }

    return (up-down+1);

}

};


double test0() {
	int t0[] = {1, 2, 3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 6;
	ModularInequality * obj = new ModularInequality();
	clock_t start = clock();
	int my_answer = obj->countSolutions(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 5;
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
	int t0[] = {10, 30, 15, -1, 17};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 42;
	ModularInequality * obj = new ModularInequality();
	clock_t start = clock();
	int my_answer = obj->countSolutions(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 7;
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
	int t0[] = {0, 2, 3, -5, 10};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 17;
	ModularInequality * obj = new ModularInequality();
	clock_t start = clock();
	int my_answer = obj->countSolutions(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 0;
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
	int t0[] = {-693};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 1265;
	ModularInequality * obj = new ModularInequality();
	clock_t start = clock();
	int my_answer = obj->countSolutions(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2531;
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
double test4() {
	int t0[] = {965, -938, -396, -142, 926, 31, -720};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 6495;
	ModularInequality * obj = new ModularInequality();
	clock_t start = clock();
	int my_answer = obj->countSolutions(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 1781;
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
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
