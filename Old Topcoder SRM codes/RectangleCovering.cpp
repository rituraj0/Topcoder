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

class RectangleCovering
{
public:

vector<ll>  mx,mn;
int n;

ll solve( ll pass, ll len  )//pass ko bad pass kar jao, lenpe dhay de
{
    vector<ll> aval;

      for(int i=0;i<n;i++)
             if( mn[i] > pass)
                  aval.pb( mx[i]);
             else if( mx[i] > pass)
                  aval.pb( mn[i] );



       sort( aval.bg, aval.en) ;

       int cn=0;
       ll sm=0;

       for(int i=( (int)aval.sz )-1;i>=0;i--)
       {
            sm+=aval[i];
            cn++;

            if( sm >=len)
               return cn;
       }

     return -1;

}

int minimumNumber(int holeH, int holeW, vector <int> H, vector <int> W)
{
     n=H.sz;

     for(int i=0;i<n;i++)
     {
         mx.pb( max(H[i],W[i])  );
         mn.pb( min(H[i] , W[i]) );
     }

    ll ans=100;

    if( solve( (ll)holeH , (ll)holeW)!=-1)
          ans=min( ans , solve( (ll)holeH , (ll)holeW ) );


    if( solve( (ll)holeW , (ll)holeH)!=-1)
          ans=min( ans , solve( (ll)holeW , (ll)holeH) );


     if(ans==100)
         return -1;

     return ans;




}

};


double test0() {
	int p0 = 5;
	int p1 = 5;
	int t2[] = {8,8,8};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {2,3,4};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	RectangleCovering * obj = new RectangleCovering();
	clock_t start = clock();
	int my_answer = obj->minimumNumber(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
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
	int p1 = 10;
	int t2[] = {6,6,6,6};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {6,6,6,6};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	RectangleCovering * obj = new RectangleCovering();
	clock_t start = clock();
	int my_answer = obj->minimumNumber(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = -1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 5;
	int p1 = 5;
	int t2[] = {5};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {5};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	RectangleCovering * obj = new RectangleCovering();
	clock_t start = clock();
	int my_answer = obj->minimumNumber(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = -1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 3;
	int p1 = 5;
	int t2[] = {6};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {4};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	RectangleCovering * obj = new RectangleCovering();
	clock_t start = clock();
	int my_answer = obj->minimumNumber(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 10000;
	int p1 = 5000;
	int t2[] = {12345,12343,12323,12424,1515,6666,6789,1424,11111,25};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {1442,2448,42,1818,3535,3333,3456,7890,1,52};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	RectangleCovering * obj = new RectangleCovering();
	clock_t start = clock();
	int my_answer = obj->minimumNumber(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
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
