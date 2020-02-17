// [vector_t.hpp]
//
// AUTOR: Eric Dürr Sierra.
// DATE:  February 2020
// 
// SUBJECT: AyEDA (Algoritmos y Estructuras de Datos Avanzadas)
//
// Ingeniería informática - ESIT ULL 
// (Escuela Superior de Ingeniería y Tecnología - Universidad de La Laguna)
//
// DESCRIPTION:
/*
    This a template based class definition and implementation for a vector
    in the C++ languaje. 

    As well as it is template based the implementation of the code is right 
    below the class declaration.
*/


#pragma once
#include <iostream>
#include <cassert>


template <class TData> 
class Vector_T 
{
    private:
        int     sz_;
        TData*  vp_;
    
    public:   
        Vector_T(void);
        Vector_T(int sz);
        Vector_T(const Vector_T<TData>& v);
        ~Vector_T(void);

        int size(void) const;

        void resize(int nsz);

        TData& at(int pos);
        TData  value(int pos) const;

        void push_front( TData value);
        void push_back( TData value);

        std::ostream& write(std::ostream& os) const;

        TData& operator [](int pos);
        TData  operator [](int pos) const;

        template<class U>
        friend std::ostream& operator <<(std::ostream& os, Vector_T<U>&);
    
    
    private:
        void create(void);
        void copy(Vector_T v);
        void destroy(void);
};


// PUBLIC METHODS

template<class TData>
Vector_T<TData>::Vector_T(void):
vp_(NULL),
sz_(0){}

template<class TData>
Vector_T<TData>::Vector_T(int sz):
vp_(NULL),
sz_(sz)
{ 
  create(); 
}

template<class TData>
Vector_T<TData>::Vector_T(const Vector_T<TData>& v):
vp_(NULL),
sz_(v.size())
{ 
  create(); 
  copy(v);  

}

template<class TData>
Vector_T<TData>::~Vector_T(void){ 
  destroy(); 
}

template<class TData>
int Vector_T<TData>::size(void) const
{
    return sz_;
}


template<class TData>
void Vector_T<TData>::resize(int nsz)
{
    destroy();
    sz_ = nsz;
    create();
}

template<class TData>
TData Vector_T<TData>::value(int pos) const
{
    assert(pos >= 0 && pos < sz_);
    return vp_[pos];
}

template<class TData>
TData& Vector_T<TData>::at(int pos) 
{
    assert(pos >= 0 && pos < sz_);
    return vp_[pos];
}

template<class TData>
void Vector_T<TData>::push_front( TData value)
{
    Vector_T aux_v(sz_);

    for (int i = 0; i < sz_; i++) {
        aux_v[i] = vp_[i];
    }

    resize(sz_ + 1);
    vp_[0] = value;

    for (int i = 1; i < sz_; i++) {
        vp_[i] = aux_v[i - 1];
    }
}

template<class TData>
void Vector_T<TData>::push_back( TData value)
{    
    Vector_T aux_v(sz_);

    for (int i = 0; i < sz_; i++) {
        aux_v[i] = vp_[i];
    }
    resize(sz_ + 1);
    vp_[sz_ - 1] = value;

    for (int i = 0; i < sz_ - 1; i++) {
        vp_[i] = aux_v[i];
    }
}


template<class TData>
std::ostream& Vector_T<TData>::write(std::ostream& os) const
{
    os << "SIZE: " << sz_ << std::endl;
    os << "[";
    for (int i = 0; i < sz_; i++ ) {
        os << " " << vp_[i];
    }
    os << " ]" << std::endl;
    
    return os;
}

// OPERATORS

template<class TData>
TData& Vector_T<TData>::operator [](int pos)
{
    return at(pos);
}

template<class TData>
TData  Vector_T<TData>::operator [](int pos) const
{
    return value(pos);
}
    

template<class TData>
std::ostream& operator <<(std::ostream& os, Vector_T<TData>& v)
{
    v.write(os);
    return os;
}

// PRIVATE METHODS

template<class TData>
void Vector_T<TData>::create(void)
{
    vp_ = new TData[sz_];
}

template<class TData>
void Vector_T<TData>::copy(Vector_T<TData> v)
{
   for (int i = 0; i < sz_; i++)
        vp_[i] = v[i]; 
}

template<class TData>
void Vector_T<TData>::destroy(void)
{
    if( vp_ != NULL ) {
        delete[] vp_;
        vp_ = NULL;
    } 
}

