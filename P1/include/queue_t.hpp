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

    //TData front(void);    
    //TData back(void);    

    //void push(TData value);    
    //void pop(void);

};