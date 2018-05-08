#include<bits/stdc++.h>
using namespace std;
class Aircraft
{
    public:
    double CalcDistance(vector <int> p1,vector <int> p2)
        {
          return sqrt(pow(p1[0]-p2[0],2)+pow(p1[1]-p2[1],2)+pow(p1[2]-p2[2],2));
        }
    string nearMiss(vector <int> p1, vector <int> v1, vector <int> p2, vector <int> v2, int R)
        {
          double distance,prevdistance=0,flag=0,yes=0;
          while(true)
              {
                for(int i=0;i<3;i++)
                    {
                      p1[i]+=v1[i];
                      p2[i]+=v2[i];
                    }
               distance = CalcDistance(p1,p2);
               if( distance <= R )
                   {
                     yes=1;
                     break;
                   }
               if(flag!=0)
               {
                 if( prevdistance <= distance )
                 {
                   break;
                 }
               }
               prevdistance = distance;
               flag=1;
              }
    if(yes)
        {
          return "YES";
        }
    else
        {
          return "NO";
        }
     }
};

