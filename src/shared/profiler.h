#ifndef SHARED_INSTRUMENTOR_H
#define SHARED_INSTRUMENTOR_H
#include <string>
#include <chrono>
#include <thread>

namespace hg
{
    struct ProfileResult
    {
        std::string Name;
        long long Start, End;
        uint32_t ThreadID;
    };

    class Profiler
    {
    public:
        void BeginSession(const std::string& name, const std::string& filepath = "perf.json");
        void EndSession();

        static Profiler& Get(){ return s_Instance; }
    private:
        Profiler()
        
        {}

        static Profiler s_Instance;
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

        void Stop();
    private:
        std::string m_Name;
        std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimePoint;
        bool m_IsStopped;
    };

} // namespace hg


#endif