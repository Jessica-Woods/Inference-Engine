#include <iostream>

#include "../Inference-Engine/InferenceEngine.h"

int main(int argc, char** argv) {
  if (argc != 3) {
    std::cout << "Usage: InferenceEngine.exe <filepath> <method>" << std::endl;
    return 1;
  }

  try {
    InferenceEngine program;
    std::string filepath(argv[1]);
    std::string method(argv[2]);

    std::cout << program.runFromFile(filepath, method) << std::endl;
  }
  catch (std::exception e) {
    std::cout << e.what() << std::endl;
  }
}