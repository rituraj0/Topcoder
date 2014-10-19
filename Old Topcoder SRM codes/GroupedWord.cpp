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


class GroupedWord
{
public:


bool cool( string a)
{
    int n=a.sz;

    for(int i=0;i<n;i++)
         for(int j=i+1;j<n;j++)
           if( a[i]==a[j])
           {
               for(int k=i+1;k<=j;k++)
                  if( a[i]!=a[k])
                    return false;
            }

          return true;
}

bool join( vector<string> &a)
{
    int n=a.sz;

     for(int i=0;i<n;i++)
         for(int j=0;j<n;j++)
            if( i!=j)
     {
          char ls=a[i][ a[i].sz-1 ];

          if( ls==a[j][0] )
          {
              char jlast=a[j][ a[j].sz-1];

               if( ls==jlast)
               {
                   a[i]+=a[j];
                   a.erase(a.begin()+j);
                    return true;
               }
          }
     }

     return false;
}

bool join2( vector<string> &a)
{
    int n=a.sz;

     for(int i=0;i<n;i++)
         for(int j=0;j<n;j++)
            if( i!=j)
     {
          char ls=a[i][ a[i].sz-1 ];

          if( ls==a[j][0] )
          {
                   a[i]+=a[j];
                   a.erase(a.begin()+j);
                    return true;
          }

     }

     return false;
}

string restore(vector <string> parts)
{
   for(int i=0;i<parts.sz;i++)
     if( !cool(parts[i]) )
        return "IMPOSSIBLE";

   while( join(parts) );

   while( join2(parts) );

   for(int i=0;i<parts.sz;i++)
     if(!cool(parts[i]) )
       return "IMPOSSIBLE";

   for(int i=0;i<parts.sz;i++)
     for(int j=i+1;j<parts.sz;j++)
   {
       set<int> a( parts[i].begin() , parts[i].end() );
       set<int> b( parts[j].begin() , parts[j].end() );

       for( set<int>::iterator it=b.begin() ;it!=b.end() ; it++)
          if( a.count( *it) )
            return "IMPOSSIBLE";
   }

   if( parts.sz > 1)
     return "MANY";

   return parts[0];



}

};


double test0() {
	string t0[] = {"aaa", "a", "aa"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	GroupedWord * obj = new GroupedWord();
	clock_t start = clock();
	string my_answer = obj->restore(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "aaaaaa";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"ab", "bba"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	GroupedWord * obj = new GroupedWord();
	clock_t start = clock();
	string my_answer = obj->restore(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "IMPOSSIBLE";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"te", "st"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	GroupedWord * obj = new GroupedWord();
	clock_t start = clock();
	string my_answer = obj->restore(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "stte";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"te", "s", "t"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	GroupedWord * obj = new GroupedWord();
	clock_t start = clock();
	string my_answer = obj->restore(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "MANY";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"orr", "rd", "woo", "www"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	GroupedWord * obj = new GroupedWord();
	clock_t start = clock();
	string my_answer = obj->restore(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "wwwwooorrrd";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	string t0[] = {"abcb"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	GroupedWord * obj = new GroupedWord();
	clock_t start = clock();
	string my_answer = obj->restore(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "IMPOSSIBLE";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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

	time = test5();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
