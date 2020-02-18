#include <iostream>
#include "dll_t.hpp"

template<class TData>
class Stack_T
{
    private:
        DLL_T<TData> list_;
        int          sz_;
    
    public:

        Stack_T(void):
        list_(){}
        Stack_T(Stack_T<TData>& other_s);

        ~Stack_T(void){}

        TData top(void);

        void pop(void);
        void push(TData value);

        bool empty(void);
        int size(void);

        std::ostream& write(std::ostream& os);
};


template<class TData>
TData Stack_T<TData>::top(void) 
{
    assert(!empty());

    DLL_Node_T<TData>* node = list_.get_front();
    TData value = node->get_value();
    return value;
}


template<class TData>
void Stack_T<TData>::pop(void)
{
    list_.extract_front();
}


template<class TData>
void Stack_T<TData>::push(TData value)
{
    list_.push_front(new DLL_Node_T<TData>(value));
}


template<class TData>
bool Stack_T<TData>::empty(void)
{
    return list_.empty();
}


template<class TData>
int Stack_T<TData>::size(void)
{
    return list_.size();
}