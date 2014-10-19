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

#define pii pair<int,int>




class SpecialCells
{
public:

map<pii,bool> cool;

int n;

bool graf[55][55];
int top, bot;

int match[55];

bool done[55];

bool dfs(int u)
{
	if(done[u] )
		return false;

	 done[u] = true;

	for(int v = 0; v < bot; v++)
	 {
		if(graf[u][v] )
		   if( match[v]==-1)
		     {
			    match[v] = u;
			    return true;
			 }
	}

	for(int v=0;v<bot;v++)
	  {
	  	  if( graf[u][v])
	  	    if(  dfs( match[v] ) )
	  	      {
	  	      	match[v]=u;
	  	      	return true;
	  	      }

	  }

	  return false;
}

int solve()
{

	memset(match, -1, sizeof(match));

	int ans=0;

	for(int i = 0; i < top; i++)
	{
        memset(done,0,sizeof(done));

		if( dfs(i) )
		   ans++;
	}

	return ans;
}



int guess(vector <int> x, vector <int> y)
{
     top=bot=n=x.size();

     fill(graf,0);

     for(int i=0;i<n;i++)
         cool[ mp(x[i],y[i] ) ]=true;

     for(int i=0;i<n;i++)
          for(int j=0;j<n;j++)
              if( i!=j)
                if( cool[ mp(x[i],y[j]) ] )
                    graf[i][j]=true;


          return solve();


}

};


double test0() {
	int t0[] = {1,2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	SpecialCells * obj = new SpecialCells();
	clock_t start = clock();
	int my_answer = obj->guess(p0, p1);
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
double test1() {
	int t0[] = {1,1,2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,2,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	SpecialCells * obj = new SpecialCells();
	clock_t start = clock();
	int my_answer = obj->guess(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 3;
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
	int t0[] = {1,2,1,2,1,2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,2,3,1,2,3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	SpecialCells * obj = new SpecialCells();
	clock_t start = clock();
	int my_answer = obj->guess(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 6;
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
	int t0[] = {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	SpecialCells * obj = new SpecialCells();
	clock_t start = clock();
	int my_answer = obj->guess(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 9;
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
	int t0[] = {1,100000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,100000};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	SpecialCells * obj = new SpecialCells();
	clock_t start = clock();
	int my_answer = obj->guess(p0, p1);
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

//Powered by [KawigiEdit] 2.0!
