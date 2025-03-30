#include "onnx.pb.h"

#include <fstream>
#include <string>
#include <vector>

void TraverseONNXGraph(const onnx::GraphProto& graph) {
    // Print basic graph info
    std::cout << "Graph Name: " << graph.name() << std::endl;

    // Traverse inputs
    std::cout << "\nInputs:" << std::endl;
    for (const auto& input : graph.input()) {
        std::cout << "  Input Name: " << input.name() << std::endl;
        if (input.type().has_tensor_type()) {
            const auto& shape = input.type().tensor_type().shape();
            std::cout << "  Shape: ";
            for (const auto& dim : shape.dim()) {
                if (dim.has_dim_value()) {
                    std::cout << dim.dim_value() << " ";
                } else if (dim.has_dim_param()) {
                    std::cout << dim.dim_param() << " ";
                }
            }
            std::cout << std::endl;
        }
    }

    // Traverse outputs
    std::cout << "\nOutputs:" << std::endl;
    for (const auto& output : graph.output()) {
        std::cout << "  Output Name: " << output.name() << std::endl;
    }

    // Traverse initializers (constant weights/tensors)
    std::cout << "\nInitializers:" << std::endl;
    for (const auto& initializer : graph.initializer()) {
        std::cout << "  Initializer Name: " << initializer.name() << std::endl;
        std::cout << "  Tensor Data Type: " << initializer.data_type() << std::endl;
        std::cout << "  Tensor Dimensions: ";
        for (const auto& dim : initializer.dims()) {
            std::cout << dim << " ";
        }
        std::cout << std::endl;
    }

    // Traverse nodes (operations in the graph)
    std::cout << "\nNodes:" << std::endl;
    for (const auto& node : graph.node()) {
        std::cout << "  Node Name: " << node.name() << std::endl;
        std::cout << "  OpType: " << node.op_type() << std::endl;
        std::cout << "  Inputs: ";
        for (const auto& input : node.input()) {
            std::cout << input << " ";
        }
        std::cout << "\n  Outputs: ";
        for (const auto& output : node.output()) {
            std::cout << output << " ";
        }
        std::cout << std::endl;
    }
}

void PrintTensorShape(const onnx::TensorShapeProto& shape) {
    for (const auto& dim : shape.dim()) {
        if (dim.has_dim_value()) {
            std::cout << dim.dim_value() << " ";
        } else if (dim.has_dim_param()) {
            std::cout << dim.dim_param() << " ";
        } else {
            std::cout << "? ";
        }
    }
    std::cout << std::endl;
}
int ReadOnnx(const std::string& filename) {

    std::ifstream file(filename, std::ios::binary);

    if(!file.is_open()) {
        std::cerr << "Failed to open ONNX File!" << std::endl;
        return -1;
    }

    std::vector<char> buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    onnx::ModelProto model;
    if (!model.ParseFromArray(buffer.data(), buffer.size())) {
        std::cerr << "Failed to parse ONNX model!" << std::endl;
        return 1;
    }
    // Print model name and graph info
    std::cout << "Model Name: " << model.graph().name() << std::endl;

    TraverseONNXGraph(model.graph());
    return 0;
}