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

class PalindromePhrases
{
public:

ll leftcont[2000][15][15];
ll rightcont[2000][15][15];

vector<string> words,revwords;
int n;


bool ispalin( string in)
{
    int s=in.sz;

    for(int i=0;i<s;i++)
        if( in[i]!=in[s-1-i])
         return false;

    return true;
}

ll getleft( int mask  , int id , int len)
{
      if( leftcont[mask][id][len]!=-1)
          return leftcont[mask][id][len];

      leftcont[mask][id][len]=0;  ll ans=0;

      int pos=( (int)words[id].sz )-len;
      string UncheckedMiddleOfCurrentPhrase=words[id].substr(pos);

      if( ispalin(UncheckedMiddleOfCurrentPhrase) )  ans++;

      for(int rid=0;rid<n;rid++)
          if( (mask&(1<<rid) )!=0 )
            {
                int rlen=min( len , (int)words[rid].sz );

                if( words[id].substr(pos,pos+rlen)==revwords[rid].substr(0,rlen) )
                {
                     if( len > rlen)
                         ans+=getleft( mask^(1<<rid) , id , len-rlen );
                     else
                         ans+=getright( mask^(1<<rid) , rid , ( (int)words[rid].size() )- rlen);
                }
            }

       return leftcont[mask][id][len]=ans;
}

ll getright( int mask  , int id , int len)
{
      if( rightcont[mask][id][len]!=-1)
          return rightcont[mask][id][len];

      rightcont[mask][id][len]=0;  ll ans=0;

      int pos=( (int)revwords[id].sz )-len;

      string UncheckedMiddleOfCurrentPhrase=revwords[id].substr(pos);

      if( ispalin(UncheckedMiddleOfCurrentPhrase) )  ans++;

      for(int rid=0;rid<n;rid++)
          if( (mask&(1<<rid) )!=0 )
            {
                int rlen=min( len , (int)words[rid].sz );

                if( revwords[id].substr(pos,pos+rlen)==words[rid].substr(0,rlen) )
                {
                     if( len > rlen)
                         ans+=getright( mask^(1<<rid) , id , len-rlen );
                     else
                         ans+=getleft( mask^(1<<rid) , rid , (int)words[rid].size() - rlen);
                }
            }

       return rightcont[mask][id][len]=ans;
}

long long getAmount(vector <string> _words)
{
    revwords=words=_words;
    n=words.sz;

    for(int i=0;i<n;i++)
    {
        revwords[i]="";

         for(int j=((int)words[i].sz)-1;j>=0;j--)
             revwords[i]+=words[i][j];
    }

    fill(leftcont,-1);
    fill(rightcont,-1);

    return getleft( (1<<n)-1,0,0);

}

};


double test0() {
	string t0[] = {"a","ba"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PalindromePhrases * obj = new PalindromePhrases();
	clock_t start = clock();
	long long my_answer = obj->getAmount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 2LL;
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
	string t0[] = {"ab","bcd","efg"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PalindromePhrases * obj = new PalindromePhrases();
	clock_t start = clock();
	long long my_answer = obj->getAmount(p0);
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
double test2() {
	string t0[] = {"a", "bba", "abb"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PalindromePhrases * obj = new PalindromePhrases();
	clock_t start = clock();
	long long my_answer = obj->getAmount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 7LL;
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
	string t0[] = {"aabccc", "ccbbca", "a", "acaabb", "aaa", "aab", "c", "babb", "aacaa", "b"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PalindromePhrases * obj = new PalindromePhrases();
	clock_t start = clock();
	long long my_answer = obj->getAmount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 47LL;
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
