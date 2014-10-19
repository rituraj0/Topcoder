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

class ConstructBST
{
public:

    ll memo[30][30];

    ll solve( int x, int y)
    {
        if(x*y==0)
              return 1LL;

        if( memo[x][y]!=-1)
             return memo[x][y];

        double ans=0;

         ans+=solve(x-1,y);
         ans+=solve(x,y-1);

         return memo[x][y]=ans;
    }

    vector<int> child[30];
    int lc[30],rc[30];

int dfs(int x)
{

    if( child[x].size() > 0)
          lc[x]=dfs( child[x][0] );

    if( child[x].size() > 1)
          rc[x]=dfs( child[x][1] );

    return (lc[x]+rc[x]+1);

}


long long  numInputs(vector <int> tree)
{
    sort( tree.begin(),tree.end());

    int n=tree.size();

    for(int i=0;i<n;i++)
    {
        int curr=tree[i];

          for(int j=i+1;j<n;j++)
              if( tree[j]==curr*2 || tree[j]==curr*2+1)
                    child[i].pb(j);
    }

    memset( lc , 0 , sizeof(lc));
    memset( rc, 0, sizeof(rc));

    dfs(0);

    ll ans=1LL;

    memset( memo , -1, sizeof(memo));

    for(int i=0;i<n;i++)
    {
           ll tp=solve( lc[i] , rc[i]);
           ans*=tp;
    }

    return ans;

}

};


double test0() {
	int t0[] = {1, 2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	ConstructBST * obj = new ConstructBST();
	clock_t start = clock();
	long long my_answer = obj->numInputs(p0);
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
double test1() {
	int t0[] = {1, 3, 6};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	ConstructBST * obj = new ConstructBST();
	clock_t start = clock();
	long long my_answer = obj->numInputs(p0);
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
double test2() {
	int t0[] = {1, 2, 5, 3, 4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	ConstructBST * obj = new ConstructBST();
	clock_t start = clock();
	long long my_answer = obj->numInputs(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 8LL;
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
	int t0[] = {1, 2, 4, 6, 3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	ConstructBST * obj = new ConstructBST();
	clock_t start = clock();
	long long my_answer = obj->numInputs(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 6LL;
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
double test4() {
	int t0[] = {2, 4, 3, 62, 7, 15, 1, 31, 5, 14, 28, 57, 56, 114};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	ConstructBST * obj = new ConstructBST();
	clock_t start = clock();
	long long my_answer = obj->numInputs(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 96096LL;
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
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
