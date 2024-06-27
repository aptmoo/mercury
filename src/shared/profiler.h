#ifndef SHARED_INSTRUMENTOR_H
#define SHARED_INSTRUMENTOR_H
#include <string>
#include <chrono>

namespace hg
{
    using HighResTimePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;

    struct ProfileResult
    {

    };

    class ProfilingTimer
    {
    public:
        ProfilingTimer(const std::string& name)
            : m_Name(name)
        {
            m_StartTimePoint = std::chrono::high_resolution_clock::now();
        }

        ~ProfilingTimer()
        {
            if(!m_IsStopped)
            {
                Stop();
            }
        }

        void Stop()
        {
            HighResTimePoint endTymePoint = std::chrono::high_resolution_clock::now();
            
        }

    private:
        std::string m_Name;
        HighResTimePoint m_StartTimePoint;
        bool m_IsStopped;
    };

} // namespace hg


#endif