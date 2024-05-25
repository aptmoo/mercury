#ifndef SHARED_ARGS_H
#define SHARED_ARGS_H
#include <vector>
#include <string>

namespace hg
{
    class CArgs
    {
    public:
        /**
         * @brief Args constructor.
         * It's a good practice to pass argv and argc from main without any processing.
         * 
         * @param argc 
         * @param argv 
         */
        CArgs(int argc, const char** argv);
        ~CArgs(){};

        std::size_t Size()
        {
            return m_Args.size();
        }

        const std::string& at(std::size_t i)
        {
            return m_Args.at(i);
        }

        const std::string& operator[](std::size_t i)
        {
            return this->at(i);
        }

    private:
        std::vector<std::string> m_Args;
    };
} // namespace hg

#endif