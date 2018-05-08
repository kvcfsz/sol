#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class AlternateColors
{
public:
     string getColor(long long r, long long g, long long b, long long k)
     {
         long long int s3 = min(r,min(g,b));
         long long int s2 = min(max(r-s3,g-s3),min(max(g-s3,b-s3),max(r-s3,b-s3)));
         string out[]={"RED","GREEN","BLUE"};
         vector<long long>arr={r,g,b};
         sort(arr.begin(),arr.end());
         int red=-1,blue=-1,green=-1;
         for(int i=0;i<3;i++)
         {
             if(arr[i]==r && red == -1)
             {
                 red = i;
             }
             else if(arr[i]==g && green == -1)
             {
                 green = i;
             }
             else if(arr[i]==b && blue == -1)
             {
                 blue = i;
             }
         }
         k--;

         //cout<<red<<green<<blue<<"\n";

         if(k<s3*3)
         {
             return out[k%3];
         }
         else if(k<(s3*3)+(s2*2))
         {
             if(red == 0)
             {
                 return out[(k-(s3*3))%2+1];
             }
             else if(green == 0)
             {
                 return out[(k-(s3*3))%2==0?0:2];
             }
             else if(blue == 0)
             {
                 return out[(k-(s3*3))%2];
             }
         }
         else
         {
             return out[red==2?0:(blue==2?2:1)];
         }
         return "";
     }
};
