#include <catch.hpp>
#include <sstream>

#include "vector.hpp"

TEST_CASE("create queue_t"){
 queue_t<int> q1;
 REQUIRE(q1.head_() == nullptr);    
 REQUIRE(q1.tail_() == nullptr);
 }
TEST_CASE("push queue"){
 queue_t<int> q1;
 q1.push(1);
 q1.push(2);
 q1.push(3);
 std::string out{"1---2---3---"};
 std::ostringstream stream;
 q1.write(stream,q1.head_());
 REQUIRE(stream.str() == out);
}
TEST_CASE("pop_back"){
queue_t<int> q1;
q1.push(1);
q1.push(2);
REQUIRE( q1.pop_back() == 1 );
REQUIRE( q1.pop_back() == 2 );	
}
TEST_CASE("error pop"){
 queue_t<int> q1;
 REQUIRE_THROWS_AS( q1.pop_back(), std::logic_error );
}
TEST_CASE(" q1=q2"){
  queue_t<int> q1;
  queue_t<int> q2;
  std::string out{"5---6---7---"};
  q1.push(1);
  q1.push(2);
  q1.push(3);
  q2.push(5);
  q2.push(6);
  q2.push(7);
  q1 = q2;
  std::ostringstream stream;
  q1.write(stream,q1.head_());
  REQUIRE(stream.str() == out);
  }
