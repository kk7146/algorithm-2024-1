#include <vector>
#include <stdio.h>
#include <algorithm>
#include <float.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

struct Point{
    int x, y;

    bool operator < (const Point &b) const
    {
        if(x == b.x)
            return y < b.y;
        else
            return x < b.x;
    }
};

bool cmp(Point a, Point b){
    return a.y < b.y;
}

float dist(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

float bruteForce(vector<Point> point,int start, int end)
{
    float m = -1;
    for(int i = start; i <= end - 1; i++)
        for(int j = i + 1; j <= end; j++)
        {
            float d = dist(point[i], point[j]);
            if(m == -1 || m > d)
                m = d;
        }
    if (m == -1)
        return FLT_MAX;
    else
        return m;
}

float min(float x, float y)
{
    return (x < y)? x : y;
}

float minPoint(vector<Point> point, int size, float min)
{
    sort(point.begin(), point.end(), cmp);
    for (int i = 0; i < size - 1; ++i)
        for (int j = i + 1; j < size && point[j].y - point[i].y < min; ++j)
            if (dist(point[i],point[j]) < min)
                min = dist(point[i], point[j]);
    return min;
}

float recur(vector<Point> point, int start, int end)
{
    if (end - start + 1 <= 3)
        return bruteForce(point, start, end);
    int mid = (start + end) / 2;
    float left = recur(point, start, mid);
    float right = recur(point, mid + 1, end);
    float d = min(left, right);
    vector<Point> inDist;
    for (int i = start; i <= end; i++)
        if (abs(point[i].x - point[mid].x) < d)
            inDist.push_back(point[i]);
    return min(d, minPoint(inDist, inDist.size(), d));
}
 
float closest(vector<Point> point, int size)
{
    sort(point.begin(), point.end());
    return recur(point, 0, point.size() - 1);
}

vector<Point>   inputArray()
{
    vector<Point> point;
    int num;
    scanf("%d", &num);
    for (size_t i = 0; i < num; i++)
    {
        Point   newPoint;
        scanf("%d", &newPoint.x);
        scanf("%d", &newPoint.y);
        point.push_back(newPoint);
    }
    return (point);
}

int main()
{
    int testcase;
    scanf("%d", &testcase);
    for (int i = 0; i < testcase; i++)
    {
        vector<Point> p;
        p = inputArray();
        if (p.size() == 1)
            printf("%.2f\n", 0);
        else
            printf("%.2f\n", closest(p, p.size() - 1));
    }
    return 0;
}
