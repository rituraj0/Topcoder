#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int mx[]={-1,1,0,0};
int my[]={0,0,-1,1};


class MazeWandering {
public:
vector<int> g[2600];

double f[2600];

int fath[2600];

void solve( int v, int fa)
{
 fath[v]=fa;

 int d=0;
 double s=0;

 //cout<<"In solve\n";

 for(int i=0;i<g[v].size();i++)
 {
   int k=g[v][i];
   if(k==fa)
     continue;

     solve(k,v);
     s+=f[k];
     d++;
   }

    if( fath[v]>=0 )//non root
      f[v]=d+1+s;
}

double expectedTime(vector <string> maze)
{

int n=maze.size();
int m=maze[0].size();

 for(int i=0;i<n;i++)
   for(int j=0;j<m;j++)
      if( maze[i][j]!='X')
          for(int d=0;d<4;d++)
            {
                int x=i+mx[d];
                int y=j+my[d];
                if( x>=0 && x<n & y>=0 && y<m && maze[x][y]!='X')
                   g[i*m+j].push_back(x*m+y);
             }

   int root=-1;
   for(int i=0;i<n;i++)
     for(int j=0;j<m;j++)
       if( maze[i][j]=='*')
           root=i*m+j;

   double res=0;
   int cnt=0;

   solve(root,-1);

   for(int i=0;i<n;i++)
     for(int j=0;j<m;j++)
        if( maze[i][j]!='X')
          { cnt++;

             int v=i*m+j;

             for( ; v!=root;v=fath[v] )
                res+=f[v];
            }
                
     return (res/cnt);

}

};


double test0() {
	string t0[] = {"*",
 "."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	MazeWandering * obj = new MazeWandering();
	clock_t start = clock();
	double my_answer = obj->expectedTime(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 0.5;
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
	string t0[] = {"*.."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	MazeWandering * obj = new MazeWandering();
	clock_t start = clock();
	double my_answer = obj->expectedTime(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 2.3333333333333335;
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
	string t0[] = {"...",
 "X*X",
 "..."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	MazeWandering * obj = new MazeWandering();
	clock_t start = clock();
	double my_answer = obj->expectedTime(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 4.857142857142857;
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
	string t0[] = {".*.",
 ".XX",
 "..."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	MazeWandering * obj = new MazeWandering();
	clock_t start = clock();
	double my_answer = obj->expectedTime(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 13.714285714285714;
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
	string t0[] = {"*........",
 "XXX.XXXX.",
 ".XX.X....",
 ".....XX.X"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	MazeWandering * obj = new MazeWandering();
	clock_t start = clock();
	double my_answer = obj->expectedTime(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 167.2608695652174;
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
