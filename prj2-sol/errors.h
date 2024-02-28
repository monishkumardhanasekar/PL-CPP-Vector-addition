#ifndef ERRORS_H_
#define ERRORS_H_

#include <cstdio>
#include <cstdarg>
#include <cstdlib>

/** print message specified by fmt, ... + "\n" on stderr and exit */
void error(const char *fmt, ...);

/** print message specified by fmt, ... + "\n" on stderr and exit */
void panic(const char *fmt, ...);

#endif // ERRORS_H_
