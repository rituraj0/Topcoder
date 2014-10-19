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

#define mod 1000007

int memo[55][55][55][55];
int id[55][55];

class CountPaths
{
public:
    int r,c;


int solve( int x, int y , int d, int last)
{
       if( d<0)  return 0;

       int &ans = memo[x][y][d][last];

       if(ans!=-1)  return ans;

       if( id[x][y] > 0)
       {
               if( id[x][y] <=last )
                 return ans=0;
               else
               {
                   d--;
                   last=id[x][y];
               }
       }

       if( d < 0)   return ans=0;

       if(x==r && y==c)
       {
             if(d==0)
                 return ans=1;
             else
                  return ans=0;
       }

       ans=0;

       if(x+1<=r)
          ans=(ans  + solve(x+1,y,d,last) )%mod;

       if(y+1<=c)
           ans=(ans + solve(x , y+1, d , last) )%mod;

       return ans;
}

vector <int> difPaths(int _r, int _c, vector <int> row, vector <int> col)
{
     r=_r;
     c=_c;

   int n=row.size();

   fill(id,-1);

   for(int i=0;i<n;i++)
      id[ row[i] ][ col[i] ]=i+1;


   fill(memo,-1);

   vector<int> ans;

   for(int i=0;i<=n;i++)
     ans.pb( solve(1,1,i,0) );

   return ans;
}

};


double test0() {
	int p0 = 3;
	int p1 = 3;
	int t2[] = {2, 3};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {2, 2};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	CountPaths * obj = new CountPaths();
	clock_t start = clock();
	vector <int> my_answer = obj->difPaths(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t4[] = {1, 3, 2 };
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p4.size() > 0) {
		cout <<p4[0];
		for (int i=1; i<p4.size(); i++)
			cout <<", " <<p4[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p4) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 6;
	int p1 = 4;
	int t2[] = {5, 3};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {3, 2};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	CountPaths * obj = new CountPaths();
	clock_t start = clock();
	vector <int> my_answer = obj->difPaths(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t4[] = {14, 24, 0 };
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p4.size() > 0) {
		cout <<p4[0];
		for (int i=1; i<p4.size(); i++)
			cout <<", " <<p4[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p4) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 5;
	int p1 = 5;
	int t2[] = {1, 2, 3};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {3, 4, 5};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	CountPaths * obj = new CountPaths();
	clock_t start = clock();
	vector <int> my_answer = obj->difPaths(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t4[] = {42, 14, 10, 4 };
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p4.size() > 0) {
		cout <<p4[0];
		for (int i=1; i<p4.size(); i++)
			cout <<", " <<p4[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p4) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 35;
	int p1 = 37;
	int t2[] = {3, 28, 28, 27, 27, 5, 15, 23, 21, 3, 8, 25, 34, 31, 33, 35, 13, 34};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {12, 34, 3, 9, 34, 3, 18, 17, 26, 5, 23, 14, 20, 7, 3, 20, 19, 23};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	CountPaths * obj = new CountPaths();
	clock_t start = clock();
	vector <int> my_answer = obj->difPaths(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t4[] = {830519, 709835, 755976, 219563, 868547, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p4.size() > 0) {
		cout <<p4[0];
		for (int i=1; i<p4.size(); i++)
			cout <<", " <<p4[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p4) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 50;
	int p1 = 50;
	int t2[] = {50, 1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {50, 1};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	CountPaths * obj = new CountPaths();
	clock_t start = clock();
	vector <int> my_answer = obj->difPaths(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t4[] = {0, 0, 0 };
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p4.size() > 0) {
		cout <<p4[0];
		for (int i=1; i<p4.size(); i++)
			cout <<", " <<p4[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p4) {
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
