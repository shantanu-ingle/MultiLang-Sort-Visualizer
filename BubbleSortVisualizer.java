import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class BubbleSortVisualizer {
    
    static class SortStep {
        public int step;
        public int[] array;
        public int[] comparing;
        public boolean swapped;
        public String description;
        
        public SortStep(int step, int[] array, int[] comparing, boolean swapped, String description) {
            this.step = step;
            this.array = array.clone();
            this.comparing = comparing.clone();
            this.swapped = swapped;
            this.description = description;
        }
    }
    
    public static List<SortStep> bubbleSortWithSteps(int[] arr) {
        List<SortStep> steps = new ArrayList<>();
        int n = arr.length;
        long startTime = System.nanoTime();
        
        // Record initial state
        steps.add(new SortStep(0, arr, new int[]{}, false, "Initial array"));
        
        int stepCount = 1;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                // Record comparison step
                steps.add(new SortStep(stepCount, arr, new int[]{j, j + 1}, false, 
                    "Comparing elements at indices " + j + " and " + (j + 1)));
                stepCount++;
                
                // If elements need to be swapped
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    
                    // Record swap step
                    steps.add(new SortStep(stepCount, arr, new int[]{j, j + 1}, true,
                        "Swapped elements at indices " + j + " and " + (j + 1)));
                    stepCount++;
                }
            }
        }
        
        // Record final state
        steps.add(new SortStep(stepCount, arr, new int[]{}, false, "Array sorted!"));
        
        return steps;
    }
    
    public static void saveToJson(List<SortStep> steps, double executionTime, int[] originalArray) {
        try (FileWriter writer = new FileWriter("java_steps.json")) {
            writer.write("{\n");
            writer.write("  \"language\": \"Java\",\n");
            writer.write("  \"algorithm\": \"Bubble Sort\",\n");
            writer.write("  \"original_array\": " + Arrays.toString(originalArray) + ",\n");
            writer.write("  \"execution_time\": " + executionTime + ",\n");
            writer.write("  \"total_steps\": " + steps.size() + ",\n");
            writer.write("  \"steps\": [\n");
            
            for (int i = 0; i < steps.size(); i++) {
                SortStep step = steps.get(i);
                writer.write("    {\n");
                writer.write("      \"step\": " + step.step + ",\n");
                writer.write("      \"array\": " + Arrays.toString(step.array) + ",\n");
                writer.write("      \"comparing\": " + Arrays.toString(step.comparing) + ",\n");
                writer.write("      \"swapped\": " + step.swapped + ",\n");
                writer.write("      \"description\": \"" + step.description + "\"\n");
                writer.write("    }");
                if (i < steps.size() - 1) writer.write(",");
                writer.write("\n");
            }
            
            writer.write("  ]\n");
            writer.write("}\n");
        } catch (IOException e) {
            System.err.println("Error writing to file: " + e.getMessage());
        }
    }
    
    public static void main(String[] args) {
        // Shared input array - same for all languages
        int[] inputArray = {64, 34, 25, 12, 22, 11, 90, 88, 76, 50, 42};
        System.out.println("Java - Original array: " + Arrays.toString(inputArray));
        
        long startTime = System.nanoTime();
        List<SortStep> steps = bubbleSortWithSteps(inputArray.clone());
        long endTime = System.nanoTime();
        
        double executionTime = (endTime - startTime) / 1_000_000_000.0;
        
        System.out.println("Java - Sorted array: " + Arrays.toString(steps.get(steps.size() - 1).array));
        System.out.println("Java - Execution time: " + String.format("%.6f", executionTime) + " seconds");
        System.out.println("Java - Total steps: " + steps.size());
        
        // Save steps to JSON file
        saveToJson(steps, executionTime, new int[]{64, 34, 25, 12, 22, 11, 90, 88, 76, 50, 42});
        
        System.out.println("Java - Steps saved to java_steps.json");
    }
}