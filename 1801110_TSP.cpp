#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define V1 11

lli start;
priority_queue< pair<lli,pair<lli,pair<lli,pair<lli,lli*>>>>, vector<pair<lli,pair<lli,pair<lli,pair<lli,lli*>>>>>, greater<pair<lli,pair<lli,pair<lli,pair<lli,lli*>>>>> > p1;


lli heuristic(lli node,lli see[],lli map[][V1])
{

   see[node]=1;


   lli minimum1=100000,minimum2=100000;
   lli i,z=0,heuristic=0;



   for(i=1;i<=V1;i++)
   {
      if(see[i]==0)
    {


      if(map[node-1][i-1]<minimum1)
      minimum1=map[node-1][i-1];

      if(map[i-1][start-1]<minimum2)
      minimum2=map[i-1][start-1];

      z=z+1;
    }

   }

   if(z>=1)
   heuristic+=minimum1+minimum2;



   return heuristic;
}


void traversal(lli node,lli cst,lli see[],lli map[][V1])
{
   lli mx=-1;

    for(lli i=1;i<=V1;i++)
   { if(see[i]>=mx)
     mx=see[i];
   }



   see[node]=mx+1;



   lli z=0;
   lli see1[V1+1][V1+1]={0};
   lli see2[V1+1][V1+1]={0};
   vector<lli>path1[V1+1];

   for(lli i=1;i<=V1;i++)
   {
      if(see[i]==0)
    {
      for(lli j=1;j<=V1;j++)
      {
          see1[i][j]=see[j];

          if(see[j]>=1)
          see2[i][j]=1;
          else
          see2[i][j]=0;
      }

      lli heur=heuristic(i,see2[i],map);
      lli obj=heur+map[node-1][i-1]+cst;
      p1.push({obj,{i,{node,{cst,see1[i]}}}});

      z=z+1;
    }

   }



   if(z>=1)
   {pair<lli,pair<lli,pair<lli,pair<lli,lli*>>>> p2=p1.top();
    p1.pop();

    cst=p2.second.second.second.first + map[p2.second.second.first-1][p2.second.first-1];


    traversal(p2.second.first,cst,p2.second.second.second.second,map);
   }

   else
   {
     vector<pair<lli,lli>>finalpath;

     cout<<"Path: ";

     for(lli i=1;i<=V1;i++)
     finalpath.push_back({see[i],i});

     sort(finalpath.begin(),finalpath.end());

     for(lli i=0;i<finalpath.size();i++)
     cout<<finalpath[i].second<<" ";



     cout<<"1 ";
     cout<<"\n";

     cout<<"cst: "<<cst+map[node-1][start-1];
     return;
   }


}

int main()
{
  start=1;
  //cout<<start<<" 000"<<"    ";;
  lli see[V1+1]={0};


  lli map[][V1] =
  {
{0 , 8 ,50 ,31 ,12 ,48 ,36 , 2 , 5 ,39 ,10,},
        {8 , 0 ,38 , 9 ,33 ,37 ,22 , 6 , 4 ,14 ,32,},
        {50, 38,  0, 11, 55,  1, 23, 46, 41, 17, 52 ,},
        {31,  9, 11,  0, 44, 13, 16, 19, 25, 18, 42 ,},
        {12, 33, 55, 44,  0, 54, 53, 30, 28, 45,  7 ,},
        {48, 37,  1, 13, 54,  0, 26, 47, 40, 24, 51 ,},
        {36, 22, 23, 16, 53, 26,  0, 29, 35, 34, 49 ,},
        {2 , 6 ,46 ,19 ,30 ,47 ,29 , 0 , 3 ,27 ,15 ,},
        {5 , 4 ,41 ,25 ,28 ,40 ,35 , 3 , 0 ,20 ,21 ,},
        {39, 14, 17, 18, 45, 24, 34, 27, 20,  0, 43 ,},
        {10, 32, 52, 42,  7, 51, 49, 15, 21, 43,  0 ,}
  };

   traversal(start,0,see,map);


  return 0;

}
