#ifndef _MODPILER_MELEM_H_
#define _MODPILER_MELEM_H_

#include <string>

namespace modpiler {

class MElem {
   protected:
    std::string name;

   public:
    // make tensor with zero ... constructor
    explicit MElem(const std::string& name) : name(name) {}
    std::string GetName();
    void SetName(std::string name);
};

};  // namespace modpiler

#endif