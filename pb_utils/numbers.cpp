#include "numbers.hpp"
#include <cmath>
#include <numbers>

namespace pb_utils {
double rad2deg(const double radians) { return radians * 180 / std::numbers::pi; }
double deg2rad(const double degrees) { return degrees * std::numbers::pi / 180; }
double wrap_to_2pi(double angle_deg) {
  // Use modulus to wrap the angle
  angle_deg = fmod(angle_deg, 360.0);
  // Ensure the result is positive
  if (angle_deg < 0) {
    angle_deg += 360.0;
  }
  return angle_deg;
}
} // namespace pb_utils
