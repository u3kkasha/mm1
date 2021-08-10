#if not defined (DEBUGGING_OPTIONS_GUARD)
#define DEBUGGING_OPTIONS_GUARD

/*
بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْم

+Name: debugging options
+Type: Macro Library
+ Version: 6 Dhul Hijjah 1442 Hijri
+Purpose: The purpose of this micro library is to aid the programmer during the working by providing various options

+Dependencies: None
+Author: 215

+Usage:
In order to activate debugging options include this library in your file #include "debugging_options.macro"


*/



#include<iostream> //for std::cout

/*
+Purpose:
It prints information regarding any variable in the console along with its name, value, line_number and function where it was used.

+Dependencies: None
+Author: 215
+Parameter: variable whose data is to be output
+Usage:
int count=78;
DEBUGGING_PRINT(count);

sample output:
count= 78 from line number-12 inside the function  main()


+Mechanism:
The #operator converts a token into a string,
hence #count="count"

so we are printing the variable's name followed by the it's value, line_number and the function in which DEBUGGING_PRINT was used.

And Allah knows best

*/


#define DEBUGGING_PRINT( variable )  std::cout<< #variable <<"= "<<variable<<" from line number-"<< __LINE__<<" inside the function  "<<__FUNCTION__<<"()\n";







#endif // end of guard