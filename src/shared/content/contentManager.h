#ifndef SHARED_CONTENTMANAGER_H
#define SHARED_CONTENTMANAGER_H
#include "core/types.h"
#include <string>

namespace hg
{
    class ContentManager
    {
    public:
        ContentManager();
        ~ContentManager();

        template<typename T>
        Ref<T> Load(const std::string& name);

        bool Exists(const std::string& name);

        /**
         * @brief Lock or unlock mutex.
         * This exists to avoid resources being unloaded during rendering or updating.
         * Something can stop using a resource during a tick/frame,
         * and something else may use it again later during the same tick/frame.
         * Unloading and then loading this resource is wasteful performance wise, and may cause artifacts or crashes
         * if done during a rendering frame.
         * 
         */
        void Lock();
        void Unlock();
    private:

    };
} // namespace hg


#endif