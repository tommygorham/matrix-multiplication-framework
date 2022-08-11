#ifndef TIMER_H
#define TIMER_H 

namespace TommysLib
{
    class Timer
    {
    public:
        Timer()  {
        m_start = std::chrono::high_resolution_clock::now(); 
        }

        ~Timer() {
            Stop();
        }

        void Stop() {
           auto end = std::chrono::high_resolution_clock::now();
           std::chrono::duration<double, std::milli> mstime = end - m_start; 
           std::cout << "\nThat took: " << mstime.count() << " milliseconds"; 
           //for microseconds:   std::chrono::duration<double, std::micro> microtime = end - m_start;
           // std::cout << "\nTimer Destructor called appropriately\n"; // can omit this, just here for testing
        }
    private: 
           std::chrono::time_point< std::chrono::high_resolution_clock> m_start;  
    }; 
} 
#endif 

