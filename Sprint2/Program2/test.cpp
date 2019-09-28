#include <cstring>
#include "catch.hpp"
#include "dsvector.h"
#include "dsstring.cpp"


TEST_CASE("DSString class", "[DSString]"){

    DSString s[10];
    s[0] = DSString("testDSString");
    s[1] = DSString("a test DSString");
    s[2] = DSString("");
    s[3] = DSString("THIS IS AN UPPERCASE DSSTRING");
    s[4] = DSString("this is an uppercase DSString");
    s[5] = DSString("\n");
    s[6] = DSString("");
    s[7] = DSString("  split  split  split  ");
    s[8] = DSString("                          ");
    s[9] = DSString("testDSString");

    SECTION("Equality operators"){
        REQUIRE(s[0] == DSString("testDSString"));
        REQUIRE(s[0] == s[9]);
        REQUIRE(s[2] == DSString(""));
        REQUIRE(s[1] == DSString("a test DSString"));
        REQUIRE(!(s[3] == s[4]));
    }

    SECTION("Assignment operators"){
        DSString str;
        str = "a test DSString";
        REQUIRE(str == s[1]);
        str = DSString("testDSString");
        REQUIRE(str == s[0]);
        str = "";
        REQUIRE(str == s[6]);
        str = DSString("\n");
        REQUIRE(str == s[5]);
    }

    SECTION("Addition operator"){
        REQUIRE(DSString("testDSStringtestDSString") == s[0]+s[9]);
        REQUIRE(s[6] + s[6] == DSString(""));
        REQUIRE(s[5] + s[6] == DSString("\n"));
        REQUIRE(s[0] + s[1] + s[2] == DSString("testDSStringa test DSString"));
    }

    SECTION("Less than operator"){
        REQUIRE(s[0] < s[1]);
        REQUIRE(s[4] < s[3]);
        REQUIRE(s[6] < s[9]);
        REQUIRE(s[6] < s[7]);
    }

    SECTION("[] Operator"){
        REQUIRE(s[0][1] == 'e');
        REQUIRE(s[4][4] == ' ');
        REQUIRE(s[6][0] == 0);
    }

    SECTION("size function"){
        REQUIRE(s[9].size() == 12);
        REQUIRE(s[2].size() == 0);
        REQUIRE(s[8].size() == 26);
        REQUIRE(s[3].size() == 29);
    }

    SECTION("DSSubstring function"){
        REQUIRE(s[0].substring(0, 5) == DSString("testD"));
        REQUIRE(s[4].substring(0, 4) == DSString("this"));
        //REQUIRE(s[1].substring(6, -4) == DSString("test"));
        REQUIRE(s[4].substring(1, 3) == DSString("his"));
    }

    SECTION("c_str function"){
        REQUIRE(strcmp(s[0].c_str(), "testDSString") == 0);
        REQUIRE(strcmp(s[9].c_str(), s[0].c_str()) == 0);
        REQUIRE(strcmp(s[2].c_str(), "") == 0);
    }

}

TEST_CASE("DSVector class", "[DSVector]"){

    DSVector<DSString> aVector;
    aVector.pushBack("Hello");
    aVector.pushBack("My");
    aVector.pushBack("Name");
    aVector.pushBack("Is");
    aVector.pushBack("Luis");
    aVector.pushBack("Garduno");
    aVector.pushBack("and");
    aVector.pushBack("I");
    aVector.pushBack("go");
    aVector.pushBack("to");
    aVector.pushBack("SMU");
    aVector.pushBack("in");
    aVector.pushBack("Dallas");
    aVector.pushBack("Texas");
    aVector.pushBack("end");
}

/*
TEMPLATE_TEST_CASE( "DSVectors can be sized and resized", "[DSVector][template]", int, DSString, (std::tuple<int,float>),DSVector<double>) {

    DSVector<TestType> v( 5 );

    REQUIRE( v.size() == 5 );
    REQUIRE( v.capacity() >= 5 );

    SECTION( "resizing bigger changes size and capacity" ) {
        v.resize( 10 );

        REQUIRE( v.size() == 10 );
        REQUIRE( v.capacity() >= 10 );
    }
    SECTION( "resizing smaller changes size but not capacity" ) {
        v.resize( 0 );

        REQUIRE( v.size() == 0 );
        REQUIRE( v.capacity() >= 5 );

        SECTION( "We can use the 'swap trick' to reset the capacity" ) {
            std::vector<TestType> empty;
            empty.swap( v );

            REQUIRE( v.capacity() == 0 );
        }
    }
    SECTION( "reserving smaller does not change size or capacity" ) {
        v.reserve( 0 );

        REQUIRE( v.size() == 5 );
        REQUIRE( v.capacity() >= 5 );
    }
}
*/

