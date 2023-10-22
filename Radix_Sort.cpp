#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

void print_vec(std::vector<int> &v);

int get_max_digits(std::vector<int> &v);
void radix_sort(std::vector<int> &v);

int main()
{
 /* ?\n;||(or) e &&(and)*/

 std::vector<int> v = {5, 7, 100, 34, 98, 369};
 radix_sort(v);
 // print_vec(v);

 return 0;
}

void print_vec(std::vector<int> &v)
{
 for (int i = 0; i < v.size(); i++)
 {
  std::cout << v[i] << ' ';
 }
}

int get_max_digits(std::vector<int> &v)
{
 int max = 0;
 for (int i = 1; i < v.size(); i++)
 {
  if (v[i] > max)
  {
   max = v[i];
  }
 }
 int c;
 if (max == 0)
 {
  c = 1;
 }
 else
 {
  c = 0;
  while (max > 0)
  {
   max /= 10;
   c++;
  }
 }
 return c;
}

void radix_sort(std::vector<int> &v)
{
 std::vector<std::vector<int>> radix_list;
 for (int i = 0; i < 10; i++)
 {
  std::vector<int> tmp;
  radix_list.push_back(tmp);
 }
 std::vector<int> cpy;
 std::vector<int> sorted;
 for (int i = 0; i < v.size(); i++)
 {
  cpy.push_back(v[i]);
  sorted.push_back(0);
 }
 int k = get_max_digits(v);
 for (int i = 0; i < k; i++)
 {
  for (int j = 0; j < v.size(); j++)
  {
   int tmp = cpy[j] % 10;
   cpy[j] /= 10;
   radix_list[tmp].push_back(v[j]);
  }
  int c = 0;
  for (int j = 0; j <= 9; j++)
  {
   int h = 0;
   while (!radix_list[j].empty())
   {
    int tmp = radix_list[j][h];
    sorted[c] = tmp;
    c++;
    h++;
    radix_list[j].pop_back();
   }
  }
  // std::cout << '\n';
 }
 print_vec(sorted);
}
