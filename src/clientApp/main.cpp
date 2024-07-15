
#include "shared/args.h"
#include "shared/profiler.h"

#include <iostream>
int main(int argc, char const *argv[])
{
    hg::ParsedArgs args(argc, argv);
    HG_PROFILE_BEGIN_SESSION("mainProfile", args.GetOrDefault("profile", "profile.json"));

    HG_PROFILE_END_SESSION();
    return 0;
}
