# MultiLang Sort Visualizer

This project visualizes the **Bubble Sort algorithm** implemented in **Python, Java, and C++**, comparing their performance side-by-side.  
It generates JSON files with sorting steps and displays them in an **interactive HTML interface**.

---

## 🔧 Features

- Visualizes Bubble Sort steps for **Python**, **Java**, and **C++**
- Displays **execution time**, **total steps**, and **relative animation speed**
- Interactive controls: **load JSON files**, **start/pause/reset animation**, and **adjust speed**
- Professional **dark theme** with vibrant colors for clarity
- Performance **summary with ranking** and speed comparison

---

## 📦 Prerequisites

- Python **3.x**
- Java **JDK 8** or higher
- C++ compiler (e.g., **g++ with C++11** support)
- Modern web browser (**Chrome**, **Firefox**, etc.)

---

## ⚙️ Setup and Installation

1. **Clone or download** the repository
2. Ensure all files are in the **same directory**:
   - `bubble_sort.py`
   - `BubbleSortVisualizer.java`
   - `bubble_sort.cpp`
   - `index.html`

---

## 🚀 Usage

### 🔹 Generate JSON Files

**Python**  
```bash
python bubble_sort.py
```


Generate JSON Files:

Python: Run python bubble_sort.py to generate python_steps.json.



Java: Compile and run:
```bash
javac BubbleSortVisualizer.java
java BubbleSortVisualizer
```
This generates java_steps.json.



C++: Compile and run:
```bash
g++ -std=c++11 -o bubble_sort bubble_sort.cpp
./bubble_sort
```
This generates cpp_steps.json.



## Run the Visualizer:





Open index.html in a web browser.



Click "Load JSON Files" to load the generated JSON files.



Use "Start Animation" to begin, "Pause" to pause, "Reset" to restart, and the speed slider to adjust animation speed.

## File Structure





bubble_sort.py: Python implementation of Bubble Sort, outputs python_steps.json.



BubbleSortVisualizer.java: Java implementation, outputs java_steps.json.



bubble_sort.cpp: C++ implementation, outputs cpp_steps.json.



index.html: HTML file with JavaScript and CSS for the visualizer.



*.json: Generated files containing sorting steps and metadata.
