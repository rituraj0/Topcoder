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

#define pll pair<ll,ll>

/*Solution code starts here */

double angle( pll a)
 {
    double tp=acos( ((double)a.X) /sqrt( (double)(a.X*a.X + a.Y*a.Y) ) );

    if( a.Y < 0)
        tp=pi*2-tp;

    return tp;
 }


bool comp(pll a , pll b )
{
	 return ( angle(a) <angle(b) );

}
class TrianglesContainOrigin
{
public:

vector< pair<ll,ll> > all;
vector< double > angleS;

vector<int> low,hig;

long long count(vector <int> x, vector <int> y)
{
    int n=x.size();

    for(int i=0;i<n;i++)
        {
            all.pb( mp(x[i],y[i]) );
        }


    sort( all.begin() , all.end() , comp);

    for(int i=0;i<n;i++)
     angleS.pb( angle(all[i]));

    low.resize(n);
    hig.resize(n);

    //find  alst lk s.t lo < angles[k];

    for(int i=0;i<n;i++)
    {
         double lo=(angleS[i]+pi);

            if( lo > 2*pi)
                lo-=2*pi;

         low[i]=1000000;//if noone is such

         for(int k=0;k<n;k++)
             if( lo < angleS[k])
                {
                    low[i]=k;
                    break;
                }
    }

    //find last k s.t angleS[k] < hi

    for(int i=0;i<n;i++)
    {
         double hi=(angleS[i]+pi);

         if( hi > 2*pi )
              hi-=2*pi;

        hig[i]=-100;

        for(int k=0;k<n;k++)
             if( angleS[k] < hi)
                {
                    hig[i]=k;
                }
    }

    ll ans=0;

    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
            ll tp=max( 0 , hig[j]-low[i]+1);
            ans+=tp;
        }

        return ans;

}

};


double test0() {
	int t0[] = {-1,-1,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,-1,0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TrianglesContainOrigin * obj = new TrianglesContainOrigin();
	clock_t start = clock();
	long long my_answer = obj->count(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 1LL;
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
	int t0[] = {-1,-1,1,2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,-1,2,-1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TrianglesContainOrigin * obj = new TrianglesContainOrigin();
	clock_t start = clock();
	long long my_answer = obj->count(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 2LL;
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
	int t0[] = {-1,-2,3,3,2,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {-2,-1,1,2,3,3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TrianglesContainOrigin * obj = new TrianglesContainOrigin();
	clock_t start = clock();
	long long my_answer = obj->count(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 8LL;
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
	int t0[] = {1,5,10,5,-5,7,-9,-6,-3,0,8,8,1,-4,7,-3,10,9,-6};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {5,-6,-3,4,-2,-8,-7,2,7,4,2,0,-4,-8,7,5,-5,-2,-9};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TrianglesContainOrigin * obj = new TrianglesContainOrigin();
	clock_t start = clock();
	long long my_answer = obj->count(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 256LL;
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
