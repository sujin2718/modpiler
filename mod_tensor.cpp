#include "mod_tensor.h"

#include <iostream>
namespace modpiler {

MTensor::MTensor(std::vector<int> shape, void* ptr) {
    this->shape = shape;
    this->ptr = ptr;
    // for now , just 4 byte ...
    int base_stride = 4;

    for (int i = 0; i < this->shape.size(); ++i) {
        this->stride.push_back(base_stride);
        base_stride *= this->shape[i];
    }
}

void MTensor::PrintInfo() {
    std::cout << "Shape : ";
    for (const auto& dim : this->shape) {
        std::cout << " " << dim;
    }

    std::cout << std::endl;
}

}  // namespace modpiler