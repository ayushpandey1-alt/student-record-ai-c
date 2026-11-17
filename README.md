# AI-Assisted Student Record and Result Management System

**Course:** Programming in C (PRC1001)  
**Program:** B. Tech CSE (Semester I)  
**Institution:** University of Petroleum and Energy Studies (UPES)  
**Student Name:** Ayush Pandey  
**SAP ID:** 590034104  

---

## 📌 Project Overview
This project is a console-based, menu-driven **Student Record and Result Management System** developed in C language in accordance with UPES Project-Based Assignment guidelines.

The application manages student records, calculates semester and cumulative grade point averages (CGPA), computes year-wise average CGPA across all academic years, supports searching and deleting, performs sorting by SAP ID and Name, and includes an **AI-Assisted Academic Advisor** that delivers tailored academic feedback and guidance based on CGPA.

---

## 🚀 Key Features & Implementation

### Part A: Core C Programming Features
1. **Student Details Storage & Addition:**
   - Stores SAP ID, Roll Number, Name, Phone Number, Email ID, Academic Year (1st, 2nd, 3rd, 4th), Semester (1 to 8), and SGPA for all 8 semesters.
   - Pre-populated with 5 diverse student records across different years.
2. **Search and Display Functionality:**
   - Allows searching by either **SAP ID** or by **Student Name** (with substring matching).
3. **CGPA Calculation:**
   - Calculates CGPA by taking the average of completed semester SGPAs (`CGPA = Sum of SGPAs / Completed Semesters`).
4. **Yearly Average CGPA Calculation:**
   - Calculates and displays the average CGPA of all students enrolled in each academic year (Year 1, 2, 3, and 4).
5. **Display All Students:**
   - Displays neatly formatted tabular records of all students in the university with all 8 semester SGPA breakdowns.
6. **Delete Student Record:**
   - Searches for an individual student by SAP ID and deletes their record, safely shifting array elements.
7. **Sorting by SAP ID:**
   - Displays all student records in increasing numerical order of SAP ID using standard Bubble Sort.
8. **Sorting by Name:**
   - Displays all student records in alphabetical order of student name using Bubble Sort with `strcmp()`.

### Part B: AI-Assisted Academic Advisor
A decision-making function implemented using clean `if-else` statements based on CGPA recommendations designed with AI assistance:
- **CGPA ≥ 9.0:** `[Excellent Performance]` – Advice to maintain study pattern and explore undergraduate research/internships.
- **7.5 ≤ CGPA < 9.0:** `[Good Performance]` – Advice to stay consistent and aim for higher grades in core subjects.
- **5.5 ≤ CGPA < 7.5:** `[Needs Improvement]` – Advice to focus on lower SGPA subjects and attend doubt sessions.
- **CGPA < 5.5:** `[Requires Immediate Attention]` – Advice to consult faculty mentor urgently and join remedial classes.

---

## 📁 Repository Structure
```text
student-record-ai-c/
├── 590034104.c                 # Final C source file (named as per assignment instructions: SAP_ID.c)
├── README.md                   # Comprehensive project documentation
├── AI_USAGE_LOG.md             # Detailed log of AI interactions and verification
├── .vscode/
│   └── tasks.json              # VS Code build tasks configuration
└── tests/
    ├── sample_input.txt        # Automated input test cases covering all menu functions
    └── sample_output.txt       # Verified console execution output
```

---

## 🛠️ How to Compile and Run in VS Code

### Method 1: Using the Integrated Terminal (PowerShell)
1. Open this project directory in **VS Code**:
   `File` -> `Open Folder...` -> Select this folder.
2. Open the terminal (``Ctrl + ` ``).
3. Compile the program using GCC:
   ```powershell
   gcc 590034104.c -o 590034104.exe
   ```
4. Run the program:
   ```powershell
   .\590034104.exe
   ```

### Method 2: Using VS Code Build Task
- Open `590034104.c` in VS Code.
- Press `Ctrl + Shift + B` to compile automatically.
- Run `.\590034104.exe` in the terminal.

---

## 🧪 Automated Testing
Run the complete automated test script using:
```powershell
Get-Content tests\sample_input.txt | .\590034104.exe
```

---

## 👤 Author Information
- **Student Name:** Ayush Pandey
- **SAP ID:** 590034104
- **Course:** Programming in C (PRC1001)
- **Program:** B.Tech CSE (Semester I)
- **University:** University of Petroleum and Energy Studies (UPES)
