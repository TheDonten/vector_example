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
 std::string out{1---2---3---};
   std::ostringstream stream;
  q1.write(stream,q1.head_());
  REQUIRE(stream.str() == out);
}



