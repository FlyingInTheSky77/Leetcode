// g++ -o speed_meter 0_helper_1_speed_meter.cpp -lboost_chrono -lboost_system

#include <iostream>
#include <boost/chrono.hpp>
#include <boost/chrono/chrono_io.hpp> // For pretty printing

typedef boost::chrono::high_resolution_clock Clock;

/*Usage:
1) use start() - to start measure the time, restart() - to restart measure the time and stop() - to stop and show time duration.
2) don't look at time Duration in destructor (that's why I commented out the time output there)
3) time difference less than 0.1 microseconds (0.06 or 0.07) - not important:
   if you got for one code(1) duration of 0.05 microseconds, and for another code(2) duration of 0.06 microseconds - consider,
   that duration of 0.1 and the running time of the first(1) and second(2) code are equal to each other.
   This is relevant for my computer based on the testing below - see the commented code in this file
*/

class Speed_meter {
public:
    void start() {
        start_ = Clock::now();
        // std::cout << boost::chrono::duration_long << start_ << std::endl;
    }
    void restart() {
        start_ = Clock::now();
    }
    void stop() {
        Clock::time_point end = Clock::now();
        boost::chrono::duration<double, boost::chrono::microseconds::period> duration_us = end - start_;
        std::cout << "Time taken: " << duration_us.count() << " microseconds" << std::endl;
    }
    ~Speed_meter() {
        // Clock::time_point end = Clock::now();
        // boost::chrono::duration<double, boost::chrono::microseconds::period> duration_us = end - start_;
        // std::cout << "~Speed_meter: Time taken: " << duration_us.count() << " microseconds" << std::endl;
    }
private:
    Clock::time_point start_;
};


//Testing:
/*int main() {
    Speed_meter sp;
    sp.start();
    sp.restart();
    sp.stop();
    sp.restart();
    sp.stop();
    sp.restart();
    sp.stop();
}*/

/* Results of testing on my laptop:

../Leetcode/Algorithms$ ./speed_meter
Time taken: 0.075 microseconds
Time taken: 0.043 microseconds
Time taken: 0.05 microseconds
~Speed_meter: Time taken: 2.502 microseconds

../Leetcode/Algorithms$ ./speed_meter
Time taken: 0.08 microseconds
Time taken: 0.043 microseconds
Time taken: 0.045 microseconds
~Speed_meter: Time taken: 2.428 microseconds

../Leetcode/Algorithms$ ./speed_meter
Time taken: 0.078 microseconds
Time taken: 0.048 microseconds
Time taken: 0.043 microseconds
~Speed_meter: Time taken: 2.329 microseconds
*/
