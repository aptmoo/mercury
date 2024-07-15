#ifndef GDLL_MAIN_H
#define GDLL_MAIN_H

extern "C"  // Since we use dll func lookup, avoid cpp name scrambling
{
/* Exchange interfaces with app */
void* GDLL_SetupInterfaces(void* iface);
}


#endif