#include "timer.hpp"
#include <iostream>

namespace pb_utils {
Timer::~Timer() {
  auto end_time = Clock::now();
  Duration duration = end_time - start_time;
  std::cout << label << " took " << duration.count() << " seconds.\n";
}
} // namespace pb_utils
