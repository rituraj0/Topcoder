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
#define Y second
#define X first

#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)

const double pi     =   acos(-1.0);
const double eps    =   1e-8;

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

typedef long long ll;

#define maxi 3190000

bool done[maxi];
int nexte[maxi];
int power[11];

int memo[maxi];


class ExtendedHappyNumbers
{
public:

 void init()
 {
      for(int i=1;i<maxi;i++)
      {
            int curr=i;
            int ans=0;

            while(curr>0)
            {
                ans+=power[ curr%10];
                curr=curr/10;
            }

            nexte[i]=ans;
      }
 }


long long  calcTheSum(int A, int B, int K)
{

   for(int i=0;i<=9;i++)
    {
       power[i]=1;
       for(int j=1;j<=K;j++)
         power[i]*=i;
    }



    init();

    cout<<"init done"<<endl;


    long long ans=0;

    memset( done , 0, sizeof(done));
    memset(memo,-1,sizeof(memo) );

    int  used[200];
    int uc=0;

    for(int i=A;i<=B;i++)
        {
               int agla=i;
               uc=0;
               ll add=i;

               while(1)
               {
                   add=min( add , (ll)agla);

                   if( !done[agla])
                   {
                       done[agla]=true;
                       used[uc++]=agla;


                           if(memo[agla]!=-1)
                           {
                               add=min( add , (ll)memo[agla] );
                               break;
                           }

                       agla=nexte[agla];
                   }
                   else
                   {
                       break;
                   }
               }

               ans+=add;
               memo[i]=add;

               for(int j=0;j<uc;j++)
                 {done[ used[j] ]=false;
                 }
        }


    return ans;
}

};


double test0() {
	int p0 = 13;
	int p1 = 13;
	int p2 = 2;
	ExtendedHappyNumbers * obj = new ExtendedHappyNumbers();
	clock_t start = clock();
	long long my_answer = obj->calcTheSum(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 1LL;
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
	int p0 = 1;
	int p1 = 5;
	int p2 = 2;
	ExtendedHappyNumbers * obj = new ExtendedHappyNumbers();
	clock_t start = clock();
	long long my_answer = obj->calcTheSum(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 14LL;
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
	int p0 = 10;
	int p1 = 99;
	int p2 = 1;
	ExtendedHappyNumbers * obj = new ExtendedHappyNumbers();
	clock_t start = clock();
	long long my_answer = obj->calcTheSum(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 450LL;
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
	int p0 = 535;
	int p1 = 538;
	int p2 = 3;
	ExtendedHappyNumbers * obj = new ExtendedHappyNumbers();
	clock_t start = clock();
	long long my_answer = obj->calcTheSum(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 820LL;
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
	int p0 = 100000;
	int p1 = 400000;
	int p2 = 6;
	ExtendedHappyNumbers * obj = new ExtendedHappyNumbers();
	clock_t start = clock();
	long long my_answer = obj->calcTheSum(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 5169721292LL;
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
