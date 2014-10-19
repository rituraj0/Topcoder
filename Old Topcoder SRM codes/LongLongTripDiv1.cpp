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

class LongLongTripDiv1
{
public:

    ll dp[55][55];


string isAble(int n, vector <int> A, vector <int> B, vector <int> D, long long T)
{
     fill(dp,63);

     cout<<dp[0][0]<<endl;

     for(int i=0;i<n;i++)
         dp[i][i]=0;

     for(int i=0;i<A.sz;i++)
          dp[ A[i] ][ B[i] ]=dp[ B[i] ][ A[i] ]=D[i];

     for(int k=0;k<n;k++)
         for(int i=0;i<n;i++)
          for(int j=0;j<n;j++)
            dp[i][j]=min( dp[i][j] , dp[i][k] + dp[k][j] );

            if( dp[0][n-1] <=T)
                  return "Possible";

            return "Impossible";


}

};


double test0() {
	int p0 = 3;
	int t1[] = {0,0,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {2,1,2};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {7,6,5};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	long long p4 = 11LL;
	LongLongTripDiv1 * obj = new LongLongTripDiv1();
	clock_t start = clock();
	string my_answer = obj->isAble(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "Possible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 3;
	int t1[] = {0,0,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {2,1,2};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {7,6,5};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	long long p4 = 25LL;
	LongLongTripDiv1 * obj = new LongLongTripDiv1();
	clock_t start = clock();
	string my_answer = obj->isAble(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "Possible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 2;
	int t1[] = {0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {1};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	long long p4 = 9LL;
	LongLongTripDiv1 * obj = new LongLongTripDiv1();
	clock_t start = clock();
	string my_answer = obj->isAble(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "Possible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 2;
	int t1[] = {1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {0};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {1};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	long long p4 = 1000000000000000000LL;
	LongLongTripDiv1 * obj = new LongLongTripDiv1();
	clock_t start = clock();
	string my_answer = obj->isAble(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "Impossible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 4;
	int t1[] = {0,0,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {2,1,2};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {10,10,10};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	long long p4 = 1000LL;
	LongLongTripDiv1 * obj = new LongLongTripDiv1();
	clock_t start = clock();
	string my_answer = obj->isAble(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "Impossible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	int p0 = 9;
	int t1[] = {4,8,5,8,3,6,2,6,7,6,6};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {2,7,1,5,1,3,1,1,5,4,2};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {6580,8822,1968,673,1394,9337,5486,1746,5229,4092,195};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	long long p4 = 937186357646035002LL;
	LongLongTripDiv1 * obj = new LongLongTripDiv1();
	clock_t start = clock();
	string my_answer = obj->isAble(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "Impossible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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

//Powered by [KawigiEdit] 2.0!
