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

        
};

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
{}

template<class TData>
DLL_Node_T<TData>* DLL_T<TData>::extract_front(void)
{}

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
{}

template<class TData>
bool DLL_T<TData>::empty(void)
{
    return head_ == NULL 
           && tail_ == NULL
           && sz_ == 0 ? true : false;

}
        