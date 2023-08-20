# Bronze

* [Circular Barn](../src/circularbarn.cpp)

* [Hungry Cow](../src/hungrycow.cpp)

* [Speeding Ticket](../src/speedingticket.cpp):
    * Use two pointers, one for Bessie and one for limit information
    * While traversing all ordered landmarks, decide whether the pointer of Bessie or the pointer of limit or both need to proceed
    * Pay attention that `>` or `<` should be used instead of `>=`, `<=` in line 46, 47
    * Keep track of all the landmarks (either Bessie or limit has new information)
    * Use `struct` instead of `pair` to make code more readable (without performance penalty)
