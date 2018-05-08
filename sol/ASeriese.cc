#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class ASeries
{
public:
    long long findMax(vector<int>v,long long start,long long diff)
    {
        for(long long i=start+1;i<v.size();i++)
        {
            if( v[i]-v[start] == diff )
            {
                //cout<<diff<<" "<<v[i]<<" "<<v[start]<<"\n";
                return 1 + findMax(v,i,diff);
            }
        }
        return 0;
    }
     int longest(vector <int> v)
     {
         long long fa=0;
         sort(v.begin(),v.end());
         for(long long i=0;i<v.size();i++)
         {
           for(long long j=i+1;j<v.size();j++)
           {
               fa=max(fa,findMax(v,j,v[j]-v[i])+2);
           }
         }
         return fa;
     }
};

