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

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

map<int,int> dist;
map<int,bool> done;

class PiecesMover
{
public:

queue<int> Qu;

int incode(  vector<string> in)
{
    int ans=0;

    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
             if( in[i][j]=='*')
                {
                        int id=(5*i+j);
                         ans+=(1<<id);
                }

//                print(ans);

        return ans;
}


vector<string> decode( int mask)
{
    vector<string> ans(5,".....");

//    for(int i=0;i<5;i++)
//        cout<<ans[i]<<endl;

    for(int i=0;i<25;i++)
         if( mask&(1<<i))
         {
           int row=(i/5),col=(i%5);
           ans[row][col]='*';
         }

         return ans;
}

bool cool( vector<string> in)
{
    queue< pair<int,int> >Q;

    int sx=-1,sy=-1;

    int all=0;

    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
          if( in[i][j]=='*')
          {
              sx=i;
              sy=j;
              all++;
          }


     int cont=0;

     Q.push( mp(sx,sy) );

     map< pair<int,int> , bool> done;

     while(Q.size() >0 )
     {
         pair<int,int> curr=Q.front() ; Q.pop();

         if( done.count(curr) ) continue;

         done[curr]=true;
         cont++;

           for(int i=0;i<4;i++)
           {
               int nx=curr.X+dx[i];
               int ny=curr.Y+dy[i];

               if( (nx<0) || (nx>=5)||( ny<0)|| (ny>=5) ) continue;

               if( in[nx][ny]!='*') continue;

               Q.push( mp(nx,ny) );
           }
     }

     return (cont==all);

}



int getMinimumMoves(vector <string> board)
{
    done.clear();
    dist.clear();

    int st=incode(board);

    dist[st]=0;
    Qu.push(st);

    while( Qu.size() > 0)
    {
        int tp=Qu.front();Qu.pop();

        if( done.count(tp) ) continue;
        done[tp]=true;

        vector<string> curr=decode(tp);

        if( cool(curr) )
             return dist[tp];


         for(int i=0;i<5;i++)
             for(int j=0;j<5;j++)
                 if( curr[i][j]=='*')
                 {
                     for(int k=0;k<4;k++)
                      {
                          int nx=i+dx[k];
                          int ny=j+dy[k];

                          if( (nx<0)||(nx>=5)||(ny<0)||(ny>=5)) continue;

                           swap(curr[i][j] ,curr[nx][ny] );

                           int id=incode(curr);

                           swap(curr[i][j] ,curr[nx][ny] );

                            if( dist.count(id)==0)
                             { dist[id]=dist[tp]+1;
                               Qu.push(id);
                             }


                      }//end inner for
                 }//end if
    }//end while

   return -1;

}

};


double test0() {
	string t0[] = {".....",
 "..**.",
 ".....",
 "...*.",
 "....."}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PiecesMover * obj = new PiecesMover();
	clock_t start = clock();
	int my_answer = obj->getMinimumMoves(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
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
	string t0[] = {".....",
 ".....",
 ".**..",
 ".*...",
 "**..."}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PiecesMover * obj = new PiecesMover();
	clock_t start = clock();
	int my_answer = obj->getMinimumMoves(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 0;
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
	string t0[] = {"*...*",
 ".....",
 ".....",
 ".....",
 "*...*"}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PiecesMover * obj = new PiecesMover();
	clock_t start = clock();
	int my_answer = obj->getMinimumMoves(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 12;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
