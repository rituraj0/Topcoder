#include <bits/stdc++.h>
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

const double pi     =   acos(-1.0);
const double eps    =   1e-8;

#define print(a) cout<<(#a)<<" = "<<a<<"\n";
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

#define mod 1234567891

class TheLongPalindrome
{
public:

vector< vector<ll> > munit()
{
   vector< vector<ll> > ret(  27 , vector<ll> (27,0)  ) ;

   for(int i=0;i<27;i++)
     ret[i][i]=1;
//
//      for(int i=0;i<27;i++,cout<<endl)
//     for(int j=0;j<27;j++)
//       cout<<ret[i][j]<<" ";

   return ret;
}

vector< vector<ll> > madd( vector< vector<ll> > a , vector< vector<ll> > b)
{
      vector< vector<ll> > ans=a;

      for(int i=0;i<27;i++)
         for(int j=0;j<27;j++)
          ans[i][j]=(a[i][j]+b[i][j])%mod;

      return ans;
}

vector< vector<ll> > mmul( vector< vector<ll> > a , vector< vector<ll> > b)
{
   vector< vector<ll> > c=a;

     for(int i=0;i<27;i++)
         for(int j=0;j<27;j++)
        {
            ll sm=0;

            for(int k=0;k<27;k++)
            {
                sm=(sm + ( a[i][k]*b[k][j] ) )%mod;
            }

            c[i][j]=sm;
        }

        return c;
}

vector< vector<ll> > mpow( vector< vector<ll> > a, ll k)
{
     if( k==0)
         return munit();
     else if( k%2==0)
     {
         return mpow( mmul(a,a) , k/2 );
     }
     else
         return mmul( a, mpow(a,k-1) );
}

vector< vector<ll> > mpsum( vector< vector<ll> > a, ll k)
{
    if(k==0)
    {
        vector< vector<ll> >ans(27, vector<ll>(27,0) );
        return ans;
    }
   else if( k%2==0)
   {
       return mmul( mpsum(a,k/2) , madd( munit() , mpow(a,k/2) ) );
   }
   else
   {
       return madd( munit() , mmul( mpsum(a,k-1) ,a ));
   }
}

int count(int n, int k)
{
    vector< vector<ll> >m( 27 , vector<ll>(27,0) );
    for(int i=1;i<27;i++)
    {
        m[i][i]=i;
        m[i][i-1]=(27-i);
    }

    ll h1=(n+1)/2+1;
    ll h2=(n/2)+1;

    vector< vector<ll> > mres=madd( mpsum(m,h1) ,mpsum(m,h2));
    ll ans=0;

    for(int i=1;i<=k;i++)
    {
        ans=(ans+mres[i][0])%mod;
    }

   return ans;
}

};


double test0() {
	int p0 = 1;
	int p1 = 1;
	TheLongPalindrome * obj = new TheLongPalindrome();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 26;
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
	int p0 = 2;
	int p1 = 10;
	TheLongPalindrome * obj = new TheLongPalindrome();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 52;
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
	int p0 = 3;
	int p1 = 2;
	TheLongPalindrome * obj = new TheLongPalindrome();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 728;
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
	int p0 = 44;
	int p1 = 7;
	TheLongPalindrome * obj = new TheLongPalindrome();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 240249781;
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
