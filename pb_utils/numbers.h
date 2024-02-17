#pragma once
#include <concepts>
#include <limits>
namespace pb_utils {
double rad2deg(const double radians);
double deg2rad(const double degrees);

/* use for narrowing conversions. and avoid using this one c++26 becomes available. i
 * have not really studied in detail the gcc implementation for this */
template <typename Target, typename Source>
  requires std::integral<Target> && std::integral<Source>
Target saturate_cast(Source value) {
  if constexpr (std::is_signed_v<Target> && std::is_signed_v<Source>) {
    // Handling signed to signed conversion
    if (value > std::numeric_limits<Target>::max()) {
      return std::numeric_limits<Target>::max();
    } else if (value < std::numeric_limits<Target>::min()) {
      return std::numeric_limits<Target>::min();
    }
  } else if constexpr (std::is_signed_v<Target> && !std::is_signed_v<Source>) {
    // Handling unsigned to signed conversion
    if (value > static_cast<Source>(std::numeric_limits<Target>::max())) {
      /* TODO: can the static cast cause problems i wonder */
      return std::numeric_limits<Target>::max();
    }
  } else if constexpr (!std::is_signed_v<Target> && std::is_signed_v<Source>) {
    // Handling signed to unsigned conversion
    if (value < 0) {
      return 0;
    } else if (value > std::numeric_limits<Target>::max()) {
      return std::numeric_limits<Target>::max();
    }
  } else {
    // Handling unsigned to unsigned conversion
    if (value > static_cast<Source>(std::numeric_limits<Target>::max())) {
      return std::numeric_limits<Target>::max();
    }
  }

  return static_cast<Target>(value);
}
} // namespace pb_utils
