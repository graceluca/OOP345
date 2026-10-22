#include <iostream>
#include <iomanip>
#include <chrono>
#include "TimedTask.h"
namespace seneca {
    void TimedTask::startClock() {
            m_startTime = std::chrono::steady_clock::now();
    }
    void TimedTask::stopClock() {
        m_endTime = std::chrono::steady_clock::now();
    }
    void timedTask::addTask(const char* c) {
        auto length = std::chrono::duration_cast<std::chrono::nanoseconds>(m_endTime - m_startTime);
        if (m_numTasks < MAX_TASKS) {
            this->m_tasks[m_numTasks].m_description = c;
            this->m_tasks[m_numTasks].m_unit = "nanoseconds";
            this->m_tasks[m_numTasks].m_duration = length;
        }
    }
    std::ostream& timedTask::operator<<(std::ostream& os, const TimedTask& task) {
        os 
            << "Execution Times:" << std::endl
            << "--------------------------" << std::endl;
        for (std::size_t i = 0; i < m_numTasks; i++) {
            os 
                << std::setw(21) << std::left 
                << tasks.m_tasks[i].m_description << ' ' 
                << std::right << std::setw(3)
                << tasks.m_tasks[i].m_duration 
                << ' '
                << tasks.m_unit << std::endl;
        }
        os << "--------------------------" << std::endl;
    }
}