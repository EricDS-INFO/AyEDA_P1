// [main.cpp]
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
    CLASS MODIFICATION:

    Create a structure where a subject can be explainded
*/



#include <iostream>

#include "../include/dll_t.hpp"
#include "../include/vector_t.hpp"

struct Book
{
    std::string isbn;
    std::string title;
};


struct Subject
{
    std::string st_code;
    std::string name;

    DLL_T<Book> bibl;
};



void ver_biblio(Vector_T<Subject>& itinerary, std::string code);


int main(void ) {

    Vector_T<Subject> itinerary;
    itinerary.resize(2);

    

    Book book1;
    Book book2;

    
    book1.isbn = "?????";
    book1.title = "first book";

    book2.isbn = "?????";
    book2.title = "second book";
    
    
    itinerary[0].st_code = "00a0";
    itinerary[0].name = "Advanced Maths";
    itinerary[0].bibl.push_back(new DLL_Node_T<Book> (book1));
    itinerary[0].bibl.push_back(new DLL_Node_T<Book> (book2));

    itinerary[1].st_code = "10b2";
    itinerary[1].name = "History of computers";
    itinerary[1].bibl.push_back(new DLL_Node_T<Book> (book1));
    itinerary[1].bibl.push_back(new DLL_Node_T<Book> (book2));
    

    ver_biblio(itinerary, "0000");
    

}



void ver_biblio(Vector_T<Subject>& itinerary, std::string st_code)
{
    for (int i = 0; i < itinerary.size(); i++) {
        if (itinerary[i].st_code == st_code) {
            std::string name = itinerary[i].name; 
            std::cout << "Bibliografía de la asignatura " << name <<": " << std::endl;
        
            std::cout << "\n\n";
            itinerary[i].bibl.write(std::cout);
            std::cout << std::endl;
        }
    }
}