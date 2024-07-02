#include "args.h"

namespace hg
{
    Args::Args(int argc, const char** argv)
    {
        if(argc <= 1)
            return;

        for(int i = 1; i < argc; i++)
        {
            m_Args.push_back(std::string(argv[i]));
        }
    }
} // namespace hg
