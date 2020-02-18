// [vector_t_test.cpp]
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
  Test file that arranges all the code testing from the vector class made
  with template style
*/

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>


#include "../include/vector_t.hpp"

// Unit Testing style tests

TEST_CASE( "The vector class tests basic operations", "[Vector_t]" ) 
{
  Vector_T<int> v1(2);
  REQUIRE (v1.size() == 2);
  
  SECTION( "Introducing values to the vector: " )
  {
    v1[0] = 1;
    v1[1] = 2;

    REQUIRE( v1[0] == 1 );
    REQUIRE( v1[1] == 2 );

    SECTION ("Resizing up the vector should increase the size value") 
    {
      int old_sz = v1.size();
      v1.resize(3);
      int new_sz = v1.size();

      REQUIRE( v1.size() == 3);
      REQUIRE( old_sz <= new_sz);
    }

    SECTION ("Resizing down the vector should decrease the size value") 
    {
      int old_sz = v1.size();
      v1.resize(1);
      int new_sz = v1.size();

      REQUIRE( v1.size() == 1);
      REQUIRE( old_sz >= new_sz);
    }

    SECTION ( "Pushing values to the vector should increase the size\nand have the right value" ) 
    {
      v1.push_front(0);
    
      REQUIRE( v1.size() == 3 );
      CHECK( v1[0] == 0 );
      CHECK( v1[1] == 1 );
      CHECK( v1[2] == 2 );
    }

    SECTION ( "Pushing back to the vector should increase the size\nand have the right value" ) 
    {
      v1.push_back(3);
    
      REQUIRE( v1.size() == 3 );
      CHECK( v1[0] == 1 );
      CHECK( v1[1] == 2 );
      CHECK( v1[2] == 3 );
    }

    SECTION( "copy of vector does not copy the reference")
    {
      Vector_T<int> v2(v1);

      REQUIRE(v2.size() == 2);
      CHECK( v2[0] == v1[0]  );
      CHECK( v2[1] == v1[1]  );
      CHECK( &v2 != &v1 );
      
    }

  }

  SECTION("Reading and writting the vector") 
  {    
    v1[0] = 1;
    v1[1] = 2;
    std::cout << v1 << std::endl;
    
  }
}

template<class TData>
class DLL_T 
{

};


template<class TData>
class DLL_Node_t
{

};

// BDD Style tests

SCENARIO( "The doubly linked list basic tests", "[DLL_T]" ) 
{
  GIVEN("An instance of DLL_T and DLL_Node_T")
  {
    DLL_T<char> list1;
    DLL_Node_t<char> node1();

  }

}