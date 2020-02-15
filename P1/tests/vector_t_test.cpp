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

TEST_CASE( "The vector class tests", "[Vector_t]" ) 
{
  Vector_T<int> v1(2);
  REQUIRE (v1.size() == 2);
  
  SECTION( "Introducing values to the vector" )
  {
    v1.at(0) = 1;
    v1.at(1) = 2;

    REQUIRE( v1.value(0) == 1 );
    REQUIRE( v1.value(1) == 2 );

  }
}