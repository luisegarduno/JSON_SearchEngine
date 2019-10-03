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

    DSVector<DSString> v1;
    v1.pushBack("Hello");      // 0
    v1.pushBack("My");         // 1
    v1.pushBack("Name");       // 2
    v1.pushBack("Is");         // 3
    v1.pushBack("Luis");       // 4
    v1.pushBack("and");        // 5
    v1.pushBack("I");          // 6
    v1.pushBack("go");         // 7
    v1.pushBack("to");         // 8
    v1.pushBack("SMU");        // 9

    DSVector<DSString> v2;
    v2.pushBack("This");        // 0
    v2.pushBack("is");          // 1
    v2.pushBack("brand");       // 2
    v2.pushBack("new");         // 3
    v2.pushBack("END");         // 4

    SECTION("Overloaded Operators"){
        SECTION("+= Overload"){
            v1 += v2;

            REQUIRE(v1.elementIndex(0) == DSString("Hello"));
            REQUIRE(v2.elementIndex(0) == DSString("This"));
            REQUIRE(v1.elementIndex(10) == DSString("This"));
            REQUIRE(v1.elementIndex(14) == DSString("END"));
        }

        SECTION("= Overload"){
            DSVector<DSString> v3 = v1;
            //v1 = v2;
            //DSVector<DSString> v3 = v1 + v2;
        }

        SECTION("+ Overload"){

        }
    }

    SECTION("Size Operator"){
        REQUIRE(v1.getSize() == 10);           // Size should equal 15
        v1.pushBack("again");                  // data[15] = "again" & size increases
        REQUIRE(v1.getSize() == 11);
        v1.popBack();                          // popBack removes last item from data Array
        REQUIRE(v1.getSize() == 10);
        v1.popBack();
        v1.popBack();
        v1.popBack();
        REQUIRE(v1.getSize() == 7);            // after removing 3 items, data array should equal 12
    }

    SECTION("Swap Function"){                       // swap elements between 2 vectors
        v1.swap(v2);
        REQUIRE(v1.getSize() == 5);
        REQUIRE(v2.getSize() == 10);

        SECTION("Vector print"){                    // prints out specific element in vector
            REQUIRE(v2.elementIndex(0) == DSString("Hello"));
            REQUIRE(v2.elementIndex(9) == DSString("SMU"));
            REQUIRE(v1.elementIndex(0) == DSString("This"));
            REQUIRE(v1.elementIndex(4) == DSString("END"));
        }
    }

    SECTION("Clear Function"){                      // Empty's out Vector
        DSVector<int> v1;
        v1.pushBack(1);
        REQUIRE(v1.isEmpty() == false);
        v1.popBack();
        REQUIRE(v1.isEmpty() == true);
        v1.pushBack(1);
        v1.pushBack(2);
        v1.pushBack(3);
        v1.clearVector();
        REQUIRE(v1.isEmpty() == true);
    }
}

/*
TEMPLATE_TEST_CASE( "DSVectors can be sized and resized", "[DSVector][template]", int, DSString, (std::tuple<int,float>),DSVector<double>) {

    DSVector<DSString> v;

    REQUIRE( v.getSize() == 5 );
    REQUIRE( v.getCapacity() >= 5 );

    SECTION( "resizing bigger changes size and capacity" ) {
        v = 5;

        REQUIRE( v.getSize() == 10 );
        REQUIRE( v.getCapacity() >= 10 );
    }
    SECTION( "resizing smaller changes size but not capacity" ) {
        v = 0;

        REQUIRE( v.getSize() == 0 );
        REQUIRE( v.getCapacity() >= 5 );

        SECTION( "We can use the 'swap trick' to reset the capacity" ) {
            DSVector<DSString> empty;
            empty.swap( v );

            REQUIRE( v.getCapacity() == 0 );
        }
    }

    SECTION( "reserving smaller does not change size or capacity" ) {
        v = 0;

        REQUIRE( v.getSize() == 5 );
        REQUIRE( v.getCapacity() >= 5 );
    }

}
*/


