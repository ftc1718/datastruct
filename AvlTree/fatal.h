#ifndef FATAL_H_INCLUDED
#define FATAL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define Error(str) FatalError(str)
#define FatalError(str) fprintf(stderr, "%s\n", str), exit(1)


#endif // FATAL_H_INCLUDED
