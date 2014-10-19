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


int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

class TurningMaze
{
public:

vector<string> in;
int row,col;

int dist[8][8][1<<7][1<<7];

queue<int> Q;

void add( int x, int y , int xm , int ym , int d)
{
     if( d < dist[x][y][xm][ym])
     {
         dist[x][y][xm][ym]=d;
         Q.push(x); Q.push(y); Q.push(xm);Q.push(ym);
     }
}

bool ns_open( int x, int y , int xm , int ym)
{
     if( ( (xm&(1<<x))==0) ==( (ym&(1<<y))==0) )
          return in[x][y]=='A' || in[x][y]=='C';
     else
          return in[x][y]=='A' || in[x][y]=='D';
}

bool ew_open( int x, int y , int xm , int ym)
{
     if( ( (xm&(1<<x))==0) ==( (ym&(1<<y))==0) )
          return in[x][y]=='A' || in[x][y]=='D';
     else
          return in[x][y]=='A' || in[x][y]=='C';
}



int minTime(vector <string> _in)
{
     in=_in;
     row=in.sz;
     col=in[0].sz;


     fill(dist,63);

     int mx=dist[0][0][0][0];

     add(0,0,0,0,0);

     int x,y,xm,ym;

     while(!Q.empty())
     {
          x=Q.front(); Q.pop();
          y=Q.front(); Q.pop();
          xm=Q.front(); Q.pop();
          ym=Q.front(); Q.pop();

          int d=dist[x][y][xm][ym];

          add( x , y , (xm^(1<<x)) , (ym^(1<<y)) , d+1);

          for(int i=0;i<4;i++)
          {
               int nx=x+dx[i];
               int ny=y+dy[i];

               if( nx <0 || nx >=row || ny <0 || ny>=col) continue;

               if(i<2)
                  if( ns_open(x,y,xm,ym) )
                    if( ns_open(nx,ny,xm,ym) )
                      add( nx , ny , xm ,ym , d+1);

               if( i>=2)
                  if( ew_open(x,y,xm,ym) )
                    if( ew_open(nx,ny,xm,ym))
                        add( nx , ny , xm ,ym , d+1);
          }
     }

     int ans=mx;

     for(int i=0;i<(1<<row);i++)
         for(int j=0;j<(1<<col);j++)
          ans=min( ans , dist[row-1][col-1][i][j]);

     if( ans == mx)
         return -1;

     return ans;

}

};


double test0() {
	string t0[] = {"AA", "AA"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TurningMaze * obj = new TurningMaze();
	clock_t start = clock();
	int my_answer = obj->minTime(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
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
	string t0[] = {"AAA", "BBA", "AAA", "ABB", "AAA"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TurningMaze * obj = new TurningMaze();
	clock_t start = clock();
	int my_answer = obj->minTime(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 10;
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
	string t0[] = {"AAACAAA", "BBBBBBA"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TurningMaze * obj = new TurningMaze();
	clock_t start = clock();
	int my_answer = obj->minTime(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 8;
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
	string t0[] = {"ACDCDCA", "BBBBBBA"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TurningMaze * obj = new TurningMaze();
	clock_t start = clock();
	int my_answer = obj->minTime(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 12;
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
	string t0[] = {"CA", "BA"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TurningMaze * obj = new TurningMaze();
	clock_t start = clock();
	int my_answer = obj->minTime(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = -1;
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
double test5() {
	string t0[] = {"CAA", "DAA", "ACA"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TurningMaze * obj = new TurningMaze();
	clock_t start = clock();
	int my_answer = obj->minTime(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 6;
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
	
	time = test5();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
