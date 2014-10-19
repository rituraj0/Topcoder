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

class PackingBallsDiv1
{
public:

    ll k,a,b,c,d;

    ll in[100009];
    ll cont[100009];

ll solve()
{
     in[0]=a;

     for(int i=1;i<k;i++)
         in[i]=(in[i-1]*b+c)%d +1;

         for(int i=0;i<k;i++)
              cout<<in[i]<<"  ";

      ll full=0;

      fill(cont,0);

      for(int i=0;i<k;i++)
      {
          full+=in[i]/k;
          cont[ in[i]%k ]++;
      }

      for(int i=k;i>=0;i--)
         cont[i]+=cont[i+1];


      ll ex=k+1;

      for(int i=0;i<=k+1;i++)//diff bags
      {
            ll tp=i;
            tp+=cont[i+1];

            ex=min( ex, tp);
      }

      return (full+ex);



}


int minPacks(int K, int A, int B, int C, int D)
{

   k=K;
   a=A;
   b=B;
   c=C;
   d=D;

   return solve();

}

};



double test0() {
	int p0 = 2;
	int p1 = 1000000000;
	int p2 = 1000000000;
	int p3 = 1000000000;
	int p4 = 1000000000;
	PackingBallsDiv1 * obj = new PackingBallsDiv1();
	clock_t start = clock();
	int my_answer = obj->minPacks(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 4;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 1;
	int p1 = 58;
	int p2 = 23;
	int p3 = 39;
	int p4 = 93;
	PackingBallsDiv1 * obj = new PackingBallsDiv1();
	clock_t start = clock();
	int my_answer = obj->minPacks(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 58;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 23;
	int p1 = 10988;
	int p2 = 5573;
	int p3 = 4384;
	int p4 = 100007;
	PackingBallsDiv1 * obj = new PackingBallsDiv1();
	clock_t start = clock();
	int my_answer = obj->minPacks(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 47743;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 100000;
	int p1 = 123456789;
	int p2 = 234567890;
	int p3 = 345678901;
	int p4 = 1000000000;
	PackingBallsDiv1 * obj = new PackingBallsDiv1();
	clock_t start = clock();
	int my_answer = obj->minPacks(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 331988732;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
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

//	time = test1();
//	if (time < 0)
//		errors = true;
//
//	time = test2();
//	if (time < 0)
//		errors = true;
//
//	time = test3();
//	if (time < 0)
//		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
