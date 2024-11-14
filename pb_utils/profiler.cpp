#include "profiler.hpp"
#include <format>
#include <iostream>

namespace pb_utils {
void Profiler::tick() { start_time = Clock::now(); };
void Profiler::tock() {
  total_time += std::chrono::duration<double>(Clock::now() - start_time).count();
  ++count;
};

double Profiler::compute_average_time() const {
  return count > 0 ? (total_time / std::nano::den) / static_cast<double>(count) : 0;
}
double Profiler::compute_frequency() const {
  const double average_time = compute_average_time();
  return average_time > 0 ? (1.0 / average_time) : 0.0;
}
Profiler::~Profiler() {
  std::cout << name << " - Profiling results:\nExecution count: " << count
            << "\nAverage time: " << std::format("{:.2f}", compute_average_time() * 1e3) << "ms." << std::endl;
  if (print_frequency) {
    std::cout << "Average Frequency: " << std::format("{:.2f}", compute_frequency()) << "Hz." << std::endl;
  }
}
} // namespace pb_utils
