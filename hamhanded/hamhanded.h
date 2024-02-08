#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

extern int hhAdd(int a, int b);
extern int hhCalcOld(const char* str);
extern int hhCalc(const char* str);
extern long double hhCalcAddFloat(const char* str);
extern long double hhCalcFloat(const char* str);
extern int q();
