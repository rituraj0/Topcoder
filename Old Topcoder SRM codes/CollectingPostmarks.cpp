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

class CollectingPostmarks
{
public:


int amountOfMoney(vector <int> prices, vector <int> have, vector <int> values, int K)
{
	 int n=prices.sz;

      if( n&1)
      {
          n++;
          prices.pb(0);
          values.pb(0);
      }

	 ll aval=0;
	 for(int i=0;i<have.sz;i++)
         aval+=prices[ have[i] ];


     vector< pair<ll,ll> >A,B;

       for(int mask=0;mask<(1<<(n/2) );mask++ )
       {
              ll cs=0 , val=0;

              for(int i=0;i<n/2;i++)
                  if( mask&(1<<i))
                   {
                     cs+=prices[i];
                     val+=values[i];
                   }
            A.pb( mp(val,cs) );
       }


       for(int mask=0;mask<(1<<(n/2) );mask++ )
       {
               ll cs=0 , val=0;

              for(int i=0;i<n/2;i++)
                  if( mask&(1<<i))
                   {
                     cs+=prices[i+(n/2)];
                     val+=values[i+(n/2)];
                   }
              B.pb( mp(val,cs) );
       }

     sort( A.begin(),A.end());
     sort( B.begin(),B.end());


//     for(int i=0;i<A.sz;i++)
//     {
//            int lo=0,hi=B.sz-1;
//             int id=-1;
//
//             while(lo<=hi)
//             {
//                    int mid=(lo+hi)/2;
//
//                    if( B[mid].X+A[i].X>=(ll)K)
//                    {
//                        id=mid;
//                        hi=mid-1;
//                    }
//                   else
//                   {
//                        lo=mid+1;
//                   }
//             }
//
//          if( id==-1)
//             continue;
//
//          ans=min( ans , A[i].Y+B[id].Y);
//     }

/*Some "BUG" in binary serach */

      ll mini=(1LL<<62),ans=(1LL<<62);
      int bpos=B.sz-1;

      for(int i=0;i<A.sz;i++)
      {
             while( (bpos>=0) && ( B[bpos].X + A[i].X >= (ll)K) )
             {
                 mini=min( mini , B[bpos].Y);
                 bpos--;
             }

             ans=min( ans , A[i].Y + mini);
      }

     if( ans==(1LL<<62) )
         return -1;

     return max(0LL,ans-aval);
}

};


double test0() {
	int t0[] = {2,15};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	vector <int> p1;
	int t2[] = {2,21};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 13;
	CollectingPostmarks * obj = new CollectingPostmarks();
	clock_t start = clock();
	int my_answer = obj->amountOfMoney(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 15;
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
	int t0[] = {9,18,7,6,18};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {4,0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {12,27,10,10,25};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 67;
	CollectingPostmarks * obj = new CollectingPostmarks();
	clock_t start = clock();
	int my_answer = obj->amountOfMoney(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 22;
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
	int t0[] = {14,14,12,6};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {3,2,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {19,23,20,7};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 10;
	CollectingPostmarks * obj = new CollectingPostmarks();
	clock_t start = clock();
	int my_answer = obj->amountOfMoney(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 0;
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
	int t0[] = {43,33,14,31,42,37,17,42,40,20};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {6};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {116,71,38,77,87,106,48,107,91,41};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 811;
	CollectingPostmarks * obj = new CollectingPostmarks();
	clock_t start = clock();
	int my_answer = obj->amountOfMoney(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = -1;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
