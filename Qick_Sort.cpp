#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

int partition(std::vector<int> &v, int strt, int end);
void quick_sort(std::vector<int> &v, int strt, int end);

int main()
{
 /* ?\n;||(or) e &&(and)*/

 std::vector<int> v = {3, 6, -19, 87, 11};

 quick_sort(v, 0, v.size() - 1);

 for (int i = 0; i < v.size(); i++)
 {
  std::cout << v[i] << " ";
 }

 return 0;
}

int partition(std::vector<int> &v, int strt, int end)
{
 int mid = (strt + end) / 2;

 while (strt <= end)
 {
  while (v[mid] > v[strt])
  {
   strt++;
  }
  while (v[mid] < v[end])
  {
   end--;
  }
  if (strt <= end)
  {
   std::swap(v[strt], v[end]);
   strt++;
   end--;
  }
 }
 return strt;
}

void quick_sort(std::vector<int> &v, int strt, int end)
{
 int point = partition(v, strt, end);
 if (strt >= end)
 {
  return;
 }
 if (v[point] - 1 > v[strt])
 {
  quick_sort(v, strt, point - 1);
 }
 if (v[point] < v[end])
 {
  quick_sort(v, point, end);
 }
}
