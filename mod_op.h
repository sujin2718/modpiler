#ifndef _MODPILER_OP_H_
#define _MODPILER_OP_H_

#include "mod_node.h"
#include <iostream>

namespace modpiler {

class MOp : public MNode {
   public:
    MOp(const std::string& name) : MNode(name) {}

    virtual void Execute() {

    }
    virtual void Visit() {

    }
};

class MAddOp : public MOp {
   public:
   MAddOp(const std::string& name) : MOp(name) {}
    void Execute() {
        std::cout << this->name << " MAddOp" << std::endl;
    }
};

};  // namespace modpiler

#endif