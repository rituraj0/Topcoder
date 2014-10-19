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


class TheHexagonsDivOne
{
public:

vector<int> valid;

bool cool( int mask)
{
   if( __builtin_popcount(mask)==1 )  return true;

   string curr="";
   vector<int> all;

   while( sz(curr)<6)
   {
       if(mask&1)
         {curr="1"+curr;
           all.pb( sz(curr) );
         }
       else
         curr="0"+curr;

       mask/=2;
   }

   if( sz(all)!=2) return false;

   sort( all.bg,all.en);

   if( abs(all[0]-all[1])==1) return false;

   if( (all[0]==1) & (all[1]==6) ) return false;

   return true;
}

int N;

ll memo[200][100];

ll solve( int curr, int mask)
{
    if( curr==N-1)//bcz only x%n rakhne ja rahe hai , zero ko chhorkar
    {
         if( mask==(1<<6)-1)
            return 1;
          else
              return 0;
    }

    if( memo[curr][mask]!=-1) return memo[curr][mask];

    memo[curr][mask]=0;

    ll ans=0;

    ans+=solve(curr+1,mask);

    for(int i=0;i<sz(valid);i++)
    {
        if( !(mask&valid[i]) )
             ans+=solve(curr+1,mask|valid[i])*2LL;
    }

    return memo[curr][mask]=ans;
}

long long count(int n)
{
   for(int i=1;i<(1<<6);i++)
     if( cool(i) )
       valid.pb(i);

       cout<<sz(valid)<<endl;

   N=n;

   fill(memo,-1);

   return (solve(0,0)/3)*n;
}

};


double test0() {
	int p0 = 3;
	TheHexagonsDivOne * obj = new TheHexagonsDivOne();
	clock_t start = clock();
	long long my_answer = obj->count(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 0LL;
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
	int p0 = 4;
	TheHexagonsDivOne * obj = new TheHexagonsDivOne();
	clock_t start = clock();
	long long my_answer = obj->count(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 256LL;
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
	int p0 = 8;
	TheHexagonsDivOne * obj = new TheHexagonsDivOne();
	clock_t start = clock();
	long long my_answer = obj->count(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 3458560LL;
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
	int p0 = 20;
	TheHexagonsDivOne * obj = new TheHexagonsDivOne();
	clock_t start = clock();
	long long my_answer = obj->count(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 11193888000LL;
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
