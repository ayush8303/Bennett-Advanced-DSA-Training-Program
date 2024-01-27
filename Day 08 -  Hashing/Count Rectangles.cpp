#include <bits/stdc++.h>
using namespace std;

#define Point pair<int, int>
#define x first
#define y second

int count_rectangles(vector<Point> &pts)
{
  // insert all the points in the set
  set<Point> st;
  for (Point p : pts)
  {
    st.insert(p);
  }

  // Two points + look up for other two
  int ans = 0;
  for (auto it = st.begin(); it != prev(st.end()); it++)
  {
    for (auto jt = next(it); jt != st.end(); jt++)
    {
      Point p1 = *it;
      Point p2 = *jt;

      if (p2.x == p1.x or p2.y == p1.y)
        continue;
      Point p4(p1.x, p2.y);
      Point p3(p2.x, p1.y);

      if (st.find(p3) != st.end() and st.find(p4) != st.end())
      {
        ans++;
      }
    }
  }
  return ans / 2;
}

int main()
{
  int n;
  cin >> n;

  vector<Point> pts;
  for (int i = 0; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    Point p(x, y);
    pts.push_back(p);
  }
  cout << count_rectangles(pts);
  return 0;
}
