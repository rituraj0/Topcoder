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

ll dp[1<<21];

class PeopleYouMayKnow
{
public:


int maximalScore(vector <string> in, int A, int B)
{
    set<int> oned;

    int n=in.sz;

    for(int i=0;i<n;i++)
        if( in[A][i]=='Y' && in[i][B]=='Y')
           oned.insert(i);

     int ans=oned.size();//direct wale ko hatna padega


     print(ans);

    for(int i=0;i<n;i++)
         for(int j=0;j<n;j++)
              if( in[i][j]=='Y')
                 if( (oned.find(i)!=oned.end()) || (oned.find(j)!=oned.end() ) )//delete either i or j
                    {
                        in[i][j]='N';
                    }

     vector<int>  mini , maxi;

     for(int i=0;i<n;i++)
         if( in[A][i]=='Y')
           mini.pb( i),cout<<" in mini "<<i<<" - ";

     for(int i=0;i<n;i++)
         if( in[B][i]=='Y')
           maxi.pb(i),cout<<" in maxi "<<i<<"  - ";

     if( ((int)mini.size()) > ((int)maxi.size()) )
        {
            swap(mini,maxi);
            swap(A,B);
        }

        cout<<A<<"  "<<mini.sz<<"  "<<B<<"   "<<maxi.sz<<endl;

     //now A is person with mininum number with

     if( (int)(mini.size())==0 )
          return ans;

      int ms=mini.sz;


    fill(dp,-1);

    dp[0]=0;//left se sabko hata dia(koe nahi bacha) , islia right me kjoe nahi hataha padega

     for(int i=0;i<(int)mini.size();i++)//left me bas yahi jinda hai
     {
          int curr=mini[i];
          int mask=(1<<i);

          ll cm=0;

          for(int j=0;j<n;j++)
             if( (in[curr][j]=='Y') && ( in[j][B]=='Y') )
                  cm=cm|(1<<j);

         dp[mask]=cm;

       print(mask);print(cm);
     }

    for(int i=0;i<(1<<ms);i++)
          if( dp[i]==-1)
                {
                    dp[i]=0;

                    for(int j=0;j<ms;j++)
                        if( i & (1<<j) )
                         dp[i]=dp[i]|dp[1<<j];
                }

      int ret=1e5;

      for(int i=0;i<(1<<ms);i++)
      {
          int tp=ans+( ms- __builtin_popcount(i) )+__builtin_popcount( dp[i]);

          ret=min(ret,tp);
      }

      return ret;





   return 0;

}

};


double test0() {
	string t0[] = {"NN"
,"NN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 0;
	int p2 = 1;
	PeopleYouMayKnow * obj = new PeopleYouMayKnow();
	clock_t start = clock();
	int my_answer = obj->maximalScore(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 0;
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
	string t0[] = {"NYNN"
,"YNYN"
,"NYNY"
,"NNYN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 0;
	int p2 = 3;
	PeopleYouMayKnow * obj = new PeopleYouMayKnow();
	clock_t start = clock();
	int my_answer = obj->maximalScore(p0, p1, p2);
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
double test2() {
	string t0[] = {"NYNYYYN"
,"YNYNNYY"
,"NYNNNNY"
,"YNNNNNN"
,"YNNNNYN"
,"YYNNYNY"
,"NYYNNYN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 2;
	int p2 = 3;
	PeopleYouMayKnow * obj = new PeopleYouMayKnow();
	clock_t start = clock();
	int my_answer = obj->maximalScore(p0, p1, p2);
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
double test3() {
	string t0[] = {"NYYYYNNNN"
,"YNNNNYYYN"
,"YNNNNNNYN"
,"YNNNNNNYN"
,"YNNNNNNNY"
,"NYNNNNNNY"
,"NYNNNNNNY"
,"NYYYNNNNY"
,"NNNNYYYYN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 8;
	int p2 = 0;
	PeopleYouMayKnow * obj = new PeopleYouMayKnow();
	clock_t start = clock();
	int my_answer = obj->maximalScore(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 3;
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
