#include <fstream>
#include <cstring>
#include <map>
using namespace std;
ifstream fin("dfa.in");
ofstream fout("dfa.out");
int main()
{
    int n,m,c,i,j,p,f,ff[100],qn[100],q0;
    char al[100];
    fin>>n;
    for(i=0;i<n;i++)fin>>qn[i];
    fin>>m;
    for(i=0;i<m;i++)fin>>al[i];

    fin>>q0;

    fin>>f;
    for(i=0;i<f;i++)fin>>ff[i];

    map <pair <int, char>, int> delta;
    char a;
    fin>>p;
    int q1,q2;
    for(i=0;i<p;i++)
    {
        fin>>q1>>a>>q2;
        pair <int, char> pa;
        pa.first=q1;
        pa.second=a;
        delta[pa]=q2;
    }
    char cuv[100][20];
    fin>>c;
    for(i=0;i<c;i++)fin>>cuv[i];
    for(i=0;i<c;i++)
        {
            int ok1=1,ok2=0;
            int q=q0;
            for(j=0;j<strlen(cuv[i])&&ok1==1;j++)
            {
                pair <int,char> pa;
                pa.first=q;
                pa.second=cuv[i][j];
                q=delta[pa];
                if(q==0)
                {
                    fout<<"Rejected_1\n";ok1=0;
                }
            }
            if(ok1==1)
            {
                for(j=0;j<f&&ok2==0;j++)
                    if(q==ff[j])
                    {
                        fout<<"Accepted\n";
                        ok2=1;
                    }
                if(ok2==0)fout<<"Rejected_2\n";
            }
        }
    fin.close();
    fout.close();
    return 0;
}
