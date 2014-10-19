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

#define two(x) (1<<(x))
#define contain(s,x) (((s)&two(x))!=0)

class RectangleAvoidingColoring
{
public:

int n,m;
int a[55][55];
bool g[55][16],h[16][16];
ll memo[55][two(16)];

ll solve( int d, int ps)
{
    if(d==n) return 1;

    if( memo[d][ps]!=-1)
         return memo[d][ps];

    ll ans=0;
    memo[d][ps]=ans;

    for(int st=0;st<two(m);st++)
        if( g[d][st])
        {
            bool cool=true;

            for(int i=0;i<two(m);i++)
                 if( contain(ps,i) && !h[st][i])
                    {
                      cool=false;
                      break;
                    }

               if( cool)
                 ans+=solve(d+1, ps | two(st) );//kya encoding hai , set me set
        }

    return memo[d][ps]=ans;
}
long long count(vector <string> in)
{
    n=sz(in);
    m=sz(in[0]);

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
          if( in[i][j]=='W')
             a[i][j]=0;
        else if( in[i][j]=='B')
             a[i][j]=1;
        else
              a[i][j]=-1;

   if( n < m )
   {
       int t[55][55];
       memcpy(t,a,sizeof(t));
       swap(n,m);

       for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
           a[i][j]=t[j][i];
   }

   if( m > 4)
     return 0;

   for(int i=0;i<n;i++)
     for(int st=0;st<two(m);st++)
      {
       g[i][st]=true;

       for(int k=0;k<m;k++)
         if( ( contain(st,k) && a[i][k]==1) || (!contain(st,k) && a[i][k]==0) )
          g[i][st]=false;
      }


   for(int s1=0;s1<two(m);s1++)
     for(int s2=0;s2<two(m);s2++)
        {
            h[s1][s2]=true;

             for(int x=0;x<m;x++)
                 for(int y=x+1;y<m;y++)
             {
                 int c=0;
                 c+=contain(s1,x);
                 c+=contain(s1,y);
                 c+=contain(s2,x);
                 c+=contain(s2,y);

                 if( c==0 || c==4 )
                     h[s1][s2]=false;
             }
        }

        fill( memo , -1 );

        return solve(0,0);

}

};


double test0() {
	string t0[] = {"??",
 "??"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	RectangleAvoidingColoring * obj = new RectangleAvoidingColoring();
	clock_t start = clock();
	long long my_answer = obj->count(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 14LL;
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
	string t0[] = {"B?",
 "?B"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	RectangleAvoidingColoring * obj = new RectangleAvoidingColoring();
	clock_t start = clock();
	long long my_answer = obj->count(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 3LL;
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
	string t0[] = {"WW",
 "WW"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	RectangleAvoidingColoring * obj = new RectangleAvoidingColoring();
	clock_t start = clock();
	long long my_answer = obj->count(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 0LL;
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
	string t0[] = {"??B??",
 "W???W",
 "??B??"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	RectangleAvoidingColoring * obj = new RectangleAvoidingColoring();
	clock_t start = clock();
	long long my_answer = obj->count(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 12LL;
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
	string t0[] = {"??",
 "W?",
 "W?",
 "?W",
 "W?"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	RectangleAvoidingColoring * obj = new RectangleAvoidingColoring();
	clock_t start = clock();
	long long my_answer = obj->count(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 16LL;
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
