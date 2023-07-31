#include "shared.h"
#include <limits.h>
#ifndef UTILITY_H
#define UTILITY_H

/* the default line length for input / output */
#define LINELEN 80

/* the last two characters required in a string as returned from fgets */
#define EXTRACHARS 2

/* newline character required for I/O functions */
#define NEWLINE '\n'
typedef enum
{
        FAILURE, SUCCESS, EXIT
} INPUT_RESULT;
void read_rest_of_line(void);
INPUT_RESULT fgetsChecker(char* input,int inputsize);
#endif /* ifndef UTILITY_H */
