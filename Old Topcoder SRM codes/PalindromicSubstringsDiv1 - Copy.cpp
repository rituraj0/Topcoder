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

typedef long long ll;
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

    double memo[5110][5100];

class PalindromicSubstringsDiv1
{
public:

    string in;


double solve( int l , int r)
{
    if(l==r)
         return 1.0;

      if( l > r)
            return 1.0;

    if( memo[l][r] > -0.5)
         return memo[l][r];

    double ans=0;

    if( in[l]=='?' && in[r]=='?' )
         ans=(1./26.)*solve(l+1,r-1);
    else if( in[l]=='?' || in[r]=='?')
         ans=(1./26.)*solve(l+1,r-1);
    else if( in[l]==in[r])
         ans=solve(l+1,r-1);

    return memo[l][r]=ans;

}



double expectedPalindromes(vector <string> S1, vector <string> S2)
{
       in="";

     for(int i=0;i<S1.size();i++)
          in+=S1[i];

     for(int i=0;i<S2.size();i++)
          in+=S2[i];

        fill( memo , -1);

        double ans=0;

        for(int i=0;i<in.size();i++)
             for(int j=i;j<in.size();j++)
               ans+=solve(i,j);

        return ans;


}

};


double test0() {
	string t0[] = {"a","a",""};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"a"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	PalindromicSubstringsDiv1 * obj = new PalindromicSubstringsDiv1();
	clock_t start = clock();
	double my_answer = obj->expectedPalindromes(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 6.0;
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
	string t0[] = {"z??"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	vector <string> p1;
	PalindromicSubstringsDiv1 * obj = new PalindromicSubstringsDiv1();
	clock_t start = clock();
	double my_answer = obj->expectedPalindromes(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 3.115384615384615;
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
	string t0[] = {"ab","c"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"??","a?"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	PalindromicSubstringsDiv1 * obj = new PalindromicSubstringsDiv1();
	clock_t start = clock();
	double my_answer = obj->expectedPalindromes(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 7.315088757396449;
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
	vector <string> p0;
	string t1[] = {"?"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	PalindromicSubstringsDiv1 * obj = new PalindromicSubstringsDiv1();
	clock_t start = clock();
	double my_answer = obj->expectedPalindromes(p0, p1);
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
double test4() {
	string t0[] = {"ab?def","?"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"f??a"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	PalindromicSubstringsDiv1 * obj = new PalindromicSubstringsDiv1();
	clock_t start = clock();
	double my_answer = obj->expectedPalindromes(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 12.545971779699588;
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
