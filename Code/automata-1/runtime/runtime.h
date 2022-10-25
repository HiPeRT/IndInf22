#ifndef _RUNTIME_H_
#define _RUNTIME_H_

#include <string>

/*
 * Gets next inputs, or 'x' if no inputs available.
 * WARNING: this function shifts the input, once you call it!
 */
char nextChar(const char* inputs);

void debug();

void write(std::string);

#endif
