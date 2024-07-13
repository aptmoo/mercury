#ifndef SHARED_APPLICATION_H
#define SHARED_APPLICATION_H

namespace hg
{
    class IBaseApplication
    {
    public:
        /**
         * @brief Run this application.
         */
        virtual void Run() = 0;

        /**
         * @brief Get the current instance.
         * 
         * @return IBaseApplication* 
         */
        static IBaseApplication* GetInstance();
    };
} // namespace hg


#endif