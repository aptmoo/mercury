#ifndef GDLL_MAIN_H
#define GDLL_MAIN_H

extern "C"  // Since we use dll func lookup, avoid cpp name scrambling
{
void* GDLL_GetInterface(void* appInterface);
}


#endif