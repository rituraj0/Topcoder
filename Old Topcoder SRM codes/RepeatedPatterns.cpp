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

class RepeatedPatterns
{
public:

     int p1head,p2head,p1tail,p2tail;

    int check(  string hey , ll zero )
    {
        if( zero > hey.size())
             return -1;

        string need(zero,'0');

        return hey.find(need);
    }

    bool startWith( string in , string b)
    {
        if( b.size() > in.size())
             return false;

        string temp=in.substr( 0 , b.size());

        return (temp==b);
    }

    bool endWith( string in  , string b)
    {
        if( b.size() > in.size())
             return false;

        string temp=in.substr( in.size() -b.size() );

        return (temp==b);
    }

    long long getLength( ll a, ll b, ll c)
    {
         ll ans=(1000000LL)*a*c +(c*(c-1)*b )/2LL;

//         cout<<a<<" "<<b<<"  "<<c<<"  "<<ans<<endl;
          return ans;

    }

long long  findZeroSegment(string p1, string p2, string in)
{
   bool p1all=(p1.find("1")==-1);
   bool p2all=(p2.find("1")==-1);

   ll zeroCount=atoll(in.c_str() );

   cout<<zeroCount<<endl;

   if( p1all && p2all )
   {
       return 0;
   }


   if( (!p1all) &&(!p2all) )
   {
        ll x=check(p1+p1,zeroCount);
                if(x >=0)
                     return x;

        x=check( p1+p2 , zeroCount) ;
                if( x >=0)
                      return x+(ll)999999*(ll)p1.size();

        x=check( p2+p1 , zeroCount) ;
                   if( x>=0)
                      return x+(ll)1000000*(ll)p1.size();

         x=check(p2+p2 , zeroCount);
                    if( x>=0)
                        return x+(ll)2000000*(ll)p1.size()+(ll)p2.size();

        return -1;

   }

   string zs="";

    p1head=0,p2head=0,p1tail=0,p2tail=0;

   for(int i=1;i<=55;i++)
   {
       zs+="0";

       if( startWith(p1,zs))
          p1head=i;

       if( startWith(p2,zs))
            p2head=i;

       if( endWith(p1,zs) )
            p1tail=i;

       if( endWith(p2,zs) )
           p2tail=i;
   }


   if( p1all && (!p2all) )
   {
        ll beg=(1000000LL)*p1.size() + p2head;
        ll mid=p2tail+(1000000LL)*p1.size()+p2head;

        if( beg >=zeroCount)
             return 0;

        if( mid >=zeroCount)
              return (1000000LL)*p1.size()+p2.size()-p2tail;

        return -1;
   }

   ll p16=1;
    for(int i=0;i<16;i++)
         p16*=10LL;

    int x=check(p1+p1,zeroCount);
      if( x>=0)
         return x;

      zeroCount-=p1tail;
      zeroCount-=p1head;

      ll lo=0,hi=1;

     while( getLength( p1.size() , p2.size() , hi ) < p16)
         hi*=2LL;

         cout<<"hi is"<<hi<<endl;

     while( hi-lo > 1)
     {
        ll  mid=(lo+hi)/2;

        if( getLength( p1.size() , p2.size() , mid) < p16 )
        {
            lo=mid;
        }
        else
        {
            hi=mid;
        }
     }

     ll aval=hi;
     ll req=( (ll)zeroCount+(ll)p2.size()-1LL)/(ll)p2.size();

     if( req > aval )
        return -1;

     ll id=getLength(p1.size() , p2.size() , (ll)req) -p1tail;

     if( id+zeroCount > p16)
       return -1;

     return id;


}

};


double test0() {
	string p0 = "111010100001010";
	string p1 = "010000001000";
	string p2 = "3";
	RepeatedPatterns * obj = new RepeatedPatterns();
	clock_t start = clock();
	long long my_answer = obj->findZeroSegment(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 7LL;
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
	string p0 = "1101010010";
	string p1 = "0001000";
	string p2 = "3";
	RepeatedPatterns * obj = new RepeatedPatterns();
	clock_t start = clock();
	long long my_answer = obj->findZeroSegment(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 9999999LL;
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
	string p0 = "1101010010";
	string p1 = "0001000";
	string p2 = "5";
	RepeatedPatterns * obj = new RepeatedPatterns();
	clock_t start = clock();
	long long my_answer = obj->findZeroSegment(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 20000011LL;
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
	string p0 = "10101010";
	string p1 = "101010101010";
	string p2 = "9876543219876";
	RepeatedPatterns * obj = new RepeatedPatterns();
	clock_t start = clock();
	long long my_answer = obj->findZeroSegment(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = -1LL;
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
	string p0 = "11111111111111111111111111";
	string p1 = "0";
	string p2 = "9876543219876";
	RepeatedPatterns * obj = new RepeatedPatterns();
	clock_t start = clock();
	long long my_answer = obj->findZeroSegment(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = -1LL;
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
