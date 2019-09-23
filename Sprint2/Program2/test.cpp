#include <cstring>
#include "catch.hpp"
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
    s[7] = DSString(" split  split  split ");
    s[8] = DSString("                     ");
    s[9] = DSString("testDSString");

    SECTION("Equality operators"){
        REQUIRE(s[0] == DSString("testDSString"));
        REQUIRE(s[0] == s[9]);
        REQUIRE(s[2] == "");
        REQUIRE(s[1] == "a test DSString");
        REQUIRE(!(s[3] == s[4]));
    }
}
