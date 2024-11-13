#pragma once
#include <chrono>
#include <format>
#include <iostream>
#include <string>
#include <utility>

namespace {
// TODO: use std::derived_from instead
template <typename T>
concept ChronoDuration = std::is_base_of_v<std::chrono::duration<typename T::rep, typename T::period>, T>;

template <ChronoDuration Duration>
constexpr std::string get_duration_unit();
template <>
constexpr std::string get_duration_unit<std::chrono::seconds>() {
  return "s";
}
template <>
constexpr std::string get_duration_unit<std::chrono::milliseconds>() {
  return "ms";
}
template <>
constexpr std::string get_duration_unit<std::chrono::microseconds>() {
  return "us";
}
template <>
constexpr std::string get_duration_unit<std::chrono::nanoseconds>() {
  return "ns";
}
} // namespace

namespace pb_utils {
template <ChronoDuration Duration>
class Profiler {
public:
  using Clock = std::chrono::high_resolution_clock;
  using TimePoint = Clock::time_point;
  static constexpr std::string UnitString = get_duration_unit<Duration>();

  explicit Profiler(std::string name_ = "Profiler", bool print_frequency = true)
      : name(std::move(name_)), print_frequency(print_frequency) {}
  void tick() { start_time = Clock::now(); };
  void tock() {
    total_time += std::chrono::duration(Clock::now() - start_time).count();
    ++count;
  };
  ~Profiler() {
    const double average_time = count > 0 ? (total_time / std::nano::den) / count : 0;
    const double frequency = average_time > 0 ? (1.0 / average_time) : 0.0;
    std::cout << name << " - Profiling results:\nExecution count: " << count << "\nAverage time: "
              << std::format("{:.2f}", average_time * Duration::period::den / Duration::period::num) << UnitString
              << "." << std::endl;
    if (print_frequency) {
      std::cout << "Average Frequency: " << std::format("{:.2f}", frequency) << "Hz." << std::endl;
    }
  }

private:
  std::string name;
  TimePoint start_time;
  double total_time;
  size_t count = 0;
  bool print_frequency;
};
} // namespace pb_utils
