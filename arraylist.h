#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>

using namespace std;

template <typename T>
class ArrayList;

template <typename T>
ostream& operator<<(ostream& out,const ArrayList<T>& alist);

template <typename T>
class ArrayList
{
  int m_size;
  int m_max;
  T *m_data;
  T m_errobj;
  void grow();
  void shrink();
  bool isEmpty();
  bool isFull();
public:
  ArrayList(): m_size(0),m_max(0),m_data(NULL) {}; //checked
  ArrayList(int s, const T& x); 
  ~ArrayList();
  //Copy Constructor
  ArrayList(const ArrayList<T>& cpy); 
  
  // Assignment Operator
  ArrayList<T>& operator=(const ArrayList<T>& rhs); //Checked

  //Accessor function for m_size
  int size() const;  

  //Accessor function for m_max
  int max() const {return m_max;};
  
  const T& first() const; 

  T& operator[](int i); 

  const T& operator[](int i) const; 

  int find(const T& x) const; 

  void clear();

  void insert_back(const T& x); 

  void insert(const T& x,int i); 

  void remove(int i); 

  void swap(int i,int k);

  void append(const ArrayList<T>& alist);

  void purge();
  
  friend ostream& operator<< <>(ostream& out, const ArrayList<T>& alist);
};

#include "arraylist.hpp"

#endif
