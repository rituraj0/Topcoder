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

const ll mod=1000000007LL;

class TwoSidedCards
{
public:

ll power( ll a , ll up , ll mod)
{
    ll ans=1;

    while(up>0)
    {
        if(up&1)
        {
            ans=(ans*a)%mod;
        }

        a=(a*a)%mod;
        up=up/2;
    }

    return ans;
}

int theCount(vector <int> A, vector <int> B)
{
    int edge[55]; bool done[55];
    fill(edge,0); fill(done,0);

   //calculating all cycle length
    int n=sz(A);

    for(int i=0;i<n;i++)
        edge[ A[i] - 1 ]=B[i]-1;

    vector<int> all_cycle;

    for(int i=0;i<n;i++)
         if(!done[i])
            {
                int len=0;

                for(int k=i;!done[k];k=edge[k])
                {
                    len++;
                    done[k]=true;
                }

                all_cycle.pb(len);
            }

     // FActorilal section
     ll fact[1000];
     fact[0]=fact[1]=1;
      for(ll i=2;i<1000;i++)
         fact[i]=(fact[i-1]*i)%mod;

      //ncm clac
      ll dp[100][100]; fill(dp,0);
      dp[0][0]=1;

      for(int i=1;i<100;i++)
      {
          dp[i][0]=1;

            for(int j=1;j<100;j++)
                 dp[i][j]=( dp[i-1][j-1] + dp[i-1][j] )%mod;
      }

    // Now final calulation
     ll ans=1;

     ll rem_pos=n;

     for(int i=0;i<sz(all_cycle);i++)
     {
         int N=all_cycle[i];

            ll tp=0;

               for(int k=0;2*k<=N;k++)
               {
                        ll up=2;

                        if(k==0)
                             up=1;

                        up=(up*fact[N])%mod;
                        up=(up*fact[N])%mod;

                        ll down=1;
                        down=(down*fact[2*k])%mod;
                        down=(down*fact[N-2*k])%mod;
                        down=(down*power(2LL,(ll)k,mod) )%mod;

                        //now inverse of down
                        ll inv=power(down,mod-2,mod);//fermeet theorm

                        ll temp=(up*inv)%mod;

                        tp=(tp+temp)%mod;
               }

               ans=(ans*tp)%mod;
               ans=(ans*dp[rem_pos][N])%mod;

               rem_pos-=N;
     }

     return ans;


}

};


double test0() {
	int t0[] = {1, 2, 3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1, 3, 2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TwoSidedCards * obj = new TwoSidedCards();
	clock_t start = clock();
	int my_answer = obj->theCount(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 12;
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
	int t0[] = {1, 2, 3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1, 2, 3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TwoSidedCards * obj = new TwoSidedCards();
	clock_t start = clock();
	int my_answer = obj->theCount(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 6;
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
	int t0[] = {1, 2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2, 1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TwoSidedCards * obj = new TwoSidedCards();
	clock_t start = clock();
	int my_answer = obj->theCount(p0, p1);
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
	int t0[] = {5, 8, 1, 2, 3, 4, 6, 7};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1, 2, 3, 4, 5, 6, 7, 8};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TwoSidedCards * obj = new TwoSidedCards();
	clock_t start = clock();
	int my_answer = obj->theCount(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2177280;
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
	int t0[] = {41, 22, 17, 36, 26, 15, 10, 23, 33, 48, 49, 9, 34, 6, 21, 2, 46, 16, 25, 3, 24, 13, 40, 37, 35,
50, 44, 42, 31, 12, 29, 7, 43, 18, 30, 19, 45, 32, 39, 14, 8, 27, 1, 5, 38, 11, 4, 20, 47, 28};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {19, 6, 23, 35, 17, 7, 50, 2, 33, 36, 12, 31, 46, 21, 30, 13, 47, 22, 44, 4, 25, 24, 3, 15, 20,
48, 10, 28, 26, 18, 5, 45, 49, 16, 40, 42, 43, 14, 1, 37, 29, 8, 41, 38, 9, 11, 34, 32, 39, 27};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TwoSidedCards * obj = new TwoSidedCards();
	clock_t start = clock();
	int my_answer = obj->theCount(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 529165844;
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
