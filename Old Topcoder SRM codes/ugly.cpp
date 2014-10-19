#include<iostream>
#include<queue>
using namespace std;

void print( queue<int> in)
{
    while( !in.empty() )
    {
        cout<<in.front()<<"  ";
        in.pop();
    }

}
int main()
{
    queue<int> A,B,C;
    A.push(2);B.push(3);C.push(5);

    int n=10;

    while(n--)
    {
        int x=min( A.front() , min( B.front() , C.front() ) );

        cout<<x<<" < "<<endl;
        print(A);cout<<endl;
        print(B);cout<<endl;
        print(C);cout<<endl;
        cout<<" * * **   \n";

        if( x==A.front())
        {
            A.pop();
            A.push(x*2); B.push(x*3);C.push(x*5);
        }
        else if( x==B.front())
        {
            B.pop();
            B.push(x*3);C.push(x*5);
        }
        else
        {
            C.pop();
            C.push(x*5);
        }
    }
}
