#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
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
#define sz(s) ((int)(s.size()))

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

#define mod 2000000011
int dx[]={1,0,1};
int dy[]={1,1,0};

unsigned int  memo[15][15][1<<16];

class HexagonalBattlefield
{
public:

int N,n;

bool used[15][15];

bool cool( int x, int y)
{
  if( (x < 0) || (x>=n) ) return 0;

  int lo=(x<N)?0:x-N;
  int hi=(x<N)?x+N:2*N;

  return ( (lo<=y)&&(y<=hi) );
}

unsigned int solve( int x, int y)
{
  if(x==n) return 1;

  if(y==n) return solve(x+1,0);

  if( used[x][y]) return solve(x,y+1);

  int mask=0,b=0;

  for(int  yy=y+1;yy<n;yy++)
     if( cool(x,yy))
      mask|=used[x][yy]<<(b++);

  for(int yy=0;yy<=y+1;yy++)
     if( cool(x+1,yy))
      mask|=used[x+1][yy]<<(b++);

   unsigned int &ans=memo[x][y][mask];

   if(ans!=-1) return ans;

   ans=0;

   used[x][y]=1;

  for(int i=0;i<3;i++)
  {
      int xx=x+dx[i];
      int yy=y+dy[i];

      if(xx<0 || xx>=n || yy<0 || yy>=n|| used[xx][yy]) continue;

      used[xx][yy]=1;

      ans+=solve(x,y+1);

      ans=ans%mod;
      used[xx][yy]=0;
  }

  used[x][y]=0;

  return ans;
}

int countArrangements(vector <int> X, vector <int> Y, int NN)
{
    N=NN-1;
    n=2*N+1;

    for(int x=0;x<n;x++)
        for(int y=0;y<n;y++)
          used[x][y]=!cool(x,y);

    for(int i=0;i<sz(X);i++)
        used[ X[i]+N ][ Y[i]+N ]=true;

    fill(memo,-1);

    return solve(0,0);

}

};


double test0() {
	int t0[] = {-2,0,1,1,0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {-2,0,1,0,2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 3;
	HexagonalBattlefield * obj = new HexagonalBattlefield();
	clock_t start = clock();
	int my_answer = obj->countArrangements(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 10;
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
	int t0[] = {0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 2;
	HexagonalBattlefield * obj = new HexagonalBattlefield();
	clock_t start = clock();
	int my_answer = obj->countArrangements(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 2;
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
	int t0[] = {0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 3;
	HexagonalBattlefield * obj = new HexagonalBattlefield();
	clock_t start = clock();
	int my_answer = obj->countArrangements(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 104;
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
	int t0[] = {-1,0,0,1,2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,0,1,0,0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 3;
	HexagonalBattlefield * obj = new HexagonalBattlefield();
	clock_t start = clock();
	int my_answer = obj->countArrangements(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 6;
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
double test4() {
	int t0[] = {0,1,0,0,1,-1,-1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,0,-1,1,1,0,-1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 2;
	HexagonalBattlefield * obj = new HexagonalBattlefield();
	clock_t start = clock();
	int my_answer = obj->countArrangements(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1;
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

	time = test4();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
