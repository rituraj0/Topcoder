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


class AllCycleLength
{
public:

string findAll(vector <string> arcs)
{
     int n, from[55] , a[55] , b[55];
     char temp[10000];

      n=arcs.sz;

     fill(from,0);

     for(int i=0;i<n;i++)
         for(int j=0;j<n;j++)
            if( arcs[i][j]=='Y')
                 from[i]|=(1<<j);

      for(int i=0;i<n;i++)
          a[i]=(1<<i);


      for(int l=1;l<5000;l++)
      {
            for(int i=0;i<n;i++)
                 b[i]=a[i];
            fill(a,0);

            for(int i=0;i<n;i++)
                 for(int j=0;j<n;j++)
                    if( b[i]&(1<<j) )
                      a[i]|=from[j];

            temp[l]='0';

            for(int i=0;i<n;i++)
                 if( a[i]&(1<<i) )
                   temp[l]='1';
      }

      int len=4999,cut=-1;

      for(int d=1;d<5000;d++)
      {
           int k=4999-d;

           for(;k>0 && temp[k]==temp[k+d];k--) ;

           if( k+d < len)
           {
               len=k+d;
               cut=k;
           }
      }

      string ans="";

      for(int i=1;i<=len;i++)
      {
           if(i==cut+1)
             ans+="(";

           ans+=temp[i];
      }

      ans+=")";

      return ans;

}

};



double test0() {
	string t0[] = {"NYNN", "NNYY", "NNNY", "YNNN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	class AllCycleLength * obj = new class AllCycleLength();
	clock_t start = clock();
	string my_answer = obj->findAll(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "00110(1)";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"NY", "YN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	class AllCycleLength * obj = new class AllCycleLength();
	clock_t start = clock();
	string my_answer = obj->findAll(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "(01)";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"NYYYY", "NNYYY", "NNNYY", "NNNNY", "YNNNN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	class AllCycleLength * obj = new class AllCycleLength();
	clock_t start = clock();
	string my_answer = obj->findAll(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "0(1)";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"NYNNN", "NNYNN", "NNNYN", "NNNNY", "YNNYN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	class AllCycleLength * obj = new class AllCycleLength();
	clock_t start = clock();
	string my_answer = obj->findAll(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "010(1)";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

class AllCycleLengths
{
public:

string findAll(vector <string> arcs)
{
     int n, from[55] , a[55] , b[55];
     char temp[10000];

      n=arcs.sz;

     fill(from,0);

     for(int i=0;i<n;i++)
         for(int j=0;j<n;j++)
            if( arcs[i][j]=='Y')
                 from[i]|=(1<<j);

      for(int i=0;i<n;i++)
          a[i]=(1<<i);


      for(int l=1;l<5000;l++)
      {
            for(int i=0;i<n;i++)
                 b[i]=a[i];
            fill(a,0);

            for(int i=0;i<n;i++)
                 for(int j=0;j<n;j++)
                    if( b[i]&(1<<j) )
                      a[i]|=from[j];

            temp[l]='0';

            for(int i=0;i<n;i++)
                 if( a[i]&(1<<i) )
                   temp[l]='1';
      }

      int len=4999,cut=-1;

      for(int d=1;d<5000;d++)
      {
           int k=4999-d;

           for(;k>0 && temp[k]==temp[k+d];k--) ;

           if( k+d < len)
           {
               len=k+d;
               cut=k;
           }
      }

      string ans="";

      for(int i=1;i<=len;i++)
      {
           if(i==cut+1)
             ans+="(";

           ans+=temp[i];
      }

      ans+=")";

      return ans;

}

};




double test0() {
	string t0[] = {"NYNN", "NNYY", "NNNY", "YNNN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	AllCycleLengths * obj = new AllCycleLengths();
	clock_t start = clock();
	string my_answer = obj->findAll(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "00110(1)";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"NY", "YN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	AllCycleLengths * obj = new AllCycleLengths();
	clock_t start = clock();
	string my_answer = obj->findAll(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "(01)";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"NYYYY", "NNYYY", "NNNYY", "NNNNY", "YNNNN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	AllCycleLengths * obj = new AllCycleLengths();
	clock_t start = clock();
	string my_answer = obj->findAll(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "0(1)";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"NYNNN", "NNYNN", "NNNYN", "NNNNY", "YNNYN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	AllCycleLengths * obj = new AllCycleLengths();
	clock_t start = clock();
	string my_answer = obj->findAll(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "010(1)";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
