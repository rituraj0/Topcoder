#include <bits/stdc++.h>
#include <algorithm>    // std::sort
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

int decode( char in)
{
    if( ('0'<=in) && (in<='9') )
          return (in-'0');

    return (10+(in-'A') );
}

char incode( int in)
{
    if( (0<=in)&&(in<=9) )
         return ('0'+in);

    return ('A'+in-10);
}

bool comp( string a, string b)//a>b
{
    for(int i=0;i<a.sz;i++)
         if( decode(a[i]) < decode(b[i]) )
            return false;
          else if( decode(a[i]) > decode(b[i]) )
              return true;

          //continue on same val

     return false;
}


class HexatridecimalSum
{
public:


string add( string a, string b )
{

    assert(a.sz==b.sz);

    int carry=0;

    string sum=a;

    for(int i=((int)a.sz)-1;i>=0;i--)
    {
         int x=decode(a[i]),y=decode( b[i] );
         int curr=x+y+carry;

         if(curr>=36)
         {
             curr-=36;
             carry=1;
         }
         else
         {
             carry=0;
         }

         sum[i]=incode(curr);
    }

    return sum;
}


string build( string in)
{
    while(in.sz<55)
         in="0"+in;

    return in;
}




string maximizeSum(vector <string> numb, int k)
{
    for(int  i=0;i<numb.sz;i++)
    {
             numb[i]=build( numb[i] );
    }


   vector<string>canadd( 40 ,string(55,'0') );

   cout<<canadd[0]<<endl;


  string oldval(55,'0');

   for(int i=0;i<numb.sz;i++)
   {
        string curr=numb[i];

        cout<<oldval<<endl;
        cout<<"+"<<endl;
        cout<<curr<<endl;

        oldval=add(oldval,curr);//already achived

        cout<<oldval<<"\n\n\n";

        int j=0;
        while( curr[j]=='0')
              j++;

        for(;j<curr.sz;j++)
        {
            char tp=curr[j];
            int id=decode(tp);

              string pos(55,'0');

              pos[j]=incode( 35- id );

//              if(id==0)
//                print(pos[j]);

              canadd[ id]=add( canadd[id] ,pos );
        }
   }

   string zero(55,'0');

   for(int i=0;i<40;i++)
     if( canadd[i]!=zero)
      cout<<i<<"  "<<incode(i)<<"  "<<canadd[i]<<endl;


   sort( canadd.begin(), canadd.end(),comp );

   for(int i=0;i<k;i++)
    oldval=add(oldval,canadd[i]);


   while(oldval[0]=='0')
     oldval=oldval.substr(1);

   return oldval;

}

};


double test0() {
	string t0[] = {"HELLO"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 2;
	HexatridecimalSum * obj = new HexatridecimalSum();
	clock_t start = clock();
	string my_answer = obj->maximizeSum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "ZZLLO";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"500", "POINTS", "FOR", "THIS", "PROBLEM"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 5;
	HexatridecimalSum * obj = new HexatridecimalSum();
	clock_t start = clock();
	string my_answer = obj->maximizeSum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "1100TC85";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"TO", "BE", "OR", "NOT", "TO", "BE"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 0;
	HexatridecimalSum * obj = new HexatridecimalSum();
	clock_t start = clock();
	string my_answer = obj->maximizeSum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "QNO";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"KEQUALS36"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 36;
	HexatridecimalSum * obj = new HexatridecimalSum();
	clock_t start = clock();
	string my_answer = obj->maximizeSum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "ZZZZZZZZZ";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"GOOD", "LUCK", "AND", "HAVE", "FUN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 7;
	HexatridecimalSum * obj = new HexatridecimalSum();
	clock_t start = clock();
	string my_answer = obj->maximizeSum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "31YUB";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
