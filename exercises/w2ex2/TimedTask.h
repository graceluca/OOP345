#include <iostream>
#include <chrono>
namespace seneca {
    class TimedTask {
        constexpr std::size_t MAX_TASKS = 10;
        private:
            std::size_t m_numTasks{ 0 };
            std::chrono::steady_clock::time_point m_startTime;
            std::chrono::steady_clock::time_point m_endTime;
            struct Task {
                std::string m_description{};
                std::string m_unit{};
                std::chrono::steady_clock::duration m_duration{};
            } m_tasks[MAX_TASKS];
        public:
            TimedTask() = default;
            void startClock();
            void stopClock();
            void addTask(const char* c);
            friend std::ostream& operator<<(std::ostream& os, const TimedTask& task);
    };
}