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

#define mod 1000000007

class SumOfPowers
{
public:

ll dp[55][55];

int K;

ll all[55][55],rm[55][55],C[55][55];

void multiply( ll c[55][55] , ll a[55][55] , ll b[55][55])
    {
        fill(rm,0);

        for(int i=0;i<K;i++)
             for(int j=0;j<K;j++)
             {
               ll tp=0;

                for(int k=0;k<K;k++)
                     tp=(tp+a[i][k]*b[k][j])%mod;

                rm[i][j]=tp;
             }

             memcpy(c,rm,sizeof(rm));
    }




  void power(int ex)
    {
         if(ex==0)
         {
            fill(C,0);
            for(int i=0;i<K;i++)
                 C[i][i]=1;
            return;
         }

         if( ex&1)
         {
            power(ex-1);
            multiply(C,C,all);
         }
         else
         {
             power(ex/2);
             multiply(C,C,C);
         }
    }



int value(int n, int k)
{
//     if(n==1)
//         return 1;

     fill(dp,0);

    dp[0][0]=1;

    for(int i=1;i<55;i++)
         for( int j=0;j<55;j++)
    {
            if(j==0)
                 dp[i][j]=1;
            else
                 dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
    }

    K=k+2;

    fill(all,0);

    all[0][0]=1;

    for(int i=0;i<2;i++)
    {
         int cn=0;

         for(int j=1;j<K;j++)
             all[i][j]=dp[k][cn++];
    }

    for(int i=2;i<K;i++)
    {
         int up=k-i+1;
         int down=0;

        for(int j=i;j<K;j++)
              all[i][j]=dp[up][down++];
    }


  cout<<k<<"\n\n";

    for(int i=0;i<K;i++,cout<<endl)
         for(int j=0;j<K;j++)
          cout<<all[i][j]<<"  ";

    cout<<"\n\n\n\n";

    power(n-1);

    ll ans=0;

    for(int i=0;i<K;i++)
         ans=(ans+C[0][i])%mod;

    return ans;



}

};


double test0() {
	int p0 = 5;
	int p1 = 1;
	SumOfPowers * obj = new SumOfPowers();
	clock_t start = clock();
	int my_answer = obj->value(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 15;
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
	int p0 = 4;
	int p1 = 2;
	SumOfPowers * obj = new SumOfPowers();
	clock_t start = clock();
	int my_answer = obj->value(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 30;
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
	int p0 = 13;
	int p1 = 5;
	SumOfPowers * obj = new SumOfPowers();
	clock_t start = clock();
	int my_answer = obj->value(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 1002001;
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
	int p0 = 123456789;
	int p1 = 1;
	SumOfPowers * obj = new SumOfPowers();
	clock_t start = clock();
	int my_answer = obj->value(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 383478132;
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
