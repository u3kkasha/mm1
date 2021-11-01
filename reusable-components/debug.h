#if not defined(DEBUGGING_OPTIONS_GUARD)
#define DEBUGGING_OPTIONS_GUARD

/*
بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْم

+Name: debugging options
+Type: Macro Library
+Version: 11 Muharram 1443 Hijri
+Purpose: The purpose of this macro library is to aid the programmer by
providing various debugging options in sha Allah +Dependencies: None +Author:
215


*/

#include <iostream> //for std::cout

/*
+Purpose:
It prints information regarding any variable in the console along with its name,
value, line_number, function and file where it was used.

+Dependencies: None
+Author: 215
+Parameter: variable whose data is to be output
+Usage:
int count=78;
DEBUGGING_PRINT(count);

+Mechanism:
The #operator converts a token into a string,
hence #count="count"

so we are printing the variable's name followed by the it's value, line_number
and the function and file in which DEBUGGING_PRINT was used.

And Allah knows best

*/

#define DEBUGGING_PRINT(variable)                                              \
  std::cout << #variable << "= " << variable << " from line number-"           \
            << __LINE__ << " inside the function  " << __FUNCTION__ << "() "   \
            << "__FILE__" << std::endl;

#endif // end of guard