#include<algorithm>
#include<iomanip> 
#include<iostream>
#include<sstream>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<fstream>
#include<cctype>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<map>
#include<set>
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

vector <ll> parse2(string s, string c)
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

  vector<ll> ret;

  for(int i=0;i<sz(ans);i++)
     ret.pb( atoi(ans[i].c_str()) );

  return ret;
}



/*Solution code starts here */

class TheAirTripDivOne
{
public:

vector<ll> edge[555];
int edcon;

ll max_time;
int n;

set< pair<ll,int> >st;
ll dist[555];

ll get_next( ll st , int id)
{
        ll F=edge[id][2];
        ll P=edge[id][4];

		ll add_wait=0;

        if( st <= F)
        {
            add_wait=(F-st);
        }
        else
        {
            ll off=(st-F)%P;
            add_wait= (P-off)%P;
        }

        ll t=edge[id][3];

        return (st+add_wait+t);
}

bool cool( ll safety)
{
    st.clear();
    fill(dist,63);
    dist[1]=0;
    st.insert( mp(0LL,1) );

    while(!st.empty())
    {
        pair<ll,int> tp=*st.begin();
                          st.erase(st.begin());

            int curr=tp.Y;
            ll d=tp.X;



           if( curr == n )
              return true;

            ll next_time=d;//can take a train staertinmg from this

			if(curr!=1)
				 next_time+=safety;

						//cout<<"curr and distance  and next_time is "<<curr<<"   "<<d<<"   "<<next_time<<endl;

           for(int i=0;i<edcon;i++)//can improve time here, consdierng only f
           {
               if( edge[i][0]!=curr)
                 continue;

               int nx=edge[i][1];

                ll next_st=get_next( next_time,i);

				//cout<<nx<<"  "<<next_st<<endl;

                if( next_st <= max_time)
                      if( next_st < dist[nx])
                      {
                          if( st.find( mp(dist[nx],nx) ) != st.end() )
                              st.erase( mp(dist[nx],nx) );

                          dist[nx]=next_st;
                          st.insert( mp(dist[nx],nx) );
                      }

           }
    }

	return false;

}

int find(int _n, vector <string> in, int time2)
{
    //parsing section
    string all="";
    for(int i=0;i<sz(in);i++)
        all+=in[i];

    vector<string> temp=parse(all," ");

    edcon=sz(temp);

    for(int i=0;i<edcon;i++)
          { edge[i]=parse2(temp[i],",");

			/*for(int j=0;j<sz( edge[i] );j++ )
				cout<<edge[i][j]<<"  ";*/

            
			if(sz( edge[i]) !=5  )
			{
				cout<<"Some errror in prasing";
			}
        }

    //
        max_time=time2;
        n=_n;

  // binary search

  ll lo=1LL,hi=(1LL<<34);
  ll ans=-1;

  cout<<cool(15)<<endl;

  cout<<" 14 ";
  cout<<cool(14)<<endl;

 while(lo<=hi)
  {
      ll mid=(lo+hi)/2;

      if( cool(mid) )
      {
          ans=mid;
          lo=mid+1;
      }
     else
     {
         hi=mid-1;
     }
  }
 
  return  ans;
}

};


double test0() {
	int p0 = 3;
	string t1[] = {"1,2,1,4,7 ", "2,3,9,1,10"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int p2 = 20;
	TheAirTripDivOne * obj = new TheAirTripDivOne();
	clock_t start = clock();
	int my_answer = obj->find(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 14;
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
	int p0 = 3;
	string t1[] = {"1,2,1,1,1 2,3,2,1,98"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int p2 = 100;
	TheAirTripDivOne * obj = new TheAirTripDivOne();
	clock_t start = clock();
	int my_answer = obj->find(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = -1;
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
	int p0 = 477;
	string t1[] = {"47,74,1,1,1"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int p2 = 20;
	TheAirTripDivOne * obj = new TheAirTripDivOne();
	clock_t start = clock();
	int my_answer = obj->find(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = -1;
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
	int p0 = 7;
	string t1[] = {"1,3,15,17,11 1,3,14,16,14 5,7,12,18,18 1,6,13,1",
 "6,12 1,2,18,14,13 5,6,10,10,18 3,1,10,10,10 1,3",
 ",17,16,10 2,3,16,18,16 6,1,15,12,10 2,1,15,18,1",
 "0 4,7,10,16,15 6,3,10,14,10 1,6,19,19,15 1,4,12",
 ",10,14 4,7,10,18,14 2,3,16,12,12 1,3,14,10,19 3",
 ",7,17,10,12 2,1,14,12,16 4,3,19,11,12 1,6,10,18",
 ",12 2,3,16,12,10 6,2,10,18,12 5,1,14,18,12 5,1,",
 "18,10,10 3,2,19,15,10 7,4,16,19,14 6,3,16,12,10",
 " 5,7,14,13,13 1,3,12,10,16 5,7,16,18,15 6,2,18,",
 "12,14 3,2,10,18,16 4,2,18,18,14 1,5,10,18,16 2,",
 "3,10,19,16 1,4,11,18,15 2,1,15,15,14 7,2,10,12,",
 "10"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int p2 = 74;
	TheAirTripDivOne * obj = new TheAirTripDivOne();
	clock_t start = clock();
	int my_answer = obj->find(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 33;
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
double test4() {
	int p0 = 7;
	string t1[] = {"1,4,10,8,2 4,6,14,8,2 6,2,8,1",
 "0,1 2,7,19,5,1 ",
 "1,5,15,17,11 5,3,10,1",
 "0,18 3,7,12,18,18"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int p2 = 147;
	TheAirTripDivOne * obj = new TheAirTripDivOne();
	clock_t start = clock();
	int my_answer = obj->find(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 35;
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

	time = test4();
	if (time < 0)
		errors = true;
	

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
