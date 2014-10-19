#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()
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

#define mod 2000000011
int dx[]={1,0,1};
int dy[]={1,1,0};

ll memo[18][18][1<<18];

bool done[20][20];

class HexagonalBattlefield
{
public:

int n;

ll  solve( int row, int col, int mask)
{
    ll ans=0;

    if( memo[row][col][mask]!=-1) return memo[row][col][mask];

    if( col >=n) return solve(row+1,0,mask);

    if( row >=n)  return 1;

    if(done[row][col] ||(mask&1) )
    {
        ans=solve(row,col+1 ,mask>>1);
        ans=ans%mod;
    }
    else
    {
        int newmask=0;
        //Nect cell
        if( (col < n-1) && (done[row][col+1]==0) && ((mask&2)==0) )
        {
            newmask=(mask>>1); newmask|=1;
            ans+=solve( row,col+1,newmask); ans=ans%mod;
        }

        if( row < n-1)
        {
            //next row , upper cell

            if( (col > 0)&& (done[row+1][col-1]==0)&& (mask&(1<<(n-1)))==0 )
               {
                   newmask=(mask>>1) ; newmask|=(1<<(n-2));//a current row,col k lia kar rahe hai
                   ans+=solve(row,col+1,newmask); ans=ans%mod;
               }

            //Next row, next col

                if( (done[row+1][col]==0) && ( (mask&(1<<n))==0) )
                {
                    newmask=(mask>>1); newmask|=(1<<(n-1));
                    ans+=solve(row,col+1,newmask); ans=ans%mod;
                }
          }
    }//end else

     return memo[row][col][mask]=ans;
}

int countArrangements(vector <int> X, vector <int> Y, int N)
{
     n=N;

    for(int i=0;i<sz(X);i++)
    {
        X[i]+=N-1;
        Y[i]*=-1; Y[i]+=N-1;
    }

    fill(done,0);

    for(int i=0;i<sz(X);i++)
        done[ Y[i] ][ X[i] ]=1;

    for(int i=0;i<n-1;i++)
        for(int c=0;c<(n-i-1);c++)
           done[i][c]=1;

    for(int i=n;i<n*2-1;i++)
        for(int c=0;c<=i-n;c++)
          done[i][2*n-2-c]=1;

      n=n*2-1;

      fill(memo,-1);

      cout<<memo[0][0][0]<<endl;
      int ans=solve(0,0,0);
      return ans;
}

};


double test0() {
	int t0[] = {-2,0,1,1,0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {-2,0,1,0,2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 3;
	HexagonalBattlefield * obj = new HexagonalBattlefield();
	clock_t start = clock();
	int my_answer = obj->countArrangements(p0, p1, p2);
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
	int t0[] = {0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 2;
	HexagonalBattlefield * obj = new HexagonalBattlefield();
	clock_t start = clock();
	int my_answer = obj->countArrangements(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 2;
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
	int t0[] = {0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 3;
	HexagonalBattlefield * obj = new HexagonalBattlefield();
	clock_t start = clock();
	int my_answer = obj->countArrangements(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 104;
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
	int t0[] = {-1,0,0,1,2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,0,1,0,0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 3;
	HexagonalBattlefield * obj = new HexagonalBattlefield();
	clock_t start = clock();
	int my_answer = obj->countArrangements(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 6;
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
	int t0[] = {0,1,0,0,1,-1,-1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,0,-1,1,1,0,-1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 2;
	HexagonalBattlefield * obj = new HexagonalBattlefield();
	clock_t start = clock();
	int my_answer = obj->countArrangements(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1;
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
