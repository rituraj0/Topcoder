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

class MinimumSquare
{
public:

    vector<ll> x,y,ax,ay;
    int n,k;


bool cool( ll a, ll b,ll c,ll d)
{
     ll x1=min(a , b);
     ll x2=max(a , b);

     ll y1=min( c , d);
     ll y2=max( c , d);

     int mila=0;

     for(int i=0;i<n;i++)
          if( (x1<x[i]) && ( x[i]<x2) )
              if( (y1<y[i]) && (y[i]<y2) )
                 {

                    mila++;

                    if( mila>=k)
                      return true;
                 }

     return false;

}


long long minArea(vector <int> _x, vector <int> _y, int _k)
{

    k=_k;

    n=_x.sz;


    for(int i=0;i<n;i++)
    {
        x.pb( _x[i]);
        y.pb( _y[i] );
    }



    for(int i=0;i<n;i++)
          for(int j=-1;j<2;j++)
    {
         if(j==0)
             continue;

        ax.pb( x[i]+j);
        ay.pb( y[i]+j);
    }


     sort(ax.begin(),ax.end());
    ax.erase(unique(ax.begin(),ax.end()),ax.end());

       sort(ay.begin(),ay.end());
    ay.erase(unique(ay.begin(),ay.end()),ay.end());



    ll lo=0,hi=(1LL<<32);

    ll ans=-1;

    while(lo<=hi)
    {
        ll mid=(lo+hi)/2;

        bool mila=false;

           for(int i=0;i<ax.sz;i++)
           {


                    for( int j=0;j<ay.sz;j++)
                    {
                            if( cool(ax[i],ax[i]+mid , ay[j] , ay[j]+mid ) )
                                 { mila=true;
                                    break;
                                 }


                            if( cool(ax[i],ax[i]+mid , ay[j] , ay[j]-mid ) )
                                {
                                  mila=true;
                                   break;
                                }

                            if( cool(ax[i],ax[i]-mid , ay[j] , ay[j]+mid ) )
                                {
                                   mila=true;
                                   break;
                                }

                            if( cool(ax[i],ax[i]-mid , ay[j] , ay[j]-mid ) )
                                 {
                                   mila=true;
                                   break;
                                }

                    }

                   if(mila)
                   {
                       break;
                   }

           }

            if( mila)
            {
                ans=mid;
                hi=mid-1;
            }
           else
           {
               lo=mid+1;
           }


    }

    return ans*ans;



}

};


double test0() {
	int t0[] = {0, 3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0, 7};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 2;
	MinimumSquare * obj = new MinimumSquare();
	clock_t start = clock();
	long long my_answer = obj->minArea(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 81LL;
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
	int t0[] = {-4, 3, 1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {3 , -1, -2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 2;
	MinimumSquare * obj = new MinimumSquare();
	clock_t start = clock();
	long long my_answer = obj->minArea(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 16LL;
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
	int t0[] = {0, 0, 1, 1, 2, 2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0, 1, 0, 1, 0, 1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 4;
	MinimumSquare * obj = new MinimumSquare();
	clock_t start = clock();
	long long my_answer = obj->minArea(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 9LL;
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
	int t0[] = {1000000000, 1000000000, 1000000000, -1000000000, -1000000000, -1000000000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1000000000, 0, -1000000000, 1000000000, 0, -1000000000};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 3;
	MinimumSquare * obj = new MinimumSquare();
	clock_t start = clock();
	long long my_answer = obj->minArea(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 4000000008000000004LL;
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
	int t0[] = {-47881, 28623, 1769, -38328, -16737, 16653, -23181, 37360, 41429, 26282, 254, 728, 8299, -41080, -29498, 17488, -23937, -11, 33319, 25232};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {-46462, 48985, -43820, -19587, -33593, -28337, 13667, -48131, -5568, -2332, -41918, -31370, -3695, 42599, -37788, -40096, 39049, 25045, -2122, 3874};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 8;
	MinimumSquare * obj = new MinimumSquare();
	clock_t start = clock();
	long long my_answer = obj->minArea(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 1695545329LL;
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
