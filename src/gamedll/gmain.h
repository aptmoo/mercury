#ifndef GDLL_MAIN_H
#define GDLL_MAIN_H

namespace hg { class IAppInterface; }
extern hg::IAppInterface* s_AppInterface;   // TODO: This name kind of sucks?

extern "C"  // Since we use dll func lookup, avoid cpp name scrambling
{
/* Exchange interfaces with app */
void* GDLL_SetupInterfaces(void* iface);
}


#endif