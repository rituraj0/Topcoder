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

const double pi     =   3.14159265358979323846;
const double eps    =   1e-11;

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

class ParticleCollision
{
public:

    vector<double> ans;

    ll vx,vy,vz,x0,y0,z0;


void solve( double t2)
{
    double t1=vz*t2+z0;

    if( fabs(vx*t2+x0-cos(pi*t1) )<=eps && fabs(vy*t2+y0-sin(pi*t1))<=eps )
    {
         if( ans.size() ==0)
         {
            ans.pb( cos(pi*t1) );
            ans.pb( sin(pi*t1) );
            ans.pb(t1);
         }
        else
        {
             ans.clear();
             ans.pb(0);  ans.pb(0) ; ans.pb(0);
        }

    }

}


vector <double> collision(int _vx, int _vy, int _vz, int _x0, int _y0, int _z0)
{
     vx=_vx; vy=_vy; vz=_vz;
     x0=_x0; y0=_y0; z0=_z0;

     ll a=vx*vx+vy*vy;
     ll b=2*(x0*vx+y0*vy);
     ll c=x0*x0+y0*y0-1;

     if(a==0)
     {
          if(b!=0)
          {
              solve( -(double)c/b );
          }
         else if( c==0)
         {
               if(vz!=0)
               {
                   ans.pb(0); ans.pb(0) ; ans.pb(0);
               }
               else
               {
                   solve(0);
               }
         }
     }
     else
     {
         ll d=b*b-4*a*c;

         if(d==0)
         {
              solve( -(double)b/(2.0*a) );
         }
         else
         {
              double r= ( (double)( -b -sqrt( (double)d) ) )/(2.0*a);

              solve(r);

               r= ( (double)( -b +sqrt( (double)d) ) )/(2.0*a);

               solve(r);
         }
     }

     return ans;

}

};


double test0() {
	int p0 = 0;
	int p1 = 0;
	int p2 = 0;
	int p3 = 0;
	int p4 = 0;
	int p5 = 0;
	ParticleCollision * obj = new ParticleCollision();
	clock_t start = clock();
	vector <double> my_answer = obj->collision(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	vector <double> p6;
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p6.size() > 0) {
		cout <<p6[0];
		for (int i=1; i<p6.size(); i++)
			cout <<", " <<p6[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p6) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 2;
	int p1 = 4;
	int p2 = 1;
	int p3 = -1;
	int p4 = -1;
	int p5 = 0;
	ParticleCollision * obj = new ParticleCollision();
	clock_t start = clock();
	vector <double> my_answer = obj->collision(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double t6[] = {0.0, 1.0, 0.5 };
	vector <double> p6(t6, t6+sizeof(t6)/sizeof(double));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p6.size() > 0) {
		cout <<p6[0];
		for (int i=1; i<p6.size(); i++)
			cout <<", " <<p6[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p6) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 4;
	int p1 = 4;
	int p2 = 2;
	int p3 = 5;
	int p4 = 4;
	int p5 = 0;
	ParticleCollision * obj = new ParticleCollision();
	clock_t start = clock();
	vector <double> my_answer = obj->collision(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double t6[] = {0.0, 0.0, 0.0 };
	vector <double> p6(t6, t6+sizeof(t6)/sizeof(double));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p6.size() > 0) {
		cout <<p6[0];
		for (int i=1; i<p6.size(); i++)
			cout <<", " <<p6[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p6) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 0;
	int p1 = 0;
	int p2 = 1;
	int p3 = 1;
	int p4 = 0;
	int p5 = 0;
	ParticleCollision * obj = new ParticleCollision();
	clock_t start = clock();
	vector <double> my_answer = obj->collision(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double t6[] = {0.0, 0.0, 0.0 };
	vector <double> p6(t6, t6+sizeof(t6)/sizeof(double));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p6.size() > 0) {
		cout <<p6[0];
		for (int i=1; i<p6.size(); i++)
			cout <<", " <<p6[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p6) {
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
