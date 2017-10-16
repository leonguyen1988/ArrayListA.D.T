template <typename T>
void ArrayList<T>::grow()
{
  T *tmp;
  m_max == 0 ? m_max++ : m_max; 
  tmp = new T[m_max*2];
  for(int k=  0; k<m_size; k++)
  {
      tmp[k] = m_data[k]; 
  }
  delete [] m_data;
  m_data = tmp;
  m_max *=2;
}

template <typename T>
void ArrayList<T>::shrink()
{
  T* tmp; 
  tmp = new T[m_max/2];
  for(int k = 0 ; k < m_size;k++)
    tmp[k] = m_data[m_size];
  delete[] m_data;
  m_data = tmp;
  m_max /=2;
}

template <typename T>
bool ArrayList<T>::isEmpty()
{
  return (m_size == 0? true : false);
}

template <typename T>
bool ArrayList<T>::isFull()
{
  return (m_size == m_max ? true: false);
}

template <typename T>
ArrayList<T>::ArrayList(int s, const T& x)
{
  T *tmp;
  tmp = new T[s];
  tmp[0] =x;
  delete[] m_data;
  tmp = m_data;
}

template <typename T>
ArrayList<T>::~ArrayList()
{
  m_size =0;
  m_max =0;
  delete[] m_data;
  m_data = NULL;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& cpy)
{
  m_size = cpy.m_size;
  m_max = cpy.m_max;
  m_data = new T[m_max];
  for(int k = 0; k<cpy.m_size; k++)
  {
    m_data[k] = cpy.m_data[k];
  } 
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rhs)
{
  T *tmp;
  tmp = new T[rhs.m_max];
  for(int i =0; i< rhs.m_size; i++)
    tmp[i]= rhs.m_data[i];
  delete[] m_data;
  m_data = tmp;
  m_size = rhs.m_size;
  m_max = rhs.m_max;
  return *this;
}

template <typename T>
int ArrayList<T>::size() const
{
  return m_size;
}

template <typename T>
const T& ArrayList<T>::first() const
{
  try
  {
    if(m_size==0 || m_max ==0)
      throw m_errobj;
  }
  catch(T)
  {
    cout<<"!-- ERROR: PANIC in ARRAYLIST!!";
    cout<<"     (List is empty) \n";
    return m_errobj;
  }
  return m_data[0];
} 


template <typename T>
T& ArrayList<T>::operator[](int i)
{
  try
  {
    if(i<m_max)
      return m_data[i];
    else
    throw m_errobj;
  }
  catch(T)
  {
    cout<<"!-- ERROR: PANIC in ARRAYLIST!!";
    cout<<"    (Index out of bounds)\n";
    return m_errobj;
  }
}

template <typename T>
const T& ArrayList<T>::operator[](int i) const
{
  try
  {
    if(i<m_max)
      return m_data[i];
    else 
      throw m_errobj;
  }
  catch(T)
  {
    cout<<"!-- ERROR: PANIC in ARRAYLIST!!";
    cout<<"    (Index out of bounds)\n";
    return m_errobj;
  }
}

template <typename T>
int ArrayList<T>::find(const T& x) const
{
  int found =-1;
    for(int k=0; k < m_size ; k++)
    {
      if(m_data[k]==x)
        found = k;
    }
  return found;
}

template <typename T>
void ArrayList<T>::clear()
{
  m_max = 0;
  m_size = 0;
  delete[] m_data;
  m_data = NULL;
}

template <typename T>
void ArrayList<T>::insert_back(const T& x)
{
  try
  {
    if(isFull())
      grow();
    m_data[m_size] = x;
    m_size++;
  }
  catch(...)
  {
    cout<<"!-- ERROR : PANIC in ARRAYLIST!!"<<endl;
    cout<<"    (Index out of bounds)\n";
  }
} 


template <typename T>
void ArrayList<T>::insert(const T& x, int i)
{
  try
  {
    if(i > m_size || i < 0) 
    {
      throw i;
    }
    else
    {
      if(isFull())
        grow();
      for(int k = m_size ; k > i ; k--)
      {
        m_data[k] = m_data[k-1];
      }
      m_data[i] = x;
      m_size++;
    }
  }
  catch (...)
  {
    cout<<"!-- ERROR : PANIC in ARRAYLIST!!";
    cout<<"    (Index out of bounds)\n";
  }
}

template <typename T>
void ArrayList<T>::remove(int i)
{
  try
  {
    if(!isEmpty())
    {
      if(i<m_size && i>=0)
      {
        for(int k = i ; k<m_size-1;k++)
          m_data[k] = m_data[k+1];
        m_size--;
      }
      if(m_size < (m_max/4))
        shrink();
    }
    if(i>m_size)
     throw i;
  }
  catch(int)
  {
    cout<<"!-- ERROR : PANIC in ARRAYLIST!!";
    cout<<"    (Index out of bounds)\n";
  }
  catch(...)
  {
    cout<<"!-- ERROR : PANIC in ARRAYLIST!!";
    cout<<"    (List is empty)\n";
  }
 
}

template <typename T>
void ArrayList<T>::swap(int i, int k)
{
  try
  {
    if(isEmpty())
      throw m_errobj;
    else if( i > m_max || i < 0)
      throw i;
    else if(k>m_max || k < 0)
      throw k;
    else 
    {
      T tmp;
      tmp = m_data[i];
      m_data[i]= m_data[k];
      m_data[k] = tmp; 
    }
    
  }
  catch(int)
  {
    cout<<"!-- ERROR : PANIC in ARRAYLIST!!";
    cout<<"    (index out of bounds)\n";
  }
  catch(T)
  {
    cout<<"!-- ERROR : PANIC in ARRAYLIST!!";
    cout<<"List is empty!!\n";
  }
}

template <typename T>
void ArrayList<T>::append(const ArrayList<T>& alist)
{
  try
  {
    if(alist.m_max !=0)
    { 
      T *tmp;
      int k=0;
      tmp = new T[m_size+alist.m_size];
      for(int i =0; i<m_size;i++)
      {
          tmp[k] = m_data[i];
          k++;
      }
      for(int j = 0; j<alist.m_size ; j++)
      {
        tmp[k] = alist.m_data[j];
        k++;
      }
      delete[] m_data;
      m_data = tmp;
      m_size +=alist.m_size;
      m_max +=alist.m_max;
      tmp=NULL;
    }
    else
      throw alist.m_max;
  }
  catch(int)
  {
    cout<<"!-- ERROR : PANIC in ARRAYLIST!!";
    cout<<"    (List is empty list)\n";
  }
}

template <typename T>
void ArrayList<T>::purge()
{
  try
  {
    if(!isEmpty())
    {
      for(int k = 0; k<m_size;k++)
      {
        for(int j=k+1;j<m_size;j++)
        {
          if(m_data[k]==m_data[j])
          {
            remove(j);
            j--;
          }
        } 
      }
    }     
    else
      throw m_errobj;
    if(m_size < (m_max/4))
      shrink();
  }
  catch(T)
  {
    cout<<"!-- ERROR : PANIC in ARRAYLIST!!";
    cout<<"    (List is empty list)\n";
  } 
}

template <typename T>
ostream& operator<<(ostream& out, const ArrayList<T>& alist)
{
  out<<"[ ";
  for(int k=0; k<alist.m_size;k++)
  {
    out<<alist.m_data[k]<<", ";
  }
  out<<"]";
  return out;
}