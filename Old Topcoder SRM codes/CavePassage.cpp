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

#define pii pair<int,int>

int incode( int a, int b)
{
    return (10*a+b);
}

pii decode( int a)
{
        return mp(a/10,a%10);
}

class CavePassage
{
public:

bool cool[1<<15];
int  speed[1<<15] , dist[100000];

vector<string> trust;

vector<int> wt,time;
int bs,n;

int speed_cal( int mask )
{
   int ans=0;

   for(int i=0;i<n;i++)
     if( mask&(1<<i))
      ans=max( ans , time[i]);

    return ans;
}

bool cool_cal( int mask)
{
    if( __builtin_popcount(mask)==1)
     {
         int id=-1;

         for(int i=0;i<n;i++)
             if(mask&(1<<i))
                 id=i;

          if( wt[id] <= bs)
             return true;

          return false;
     }

     int sm=0;

     for(int i=0;i<n;i++)
         if( (1<<i)&mask)
     {
          bool mila=false;

          sm+=wt[i];

           for(int j=0;j<n;j++)
             if(i!=j)
             if( (1<<j)&mask)
             {
                 if( trust[i][j]=='Y' )
                  mila=true;
            }

           if(!mila)
             return false;
     }

    return (sm<=bs);

}

int minimalTime(vector <int> _wt, vector <int> _time, vector <string> _trust , int _bs)
{
   wt=_wt;
   trust=_trust;
   time=_time;
   bs=_bs;

   n=wt.sz;

   for(int i=1;i<(1<<n);i++)
   {
       cool[i]=cool_cal(i);
       speed[i]=speed_cal(i);
   }

   fill(dist,63);

   set< pii> Q;

   //cource (1<<n),1 , dist 0,0

   int all=(1<<n)-1;

   dist[ incode( all ,1) ]=0; // second filed 1 emans  map cave k  entrance pe hai ,0 means  on exit pe
   Q.insert( mp(0, incode( all ,1)  ) );


   while( Q.size() > 0)
   {
       pii curr=*Q.begin(); Q.erase( Q.begin() );
       int sc=curr.Y;
       pii node=decode(sc);


//       cout<<" \n********    "<<node.X<<"  "<<node.Y<<"  "<<dist[sc]<<endl;

       if( (node.X==0)&& (node.Y==0) )
         return dist[sc];

        int old_mask=node.X , old_pos=node.Y;

        int left_side=old_mask;

        int this_side=old_mask;
        if( old_pos==0)//on right sie
            this_side=(all^this_side);

        for(int i=this_side; i>0; i=(i-1)&this_side )//moving this susbset
        {
           // if(i==this_side) continue;

            if( !cool[i] ) continue;

            int new_left_side,new_pos;

             if( old_pos==1)//on left side
             {
                  new_left_side=(left_side^i);
                  new_pos=0;
             }
            else
            {
                new_left_side=(left_side|i);
                new_pos=1;
            }

            int x=incode(new_left_side,new_pos);

            if( dist[sc]+speed[i]<dist[x])
            {
                //deleting old values of i
                pii d=mp( dist[x] , x );
                if( Q.find(d)!=Q.end() )
                     Q.erase( Q.find(d) );

                //end deleting code
                dist[x]=dist[sc]+speed[i];

//                 cout<<" ---"<<i<<"   "<<new_left_side<<"  "<<new_pos<<"  "<<dist[x]<<endl;

                Q.insert( mp(dist[x],x) );
            }

        }//end for


   }//end while

   return -1;

}

};

double test0() {
	int t0[] = { 1, 1, 1 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = { 2, 3, 4 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	string t2[] = { "YYY", "YYY", "YYY" };
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	int p3 = 2;
	CavePassage * obj = new CavePassage();
	clock_t start = clock();
	int my_answer = obj->minimalTime(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 9;
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
	int t0[] = { 1, 1, 1 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = { 2, 3, 4 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	string t2[] = { "YYY", "YYY", "NYY" };
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	int p3 = 2;
	CavePassage * obj = new CavePassage();
	clock_t start = clock();
	int my_answer = obj->minimalTime(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 10;
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
	int t0[] = { 1, 1, 1 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = { 7, 13, 19 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	string t2[] = { "YYN", "NYY", "YNY" };
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	int p3 = 3;
	CavePassage * obj = new CavePassage();
	clock_t start = clock();
	int my_answer = obj->minimalTime(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 19;
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
	int t0[] = { 43 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = { 23 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	string t2[] = { "Y" };
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	int p3 = 42;
	CavePassage * obj = new CavePassage();
	clock_t start = clock();
	int my_answer = obj->minimalTime(p0, p1, p2, p3);
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
