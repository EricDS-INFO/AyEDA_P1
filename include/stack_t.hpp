// [stack_t.cpp]
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
   List based Stack class. Contains the basic operations of the stack class
   TAD implementation.
*/



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

        template<class U>
        friend std::ostream& operator <<(std::ostream& os, Stack_T<U>&);
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
    assert(!empty());
    DLL_Node_T<TData>* aux = list_.extract_front();

    delete aux;
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


template<class TData>
std::ostream& Stack_T<TData>::write(std::ostream& os)
{   
    os << "SIZE: " << list_.size() << "\n\n";

    os << "#     #" << std::endl;
    if (!empty()) {
        DLL_Node_T<TData>* aux = list_.get_front();
        while (aux) {
            os <<"|  " << aux->get_value() <<"  |" <<std::endl;
            aux = aux->get_next();
        }
    }

    os << "=======" << std::endl;
    return os;
}


template<class TData>
std::ostream& operator <<(std::ostream& os, Stack_T<TData>& stack)
{
    stack.write(os);
    return os;
}