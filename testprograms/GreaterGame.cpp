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

void go( vector<int> in)
{
    cout<<" \n";
    for(int i=0;i<sz(in);i++)
        cout<<in[i]<<"  ";

    cout<<" \n";
}
class GreaterGame
{
public:


double calc(vector <int> hand, vector <int> sothe)
{

    vector<int> save=hand;

    int n=sz(hand);

	sort(hand.begin(),hand.end());

//	deque<int> pas;
//
//	for(int i=0;i<n;i++)
//        pas.push_back(hand[i]);

    vector<int> know;

    for(int i=0;i<n;i++)
         if( sothe[i]!=-1)
          know.push_back( sothe[i]);

    sort(know.begin(),know.end());

    double sure=0;

    for(int i=0;i<sz(know);i++)
    {
        bool mila=false;

        for(int j=0;j<n;j++)
             if( hand[j] > know[i] )//lowest poss se  jito
             {
                 mila=true;
                 hand[j]=-10;
                 break;
             }

        if( mila)
        {
            sure+=1.0;
            continue;
        }
        //goint ot lose, waste minimum possible

        //cout<<

        for(int j=0;j<n;j++)
              if( hand[j] > 0)
                {
                 hand[j]=-20;
                 break;
                }
    }




    vector<int> snuke_left;

    for(int i=0;i<n;i++)
         if( hand[i] > 0 )
            snuke_left.pb( hand[i]);


    //sothe left

    map<int,bool> ds;


    for(int i=0;i<n;i++)
        ds[ save[i] ]=true;

    for(int i=0;i<sz(know);i++)
         ds[ know[i] ]=true;

    vector<int> sothe_left;

    for(int i=1;i<=2*n;i++)
         if( ds.count(i)==0)
          sothe_left.pb(i);


       // go( snuke_left)  ;
        //go(sothe_left);

    assert( sz(snuke_left)==sz(sothe_left ) );



     int m=sz( snuke_left);

     if(m==0)
         return sure;


        double add=0;

    for(int i=0;i<m;i++)
    {
        double cn=0;

        for(int j=0;j<m;j++)
             if( snuke_left[i] > sothe_left[j])
               cn+=1;

              // print(cn);

        add+=cn;
    }


    add=add/( double(m) );//bug m can be zero

    // print(sure);
    // print(add);

    return (sure+add);



}

};


double test0() {
	int t0[] = {4,2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {-1,-1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	GreaterGame * obj = new GreaterGame();
	clock_t start = clock();
	double my_answer = obj->calc(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 1.5;
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
	int t0[] = {4,2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	GreaterGame * obj = new GreaterGame();
	clock_t start = clock();
	double my_answer = obj->calc(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 2.0;
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
	int t0[] = {2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {-1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	GreaterGame * obj = new GreaterGame();
	clock_t start = clock();
	double my_answer = obj->calc(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 1.0;
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
	int t0[] = {1,3,5,7};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {8,-1,4,-1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	GreaterGame * obj = new GreaterGame();
	clock_t start = clock();
	double my_answer = obj->calc(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 2.5;
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
double test4() {
	int t0[] = {6,12,17,14,20,8,16,7,2,15};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {-1,-1,4,-1,11,3,13,-1,-1,18};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	GreaterGame * obj = new GreaterGame();
	clock_t start = clock();
	double my_answer = obj->calc(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 8.0;
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
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
