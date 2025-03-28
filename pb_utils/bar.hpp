#pragma once
#include <chrono>
#include <iostream>

namespace pb_utils {
class bar {
public:
  using Clock = std::chrono::high_resolution_clock;
  using TimePoint = std::chrono::time_point<Clock>;

  explicit bar(size_t total_count_)
      : total_count(total_count_), start_time(Clock::now()), last_print_time(start_time) {};
  ~bar() { std::cout << '\n'; }
  bar(const bar&) = default;
  bar(bar&&) = delete;
  bar& operator=(const bar&) = default;
  bar& operator=(bar&&) = delete;

  void tick();
  size_t count = 0;
  size_t total_count = 0;
  TimePoint start_time;
  TimePoint last_print_time;
  long print_gap_time = 1; // second
};
} // namespace pb_utils
