#ifndef GDLL_MAIN_H
#define GDLL_MAIN_H

extern "C"  // Since we use dll func lookup, avoid cpp name scrambling
{
void* GDLL_GetInterface();
void GDLL_SetInterface(void* iface); /* You should probably never change your appInterface or have multiple interfaces in general. Still, you can do it! */
}


#endif