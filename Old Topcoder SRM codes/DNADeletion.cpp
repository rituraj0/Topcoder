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

#define mod 1000000007

class DNADeletion
{
public:

map<string, vector<string>  >mapa;
ll memo[2600];
string in;
int n;
int next[2600][27];

ll solve( int x)
{
    if(x==n) return 0;

    if( memo[x]!=-1) return memo[x];

    memo[x]=0;

    ll ans=0;

    for( map<string, vector<string> >::iterator it=mapa.begin() ;it!=mapa.end();it++)
    {
         vector<string> curr=(it->second);

          int mnid=n;

          for(int i=0;i<curr.sz;i++)
          {
              string cs=curr[i];

              int id=next[x][ cs[0]-'A' ];
               id=next[ id +1][ cs[1] -'A'];
               id=next[ id +1][ cs[2] -'A'];

               mnid=min( mnid , id);
          }

         if( mnid >= n)  continue;

         ans=(ans+1+solve(mnid+1) )%mod;
    }

    return memo[x]=ans;
}

int differentProteins(vector <string> dns, vector <string> table)
{
     in="";

     for(int i=0;i<dns.sz;i++)
         in+=dns[i];

       n=in.sz;

     for(int i=0;i<26;i++)  next[n+1][i]= next[n][i]=n;

      for(int i=n-1;i>=0;i--)
         for(int j=0;j<26;j++)
      {
          next[i][j]=next[i+1][j];

          if( in[i]=='A'+j)
            next[i][j]=i;
      }

     for(int i=0;i<table.sz;i++)
     {
         vector<string> tp=parse( table[i]," ");

         mapa[ tp[1] ] .pb( tp[0] );
     }

    fill(memo,-1);

     return solve(0);

}

};



double test0() {
	string t0[] = {"ACTG"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"ACT gua", "ACG cys", "ATG leu", "CTG thr"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	DNADeletion * obj = new DNADeletion();
	clock_t start = clock();
	int my_answer = obj->differentProteins(p0, p1);
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
double test1() {
	string t0[] = {"AAACCC"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"AAA thr", "CCC cys"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	DNADeletion * obj = new DNADeletion();
	clock_t start = clock();
	int my_answer = obj->differentProteins(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 3;
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
	string t0[] = {"AAATCCC"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"AAA gua","TCC dop","AAT dop","CCC gua"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	DNADeletion * obj = new DNADeletion();
	clock_t start = clock();
	int my_answer = obj->differentProteins(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 5;
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
	string t0[] = {"ATGCGCATTAACCTCCTACCATGGAAGGGACGTAACCCGGCAATTTGATC",
 "CTGATGACGGCATAAGCTACCCCTAGAGGTAAAAATGCATACTGCGTGCT",
 "ATGCAG"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"AAC RpjZt","AAT ZeiC","GCA ChZwh","TCC RpjZt","GAA I",
 "TAG ZeiC","CTG dVK","GAG ZeiC","GTG I","AAG q","ATT dVK",
 "AGA cJEjM","GGG KONUd","GTC ZRV","GGC ZeiC","TTA KONUd",
 "GAC q","CCA q","GCC ZRV","GCG RpjZt","CCT ZRV","ATG dVK",
 "ATC ChZwh","CTC cJEjM","CCC q","ATA dWjz","TTG DkEG",
 "CAG q","CAA ZRV","ACT dVK","TCG dVK","ACC I","CGC dVK"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	DNADeletion * obj = new DNADeletion();
	clock_t start = clock();
	int my_answer = obj->differentProteins(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 455985264;
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
