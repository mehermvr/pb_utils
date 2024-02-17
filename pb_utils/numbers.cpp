#include "numbers.h"
#include <numbers>

namespace pb_utils {
double rad2deg(const double radians) { return radians * 180 / std::numbers::pi; }
double deg2rad(const double degrees) { return degrees * std::numbers::pi / 180; }
} // namespace pb_utils
