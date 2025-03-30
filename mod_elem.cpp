#include "mod_elem.h"

namespace modpiler {
std::string MElem::GetName() { return this->name; }
void MElem::SetName(std::string name) { this->name = name; }
};  // namespace modpiler