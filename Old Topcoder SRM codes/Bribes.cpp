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

int memo[101][1<<17];

class Bribes
{
public:

int infi[101], resi[101];

int calc( int id , int mask )
{
     if( (id >=18) && ( resi[id-8]>0) )
     {
         int left=resi[id-8];

          for(int i=0;i<=16;i++)
             if( mask&(1<<i))
                {
                    left-=( infi[id-i]>>abs(i-8) );
                }

             if( left > 0)
                 return 1000000;
     }
     return  solve( id+1, mask&( (1<<16) -1 ) );
}
int solve( int id , int mask)//going to decide id , with prevous config mask
{
    if(id == 100)
        return 0;

    if( memo[id][mask]!=-1)
         return memo[id][mask];

    int ans=memo[id][mask]=1000000;

    ans=min( ans ,  calc(id,mask<<1) );//dont bribe id th

    if( infi[id] > 0)
    ans=min( ans ,  calc(   id, (mask<<1)+1     )   +1 );//Bribe this

    return memo[id][mask]=ans;
}


int minBribes(vector <int> in, vector <int> rs)
{
    int n=sz(in);

     fill( infi,0);
     fill(resi,0);
     fill(memo,-1);

    for(int i=0;i<n;i++)
    {
        infi[i+20]=in[i];
        resi[i+20]=rs[i];
    }

    int ans=solve(1,0);

    if( ans == 1000000)
         return -1;

    return ans;

}

};


double test0() {
	int t0[] = { 10, 3, 5, 3, 1 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = { 11, 2, 7, 3, 1 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Bribes * obj = new Bribes();
	clock_t start = clock();
	int my_answer = obj->minBribes(p0, p1);
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
	int t0[] = { 15, 15, 15 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = { 13, 42, 13 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Bribes * obj = new Bribes();
	clock_t start = clock();
	int my_answer = obj->minBribes(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = -1;
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
	int t0[] = { 10, 16, 4, 7, 1, 1, 13 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = { 10, 16, 4, 7, 1, 1, 13 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Bribes * obj = new Bribes();
	clock_t start = clock();
	int my_answer = obj->minBribes(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 4;
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
	int t0[] = { 479, 340, 398, 40, 477, 181, 422, 377, 60, 486, 15, 500, 307, 1, 2, 65, 411, 374, 446, 401 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = { 402, 87, 20, 76, 468, 493, 252, 98, 216, 58, 89, 500, 89, 26, 8, 125, 269, 116, 426, 81 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Bribes * obj = new Bribes();
	clock_t start = clock();
	int my_answer = obj->minBribes(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 7;
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
double test4() {
	int t0[] = { 21, 196, 401, 157, 9, 497, 371, 84, 395, 495, 401, 190, 465, 359, 47, 441, 245, 487, 118, 405 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = { 127, 313, 376, 94, 66, 37, 237, 142, 315, 495, 257, 153, 437, 339, 483, 356, 16, 132, 231, 342 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	Bribes * obj = new Bribes();
	clock_t start = clock();
	int my_answer = obj->minBribes(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 8;
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

	time = test4();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
