//计算蚂蚁落下长竿的最长时间与最短时间
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

#define timeType long
#define distance long
#define speed long

pair<timeType, timeType>
calcTime(vector<distance> &vd, distance len, speed v)
{
  timeType minResult;
  timeType maxResult;
  distance max = 0;
  distance min = (*vd.begin());

  auto abs = [](distance d) -> distance {
    if(d<0)
      return -d;
    else
      return d;
  };
  auto Max = [](distance d1, distance d2) -> distance {
    return d1>d2 ? d1 : d2;
  };
  auto Min = [](distance d1, distance d2) -> distance {
    return d1<d2 ? d1 : d2;
  };
  
  for(auto iter=vd.begin(); iter!=vd.end(); ++iter) {
    if((Min(abs(*iter), len-abs(*iter)))>min)
      min = Min(abs(*iter), len-abs(*iter));
    if((Max(abs(*iter), abs(len-abs(*iter))))>max)
      max = Max(abs(*iter), abs(len-abs(*iter)));
  }

  minResult = min/v;
  maxResult = max/v;

  return make_pair(minResult, maxResult);
}

int main()
{
  vector<distance> vd;
  distance len, tmp;
  speed v;

  cout << "请输入长竿长度：";
  cin >> len;
  cout << "请输入蚂蚁速度：";
  cin >> v;
  cout << "请输入蚂蚁的初始点： ";
  while(cin>>tmp)
    vd.push_back(tmp);
  auto r = calcTime(vd, len, v);

  cout << "最短时间：" << r.first << "\n最长时间：" << r.second << endl;
  
  return 0;
}
