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

vector <int> parse(string s, string c)
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

  vector<int> ret;

  for(int i=0;i<ans.size();i++)
     ret.pb( atoi(ans[i].c_str() ) );

  return ret;
}


/*Solution code starts here */

#define pii  pair<int,int>

class BlockEnemy
{
public:

    int wt[55][55];
    bool path[55][55],temp[55][55];

    int n;

    vector<int> bad;

    bool check()
    {
         memset( temp , 0, sizeof(temp) );

         for(int i=0;i<n;i++)
           for(int j=0;j<n;j++)
              temp[i][j]=path[i][j];

           for(int k=0;k<n;k++)
             for(int i=0;i<n;i++)
              for(int j=0;j<n;j++)
                temp[i][j]=temp[i][j]||(temp[i][k] && temp[k][j]);

           for(int i=0;i<bad.size();i++)
             for(int j=i+1;j<bad.size();j++)
               if( temp[ bad[i] ][ bad[j] ] )
                  return false;

           return true;

    }

int  minEffort(int N, vector <string> roads, vector <int> occupiedTowns)
{
   memset(wt,0,sizeof(wt));
   memset(path,0,sizeof(path));

   n=N;

   bad=occupiedTowns;

   vector<pii> all;

   for(int i=0;i<roads.size();i++)
   {
       vector<int> tp=parse( roads[i]," ");

        all.pb( mp(tp[2] , tp[1]*100+tp[0]) );
   }

   sort( all.begin() , all.end() );

   int ans=0;

   for(int i=all.size()-1;i>=0;i--)
   {
       int a=all[i].Y/100;
       int b=all[i].Y%100;
       int w=all[i].X;

       path[a][b]=path[b][a]=true;

       if( check() )
         continue;

       path[a][b]=path[b][a]=false;

       ans+=w;
   }

   return ans;

}

};



double test0() {
	int p0 = 5;
	string t1[] = {"1 0 1", "1 2 2", "0 3 3", "4 0 4"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int t2[] = {3, 2, 4};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	BlockEnemy * obj = new BlockEnemy();
	clock_t start = clock();
	int my_answer = obj->minEffort(p0, p1, p2);
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
double test1() {
	int p0 = 5;
	string t1[] = {"1 0 1", "1 2 2", "0 3 3", "4 0 4"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int t2[] = {3};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	BlockEnemy * obj = new BlockEnemy();
	clock_t start = clock();
	int my_answer = obj->minEffort(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 0;
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
	int p0 = 12;
	string t1[] = {"0 1 3", "2 0 5", "1 3 1", "1 4 8", "1 5 4", "2 6 2",
 "4 7 11", "4 8 10", "6 9 7", "6 10 9", "6 11 6"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int t2[] = {1, 2, 6, 8};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	BlockEnemy * obj = new BlockEnemy();
	clock_t start = clock();
	int my_answer = obj->minEffort(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 13;
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
double test3() {
	int p0 = 12;
	string t1[] = {"0 1 3", "2 0 5", "1 3 1", "1 4 8", "1 5 4", "2 6 2",
 "4 7 11", "4 8 10", "6 9 7", "6 10 9", "6 11 6"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int t2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	BlockEnemy * obj = new BlockEnemy();
	clock_t start = clock();
	int my_answer = obj->minEffort(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 66;
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
	
	time = test3();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
