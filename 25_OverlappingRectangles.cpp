// For this challenge you will be determining the areas of rectangles.
/*
have the function OverlappingRectangles(strArr) read the strArr parameter being passed which will 
represent two rectangles on a Cartesian coordinate plane and will contain 8 coordinates with the 
first 4 making up rectangle 1 and the last 4 making up rectangle 2. It will be in the following 
format: ["(0,0),(2,2),(2,0),(0,2),(1,0),(1,2),(6,0),(6,2)"] Your program should determine the area 
of the space where the two rectangles overlap, and then output the number of times this overlapping 
region can fit into the first rectangle. For the above example, the overlapping region makes up a 
rectangle of area 2, and the first rectangle (the first 4 coordinates) makes up a rectangle of area 4, 
so your program should output 2. The coordinates will all be integers. If there's no overlap between 
the two rectangles return 0. 
*/



/*
traverse the string array to extract the points of each rectangle
first locate smallest and largest vertical/horizontal points of each
we then calculate the area of first rectangle
to locate points of overlapping rectangles we do a comparison of lowest and highest X and Y points
calculate are of overlapping rectangle after collecting its width and height
*/

#include <bits/stdc++.h>
using namespace std;

int OverlappingRectangles(string strArr[]) {
 vector<pair<int, int>> points;
 stringstream ss(strArr[0]);
 int x,y;
 char c;

 while (1){
  ss >> c;
  ss >> x;
  ss >> c;
  ss >> y;
  ss >> c;
  ss >> c;
  points.push_back({x, y});
  if (ss.fail())
   break;
 }
 int Xmin1, Xmax1, Ymin1, Ymax1, Xmin2, Xmax2, Ymin2, Ymax2;
 Xmin1 = min(min(min(points[0].first, points[1].first), points[2].first), points[3].first);
 Xmax1 = max(max(max(points[0].first, points[1].first), points[2].first), points[3].first);
 Ymin1 = min(min(min(points[0].second, points[1].second), points[2].second), points[3].second);
 Ymax1 = max(max(max(points[0].second, points[1].second), points[2].second), points[3].second);

 Xmin2 = min(min(min(points[4].first, points[5].first), points[6].first), points[7].first);
 Xmax2 = max(max(max(points[4].first, points[5].first), points[6].first), points[7].first);
 Ymin2 = min(min(min(points[4].second, points[5].second), points[6].second), points[7].second);
 Ymax2 = max(max(max(points[4].second, points[5].second), points[6].second), points[7].second);

 // cout << Xmin1 << ' ' << Xmax1 << ' ' << Ymin1 << ' ' << Ymax1 << ',' << Xmin2 << ' ' << Xmax2 << ' ' << Ymin2 << ' ' << Ymax2 << endl;
 
 if (Xmin2 < Xmax1 && Xmax2 > Xmin1 && Ymin2 < Ymax1 && Ymax2 > Ymin1){
  return ((Xmax1 - Xmin1) * (Ymax1 - Ymin1)) / ((min(Xmax1, Xmax2) - max(Xmin1, Xmin2)) * (min(Ymax1, Ymax2) - max(Ymin1, Ymin2)));
 }

 return 0;
}

int main() 
{
 string A[] = { "(0,0),(0,-2),(3,0),(3,-2),(2,-1),(3,-1),(2,3),(3,3)" };
 string B[] = { "(0,0),(5,0),(0,2),(5,2),(2,1),(5,1),(2,-1),(5,-1)" };
 string C[] = { "(0,0),(2,2),(2,0),(0,2),(1,0),(1,2),(6,0),(6,2)" };
 string D[] = { "(1,0),(1,1),(4,0),(4,1),(2,0),(4,0),(2,1),(4,1)" };
 string E[] = { "(5,0),(-2,0),(5,-1),(-2,-1),(3,-1),(5,-1),(3,56),(5,56)" };
 string F[] = { "(1,0),(1,1),(4,0),(4,1),(5,0),(27,0),(5,-25),(27,-25)" };
 string G[] = { "(1,0),(1,1),(4,0),(4,1),(3,0),(4,0),(3,1),(4,1)" };
 string H[] = { "(0,0),(0,-2),(3,0),(3,-2),(2,-2),(3,-2),(2,20),(3,20)" };

 cout << OverlappingRectangles(A) << endl; // 6
 cout << OverlappingRectangles(B) << endl; // 3
 cout << OverlappingRectangles(C) << endl; // 2
 cout << OverlappingRectangles(D) << endl; // 1
 cout << OverlappingRectangles(E) << endl; // 3
 cout << OverlappingRectangles(F) << endl; // 0
 cout << OverlappingRectangles(G) << endl; // 3
 cout << OverlappingRectangles(H) << endl; // 3
 return 0;
}