#include <iostream>
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

        TData get_value(void) const;

        DLL_Node_T<TData>* get_next(void) const;
        DLL_Node_T<TData>* get_prev(void) const;


};


template<class TData>
DLL_Node_T<TData>::DLL_Node_T(void):
value_(),
prev_(NULL),
next_(NULL){}

template<class TData>
DLL_Node_T<TData>::DLL_Node_T(const TData& value):
value_(value),
prev_(NULL),
next_(NULL){}


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
TData DLL_Node_T<TData>::get_value(void) const
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