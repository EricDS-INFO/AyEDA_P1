#include <iostream>

#include "dll_t.hpp"

template<class TData>
class Queue_T {
    private:
        DLL_T<TData> list_;

    public:
        Queue_T():
        list_(){}

        Queue_T( Queue_T<TData>& other_q );

        ~Queue_T(){};        

};