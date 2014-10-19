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



class FixedDiceGameDiv1
{
public:

double memo[2][55][2600];
bool done[2][55][2600];

double solve( int id, int sum, int n, int curr)
{
     if( id==1)
     {
           if(  (1<=sum) && (sum<=n) )
            return 1.0;

           return 0.0;
     }

     if( done[curr][id][sum] )
         return memo[curr][id][sum];

     done[curr][id][sum]=true;
     memo[curr][id][sum]=0;

     double ans=0;

     for(int i=1;i<=n;i++)
         if( (sum-i) >=1)
           ans+=solve( id-1,sum-i,n,curr);

     return memo[curr][id][sum]=ans;
}



double getExpectation(int a, int b, int c, int d)
{
    fill( done,0);

    if( a*b <=c) return -1;


    double ans=0;


         for(int j=1;j<=a;j++)
                for(int i=0;i<=a*b;i++)
                    solve(j,i,b,0);


         for(int j=1;j<=c;j++)
                for(int i=0;i<=c*d;i++)
                     solve(j,i,d,1);

    double win=0.0;



    for(int x=1;x<=a*b;x++)//alice score
         for(int y=1;y<x;y++)
        {
            double xc=solve(a,x,b,0);
            double yc=solve(c,y,d,1);
             double xall=pow(b,a);
            double yall=pow(d,c);

            double pr=(xc/xall)*(yc/yall);

            if(y<x)
             { ans+=pr*( ( double)x );
                win+=pr;
             }
        }

     return (ans/win);

}

};


double test0() {
	int p0 = 50;
	int p1 = 50;
	int p2 = 50;
	int p3 = 50;
	FixedDiceGameDiv1 * obj = new FixedDiceGameDiv1();
	clock_t start = clock();
	double my_answer = obj->getExpectation(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 2.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 3;
	int p1 = 1;
	int p2 = 1;
	int p3 = 3;
	FixedDiceGameDiv1 * obj = new FixedDiceGameDiv1();
	clock_t start = clock();
	double my_answer = obj->getExpectation(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 3.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 1;
	int p1 = 5;
	int p2 = 1;
	int p3 = 1;
	FixedDiceGameDiv1 * obj = new FixedDiceGameDiv1();
	clock_t start = clock();
	double my_answer = obj->getExpectation(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 3.4999999999999996;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 2;
	int p1 = 6;
	int p2 = 50;
	int p3 = 30;
	FixedDiceGameDiv1 * obj = new FixedDiceGameDiv1();
	clock_t start = clock();
	double my_answer = obj->getExpectation(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = -1.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
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
	int p1 = 11;
	int p2 = 50;
	int p3 = 50;
	FixedDiceGameDiv1 * obj = new FixedDiceGameDiv1();
	clock_t start = clock();
	double my_answer = obj->getExpectation(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 369.8865999182022;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
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
