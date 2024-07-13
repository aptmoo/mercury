#include "profiler.h"
#include <algorithm>

#include <iostream>

namespace hg
{
    void Profiler::BeginSession(const std::string& name, const std::string& filepath)
    {
        m_OutputStream.open(filepath);
        m_Name = name;
        WriteHeader();
    }

    void Profiler::EndSession()
    {
        std::cout << "called endSession\n";
        WriteFooter();

        m_Name = "none";
        m_ProfileCount = 0;
        m_OutputStream.close();
    }

    void Profiler::WriteResult(const ProfileResult& result)
    {
        if(m_ProfileCount++)
        {
            m_OutputStream << ",";
        }

        // TODO: sanitize util func
        std::string name = result.Name;
        std::replace(name.begin(), name.end(), '"', '\"');

        m_OutputStream << "{";
        m_OutputStream << "\"cat\":\"function\",";
        m_OutputStream << "\"dur\":" << (result.End - result.Start) << ',';
        m_OutputStream << "\"name\":\"" << name << "\",";
        m_OutputStream << "\"ph\":\"X\",";
        m_OutputStream << "\"pid\":0,";
        m_OutputStream << "\"tid\":" << result.ThreadID << ",";
        m_OutputStream << "\"ts\":" << result.Start;
        m_OutputStream << "}";

        m_OutputStream.flush();
    }

    void Profiler::WriteHeader()
    {
        m_OutputStream << "{\"otherData\": {},\"traceEvents\":[";
        m_OutputStream.flush();
    }

    void Profiler::WriteFooter()
    {
        std::cout << "Called WriteFooter!\n";
        m_OutputStream << "]}";
        m_OutputStream.flush();
    }

    void ProfilingTimer::Stop()
    {
        auto endTimePoint = std::chrono::high_resolution_clock::now();
        
        long long start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimePoint).time_since_epoch().count();
        long long end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();

        uint32_t threadID = std::hash<std::thread::id>{}(std::this_thread::get_id());
        Profiler::Get().WriteResult({m_Name, start, end, threadID});

        m_IsStopped = true;
    }
} // namespace hg
