#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <sstream>
struct SortStep {
    int step;
    std::vector<int> array;
    std::vector<int> comparing;
    bool swapped;
    std::string description;
    
    SortStep(int s, const std::vector<int>& arr, const std::vector<int>& comp, 
             bool swap, const std::string& desc) 
        : step(s), array(arr), comparing(comp), swapped(swap), description(desc) {}
};

std::vector<SortStep> bubbleSortWithSteps(std::vector<int>& arr) {
    std::vector<SortStep> steps;
    int n = arr.size();
    
    // Record initial state
    steps.emplace_back(0, arr, std::vector<int>{}, false, "Initial array");
    
    int stepCount = 1;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Record comparison step
            steps.emplace_back(stepCount, arr, std::vector<int>{j, j + 1}, false,
                "Comparing elements at indices " + std::to_string(j) + " and " + std::to_string(j + 1));
            stepCount++;
            
            // If elements need to be swapped
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                
                // Record swap step
                steps.emplace_back(stepCount, arr, std::vector<int>{j, j + 1}, true,
                    "Swapped elements at indices " + std::to_string(j) + " and " + std::to_string(j + 1));
                stepCount++;
            }
        }
    }
    
    // Record final state
    steps.emplace_back(stepCount, arr, std::vector<int>{}, false, "Array sorted!");
    
    return steps;
}

void saveToJson(const std::vector<SortStep>& steps, double executionTime, const std::vector<int>& originalArray) {
    std::ofstream file("cpp_steps.json");
    
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file for writing!" << std::endl;
        return;
    }
    
    file << "{\n";
    file << "  \"language\": \"C++\",\n";
    file << "  \"algorithm\": \"Bubble Sort\",\n";
    file << "  \"original_array\": [";
    for (size_t i = 0; i < originalArray.size(); i++) {
        file << originalArray[i];
        if (i < originalArray.size() - 1) file << ", ";
    }
    file << "],\n";
    file << "  \"execution_time\": " << std::fixed << std::setprecision(6) << executionTime << ",\n";
    file << "  \"total_steps\": " << steps.size() << ",\n";
    file << "  \"steps\": [\n";
    
    for (size_t i = 0; i < steps.size(); i++) {
        const auto& step = steps[i];
        file << "    {\n";
        file << "      \"step\": " << step.step << ",\n";
        file << "      \"array\": [";
        for (size_t j = 0; j < step.array.size(); j++) {
            file << step.array[j];
            if (j < step.array.size() - 1) file << ", ";
        }
        file << "],\n";
        file << "      \"comparing\": [";
        for (size_t j = 0; j < step.comparing.size(); j++) {
            file << step.comparing[j];
            if (j < step.comparing.size() - 1) file << ", ";
        }
        file << "],\n";
        file << "      \"swapped\": " << (step.swapped ? "true" : "false") << ",\n";
        file << "      \"description\": \"" << step.description << "\"\n";
        file << "    }";
        if (i < steps.size() - 1) file << ",";
        file << "\n";
    }
    
    file << "  ]\n";
    file << "}\n";
    
    file.close();
}

int main() {
    // Shared input array - same for all languages
    std::vector<int> inputArray = {64, 34, 25, 12, 22, 11, 90, 88, 76, 50, 42};
    
    std::cout << "C++ - Original array: ";
    for (size_t i = 0; i < inputArray.size(); i++) {
        std::cout << inputArray[i];
        if (i < inputArray.size() - 1) std::cout << " ";
    }
    std::cout << std::endl;
    
    auto startTime = std::chrono::high_resolution_clock::now();
    std::vector<SortStep> steps = bubbleSortWithSteps(inputArray);
    auto endTime = std::chrono::high_resolution_clock::now();
    
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    double executionTime = duration.count() / 1e9;
    
    std::cout << "C++ - Sorted array: ";
    for (size_t i = 0; i < steps.back().array.size(); i++) {
        std::cout << steps.back().array[i];
        if (i < steps.back().array.size() - 1) std::cout << " ";
    }
    std::cout << std::endl;
    
    std::cout << "C++ - Execution time: " << std::fixed << std::setprecision(6) << executionTime << " seconds" << std::endl;
    std::cout << "C++ - Total steps: " << steps.size() << std::endl;
    
    // Save steps to JSON file
    saveToJson(steps, executionTime, {64, 34, 25, 12, 22, 11, 90, 88, 76, 50, 42});
    
    std::cout << "C++ - Steps saved to cpp_steps.json" << std::endl;
    
    return 0;
}