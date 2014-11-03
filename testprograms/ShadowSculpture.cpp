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

struct point
{
    int x,y,z;
    point(int a, int b , int c)
    {
        x=a;
        y=b;
        z=c;
    }

    point()
    {

    }
};

bool adja( point a, point b)
{
    int x=0;

     x+=abs( a.x -b.x);
     x+=abs( a.y -b.y);
     x+=abs( a.z -b.z);

     return (x <=1);//may be same
}

int incode( point a)
{
    return (100*a.x + 10*a.y+a.z);//o to 9 only
}

point decode(int a)
{
    point ans;

    ans.z=a%10;
    a=a/10;
    ans.y=a%10;
    a=a/10;
    ans.x=a%10;

    return ans;
}

class ShadowSculpture
{
public:

vector<point> all[310];

vector<int> graf[310];

bool done[310];

void dfs( int x)
{
    if( done[x] )
         return ;

    done[x]=true;

    for(int i=0;i<sz( graf[x]);i++)
         dfs( graf[x][i] );
}


map< int, bool > cantake;

string possible(vector <string> XY, vector <string> YZ, vector <string> ZX)
{
    int n=sz(XY);
    int cont=0;

    //build for XY
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
          if( XY[i][j]=='Y')
            {
                for(int k=0;k<n;k++)
                     all[cont].pb ( point(i,j,k));

                     cont++;
            }

     //build for YZ
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
          if( YZ[i][j]=='Y')
           {
                for(int k=0;k<n;k++)
                     all[cont].pb( point(k,i,j) );

                     cont++;
            }

    //build for ZX

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
          if( ZX[i][j]=='Y')
           {
                for(int k=0;k<n;k++)
                     all[cont].pb( point(j,k,i));

                     cont++;
            }


          if( cont==0)
          {
                return "Possible";
          }

     //Now building graf

     for(int i=0;i<cont;i++)
                    for(int a=0;a<sz( all[i] );a++)
                    {
                        cantake[ incode(all[i][a]) ]=true;
                    }


     for(int i=0;i<sz(all[0]);i++)
     {

         set<int> st;

         st.insert( incode(all[0][i]) );//start from here

         //flod fill type

         for(int it=0;it<1009;it++)
         {
             set<int> nw;

             cout<<"Here";

             for( set<int>::iterator it1=st.begin();it1!=st.end();it1++)
             {
                 int curr=*it1;

                 point pt=decode(curr);

                 for(int dx=-1;dx<2;dx++)
                    for(int dy=-1;dy<2;dy++)
                     for(int dz=-1;dz<2;dz++)
                        {

                                if( abs(dx)+abs(dy)+abs(dz) > 1 )
                                     continue;

                                int nx=pt.x+dx;
                                int ny=pt.y+dy;
                                int nz=pt.x+dz;

                                if( (nx <0) || (nx >=n))
                                    if( (ny <0) || (ny >=n))
                                     if( (nz <0) || (nz >=n))
                                        continue;

                                 int newp=incode( point(nx,ny,nz) );

                                 if( cantake[newp])
                                    nw.insert(newp);

                        }
              }//out of all SET iterration

              if(nw==st)
                 break; //cont add nay new

               st=nw;
         }

         //now verify st;

         bool all_mila=true;

         for(int a=0;a<cont;a++)//for all group
         {
            bool mila=false;

            for(int j=0;j<sz(all[a]);j++)
                 if( st.find( incode(all[a][j]))!=st.end())
                    mila=true;

            if(!mila)
                all_mila=false;

         }

         if( all_mila)
         {
            return "Possible";
         }
     }



     return "Impossible";
}

};


double test0() {
	string t0[] = {"YN","NN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"YN","NN"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"YN","NN"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	ShadowSculpture * obj = new ShadowSculpture();
	clock_t start = clock();
	string my_answer = obj->possible(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "Possible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"YN","NY"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"YN","NY"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"YN","NY"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	ShadowSculpture * obj = new ShadowSculpture();
	clock_t start = clock();
	string my_answer = obj->possible(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "Impossible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"YYY","YNY","YYY"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"YYY","YNY","YYY"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"YYY","YNY","YYY"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	ShadowSculpture * obj = new ShadowSculpture();
	clock_t start = clock();
	string my_answer = obj->possible(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "Possible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"YYY","YNY","YYY"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"NYY","YNY","YYY"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"YYY","YNY","YYN"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	ShadowSculpture * obj = new ShadowSculpture();
	clock_t start = clock();
	string my_answer = obj->possible(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "Impossible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"N"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"N"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"N"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	ShadowSculpture * obj = new ShadowSculpture();
	clock_t start = clock();
	string my_answer = obj->possible(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "Possible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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

//	time = test2();
//	if (time < 0)
//		errors = true;
//
//	time = test3();
//	if (time < 0)
//		errors = true;
//
//	time = test4();
//	if (time < 0)
//		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
