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
    for (int i = 0; i < run_count; ++i) {
      SCOPED_PROFILER("10 Hz Simulation");
      simulate(10.0);
    }
  }
  // Test with 5 Hz frequency
  {
    for (int i = 0; i < run_count; ++i) {
      SCOPED_PROFILER("5 Hz Simulation");
      simulate(5.0);
    }
  }
  // Test with 10 Hz frequency
  {
    for (int i = 0; i < run_count; ++i) {
      SCOPED_PROFILER("10 Hz Simulation");
      simulate(10.0);
    }
  }
  // Test with 10 Hz frequency
  {
    for (int i = 0; i < run_count; ++i) {
      SCOPED_PROFILER("10 Hz Simulation");
      simulate(10.0);
    }
  }
}
