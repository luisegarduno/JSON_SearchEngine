#include <cstring>
#include "dsnode.h"
#include "catch.hpp"
#include "dsstack.h"
#include "dsvector.h"
#include "dsstring.cpp"
#include "dslinkedlist.h"

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
    }

    SECTION("c_str function"){
        REQUIRE(strcmp(s[0].c_str(), "testDSString") == 0);
        REQUIRE(strcmp(s[9].c_str(), s[0].c_str()) == 0);
        REQUIRE(strcmp(s[2].c_str(), "") == 0);
    }
}

TEST_CASE("DSVector class 1", "<DSString>"){

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
        SECTION("+= Overload Operator"){
            v1 += v2;

            REQUIRE(v1.elementIndex(0) == DSString("Hello"));
            REQUIRE(v1.elementIndex(10) == DSString("This"));
            REQUIRE(v1.elementIndex(14) == DSString("END"));
        }

        SECTION("Operator ="){
            REQUIRE(v1.elementIndex(0) == DSString("Hello"));
            v1.elementIndex(0) = v2.elementIndex(0);
            REQUIRE(v2.elementIndex(0) == DSString("This"));

            DSVector<DSString> v3 = v1;
            REQUIRE(v3.elementIndex(0) == DSString("This"));
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



TEST_CASE( "DSVector class 2", "<int>") {
    DSVector<int> v1(10);

    REQUIRE( v1.getSize() == 10);
    REQUIRE( v1.getCapacity() >= 10 );

    SECTION( "resizing bigger changes size and capacity" ) {                        // size & capacity get equally as big
        v1.assign(11,v1);

        REQUIRE( v1.getSize() == 11 );
        REQUIRE( v1.getCapacity() >= 11 );
    }
    SECTION( "resizing smaller changes size but not capacity" ) {
        v1.assign(0,v1);

        REQUIRE( v1.getSize() == 0 );
        REQUIRE( v1.getCapacity() >= 5 );

        SECTION( "We can use the 'swap trick' to reset the capacity" ) {
            DSVector<int> empty;
            empty.swap( v1 );

            REQUIRE( v1.getCapacity() == 5 );
        }
    }

    SECTION( "reserving smaller does not change size or capacity" ) {
        v1.reserve(0);

        REQUIRE( v1.getSize() == 10 );
        REQUIRE( v1.getCapacity() >= 10 );
    }

}

TEST_CASE("Doubly Linked List", "DSLinkedLists<T>"){
    DSLinkedList<int> newList;

    newList.append(2);
    newList.append(4);
    newList.append(6);
    newList.append(8);
    newList.append(10);
    newList.append(12);

    SECTION("Get at Index member function"){
        REQUIRE(newList.getAt(0) == 2);
        REQUIRE(newList.getAt(1) == 4);
        REQUIRE(newList.getAt(2) == 6);
        REQUIRE(newList.getAt(3) == 8);
        REQUIRE(newList.getAt(4) == 10);
        REQUIRE(newList.getAt(5) == 12);
    }

    SECTION("Remove a node at a specific index"){
        newList.removeAt(1);            // remove(1) = 4, so (1) now equals == 6
        REQUIRE(newList.getAt(1) == 6);
        newList.removeAt(0);            // remove(0) = 2, so (0) now equals == 6
        REQUIRE(newList.getAt(0) == 6);
        newList.removeAt(2);            // remove(2) = 10, so (2) now equals == 12
        REQUIRE(newList.getAt(2) == 12);
        newList.append(8);              // append 8 to end
        REQUIRE(newList.getAt(3) == 8);
        newList.removeAt(3);            // remove 8 from linkedlist
        newList.append(-1);             // append a negative number
        REQUIRE(newList.getAt(3) == -1);
        REQUIRE_FALSE(newList.getAt(3) == 0);

        SECTION("pop last node from Doubly Linked List"){
            newList.popLastNode(); // no memory leaks
            //newList.print();
        }
    }


    SECTION("Custom Iterator"){
        REQUIRE(newList.newIterator() == 2);
        REQUIRE(newList.getNext() == 4);

        newList.removeAt(0);
        REQUIRE(newList.newIterator() == 4);
        REQUIRE(newList.getNext() == 6);
        REQUIRE(newList.getNext() == 8);

        newList.newIterator() = newList.getNext();
        REQUIRE(newList.newIterator() == 10);
    }
}



TEST_CASE("DSStack", "DSStack<int>"){
    DSStack<int> newVector;

    newVector.push(2);
    newVector.push(4);
    newVector.push(6);
    newVector.push(8);
    newVector.push(10);
    newVector.push(12);

    SECTION("Empty Checker2"){
        REQUIRE(newVector.isEmpty() == false);
    }

    SECTION("Peek and pop"){
        REQUIRE(newVector.peek() == 12);
        REQUIRE(newVector.pop() == 12);


        REQUIRE(newVector.peek() == 10);
        REQUIRE(newVector.pop() == 10);

        REQUIRE(newVector.pop() == 8);
        REQUIRE(newVector.peek() == 6);

        REQUIRE(newVector.pop() == 6);
        REQUIRE(newVector.pop() == 4);

        REQUIRE(newVector.peek() == 2);
        REQUIRE(newVector.pop() == 2);

        SECTION("Empty Checker3"){
            REQUIRE(newVector.isEmpty() == true);
        }
    }
}



