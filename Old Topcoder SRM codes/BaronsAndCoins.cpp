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

#define pii pair<int,int>

class BaronsAndCoins
{
public:

vector<pii> in;
int n;

int memo[55][100009];

int solve( int cid,int minlen)
{
   if( cid>=n) return 0;

   if(memo[cid][minlen]!=-1)  return memo[cid][minlen];

   int ans=0;

   for(int i=cid+1;i<n;i++)
   {
       int dy=in[i].X-in[cid].X;

       if(dy==0)
        continue;

       int dx=in[i].Y-in[cid].Y;

       //check if its is possible to reach cid using dy steps , bcx in evry strep dy will increarse by 1
       //minlen+1 ,minlen+2 , minlen+3 , minlen+4 ... dy times
       int cangomin=dy*minlen+(dy*(dy+1))/2;

       if( cangomin > dx) //minum distance chalne layak is cangomin
         continue;

       int extra=dx-cangomin;
       //now distrubuting extra to dy steps evenly
       int newminlen=(minlen+dy)+extra/dy;

       //now reamining dy%dk to 1-1- everyone
        if( extra%dy)
            newminlen++;

        ans=max(ans, solve(i,newminlen) );
   }

   ans++;//khud ka bhi to hai

    return memo[cid][minlen]=ans;

}


int getMaximum(vector <int> x, vector <int> y)
{
    in.pb( mp(0,0) );
    for(int i=0;i<sz(x);i++)
        in.pb( mp( y[i],x[i]) );

    n=sz(in);

    sort(in.begin(),in.end() );

    fill(memo,-1);

    return solve(0,0)-1;

}

};


double test0() {
	int t0[] = {15, 5, 30};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {4, 5, 6};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	BaronsAndCoins * obj = new BaronsAndCoins();
	clock_t start = clock();
	int my_answer = obj->getMaximum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
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
	int t0[] = {10};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {10};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	BaronsAndCoins * obj = new BaronsAndCoins();
	clock_t start = clock();
	int my_answer = obj->getMaximum(p0, p1);
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
double test2() {
	int t0[] = {1, 3, 6, 10, 15, 21};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1, 2, 3, 4, 5, 6};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	BaronsAndCoins * obj = new BaronsAndCoins();
	clock_t start = clock();
	int my_answer = obj->getMaximum(p0, p1);
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
	int t0[] = {5, 10, 15, 20, 25, 30, 35, 40, 45};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1, 1, 1, 2, 2, 2, 3, 3, 3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	BaronsAndCoins * obj = new BaronsAndCoins();
	clock_t start = clock();
	int my_answer = obj->getMaximum(p0, p1);
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
double test4() {
	int t0[] = {1, 3, 6, 10, 22, 35, 50, 66};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1, 2, 3, 1, 2, 3, 4, 5};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	BaronsAndCoins * obj = new BaronsAndCoins();
	clock_t start = clock();
	int my_answer = obj->getMaximum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 5;
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
