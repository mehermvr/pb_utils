#include "pb_utils/profiler.hpp"
#include <thread>

void simulate(double frequency) {
  std::chrono::milliseconds sleep_duration(static_cast<int>(1e3 / frequency));
  std::this_thread::sleep_for(sleep_duration);
}

int main() {
  const int run_count = 5;
  // Test with 10 Hz frequency
  {
    pb_utils::Profiler profiler("10 Hz Simulation");
    for (int i = 0; i < run_count; ++i) {
      profiler.tick();
      simulate(10.0);
      profiler.tock();
    }
  }
  // Test with 5 Hz frequency
  {
    pb_utils::Profiler profiler("5 Hz Simulation");
    for (int i = 0; i < run_count; ++i) {
      profiler.tick();
      simulate(5.0);
      profiler.tock();
    }
  }
  // Test with 1 Hz frequency
  {
    pb_utils::Profiler profiler("1 Hz Simulation");
    for (int i = 0; i < run_count; ++i) {
      profiler.tick();
      simulate(1.0);
      profiler.tock();
    }
  }
}
