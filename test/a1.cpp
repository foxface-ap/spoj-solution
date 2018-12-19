#include <bits/stdc++.h>

using namespace std;

struct mice{
  double x,y,vx,vy;
};

struct ti{
  double st,ed;
};

int main()
{
  int n;
  cin >> n;

  double x1,x2,y1,y2;
  cin >> x1 >> y1 >> x2 >> y2;

  ti t = {0,1000000007};

  for(int i=0;i<n;i++)
  {  
    mice a;
    cin >> a.x >> a.y >> a.vx >> a.vy;

    ti t1,t2;

    if(a.vx == 0)
    {
      if(a.x > x1 && a.x < x2)
      {  
        t1.st = 0;
        t1.ed = 1000000007;
      }
      else
        t1.st = t1.ed = -1;
    }
    else if(a.vx > 0)
    {
      if(a.x >= x2)
        t1.st = t1.ed = -1;
      else if(a.x > x1)
      {
        t1.st = 0;
        t1.ed = (x2-a.x)/a.vx;
      }
      else
      {
        t1.st = (x1-a.x)/a.vx;
        t1.ed = (x2-a.x)/a.vx;
      }
    }
    else
    {
      if(a.x <= x1)
        t1.st = t1.ed = -1;
      else if(a.x < x2)
      {
        t1.st = 0;
        t1.ed = (a.x-x1)/a.vx;
      }
      else
      {
        t1.st = (a.x-x2)/a.vx;
        t1.ed = (a.x-x1)/a.vx;
      }
    }

    if(a.vy == 0)
    {
      if(a.y > y1 && a.y < y2)
      {  
        t2.st = 0;
        t2.ed = 1000000007;
      }
      else
        t2.st = t2.ed = -1;
    }
    else if(a.vy > 0)
    {
      if(a.y >= y2)
        t2.st = t2.ed = -1;
      else if(a.y > y1)
      {
        t2.st = 0;
        t2.ed = (y2-a.y)/a.vy;
      }
      else
      {
        t2.st = (y1-a.y)/a.vy;
        t2.ed = (y2-a.y)/a.vy;
      }
    }
    else
    {
      if(a.y <= y1)
        t2.st = t2.ed = -1;
      else if(a.y < y2)
      {
        t2.st = 0;
        t2.ed = (a.y-y1)/a.vy;
      }
      else
      {
        t2.st = (a.y-y2)/a.vy;
        t2.ed = (a.y-y1)/a.vy;
      }
    }

    /*cout << t1.st << " " << t1.ed << endl;
    cout << t2.st << " " << t2.ed << endl << endl;*/

    t.st = max(t.st,max(t1.st,t2.st));
    t.ed = min(t.ed,min(t1.ed,t2.ed));

  }

  if(t.st < t.ed)
    cout << setprecision(8) << t.st << endl;
  else
    cout << -1 << endl;
}