// [p1_test.cpp]
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
// #include "lib/Catch/catch2/catch.hpp"



#include "../include/vector_t.hpp"

#include "../include/dll_t.hpp"
#include "../include/dll_node_t.hpp"

#include "../include/stack_t.hpp"

#include "../include/queue_t.hpp"


// Unit Testing style tests

TEST_CASE( "The vector class tests basic operations", "[Vector_T]" ) 
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

  }

  SECTION("Reading and writting the vector") 
  {    
    std::cout << "\n\n TESTING THE VECTOR \n";
    v1[0] = 1;
    v1[1] = 2;
    std::cout << v1 << std::endl;
    
  }
}


TEST_CASE( "The doubly linked list basic tests", "[DLL_T]" ) 
{
    DLL_T<char> list1;
    
    REQUIRE(list1.empty() == true);

    SECTION("pushing nodes")
    {
      list1.push_front(new DLL_Node_T<char>('a'));
      list1.push_back(new DLL_Node_T<char>('b'));
    
      REQUIRE(list1.size() == 2);
      CHECK(list1.get_front()->get_value() == 'a' );
      CHECK(list1.get_back()->get_value() == 'b' );
    

      SECTION("One node is extracted from the back")
      {
        list1.extract_back();
        
        REQUIRE(list1.size() == 1);
        CHECK(list1.get_front()->get_value() == 'a');
        CHECK(list1.get_back()->get_value() == 'a');
        CHECK( list1.get_back()->get_value() ==
               list1.get_front()->get_value() );
        
      }
      SECTION("One node is extracted from the front")
      {
        list1.extract_front();

        REQUIRE(list1.size() == 1);
        CHECK(list1.get_front()->get_value() == 'b');
        CHECK(list1.get_back()->get_value() == 'b');
        CHECK( list1.get_back()->get_value() ==
               list1.get_front()->get_value() );
        
      }

      SECTION("A certain node can be searched in the list")
      {
        DLL_Node_T<char>* not_in = new DLL_Node_T<char>('c'); 

        DLL_Node_T<char>* yet_in = list1.get_front();
        
        CHECK(list1.contains(yet_in) == true);
        CHECK(list1.contains(not_in) == false);
      }

      SECTION("Reading a not empty list: ")
      {
        std::cout << "\n\nTESTING NOT EMPTY LIST" << std::endl;
        
        std::cout << list1 << std::endl;
      }
      SECTION("Reading an empty list: ")
      {
        std::cout << "\n\nTESTING  EMPTY LIST" << std::endl;
        //list1.write(std::cout);
        std::cout << list1 << std::endl;
      }
    }
    
  
}

TEST_CASE("The stack class tests basic operations", "[Stack_T]")
{
  Stack_T<int> stack1;

  SECTION("Basic Stack tests")
  {
    stack1.push(3);
    stack1.push(1);
    stack1.push(2);

    REQUIRE(stack1.empty() == false);
    REQUIRE(stack1.size() == 3);
    CHECK(stack1.top() == 2);

    SECTION("popping one element deacreases size and sets a different value at the top")
    {
      stack1.pop();
      REQUIRE(stack1.empty() == false);
      REQUIRE(stack1.size() == 2);
      CHECK(stack1.top() == 1);
      
    }
    SECTION("popping two element deacreases size and sets a different value at the top")
    {
      stack1.pop();
      stack1.pop();
      REQUIRE(stack1.empty() == false);
      REQUIRE(stack1.size() == 1);
      CHECK(stack1.top() == 3);    
    }

    SECTION("popping all the elements empties the stack")
    {
      stack1.pop();
      stack1.pop();
      stack1.pop();

      REQUIRE(stack1.empty() == true);
      REQUIRE(stack1.size() == 0);
      
    }

    SECTION("Reading and writting the stack") 
    {    
      std::cout << "\n\nTESTING THE NON EMPTY STACK \n";
      
      //stack1.write(std::cout);
      std::cout << stack1 << std::endl;
    
    }
  }

    SECTION("Reading and writting the stack") 
    {    
      std::cout << "\n\nTESTING THE EMPTY STACK \n";
      
      //stack1.write(std::cout);
      std::cout << stack1 << std::endl;
    
    }
}


TEST_CASE("The Queue class tests", "[Queue_T]")
{
  Queue_T<int> queue1;

  REQUIRE(queue1.empty() == true);

  SECTION("pushing elements to the queue increases the size and gives a certain order to them") 
  {
    queue1.push(1);
    queue1.push(2);
    queue1.push(3);

    REQUIRE(queue1.size() == 3);
    CHECK(queue1.front() == 1);
    CHECK(queue1.back() == 3);

    SECTION("popping one element deacreases the size in one unit")
    {
      queue1.pop();
      CHECK(queue1.size() == 2);
      
      CHECK(queue1.front() == 2);
      CHECK(queue1.back() == 3);
    }
  
    SECTION("Reading and writting the queue") 
    {    
      std::cout << "\n\nTESTING THE NON EMPTY STACK \n";
      
      //queue1.write(std::cout);
      std::cout << queue1 << std::endl;
    
    }
    SECTION("Reading and writting the queue after one element is pushed and the first is popped") 
    {    
      queue1.push(4);
      queue1.pop();
      std::cout << "\n\nTESTING THE NON EMPTY STACK -> rotating elements \n";
      
      //queue1.write(std::cout);
      std::cout << queue1 << std::endl;
    
    }

  }

    SECTION("Reading and writting the queue") 
    {    
      std::cout << "\n\nTESTING THE EMPTY STACK \n";
      
      queue1.write(std::cout);
      //std::cout << stack1 << std::endl;
    
    }

}