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

class RightTriangle
{
public:

int cont[1<<20];

long long triangleCount(int places, int points, int a, int b, int c)
{
      fill(cont,0);

      ll A=a,B=b,C=c;
      ll pl=places;

      for(ll n=0;n<points;n++)
      {
          ll curr=(A*n*n+B*n+C)%pl;

          cont[curr]++;
      }

      int rem=0;

      for(int i=0;i<(1<<22); i++ )
      {
         // cout<<i<<"  "<<rem<<"   "<<cont[i]<<endl;
          if( cont[i%places]==0)
          {
              if(rem>0)
              {
                  rem--;
                  cont[i%places]=1;
              }
          }
          else
          {
                 rem+=cont[i%places]-1;
                 cont[i%places]=1;
          }
      }


      if(places&1)//it is not possible that any line would be aame samne
        return 0;

      int diff=(places-2)/2;

      ll ans=0;

      for(int i=0;i<places;i++)
          if( cont[i] && cont[ (i+diff+1)%places])
             {
                 ans+=(ll)(points-2);
             }

       return (ans/2LL);





}

};


double test0() {
	int p0 = 9;
	int p1 = 3;
	int p2 = 0;
	int p3 = 3;
	int p4 = 0;
	RightTriangle * obj = new RightTriangle();
	clock_t start = clock();
	long long my_answer = obj->triangleCount(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p5 = 0LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 40;
	int p1 = 3;
	int p2 = 5;
	int p3 = 0;
	int p4 = 0;
	RightTriangle * obj = new RightTriangle();
	clock_t start = clock();
	long long my_answer = obj->triangleCount(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p5 = 1LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
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
	int p2 = 16;
	int p3 = 24;
	int p4 = 17;
	RightTriangle * obj = new RightTriangle();
	clock_t start = clock();
	long long my_answer = obj->triangleCount(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p5 = 4LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 1000000;
	int p1 = 47000;
	int p2 = 0;
	int p3 = 2;
	int p4 = 5;
	RightTriangle * obj = new RightTriangle();
	clock_t start = clock();
	long long my_answer = obj->triangleCount(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p5 = 0LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 200000;
	int p1 = 700;
	int p2 = 123456;
	int p3 = 789012;
	int p4 = 345678;
	RightTriangle * obj = new RightTriangle();
	clock_t start = clock();
	long long my_answer = obj->triangleCount(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p5 = 6980LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
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

//Powered by [KawigiEdit] 2.0!
