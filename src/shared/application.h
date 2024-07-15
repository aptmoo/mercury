#ifndef SHARED_APPLICATION_H
#define SHARED_APPLICATION_H
#include "types.h"
#include "args.h"
#include <string>

namespace hg
{
    struct BaseAppDesc
    {
        BaseAppDesc(std::string name = "", int width = 1280, int height = 720, ParsedArgs& args)
            : Name{name}, Width{width}, Height{height}, Args{args}
        {}

        std::string Name;
        int Width, Height;

        ParsedArgs& Args;
    };
    

    class IBaseApplication
    {
    public:
        virtual ~IBaseApplication() = default;

        // Application classes shouldn't be copied
        IBaseApplication(const IBaseApplication&) = delete;

        /**
         * @brief Run this application.
         */
        virtual void Run() = 0;

        /**
         * @brief Get or set the current instance.
         * 
         * @return IBaseApplication* 
         */
        static IBaseApplication& GetInstance() { return *s_Instance; };
        static void SetInstance(IBaseApplication* ptr) { s_Instance = ptr; };

        // Unsafe
        // static IBaseApplication* GetInstancePtr() { return s_Instance; };
    private:
        static IBaseApplication* s_Instance;
    };
} // namespace hg


#endif