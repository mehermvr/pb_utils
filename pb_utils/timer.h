#pragma once
#include <chrono>
#include <iostream>
#include <string>

namespace pb_utils {
class Timer {
private:
  using Clock = std::chrono::high_resolution_clock;
  using TimePoint = std::chrono::time_point<Clock>;
  using Duration = std::chrono::duration<double>;

  std::string _label;
  TimePoint _start_time;
  TimePoint _tick;

public:
  Timer() : _label("Execution"), _start_time(Clock::now()) {}
  explicit Timer(const std::string& label) : _label(label), _start_time(Clock::now()), _tick(Clock::now()) {}

  /* default other stuff */
  Timer(const Timer&) = default;
  Timer(Timer&&) = default;
  Timer& operator=(const Timer&) = default;
  Timer& operator=(Timer&&) = default;

  void tick() { _tick = Clock::now(); }
  // returns the seconds since the tick(), otherwise since initialization
  auto tock() const { return (Clock::now() - _tick).count(); }

  ~Timer() {
    auto end_time = Clock::now();
    Duration duration = end_time - _start_time;

    std::cout << _label << " took " << duration.count() << " seconds.\n";
  }
};
} // namespace pb_utils
