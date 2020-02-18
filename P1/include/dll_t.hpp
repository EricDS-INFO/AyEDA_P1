// [dll_t.hpp]
//
// AUTOR: Eric Dürr Sierra.
// EMAIL:   alu0101027005@ull.edu.es || eric.d.s.info@gmail.com
// CONTACT: 622435010
//
// DATE:  February 2020
// 
// SUBJECT: AyEDA (Algoritmos y Estructuras de Datos Avanzadas)
//
// Ingeniería informática - ESIT ULL 
// (Escuela Superior de Ingeniería y Tecnología - Universidad de La Laguna)
//
// DESCRIPTION:
/*
    This is a doubly linked list, template based
    class implementation. Just the basic methods
    and overloads.

    It uses the "DLL_Node_T" class.
*/

#pragma once
#include "dll_node_t.hpp"


template<class TData>
class DLL_T 
{
    private:
        DLL_Node_T<TData>* head_;
        DLL_Node_T<TData>* tail_;

        int sz_;

    public:
        
        DLL_T(void);
        DLL_T(DLL_T<TData>& other_l);

        ~DLL_T(void);
    
        void push_back(DLL_Node_T<TData>* node);
        void push_front(DLL_Node_T<TData>* node);

        DLL_Node_T<TData>* extract_back(void);
        DLL_Node_T<TData>* extract_front(void);

        DLL_Node_T<TData>* get_back(void);
        DLL_Node_T<TData>* get_front(void);
        int size(void);

        bool contains(DLL_Node_T<TData>* node);
        bool empty(void);

        std::ostream& write(std::ostream& os) const;

        template<class U>
        friend std::ostream& operator <<(std::ostream& os, DLL_T<U>& list);
        
};



// PUBLIC METHODS

template<class TData>
DLL_T<TData>::DLL_T(void):
sz_(0),
head_(NULL),
tail_(NULL){}


template<class TData>
DLL_T<TData>::~DLL_T(void)
{
    DLL_Node_T<TData>* aux = NULL; 
    while(head_) {
        aux = head_;
        head_ = head_ -> get_next();
        delete aux;
        aux = NULL;   
    }
    sz_= 0;
    head_ = NULL;
    tail_ = NULL;
}

template<class TData>
void DLL_T<TData>::push_front(DLL_Node_T<TData>* node)
{
    assert(node != NULL);

    if (empty()) {
        tail_ = head_ = node;
    } else {
        head_->set_prev(node);
        node->set_next(head_);
        head_ = node;
    }
    sz_ ++;
}

template<class TData>
void DLL_T<TData>::push_back(DLL_Node_T<TData>* node)
{

    assert(node != NULL);

    if (empty()) {
        tail_ = head_ = node;
    } else {
        tail_->set_next(node);
        node->set_prev(tail_);
        tail_ = node;
    }
    sz_ ++;
}


template<class TData>
DLL_Node_T<TData>* DLL_T<TData>::extract_back(void)
{
    assert(!empty());
    DLL_Node_T<TData>* ex_node = tail_;

    tail_= tail_->get_prev();
    if (tail_ == NULL) {
        head_ = NULL;
    } else {
        tail_->set_next(NULL);
    }

    sz_ --;

    ex_node->set_next(NULL);
    ex_node->set_prev(NULL);

    return ex_node;
}

template<class TData>
DLL_Node_T<TData>* DLL_T<TData>::extract_front(void)
{
    assert(!empty());

    DLL_Node_T<TData>* ex_node = head_;

    head_ = head_->get_next();
    if (head_ == NULL) {
        tail_ = NULL;
    } else {
        head_ ->set_prev(NULL);
    }

    sz_ --;

    ex_node->set_next(NULL);
    ex_node->set_prev(NULL);

    return ex_node;
}

template<class TData>
DLL_Node_T<TData>* DLL_T<TData>::get_back(void)
{
    return tail_;
}

template<class TData>
DLL_Node_T<TData>* DLL_T<TData>::get_front(void)
{
    return head_;
}

template<class TData>
int DLL_T<TData>::size(void)
{
    return sz_;
}


template<class TData>
bool DLL_T<TData>::contains(DLL_Node_T<TData>* node)
{
    DLL_Node_T<TData>* aux = head_;

    while (aux) {
        if (aux == node) {
            return true;
        }
        aux = aux->get_next();
    }
    return false;
}

template<class TData>
bool DLL_T<TData>::empty(void)
{
    return head_ == NULL 
           && tail_ == NULL
           && sz_ == 0 ? true : false;

}
        

template<class TData>
std::ostream& DLL_T<TData>::write(std::ostream& os) const
{
    DLL_Node_T<TData>* aux = head_;
 
    os << "SIZE: " << sz_ <<std::endl;

    os << "head -> ";
    if (aux == tail_ && aux == NULL) {
        os << "-EMPTY- ";
    } else {

        while (aux) {
            os << "[" << aux->get_value() << "] ";
            aux = aux->get_next();
        }
    }
    os << "<- tail" << std::endl;

    return os;
}

// OPERATORS

template<class TData>
std::ostream& operator <<(std::ostream& os, DLL_T<TData>& list)
{
    list.write(os);
    return os;
}