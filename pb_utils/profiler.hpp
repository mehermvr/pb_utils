#pragma once
#include <chrono>
#include <string>
#include <utility>

namespace pb_utils {
class Profiler {
public:
  using Clock = std::chrono::high_resolution_clock;
  using TimePoint = Clock::time_point;

  explicit Profiler(std::string name_ = "Profiler", bool print_frequency = true)
      : name(std::move(name_)), print_frequency(print_frequency) {}
  void tick();
  void tock();

  double compute_average_time() const;
  double compute_frequency() const;
  ~Profiler();

private:
  std::string name;
  TimePoint start_time;
  double total_time{};
  size_t count = 0;
  bool print_frequency;
};
} // namespace pb_utils
