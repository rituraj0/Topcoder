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

int memo[12][12][1<<12];

class FloorBoards
{
public:

    vector<string> room;
    int row,col;

    int solve(int x, int y , int mask)
    {
         if(x==row)  return 0;

         if( memo[x][y][mask] != -1 ) return memo[x][y][mask] ;

         if( room[x][y]=='#')
              return solve( x+ (y+1)/col  ,  (y+1)%col , mask&~(1<<y) );

         //vertical line
         int op1=solve(  x+ (y+1)/col  ,  (y+1)%col , mask|(1<<y) );

          if( (mask&(1<<y) )==0)
             op1++;

         //horizontal line
         int op2=solve( x+ (y+1)/col  ,  (y+1)%col , mask&~(1<<y) );

          if( y==0 || room[x][y-1]=='#' || (mask&(1<<(y-1)) )!=0 )
            op2++;

          return  memo[x][y][mask]=min(op1,op2);



    }


int layout(vector <string> roo)
{
     room=roo;

     row=room.sz;
     col=room[0].sz;

     fill(memo,-1);

     return solve(0,0,0);

}

};


double test0() {
	string t0[] = {"....."
,"....."
,"....."
,"....."
,"....."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FloorBoards * obj = new FloorBoards();
	clock_t start = clock();
	int my_answer = obj->layout(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 5;
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
	string t0[] = {"......."
,".#..##."
,".#....."
,".#####."
,".##..#."
,"....###"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FloorBoards * obj = new FloorBoards();
	clock_t start = clock();
	int my_answer = obj->layout(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 7;
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
	string t0[] = {"####"
,"####"
,"####"
,"####"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FloorBoards * obj = new FloorBoards();
	clock_t start = clock();
	int my_answer = obj->layout(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 0;
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
	string t0[] = {"...#.."
,"##...."
,"#.#..."
,".#...."
,"..#..."
,"..#..#"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FloorBoards * obj = new FloorBoards();
	clock_t start = clock();
	int my_answer = obj->layout(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 9;
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
	string t0[] = {".#...."
,"..#..."
,".....#"
,"..##.."
,"......"
,".#..#."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FloorBoards * obj = new FloorBoards();
	clock_t start = clock();
	int my_answer = obj->layout(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 9;
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

//Powered by [KawigiEdit] 2.0!
