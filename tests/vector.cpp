#include <catch.hpp>
#include <sstream>

#include "vector.hpp"

TEST_CASE("ptr == nullptr"){
 shared_ptr<int> sp1;
 REQUIRE (sp1.get() == nullptr);
}	

TEST_CASE("copy"){
shared_ptr<int> sp1(new int(6));
shared_ptr<int> sp2(new int(7));
REQUIRE(*sp1 == 6);
REQUIRE(*sp2 == 7);
}
TEST_CASE("swap"){
shared_ptr<int> sp1(new int(6));
shared_ptr<int> sp2(new int(7));
sp1.swap(sp2);
REQUIRE(*sp1 == 7);
REQUIRE(*sp2 == 6);		
}
TEST_CASE("reset"){
shared_ptr <int> sp1(new int(3));
sp1.reset(new int(6));
REQUIRE(*sp1 == 6);	
}
TEST_CASE("->number"){
shared_ptr<Mypair> sp1(new Mypair(1, 2));
REQUIRE(sp1->first == 1);
REQUIRE(sp1->second == 2);	
}
