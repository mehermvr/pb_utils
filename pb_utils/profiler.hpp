#pragma once
#include <chrono>
#include <iomanip>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

namespace pb_utils {

class ScopedProfiler {
public:
  explicit ScopedProfiler(std::string name_) : name(std::move(name_)), start(Clock::now()) {}
  ScopedProfiler(const ScopedProfiler&) = delete;
  ScopedProfiler(ScopedProfiler&&) = delete;
  ScopedProfiler& operator=(const ScopedProfiler&) = delete;
  ScopedProfiler& operator=(ScopedProfiler&&) = delete;

  void finish() {
    if (!finished) {
      auto& entry = profile_data.map[name];
      const MilliSeconds elapsed = Clock::now() - start;
      if (elapsed > entry.max_time) {
        entry.max_time = elapsed;
      }
      entry.total += elapsed;
      ++entry.count;
      finished = true;
    }
  }

  ~ScopedProfiler() { finish(); }

  static void print_results() { profile_data.print_results(); }

private:
  using Clock = std::chrono::high_resolution_clock;
  using TimePoint = Clock::time_point;
  using Seconds = std::chrono::duration<double>;
  using MilliSeconds = std::chrono::duration<double, std::milli>;

  struct ProfilingInfo {
    size_t count{0};
    MilliSeconds total{};
    MilliSeconds max_time{};
  };
  class ProfilingInfoMap {
  public:
    std::unordered_map<std::string, ProfilingInfo> map;
    ProfilingInfoMap() = default;
    ProfilingInfoMap(const ProfilingInfoMap&) = delete;
    ProfilingInfoMap(ProfilingInfoMap&&) = delete;
    ProfilingInfoMap& operator=(const ProfilingInfoMap&) = delete;
    ProfilingInfoMap& operator=(ProfilingInfoMap&&) = delete;
    void print_results() {
      if (!map.empty()) {
        std::cout << "Profiling results\n";
      }
      for (const auto& [name, info] : map) {
        const auto avg_ms = info.total / info.count;
        std::cout << "\t" << name << ":\n"
                  << "\t\tExecution count: " << info.count << "\n"
                  << "\t\tAverage time: " << std::fixed << std::setprecision(2) << avg_ms.count() << "ms\n"
                  << "\t\tAverage frequency: " << std::fixed << std::setprecision(2) << (1.0 / Seconds(avg_ms).count())
                  << "Hz\n"
                  << "\t\tMax (worst-case) time: " << std::fixed << std::setprecision(2) << info.max_time.count()
                  << "ms\n"
                  << "\t\tWorst-case frequency: " << std::fixed << std::setprecision(2)
                  << (1.0 / Seconds(info.max_time).count()) << "Hz\n";
      }
    }
    ~ProfilingInfoMap() { print_results(); }
  };
  // linker throws an error without the inline
  static inline ProfilingInfoMap profile_data;

  std::string name;
  TimePoint start;
  bool finished = false;
};

} // namespace pb_utils

#define CONCAT_IMPL(x, y) x##y
#define CONCAT(x, y) CONCAT_IMPL(x, y)
#define SCOPED_PROFILER(name) pb_utils::ScopedProfiler CONCAT(profiler_, __LINE__)(name)
