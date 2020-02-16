// [dll_node_t.hpp]
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
    This is a doubly linked list node , template based
    class implementation. Just the basic methods
    and overloads.
*/



#include <iostream>
#include <cstdio>
#pragma once

template<class TData>
class DLL_Node_T
{
    private:
        TData value_;

        DLL_Node_T* prev_;
        DLL_Node_T* next_;

    public:

        DLL_Node_T(void);
        DLL_Node_T(const TData& value);

        ~DLL_Node_T(void);
    
        void set_value(TData& value);

        void set_next(DLL_Node_T<TData>* next);
        void set_prev(DLL_Node_T<TData>* prev);

        const TData get_value(void) const;

        DLL_Node_T<TData>* get_next(void) const;
        DLL_Node_T<TData>* get_prev(void) const;


};


template<class TData>
DLL_Node_T<TData>::DLL_Node_T(void):
prev_(NULL),
next_(NULL),
value_(){}

template<class TData>
DLL_Node_T<TData>::DLL_Node_T(const TData& value):
prev_(NULL),
next_(NULL),
value_(value){}


template<class TData>
DLL_Node_T<TData>::~DLL_Node_T(void)
{
    prev_ = NULL;
    next_ = NULL;
}


template<class TData>
void DLL_Node_T<TData>::set_value(TData& value) 
{
    value_ = value;
}

template<class TData>
void DLL_Node_T<TData>::set_prev(DLL_Node_T<TData>* prev)
{
    prev_ = prev;
}

template<class TData>
void DLL_Node_T<TData>::set_next(DLL_Node_T<TData>* next)
{
    next_ =next;   
}



template<class TData>
const TData DLL_Node_T<TData>::get_value(void) const
{
    return value_;
}

template<class TData>
DLL_Node_T<TData>* DLL_Node_T<TData>::get_prev(void) const
{
    return prev_;
}

template<class TData>
DLL_Node_T<TData>* DLL_Node_T<TData>::get_next(void) const
{
    return next_;
}