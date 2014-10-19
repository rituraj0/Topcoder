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

class HanoiGoodAndBad
{
public:

int curr[25];
ll pow2[25],pow3[25];

void solveDave( int n , int s , int t , int aux  , ll cont)
{
    if( n==0 )
    {
        return;
    }

    if( cont <= pow2[n-1]-1 )
    {
        curr[n]=s;
        solveDave(n-1, s, aux, t, cont);
    }
    else
    {
        //After pow2[n-1] moves , n is at t and rest (n-1) is at aux
        curr[n] = t;
        solveDave(n-1, aux, t, s, cont-pow2[n-1] );
    }
}

ll solveA( int n , int s, int t , int aux)
{
    if(n==0)
         return 0;

    if( curr[n] == s )
         return solveA( n-1, s, t, aux);

    if( curr[n] == aux)// n-1 ko target pe , and nTh ko aux pe kar dia pow3[n-1] me
         return solveA( n-1, t, s, aux) + pow3[n-1];

    if( curr[n] == t)// n-1 ko medila pe rakha(pow3[n-1]) and , n th ko t pe le gaya , n-1 ko wapas s pe pow3[n-1])
          return solveA(n-1, s , t ,  aux) + pow3[n-1]*2LL;

         // return 0;
}

int moves(int N, int Dave)
{
     for(int i=0;i<25;i++)
     {
         if(i==0)
         {
             pow2[i]=pow3[i]=1;
         }
         else
         {
             pow2[i]=pow2[i-1]*2LL;
             pow3[i]=pow3[i-1]*3LL;
         }
     }

     solveDave(N,0,2,1,(ll)Dave);

     return solveA(N,0,2,1);



}

};


double test0() {
	int p0 = 3;
	int p1 = 1;
	HanoiGoodAndBad * obj = new HanoiGoodAndBad();
	clock_t start = clock();
	int my_answer = obj->moves(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
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
	int p1 = 15;
	HanoiGoodAndBad * obj = new HanoiGoodAndBad();
	clock_t start = clock();
	int my_answer = obj->moves(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 80;
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
	int p0 = 9;
	int p1 = 265;
	HanoiGoodAndBad * obj = new HanoiGoodAndBad();
	clock_t start = clock();
	int my_answer = obj->moves(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 16418;
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
