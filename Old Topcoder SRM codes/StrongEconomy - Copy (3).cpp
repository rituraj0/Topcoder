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

class StrongEconomy
{
public:

ll solve( ll p , ll f , ll old , ll tar , ll done)
{
     ll income=p*f;
     ll req=max(tar-old,0LL);
     ll cr=( req+income-1)/income;
     return (done+cr);
}


long long earn(long long p, long long f, long long cost, long long tar)
{

   double dp=p,df=f,dt=tar;

   if( dp*df > tar ) return 1;

    ll old=0;

    ll ans=solve(p,f,old,tar,0);

    for(int r=1;r<(1e7);r++)
    {
        if( (p>(1e6+10))  && (f>(1e6+10)) )
            break;

       ll income=p*f;

       ll can=(income+old)/cost;

       old+=income;

       for(int i=0;i<can;i++)
       {
            old-=cost;

            if( p < f)
             p+=1;
            else
              f+=1;

            ans=min(ans,solve(p,f,old,tar,r) );


           if( (p>(1e6+10))  && (f>(1e6+10)) )
             break;
       }

    }


    return ans;

}

};

double test0() {
	long long p0 = 2LL;
	long long p1 = 1LL;
	long long p2 = 2LL;
	long long p3 = 10LL;
	StrongEconomy * obj = new StrongEconomy();
	clock_t start = clock();
	long long my_answer = obj->earn(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p4 = 4LL;
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
	long long p0 = 2LL;
	long long p1 = 1LL;
	long long p2 = 2LL;
	long long p3 = 9LL;
	StrongEconomy * obj = new StrongEconomy();
	clock_t start = clock();
	long long my_answer = obj->earn(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p4 = 3LL;
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
	long long p0 = 1LL;
	long long p1 = 1LL;
	long long p2 = 500000LL;
	long long p3 = 1000002LL;
	StrongEconomy * obj = new StrongEconomy();
	clock_t start = clock();
	long long my_answer = obj->earn(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p4 = 1000001LL;
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
	long long p0 = 5LL;
	long long p1 = 4LL;
	long long p2 = 15LL;
	long long p3 = 100LL;
	StrongEconomy * obj = new StrongEconomy();
	clock_t start = clock();
	long long my_answer = obj->earn(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p4 = 5LL;
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

    StrongEconomy  *obj = new StrongEconomy();

    ll p,f,c,t;

		while(1)
        {
            cin>>p>>f>>c>>t;

            cout<<obj->earn(p,f,c,t)<<endl;
        }

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!

