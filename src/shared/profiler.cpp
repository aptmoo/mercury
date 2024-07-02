#include "profiler.h"

namespace hg
{
    void Profiler::BeginSession(const std::string& name, const std::string& filepath = "perf.json")
    {
        
    }

    void ProfilingTimer::Stop()
    {
        auto endTimePoint = std::chrono::high_resolution_clock::now();
        
        long long start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimePoint).time_since_epoch().count();
        long long end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();

        uint32_t threadID = std::hash<std::thread::id>{}(std::this_thread::get_id());

        m_IsStopped = true;
    }
} // namespace hg
