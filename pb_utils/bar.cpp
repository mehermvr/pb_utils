#include "bar.hpp"

namespace pb_utils {
void bar::tick() {
  ++count;
  const auto current_time = Clock::now();
  const double avg_time_per_tick =
      std::chrono::duration<double>(current_time - start_time).count() / static_cast<double>(count);
  const double remaining_time = avg_time_per_tick * static_cast<double>(total_count - count);
  if (std::chrono::duration<double>(current_time - last_print_time).count() > print_gap_time) {
    std::cout << count << " / " << total_count << " messages processed. "
              << "Estimated time remaining: " << std::format("{:.2f}", remaining_time) << " seconds."
              << "\r";
    last_print_time = current_time;
  }
}
} // namespace pb_utils
