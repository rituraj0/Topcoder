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

class KiwiJuice
{
public:

int dp[1<<16];
int sum[1<<16];


int theProfit(int C, vector <int> bt, vector <int> pr)
{
    int n=sz(bt);

    fill(dp,0); fill(sum,0);

    for(int mask=0;mask<(1<<n);mask++)
    {
        int sm=0;
        int cont=0;

          for(int i=0;i<n;i++)
             if( mask&(1<<i))
              {
               sm+=bt[i];
               cont++;
             }

         for(int i=0;i<cont;i++)
            if( sm>=C )
              { sum[mask]+=pr[C];
                 sm-=C;
              }
           else
           {
               sum[mask]+=pr[sm];
               sm=0;
           }
    }

    for(int mask=0;mask<(1<<n);mask++)
         for(int sub=mask;sub>0;sub=(sub-1)&mask)
          {
            dp[mask]=max( dp[mask] , dp[mask-sub] + sum[sub] );
          }

        return dp[(1<<n)-1];

}

};


double test0() {
	int p0 = 10;
	int t1[] = {5, 8};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	KiwiJuice * obj = new KiwiJuice();
	clock_t start = clock();
	int my_answer = obj->theProfit(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 10;
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
	int p0 = 10;
	int t1[] = {5, 8};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {0, 0, 0, 0, 0, 10, 10, 10, 10, 10, 10};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	KiwiJuice * obj = new KiwiJuice();
	clock_t start = clock();
	int my_answer = obj->theProfit(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 20;
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
	int t1[] = {4, 5, 3, 7};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {14, 76, 12, 35, 6, 94, 26, 3, 93, 90, 420};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	KiwiJuice * obj = new KiwiJuice();
	clock_t start = clock();
	int my_answer = obj->theProfit(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 625;
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
	int p0 = 1;
	int t1[] = {0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1000000, 1000000};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	KiwiJuice * obj = new KiwiJuice();
	clock_t start = clock();
	int my_answer = obj->theProfit(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1000000;
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
	int p0 = 49;
	int t1[] = {2, 47, 24, 14, 0, 32, 9, 12, 31, 46, 39, 12, 16, 22, 29};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {428668, 995687, 128567, 37241, 496916, 238624, 304781, 997819, 85856, 417008,
398570, 951499, 750349, 333625, 927594, 188616, 942498, 259414, 654344, 354809,
25303, 226854, 98578, 207140, 305527, 358343, 393213, 256248, 282644, 103327,
667191, 103402, 609183, 619323, 189127, 518006, 778846, 400460, 128334, 795097,
605203, 669142, 121825, 934404, 837430, 554265, 610818, 546228, 80784, 949440};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	KiwiJuice * obj = new KiwiJuice();
	clock_t start = clock();
	int my_answer = obj->theProfit(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 12873962;
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

//Powered by [KawigiEdit] 2.0!
