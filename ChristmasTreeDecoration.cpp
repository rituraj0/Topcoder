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

class ChristmasTreeDecoration
{
public:

int boss[55];

int root( int x)
{
    if( boss[x]==x)
         return x;

    return  boss[x]=root( boss[x] );
}

bool join( int x, int y )
{
    int xp=root(x);
    int yp=root(y);

    if(xp==yp)
        return false;

    boss[xp]=yp;

    return true;
}

int solve(vector <int> col, vector <int> x, vector <int> y)
{

    fill(boss,-1);

    int n=sz(col);

        for(int i=0;i<n;i++)
        boss[i]=i;

    int ed=sz(x);

    for(int i=0;i<ed;i++)
    {
        int a=x[i]-1;
        int b=y[i]-1;

        if( col[a]==col[b])
             continue;

        join(a,b);
    }

    int ans=0;


    for(int i=0;i<ed;i++)
    {
        int a=x[i]-1;
        int b=y[i]-1;

        if( col[a]==col[b])
            if( join(a,b) )
                  ans++;
    }

    return ans;

}

};


double test0() {
	int t0[] = {1,1,2,2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,2,3,4};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {2,3,4,1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ChristmasTreeDecoration * obj = new ChristmasTreeDecoration();
	clock_t start = clock();
	int my_answer = obj->solve(p0, p1, p2);
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
double test1() {
	int t0[] = {1,1,2,2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,2,3,4,1,2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {2,3,4,1,3,4};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ChristmasTreeDecoration * obj = new ChristmasTreeDecoration();
	clock_t start = clock();
	int my_answer = obj->solve(p0, p1, p2);
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
	int t0[] = {50,50,50,50};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,2,3,1,1,2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {2,3,4,4,3,4};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ChristmasTreeDecoration * obj = new ChristmasTreeDecoration();
	clock_t start = clock();
	int my_answer = obj->solve(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 3;
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
	int t0[] = {1,4,2,3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,2,3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {2,3,4};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ChristmasTreeDecoration * obj = new ChristmasTreeDecoration();
	clock_t start = clock();
	int my_answer = obj->solve(p0, p1, p2);
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
double test4() {
	int t0[] = {1,1,1,2,2,2,3,3,3,4,4,4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,2,3,4,5,6,7,8,9,10,11,12,1,1,1,1,1,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {2,3,1,5,6,4,8,9,7,11,12,10,5,7,12,11,6,4};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ChristmasTreeDecoration * obj = new ChristmasTreeDecoration();
	clock_t start = clock();
	int my_answer = obj->solve(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 5;
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
