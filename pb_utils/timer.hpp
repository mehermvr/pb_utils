#pragma once
#include <chrono>
#include <string>

namespace pb_utils {
struct Timer {
  using Clock = std::chrono::high_resolution_clock;
  using TimePoint = std::chrono::time_point<Clock>;
  using Duration = std::chrono::duration<double>;

  Timer() : label("Execution"), start_time(Clock::now()) {}
  explicit Timer(const std::string& label) : label(label), start_time(Clock::now()) {}
  Timer(const Timer&) = default;
  Timer(Timer&&) = default;
  Timer& operator=(const Timer&) = default;
  Timer& operator=(Timer&&) = default;
  ~Timer();

  std::string label;
  TimePoint start_time;
};
} // namespace pb_utils
