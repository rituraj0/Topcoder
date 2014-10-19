#include <bits/stdc++.h>
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

#define print(a) cout<<(#a)<<" = "<<a<<"\n";
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


int memo[11][26][1<<11];

class FourBlocks
{
public:

int  row,col;

vector<string> in;

/* x wise rakhne pe 1<<25 memro chahia ,
islia nahi rakh rahe aisa
*/

int solve( int y , int x , int mask)//try to put a 2x2 ,mask current col ki lya halat hai
{
    if(x>=col-1) return 0;

    if(y==row) return solve(0,x+1,mask);

    int &ans=memo[y][x][mask];

    if(ans!=-1) return ans;

    ans=0;
    //occupied by 1 , continue , y in next in not blocked
    if( in[y][x]=='1') return ans=solve( y+1,x,mask&(~(1<<y)) );

    //already blocked by 2x2 in prevois col, contnue
    if( mask&(1<<y) ) return ans=solve(y+1,x,mask&(~(1<<y)) );

     //it is not possible to keep z 2x2 here in conditions below
    if( (y==row-1)||(in[y+1][x]=='1') || (mask&(1<<(y+1))) )  return ans=solve( y+1,x,mask&(~(1<<y)) );

   //it is not possible to keep z 2x2 here in conditions below , next column meblocked hai
    if( in[y][x+1]=='1' || in[y+1][x+1]=='1') return ans=solve(y+1,x,mask&(~(1<<y)) );

    //nahi rakhna yaha
    ans=solve(y+1,x,mask&(~(1<<y)));//yaha 1 hi barna hai

     //rakh hi do yaar
    ans=max( ans ,1+ solve( y+2,x,mask|(1<<y)|(1<<(y+1))) );

    return ans;

}

int maxScore(vector <string> grid)
{
   in=grid;

   row=grid.sz;
   col=grid[0].sz;

   fill(memo,-1);

   int ans=solve(0,0,0);

   int all=row*col;

   int oneC=all-4*ans;

   return (oneC+16*ans);
}

};


double test0() {
	string t0[] = {".....1..1..",
 "..1.....1.."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FourBlocks * obj = new FourBlocks();
	clock_t start = clock();
	int my_answer = obj->maxScore(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 70;
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
	string t0[] = {"...1.",
 ".....",
 ".1..1",
 ".....",
 "1...."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FourBlocks * obj = new FourBlocks();
	clock_t start = clock();
	int my_answer = obj->maxScore(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 73;
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
	string t0[] = {"...1.",
 ".1...",
 "..1.1",
 "1...."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FourBlocks * obj = new FourBlocks();
	clock_t start = clock();
	int my_answer = obj->maxScore(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 20;
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
	string t0[] = {".....1...",
 ".....1...",
 "111111111",
 ".....1...",
 ".....1..."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FourBlocks * obj = new FourBlocks();
	clock_t start = clock();
	int my_answer = obj->maxScore(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 117;
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
