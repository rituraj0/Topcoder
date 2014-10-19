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

class ThirteenHard
{
public:

ll  dist[27][1<<14];
set< pair<ll, pair<int,int> > >st;//dist,curr,amsk

ll in[27][27];
vector<string> city;

int n;

ll dot(int x ,int y)
{

    if( 'A'<=city[x][y] && city[x][y]<='Z')
         return city[x][y]-'A'+1;

    return city[x][y]-'a'+27;
}

int nextt( int mask, int d )
{
  vector<int> tp;

  for(int i=0;i<13;i++)
     if( mask&(1<<i))
       tp.pb(i);

  for(int i=0;i<sz(tp);i++)
     tp[i]=(tp[i]+d)%13;

   tp.pb(d%13);

   int ans=0;

   for(int i=0;i<sz(tp);i++)
      ans=ans|(1<<tp[i]);

   return ans;
}

int calcTime(vector <string> _city)
{
    city=_city;

    fill(dist,63);
    n=sz(city);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
             in[i][j]=dot(i,j);

     fill(dist,63);

     dist[0][0]=0;
     st.insert( mp(0,mp(0,0)));

     while(!st.empty())
     {
        pair<ll,pair<int,int> >  here=*st.begin();
                                      st.erase( st.begin() );
        ll d=here.X;
        int curr=here.Y.X;
        int mask=here.Y.Y;

        if(curr==n-1)
             return dist[curr][mask];

        for(int i=0;i<n;i++)
        {
            if( city[curr][i]=='#')
                 continue;

            ll newd=d+in[curr][i];

            int new_mask=nextt(mask,in[curr][i]);

            if(new_mask&1)//zero hai
                continue;

            if( d < dist[i][new_mask] )
            {
                if( st.find( mp(dist[i][new_mask] ,mp(i,new_mask) )) !=st.end() )
                st.erase( mp(dist[i][new_mask] ,mp(i,new_mask) ) );

                dist[i][new_mask]=newd;

                st.insert( mp(dist[i][new_mask] ,mp(i,new_mask) ) );
            }
        }


     }



   return -1;
}

};


double test0() {
	string t0[] = { "#AB##",
  "###A#",
  "###C#",
  "####K",
  "#####" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ThirteenHard * obj = new ThirteenHard();
	clock_t start = clock();
	int my_answer = obj->calcTime(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 16;
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
	string t0[] = { "#Z",
  "Z#" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ThirteenHard * obj = new ThirteenHard();
	clock_t start = clock();
	int my_answer = obj->calcTime(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = -1;
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
	string t0[] = { "Good#####",
  "#Luck####",
  "##and####",
  "##Have###",
  "####Fun##",
  "#####in##",
  "#####the#",
  "CHALLENGE",
  "##PHASE##" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ThirteenHard * obj = new ThirteenHard();
	clock_t start = clock();
	int my_answer = obj->calcTime(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 137;
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
	string t0[] = { "###No#####",
  "####Zaphod",
  "#####Just#",
  "######very",
  "####very##",
  "improbable",
  "##########",
  "##########",
  "##########",
  "##########" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ThirteenHard * obj = new ThirteenHard();
	clock_t start = clock();
	int my_answer = obj->calcTime(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 103;
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
	string t0[] = { "#B#C##T#M",
  "##K######",
  "########A",
  "####R####",
  "#####U###",
  "########C",
  "#######H#",
  "########S",
  "#########" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ThirteenHard * obj = new ThirteenHard();
	clock_t start = clock();
	int my_answer = obj->calcTime(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 47;
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
