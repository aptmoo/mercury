#ifndef SHARED_INSTRUMENTOR_H
#define SHARED_INSTRUMENTOR_H
#include <string>
#include <chrono>
#include <thread>
#include <fstream>

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
        void BeginSession(const std::string& name, const std::string& filepath = "profile.json");
        void EndSession();

        void WriteResult(const ProfileResult& result);

        void WriteHeader();
        void WriteFooter();

        static Profiler& Get(){ return s_Instance; }
    private:
        Profiler()
            : m_ProfileCount{0}
        {}

        std::ofstream m_OutputStream;
        std::string m_Name;
        int m_ProfileCount;
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

// TODO: stuff
#ifndef NDEBUG
#define HG_PROFILE_BEGIN_SESSION(name, filepath)    hg::Profiler::Get().BeginSession(name, filepath)
#define HG_PROFILE_END_SESSION()                    hg::Profiler::Get().EndSession()
#define HG_PROFILE_SCOPE_NAMED(name)                hg::ProfilingTimer timer##name(#name)
#define HG_PROFILE_FUNCTION()                       HG_PROFILE_SCOPE_NAMED(__FUNCTION__)
#else
#define HG_PROFILE_BEGIN_SESSION(name, filepath)
#define HG_PROFILE_END_SESSION()
#define HG_PROFILE_SCOPE_NAMED(name)
#define HG_PROFILE_FUNCTION()
#endif

#endif