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
        ~Vector_T(void);

        int size(void) const;

        TData& at(int pos);
        TData  value(int pos) const;

    
    private:
        void create(void);
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
Vector_T<TData>::~Vector_T(void){ 
  destroy(); 
}



template<class TData>
int Vector_T<TData>::size(void) const
{
    return sz_;
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



// PRIVATE METHODS
template<class TData>
void Vector_T<TData>::create(void)
{
    vp_ = new TData[sz_];
}

template<class TData>
void Vector_T<TData>::destroy(void)
{
    if( vp_ != NULL ) {
        delete[] vp_;
        vp_ = NULL;
    } 
}

