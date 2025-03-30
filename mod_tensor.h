#ifndef _MODPILER_MTENSOR_H_
#define _MODPILER_MTENSOR_H_

#include <vector>

#include "mod_elem.h"

namespace modpiler {

class MTensor {
   private:
    std::vector<int> shape;   // element number
    std::vector<int> stride;  // element stride
    void *ptr;

   public:
    // make tensor with zero ... constructor
    MTensor(std::vector<int> shape, void *ptr);

    void PrintInfo();
};

};  // namespace modpiler

#endif