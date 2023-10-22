#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

void print_vec(std::vector<int> &v);

std::vector<int> setup(std::vector<int> &v);
std::vector<int> counting_sort(std::vector<int> &v);

int main()
{
 /* ?\n;||(or) e &&(and)*/

 std::vector<int> v = {1, 0, 3, 1, 3, 1};
 // counting_sort(v);
 std::vector<int> a = counting_sort(v);
 print_vec(a);

 return 0;
}

void print_vec(std::vector<int> &v)
{
 for (int i = 0; i < v.size(); i++)
 {
  std::cout << v[i] << ' ';
 }
}

std::vector<int> setup(std::vector<int> &v)
{
 // build the vector with the number of ocurrences do the cumulative sum and shift right by 1
 std::vector<int> tmp_vec;
 int max = v[0];
 // find max
 for (int i = 1; i < v.size(); i++)
 {
  if (v[i] > max)
  {
   max = v[i];
  }
 }
 // build list with up to max indexes
 for (int i = 0; i <= max; i++)
 {
  tmp_vec.push_back(0);
 }
 // count the number of ocurrences
 for (int i = 0; i < v.size(); i++)
 {
  tmp_vec[v[i]]++;
 }
 // cumalative sum
 for (int i = 1; i < v.size(); i++)
 {
  tmp_vec[i] += tmp_vec[i - 1];
 }
 // right shift by 1
 int prev = 0;
 for (int i = 0; i < v.size(); i++)
 {
  int tmp = tmp_vec[i];
  tmp_vec[i] = prev;
  prev = tmp;
 }
 return tmp_vec;
}

std::vector<int> counting_sort(std::vector<int> &v)
{

 std::vector<int> tmp = setup(v);
 std::vector<int> final;
 for (int i = 0; i < v.size(); i++)
 {
  final.push_back(0);
 }
 for (int i = 0; i < v.size(); i++)
 {
  final[tmp[v[i]]] = v[i];
  tmp[v[i]]++;
 }
 return final;
}
