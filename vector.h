//
//  Vector.h
//  eh787_052_P5
//
//  Created by Eric Hyson on 4/24/18.
//  Copyright © 2018 Eric Hyson. All rights reserved.
//
// Do I delete or clear contents in add & remove?
#ifndef vector_h
#define vector_h


#include <cstdlib>
#include <stdexcept>
#include <exception>
#include <iostream>

using namespace std;


template <typename T>
class Vector
{
    
public:
    typedef T* Iterator;
    
    Vector();
    Vector(const unsigned capacity) throw ( bad_alloc );
    Vector(const unsigned sz, const T &object) throw ( bad_alloc );
    Vector(const Vector<T> &obj) throw ( bad_alloc );
    ~Vector();
    void assign(const unsigned index, const T &obj) throw ( out_of_range );
    T & at(const unsigned index) const throw ( out_of_range );
    unsigned capacity() const;
    void clear();
    bool empty() const;
    void insert(const unsigned, const T &) throw ( bad_alloc, out_of_range );
    T & operator[](const unsigned index) const throw ( out_of_range );
    const Vector<T> & operator= (const Vector<T> &obj) throw ( bad_alloc );
    void push_back(const T &) throw ( bad_alloc );
    void pop_back() throw ( out_of_range );
    void resize(const unsigned new_sz, const T &object =T()) throw ( bad_alloc );
    unsigned size() const;
    void sort();
    void erase(const unsigned) throw ( out_of_range );
    T begin();
    T end();
    T& front();
    T& back();
private:
    void increaseCapacity() throw ( bad_alloc );
    T * contents; //
    unsigned sz; //
    unsigned cap; //

};




template <typename T>
Vector<T>::Vector()
{
    cap = 10;
    sz = 0;
    contents = new T[cap];
    
}


template <typename T>
Vector<T>::Vector(const unsigned capacity) throw ( bad_alloc )
{
    cap = capacity;
    sz = 0;
    contents = new T[cap];
}


template <typename T>
Vector<T>::Vector(const unsigned size, const T &object) throw ( bad_alloc )
{
    sz = size;
    cap = 10;
    contents = new T [cap];
    for( unsigned i = 0; i < size; i++ )
        contents[i] = object;
    
}



template <typename T>
Vector<T>::Vector(const Vector<T> & obj) throw ( bad_alloc )
{
    sz = obj.sz;
    cap = obj.cap;
    contents = new T[sz];
    for( unsigned int i = 0; i < sz; i++ )
        contents[i] = obj.contents[i];
}



template <typename T>
Vector<T>::~Vector()
{
    clear();
    delete [] contents;
    contents = NULL;
}



template <typename T>
void Vector<T>::assign(const unsigned index, const T &obj) throw ( out_of_range )
{
    if( index > sz || index < 0)
    {
        throw out_of_range("Vector<T>::assign Invalid index to assign");
    }
    
    contents[index] = obj;
    
}



template <typename T>
T & Vector<T>::at(const unsigned index) const throw ( out_of_range )
{
    
    if( index > sz-1 || index < 0 )
    {
        throw out_of_range("Vector<T>:at Invalid index to return");
    }
    
    return contents[index];
}



template <typename T>
unsigned Vector<T>::capacity() const
{
    return cap;
}



template <typename T>
void Vector<T>::clear()
{
    sz = 0;
}



template <typename T>
bool Vector<T>::empty() const
{
    return sz == 0;
}




template <typename T>
void Vector<T>::insert(const unsigned index, const T &obj) throw ( bad_alloc, out_of_range )
{
    
    if( index > sz || index < 0 )
    {
        throw out_of_range("Vector<T>::insert Indvalid index");
    }
    
    
    
    if( sz == cap )
    {
        increaseCapacity();
    }
    
    
    T temp = contents[index];
    
    
    
    if( index == 0 )
    {
        contents[index] = obj;
    }
    else
    {
    
        for( unsigned i = sz-1; i > index; i-- )
        {
            contents[i+1] = contents[i];
        }
        
        //contents[index] = obj;
    }
    
    contents[index+1] = temp;
    contents[index] = obj;
    sz++;
    
    
}



template <typename T>
T & Vector<T>::operator[](const unsigned index) const throw ( out_of_range )
{
    if( index > cap || index < 0)
    {
        throw out_of_range("Vector<T>:operator[] Invalid index to return");
    }
    
    return contents[index];
}



template <typename T>
const Vector<T>&Vector<T>::operator=(const Vector<T> &obj) throw ( bad_alloc )
{
    
    
    
    delete [] contents;
    sz = obj.sz;
    cap = obj.cap;
    contents = new T[cap];
    for( unsigned i = 0; i < sz; i++ )
    {
        contents[i] = obj.contents[i];
    }
    
    return *this;
    
}




template <typename T>
void Vector<T>::push_back(const T &obj) throw ( bad_alloc )
{
    if( sz+1 == cap )
    {
        increaseCapacity();
    }
    
    insert(sz, obj);
        
}

template <typename T>
void Vector<T>::pop_back() throw(std::out_of_range)
{
    if( empty() )
        throw out_of_range("Empty vector");
    
    
    erase(sz);
}



template <typename T>
void Vector<T>::resize(const unsigned new_sz, const T &object) throw ( bad_alloc )
{
    
    if( new_sz > cap )
    {
        increaseCapacity();
    }
    

    
    for( unsigned i = sz; i < new_sz; i++ )
    {
        contents[i] = object;
    }
    
    sz = new_sz;
    
}





template <typename T>
unsigned Vector<T>::size() const
{
    return sz;
}





template <typename T>
void Vector<T>::sort()
{
    
    
    double temp;
    unsigned long iteration;
    unsigned long index;
    
    
    for( iteration = 1; iteration < sz; iteration++ )
    {
        for( index = 0; index < sz - iteration; index++ )
        {
            if( contents[index] > contents[index +1] )
            {
                temp = contents[index];
                contents[index] = contents[index + 1];
                contents[index + 1] = temp;
            }
        }
        
    }
    
    
    
}





template <typename T>
void Vector<T>::erase(const unsigned index) throw ( out_of_range )
{
    if( index >= sz || index < 0)
    {
        throw out_of_range("Vector<T>:operator[] Invalid index to return");
    }
    
    
    for (unsigned i = index; i < sz; i++)
    {
        contents[i] = contents[i+1];
    }
    
    sz--;
    

    
    
}




template <typename T>
void Vector<T>::increaseCapacity() throw ( bad_alloc )
{
    
    unsigned cap_new = cap*2;
    
    T *temp = new T[cap_new];
    
    for (unsigned int i = 0; i < sz; i++)
        temp[i] = contents[i];
    
    cap = cap_new;
    delete[] contents;
    contents = temp;
   
}

template<typename T>
T Vector<T>::begin()
{
    return contents;
}


template<typename T>
T Vector<T>::end()
{
    return contents + size();
}

template<typename T>
T& Vector<T>:: front()
{
    return contents[0];
}
template <typename T>
T& Vector<T>:: back()
{
    return contents[sz-1];
}




#endif /* Vector_h */
