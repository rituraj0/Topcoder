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

string tost( ll in)
{
    char ans[25];
    sprintf(ans,"%lld",in);
    return ans;
}

class ArithmeticProgressions
{
public:

ll div[55][55][55];
ll in[55];
int n;


vector <string> maxAptitude(vector <string> numbers)
{
     n=numbers.sz;

     for(int i=0;i<n;i++)
          in[i]=atoll(numbers[i].c_str());

     sort(in,in+n);

     for(int i=0;i<n;i++)
         for(int j=i+1;j<n;j++)
           for(int k=j+1;k<n;k++)
              div[i][j][k]=__gcd( in[j]-in[i] , in[k]-in[j] );


      ll ans[2]; ans[0]=0 ; ans[1]=1;

      ll m=in[0] , M=in[n-1];


     for(int i=0;i<n;i++)
         for(int j=i+1;j<n;j++)
           for(int k=j+1;k<n;k++)
            {
               ll g=div[i][j][k];
               ll a1=(in[k]-m)/g;
               ll a2=(M-in[k])/g;
               ll A=1+a1+a2;
               ll v=3;

               if(A%3==0)
               {
                   A=A/3;
                   v=1;
               }

               if( ans[1]*v > ans[0]*A)
               {
                   ans[0]=v;
                   ans[1]=A;
               }

             }



       for(int i=0;i<n;i++)
         for(int j=i+1;j<n;j++)
           for(int k=j+1;k<n;k++)
              for(int r=k+1;r<n;r++)
                {
                    ll g=div[i][j][k];
                       g=__gcd(g,in[r]-in[k]);

                     ll a1=( in[r] - m)   /g;
                     ll a2=( M - in[r])/g;
                     ll A=a1+a2+1;
                     ll v=4;

                     if( A%2==0)
                     {
                         v=v/2;
                         A=A/2;
                     }


                     if( A%2==0)
                     {
                         v=v/2;
                         A=A/2;
                     }

                  if( ans[1]*v > ans[0]*A)
                   {
                       ans[0]=v;
                       ans[1]=A;
                   }
                }



         vector<string> ret(2);

         ret[0]=tost(ans[0]);
         ret[1]=tost(ans[1]);

         return ret;





}

};



double test0() {
	string t0[] = {"1", "3", "5", "8"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ArithmeticProgressions * obj = new ArithmeticProgressions();
	clock_t start = clock();
	vector <string> my_answer = obj->maxAptitude(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t1[] = {"3", "4" };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<"\""<<p1[0]<<"\"";
		for (int i=1; i<p1.size(); i++)
			cout <<", \"" <<p1[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<"\""<<my_answer[0]<<"\"";
		for (int i=1; i<my_answer.size(); i++)
			cout <<", \"" <<my_answer[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"1", "3", "5", "7", "9", "11", "13", "15", "17", "19"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ArithmeticProgressions * obj = new ArithmeticProgressions();
	clock_t start = clock();
	vector <string> my_answer = obj->maxAptitude(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t1[] = {"1", "1" };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<"\""<<p1[0]<<"\"";
		for (int i=1; i<p1.size(); i++)
			cout <<", \"" <<p1[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<"\""<<my_answer[0]<<"\"";
		for (int i=1; i<my_answer.size(); i++)
			cout <<", \"" <<my_answer[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"1", "999999999999999999"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ArithmeticProgressions * obj = new ArithmeticProgressions();
	clock_t start = clock();
	vector <string> my_answer = obj->maxAptitude(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t1[] = {"0", "1" };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<"\""<<p1[0]<<"\"";
		for (int i=1; i<p1.size(); i++)
			cout <<", \"" <<p1[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<"\""<<my_answer[0]<<"\"";
		for (int i=1; i<my_answer.size(); i++)
			cout <<", \"" <<my_answer[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"1", "7", "13", "3511", "1053", "10", "5"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ArithmeticProgressions * obj = new ArithmeticProgressions();
	clock_t start = clock();
	vector <string> my_answer = obj->maxAptitude(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t1[] = {"3", "391" };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<"\""<<p1[0]<<"\"";
		for (int i=1; i<p1.size(); i++)
			cout <<", \"" <<p1[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<"\""<<my_answer[0]<<"\"";
		for (int i=1; i<my_answer.size(); i++)
			cout <<", \"" <<my_answer[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
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
