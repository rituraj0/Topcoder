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

class CircuitsConstruction
{
public:

deque<int> in;

int maximizeResistance(string st, vector <int> cond)
{
  sort( cond.bg , cond.en);

  for(int i=0;i<cond.sz;i++)
     in.pb( cond[i] );

     print( in.sz);

   int ans=0;
   int n=st.sz;

    for(int i=n-1; i>0;)
    {
         int cn=0;
         char op='x';


        cout<<"Enterung an loop with i \n";
         print(i);

        bool cool=true;

         while( cool)
         {
                 if( (st[i]=='A') || (st[i]=='B') )
                 {
                    op=st[i];
                    i--;
                    cool=false;
                    break;
                 }
                 else
                 {
                     cn++;
                     i--;
                 }
         }

         print(cn);

         if( op=='A')//sum
         {
               for(int k=0;k<cn;k++)
               {
                   ans+=in.back();
                         in.pop_back();
               }
         }
         else
         {
               int mx=0;

               for(int k=0;k<cn;k++)
               {
                   mx=max(mx,in.front() );
                         in.pop_front();
               }

               ans=max(ans,mx);
         }
    }

   return ans;


  return -1;
}

};


double test0() {
	string p0 = "BXBXX";
	int t1[] = {8, 2, 3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	CircuitsConstruction * obj = new CircuitsConstruction();
	clock_t start = clock();
	int my_answer = obj->maximizeResistance(p0, p1);
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
double test1() {
	string p0 = "AAXXAXAXX";
	int t1[] = {1, 1, 2, 8, 10};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	CircuitsConstruction * obj = new CircuitsConstruction();
	clock_t start = clock();
	int my_answer = obj->maximizeResistance(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 22;
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
	string p0 = "AXBXX";
	int t1[] = {8, 2, 3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	CircuitsConstruction * obj = new CircuitsConstruction();
	clock_t start = clock();
	int my_answer = obj->maximizeResistance(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 11;
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
	string p0 = "BAAXBXXBXAXXBBAXXBXXAAXXX";
	int t1[] = {17, 7, 21, 102, 56, 72, 88, 15, 9, 192, 16, 8, 30};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	CircuitsConstruction * obj = new CircuitsConstruction();
	clock_t start = clock();
	int my_answer = obj->maximizeResistance(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 454;
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
