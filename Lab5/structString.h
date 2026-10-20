/* `structString.h`

    *FOR STUDENTS*    

    Name:
    Student ID:
    Lab section:
*/

#ifndef STRUCT_STRING_H 
#define STRUCT_STRING_H

#include <stddef.h> //For `size_t`.
#include <stdbool.h> //For `bool`, `true`, and `false`.


struct String {
    char* cstring; //Either `NULL` or 
                   //the address to a dynamically allocated null-terminated array of `char`s.
    size_t length; //Either `0` or
                   //the string length of the string stored in the dynamically allocated array.
    
    size_t capacity; //Either `0` or
                     //The length of the dynamically allocated array.
}; 




/* `String_create_arr`
    Create a dynamically allocated array of "empty" `struct String` elements.

    Parameters:
        arrLength: The length of the array.

    Preconditions: 
        - `arrLength` is a (strictly) positive integer.

    Postconditions:
        - If possible, an array of `arrLength` `struct String` objects each representing 
          an "empty" String is dynamically allocated. An "empty" String is represented
          by a value of `NULL` for the member `cstring`, and a value of `0` for the members 
          `length` and `capacity`.

        - The said allocation must later be deallocated via a call to `String_destroy_arr`.

    Returns:
        - The address to the dynamically allocated array if allocation is successful; or
        
        - `NULL` if allocation is unsuccessful.
*/
struct String* String_create_arr(size_t arrLength);




    /* `String_set_cstring`
        Create a copy of a C string onto the heap for a `struct String`.

        Parameters:
            p2String: Pointer to a `struct String` object.

            newCString: The null-terminated array of `char`s to be copied.
            
        Preconditions:
            - `newCString` points to a valid null-terminated array of `char`s.

            - `p2String` points to a valid `struct String` object whose creation and
              member updates have been through functions in this library. In particular,
              the `cstring` member must be `NULL` or point to a dynamically allocated block.

            - If the member `cstring` of `struct String` points to an array,
              the said array and the `newCString` array are nonoverlapping. 

        Returns:
            - `true` if the contents of newCString are successfully copied
            - `false` dynamic memory allocation for the copy fails.

        Postconditions:
            - If `capacity` is strictly greater than the string length of `newCString`,
                - `newCString` characters (including the null terminator) are copied into the 
                  array to which the member `cstring` points.
                - The address stored in the member `cstring` remains unchanged.
                - The member `length` stores the string length of `newCString`.

            - If `capacity` is less than or equal to the string length of `newCString`,
                - The function attempts a dynamic allocation of the smallest power of 2 that is
                  at least 8 and is strictly greater than the string length of `newCString`. 
                  More concisely, an allocation of $2^k$ bytes is attempted 
                  where $k := \min \{i \ge 3 : 2^i > strlen(newCString) \}$.
                
                - If the allocation is unsuccessful, the function is a no-op. 

                - If allocation is successful,
                    - The member `cstring` points to the dynamically allocated array.

                    - The member `capacity` is increased to $2^k$.

                    - Any previously owned allocation is deallocated.

                    - `newCString` characters (including the null terminator) are copied into the 
                      new dynamically allocated array.
                
                    - The member `length` stores the string length of `newCString`.

                    - The dynamically allocated array must be later freed via a call to a function in this library:
                        - A call to `String_destroy_arr`; or
                        - A subsequent successful call to a function that triggers resizing; or
                        - A call to `String_del_cstring`.

            - The function does not take ownership of the memory pointed to by `newCString`.        
    */
    bool String_set_cstring(struct String* p2String, const char* newCString);




/* `String_del_cstring`
    Set the members of a `struct String` object to represent no string.

    Parameters:
        p2String: Pointer to a `struct String` object.

    Preconditions:
        - `p2String` points to a valid `struct String` object whose creation and
          member updates have been through functions in this library. In particular,
          the `cstring` member must be `NULL` or what it points to must be dynamically allocated.

    Postconditions:
        - The memory block to which `cstring` previously pointed is freed. This is a no-op if 
              the old `cstring` value was `NULL`.

        - The value `NULL` is assigned to the member `cstring`.

        - The value `0` is assigned to the member `length`.

        - The value `0` is assigned to the member `capacity`.
*/
void String_del_cstring(struct String* p2String);






/* `String_destroy_arr`
    Destroy a dynamically allocated array of `struct String` elements.

    Parameters:
        arrLength: The length of the array.

        arr: The dynamically allocated array of `struct String` elements.

    Preconditions:
        - `arr` is `NULL` or points to a valid dynamically allocated array of `struct String` elements.

        - `arrLength` is the length of the dynamically allocated array. (Immaterial if `arr` is `NULL`.)

        - The elements' creation and member updates have been through functions in this library. 
          In particular, for each element, the `cstring` member must be `NULL` or what it points to 
          must be dynamically allocated; and no two elements' `cstring` members point to the same 
          allocated block.

    Postconditions:
        - The memory blocks to which `cstring` members point are freed. 
          This is a no-op if `cstring` values are `NULL`.

        - The dynamically allocated block to which `arr` points is freed.

    Notes:
        - All preconditions are satisfied if
            - `arr` is the return value of a call to `String_create_arr`; and
            - The struct member updates have been through functions in this library.

        - The function is a no-op if `arr` is `NULL`.
*/
void String_destroy_arr(size_t arrLength, struct String* arr);




/* `String_cat_cstring`
    Concatenate a C string to a `struct String`.

    Parameters:
        p2String: Pointer to a `struct String` object.

        newCString: The null-terminated array of `char`s to be concatenated.
            
    Preconditions:
        - `newCString` points to a valid null-terminated array of `char`s.

        - `p2String` points to a valid `struct String` object whose creation and
        member updates have been through functions in this library. In particular,
        the `cstring` member must be `NULL` or point to a dynamically allocated block.

        - If the member `cstring` of `struct String` points to an array,
            the said array and the `newCString` array are nonoverlapping.

    Returns:
        - `true` if the contents of newCString are successfully concatenated.
        - `false` if dynamic memory allocation for the copy fails.

    Notes:
        - In this documentation "unused capacity" is defined to be
            - 0 if the member `capacity` is 0; or
            - `capacity - (length + 1)` otherwise.

    Postconditions:
        - If the string length of `newCString` is 0,
            - The function is a no-op and returns `true`.
        - If unused capacity is greater than or equal to the nonzero string length of `newCString`,
            - `newCString` characters (including the null terminator) are concatenated to 
               what `cstring` points to.
            - The address stored in the member `cstring` remains unchanged.
            - The member `length` is increased by the string length of `newCString`.

        - If unused capacity is less than the nonzero string length of `newCString`,
            - The function attempts a dynamic allocation of the smallest power of 2 that is
                at least 8 and is strictly greater than the string length of the concatenation. 
                More concisely, an allocation of $2^k$ bytes is attempted 
                where $k := \min \{i \ge 3 : 2^i > strlen(newCString) + length \}$.
            
            - If the allocation is unsuccessful, the function is a no-op. 

            - If allocation is successful,
                - The member `cstring` points to the concatenation.

                - The member `capacity` is increased to $2^k$.

                - Any previously owned allocation is deallocated.
            
                - The member `length` stores the string length of the concatenation.

                - The dynamically allocated array must be later freed via a call to a function in this library:
                    - A call to `String_destroy_arr`; or
                    - A subsequent successful call to a function that triggers resizing; or
                    - A call to `String_del_cstring`.
*/
bool String_cat_cstring(struct String* p2String, const char* newCString);




#endif







