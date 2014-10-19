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

class NewCoins
{
public:

    vector<int> in;
    int n;

   int memo[100005];

   int solve( int a)
   {
       if(a==1) return 0;

       if( memo[a]!=-1) return memo[a];

      int ans=memo[a]=100000;

       //cout<<a<<"  "<<memo[a]<<endl;

       for(int c=1;c*c<=a;c++)
         if(a%c==0)
            {
                for(int j=0;j<2;j++)
                {
                    int b=1;

                    if(j&1)
                        b=c;
                    else
                        b=a/c;

                    int tp=0;

                      for(int i=0;i<n;i++)
                        tp+=(in[i]%a)/b;

                      tp+=solve(b);

                      ans=min(ans,tp);
                }
            }

       return memo[a]=ans;
   }

int minCoins(vector <int> price)
{
    in=price;
    n=sz(in);
    fill(memo,-1);

    int ans=(100000);

    for(int mx=1;mx<=100000;mx++)
    {
        int tp=solve(mx);

        for(int i=0;i<n;i++)
            tp+=(in[i]/mx);

        ans=min(ans,tp);
    }

    return ans;

}

};


double test0() {
	int t0[] = {25, 102};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	NewCoins * obj = new NewCoins();
	clock_t start = clock();
	int my_answer = obj->minCoins(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 4;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int t0[] = {58};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	NewCoins * obj = new NewCoins();
	clock_t start = clock();
	int my_answer = obj->minCoins(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int t0[] = {1, 4, 5, 9, 16};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	NewCoins * obj = new NewCoins();
	clock_t start = clock();
	int my_answer = obj->minCoins(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 7;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int t0[] = {1, 1, 1, 1, 1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	NewCoins * obj = new NewCoins();
	clock_t start = clock();
	int my_answer = obj->minCoins(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 5;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int t0[] = {28, 569, 587, 256, 15, 87, 927, 4, 589, 73, 98, 87, 597, 163, 6, 498};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	NewCoins * obj = new NewCoins();
	clock_t start = clock();
	int my_answer = obj->minCoins(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 62;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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

	time = test4();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
