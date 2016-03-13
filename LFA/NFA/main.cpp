#include <fstream>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
ifstream fin("nfa.in");
ofstream fout("nfa.out");
int main()
{
    int n,m,c,i,j,k,l,p,f,ff[100],qn[100],q0;
    char al[100];
    fin>>n;
    for(i=0;i<n;i++)fin>>qn[i];
    fin>>m;
    for(i=0;i<m;i++)fin>>al[i];

    fin>>q0;

    fin>>f;
    for(i=0;i<f;i++)fin>>ff[i];

    map <pair <int, char>, vector <int> > delta;
    vector <int> stari_1;
    vector <int> stari_2;
    char a;
    fin>>p;
    int q1,q2;
    for(i=0;i<p;i++)
    {
        fin>>q1>>a>>q2;
        pair <int, char> pa;
        pa.first=q1;
        pa.second=a;
        delta[pa].push_back(q2);
    }
    char cuv[100][20];
    fin>>c;
    for(i=0;i<c;i++)fin>>cuv[i];
    for(i=0;i<c;i++)
        {
            int ok1=1,ok2=0;
            stari_1.push_back(q0);
            for(j=0;j < strlen(cuv[i])&&ok1==1;j++)
            {
                for(k=0;k<stari_1.size();k++)
                {
                    pair <int,char> pa;
                    pa.first=stari_1[k];
                    pa.second=cuv[i][j];
                    for(l=0;l < delta[pa].size();l++)stari_2.push_back(delta[pa][l]);
                }
                if(stari_2.size()==0){fout<<"Rejected_1\n";ok1=0;}
                stari_1.swap(stari_2);
                stari_2.clear();
            }
            if(ok1==1)
            {
                for(k=0;k < stari_1.size()&&ok2==0;k++)
                    for(l=0;l<f&&ok2==0;l++)
                        if(stari_1[k]==ff[l])ok2=1;
                if(ok2==0)fout<<"Rejected_2\n";
                else fout<<"Accepted\n";

            }
            stari_1.clear();
            stari_2.clear();
        }
    fin.close();
    fout.close();
    return 0;
}
