#include <iostream>

#include "mod_tensor.h"
#include "mod_node.h"

int node_test() {




    return 0;
}

int main() {
    std::vector<int> shapes;
    shapes.push_back(4);
    shapes.push_back(8);

    modpiler::MTensor* tensor = new modpiler::MTensor(shapes, 0);

    tensor->PrintInfo();

    int ReadOnnx(const std::string& filename);
    ReadOnnx("bvlcalexnet-12.onnx");

    return 0;
}