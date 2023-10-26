#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

void print_vec(std::vector<int> &v);

class prio_q
{
public:
 void min_heapify(std::vector<int> &v, int k, int n)
 {
  if (n <= 1)
  {
   return;
  }
  int min = k;
  int l = 2 * k + 1;
  int r = 2 * k + 2;
  if (l < n && v[l] < v[k])
  {
   min = l;
  }
  if (r < n && v[r] < v[min])
  {
   min = r;
  }
  if (min != k)
  {
   std::swap(v[min], v[k]);
   min_heapify(v, min, n);
  }
 }
 std::vector<int> heap;
 int n = 0;
 prio_q() {}
 prio_q(std::vector<int> &v)
 {
  n = v.size();
  for (int i = 0; i < (n - 1) / 2; i++)
  {
   min_heapify(v, i, n);
  }
  for (int i = 0; i < n; i++)
  {
   heap.push_back(v[i]);
  }
 }
 ~prio_q() {}
 // push
 void push(int val)
 {
  heap.push_back(val);

  int p = (n - 1) / 2;
  while (p >= 0 && heap[p] > val)
  {
   std::swap(heap[p], heap[n - 1]);
   p = (p - 1) / 2;
  }
  n++;
 }
 // pop
 int pop()
 {
  int tmp = heap[0];
  heap.erase(heap.begin(), heap.begin() + 1);
  n--;
  min_heapify(heap, 0, n);
  return tmp;
 }
 // is_empty()
 bool is_empty()
 {
  if (n == 0)
  {
   return true;
  }
  return false;
 }
 // print
 void print_vec()
 {
  for (int i = 0; i < heap.size(); i++)
  {
   std::cout << heap[i] << (char)32;
  }
  std::cout << (char)10;
 }
};

void heap_sort(std::vector<int> &v);

main()
{
 /* ?\n;||(or) e &&(and)*/

 std::vector<int> v = {4, 9, 0, 1, 3, 2};
 heap_sort(v);
 /*prio_q *p = new prio_q(v);
 p->print_vec();
 std::cout << p->pop() << (char)10;
 p->print_vec();
 std::cout << p->pop() << (char)10;
 p->print_vec();
 std::cout << p->pop() << (char)10;
 p->print_vec();*/

 return 0;
}

void print_vec(std::vector<int> &v)
{
 for (int i = 0; i < v.size(); i++)
 {
  std::cout << v[i] << (char)32;
 }
 std::cout << (char)10;
}

void heap_sort(std::vector<int> &v)
{
 prio_q *p = new prio_q(v);
 std::vector<int> sorted;
 for (int i = 0; i < v.size(); i++)
 {
  sorted.push_back(p->pop());
 }
 print_vec(sorted);
}
