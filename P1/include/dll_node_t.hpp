#include <iostream>


template<class TData>
class DLL_Node_t
{
    private:
        TData value_;

        DLL_Node_t* prev_;
        DLL_Node_t* next_;

    public:

        DLL_Node_t(void);
        DLL_Node_t(const TData& value);

        ~DLL_Node_t(void);
    
        void set_value(TData& value);

        void set_next(DLL_Node_t<TData>* next);
        void set_prev(DLL_Node_t<TData>* prev);

        TData get_value(void) const;

        DLL_Node_t<TData>* get_next(void) const;
        DLL_Node_t<TData>* get_prev(void) const;

    private:
        void create(void);
        void destroy(void);

};


template<class TData>
DLL_Node_t<TData>::DLL_Node_t(void):
value_(),
prev_(NULL),
next_(NULL){}

template<class TData>
DLL_Node_t<TData>::DLL_Node_t(const TData& value):
value_(value),
prev_(NULL),
next_(NULL){}


template<class TData>
DLL_Node_t<TData>::~DLL_Node_t(void)
{
    prev_(NULL);
    next_(NULL);
}


template<class TData>
void DLL_Node_t<TData>::set_value(TData& value) 
{
    value_ = value;
}

template<class TData>
void DLL_Node_t<TData>::set_prev(DLL_Node_t<TData>* prev)
{
    prev_ = prev;
}

template<class TData>
void DLL_Node_t<TData>::set_next(DLL_Node_t<TData>* next)
{
    next_ =next;   
}



template<class TData>
TData DLL_Node_t<TData>::get_value(void) const
{
    return value_;
}

template<class TData>
DLL_Node_t<TData>* DLL_Node_t<TData>::get_prev(void) const
{
    return prev_;
}

template<class TData>
DLL_Node_t<TData>* DLL_Node_t<TData>::get_next(void) const
{
    return next_;
}