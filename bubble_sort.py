import json
import time

def bubble_sort_with_steps(arr):
    """
    Performs bubble sort and records each step of the sorting process
    """
    steps = []
    n = len(arr)
    start_time = time.time()
    
    # Record initial state
    steps.append({
        "step": 0,
        "array": arr.copy(),
        "comparing": [],
        "swapped": False,
        "description": "Initial array"
    })
    
    step_count = 1
    
    for i in range(n):
        for j in range(0, n - i - 1):
            # Record comparison step
            steps.append({
                "step": step_count,
                "array": arr.copy(),
                "comparing": [j, j + 1],
                "swapped": False,
                "description": f"Comparing elements at indices {j} and {j + 1}"
            })
            step_count += 1
            
            # If elements need to be swapped
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                
                # Record swap step
                steps.append({
                    "step": step_count,
                    "array": arr.copy(),
                    "comparing": [j, j + 1],
                    "swapped": True,
                    "description": f"Swapped elements at indices {j} and {j + 1}"
                })
                step_count += 1
    
    end_time = time.time()
    execution_time = end_time - start_time
    
    # Record final state
    steps.append({
        "step": step_count,
        "array": arr.copy(),
        "comparing": [],
        "swapped": False,
        "description": "Array sorted!"
    })
    
    return steps, execution_time

def main():
    # Shared input array - same for all languages
    input_array = [64, 34, 25, 12, 22, 11, 90, 88, 76, 50, 42]
    print(f"Python - Original array: {input_array}")
    
    # Perform bubble sort and get steps
    steps, exec_time = bubble_sort_with_steps(input_array.copy())
    
    print(f"Python - Sorted array: {steps[-1]['array']}")
    print(f"Python - Execution time: {exec_time:.6f} seconds")
    print(f"Python - Total steps: {len(steps)}")
    
    # Save steps to JSON file
    output_data = {
        "language": "Python",
        "algorithm": "Bubble Sort",
        "original_array": [64, 34, 25, 12, 22, 11, 90, 88, 76, 50, 42],
        "execution_time": exec_time,
        "total_steps": len(steps),
        "steps": steps
    }
    
    with open("python_steps.json", "w") as f:
        json.dump(output_data, f, indent=2)
    
    print("Python - Steps saved to python_steps.json")

if __name__ == "__main__":
    main()