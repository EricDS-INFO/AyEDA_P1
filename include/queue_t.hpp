// [queue_t.cpp]
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
   List based queue class. Contains the basic operations of the queue class
   TAD implementation.
*/


#include <iostream>

#include "dll_t.hpp"

template<class TData>
class Queue_T {
    private:
        DLL_T<TData> list_;

    public:
        Queue_T(void):
        list_(){}

        ~Queue_T(void){};

        TData front(void);    
        TData back(void);    

        void push(TData value);    
        void pop(void);

        int size(void);
        bool empty(void);

        std::ostream& write(std::ostream& os);


        template<class U>
        friend std::ostream& operator <<(std::ostream& os, Queue_T<U>&);
};



template<class TData>
TData Queue_T<TData>::front(void)
{
    DLL_Node_T<TData>* front_node = list_.get_front();
    return front_node->get_value();
}   

template<class TData>
TData Queue_T<TData>::back(void)    
{
    DLL_Node_T<TData>* back_node = list_.get_back();
    return back_node->get_value();
}

template<class TData>    
void Queue_T<TData>::push(TData value)
{
    list_.push_back(new DLL_Node_T<TData>(value));
}

template<class TData>    
void Queue_T<TData>::pop(void)
{
    assert(!empty());

    DLL_Node_T<TData>* aux = list_.extract_front();

    delete aux;
}

template<class TData>
int Queue_T<TData>::size(void)
{
    return list_.size();
}

template<class TData>
bool Queue_T<TData>::empty(void)
{
    return list_.empty();
}



template<class TData>
std::ostream& Queue_T<TData>::write(std::ostream& os)
{

    os << "SIZE: " << list_.size() << "\n\n";
    os << "    ";
    for (int i = 0; i < list_.size(); i++) {
        os << "---";
    }
    os << "    " << std::endl;
    os << "|<- ";
    if (!empty()) {
        DLL_Node_T<TData>* aux = list_.get_front();
        while (aux) {
            os << " "<< aux->get_value() << " ";
            aux = aux->get_next();
        }
    }
    os << " <-|" << std::endl;
    os << "    ";
    for (int i = 0; i < list_.size(); i++) {
        os << "¯¯¯";
    }
    os << "    " << std::endl;
    return os;
}


template<class TData>
std::ostream& operator<< (std::ostream& os, Queue_T<TData>& q )
{
    q.write(os);
    return os;
}