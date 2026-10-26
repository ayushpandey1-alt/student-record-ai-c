# AI-Assisted Student Record and Result Management System

**Course:** Programming in C (PRC1001)  
**Program:** B.Tech Computer Science & Engineering (Semester I)  
**Institution:** University of Petroleum and Energy Studies (UPES)  

---

## 📌 Project Overview
This project is a console-based, menu-driven **Student Record and Result Management System** developed in C. It allows managing student profiles, computing semester and cumulative grade point averages (CGPA), analyzing year-wise academic averages, sorting records, and providing rule-based AI academic advisory feedback based on student CGPA.

Two implementations are provided:
1. **`student_record.c` (Simple Version):** Uses static arrays and only standard `<stdio.h>` and `<string.h>` (without `<stdlib.h>` or dynamic memory complexity).
2. **`student_record_dynamic.c` (Dynamic Memory Version):** Demonstrates heap memory management using `calloc()`, `malloc()`, and `free()` from `<stdlib.h>`.

---

## 🚀 Key Features

### 1. Core Student Record Management
- **Add Student Record:** Accepts SAP ID, Roll Number, Name, Phone Number, Email, Year (1 to 4), Semester (1 to 8), and SGPA for all eight semesters.
- **Search Student Record:** Search by either SAP ID or Student Name (substring match).
- **Calculate CGPA:** Calculates CGPA for each student as the average of completed semester SGPAs.
- **Year-wise Average CGPA:** Computes and displays the average CGPA of all students belonging to each academic year (Year 1, 2, 3, and 4).
- **Display All Students:** Displays complete formatted profiles of all students in the system.
- **Delete Student Record:** Removes an individual student record by SAP ID (e.g., if a student leaves the University).
- **Sort by SAP ID:** Displays student records in increasing order of SAP ID using Bubble Sort.
- **Sort by Name:** Displays student records alphabetically by Name using `strcmp`.

### 2. AI-Assisted Academic Advisor (Part B)
A rule-based advisory function that evaluates student CGPA and provides automated performance feedback and actionable recommendations:
- **CGPA ≥ 9.0:** `[Excellent Performance]` – Advice to maintain study pattern and pursue undergraduate research/internships.
- **7.5 ≤ CGPA < 9.0:** `[Good Performance]` – Advice to maintain consistency and target high-scoring core subjects.
- **5.5 ≤ CGPA < 7.5:** `[Needs Improvement]` – Advice to focus on lower-grade subjects and attend doubt sessions.
- **CGPA < 5.5:** `[Requires Immediate Attention]` – Advice to meet faculty mentor urgently and attend remedial classes.

---

## 📁 Repository Structure
```text
student-record-ai-c/
├── student_record.c            # Simple C source file (static arrays, no stdlib.h)
├── student_record_dynamic.c    # Dynamic memory C source file (malloc, calloc, free from stdlib.h)
├── README.md                   # Complete project documentation
├── AI_USAGE_LOG.md             # Log documenting prompts and assistance from AI
├── .vscode/
│   └── tasks.json              # VS Code build task configuration for GCC
└── tests/
    ├── sample_input.txt        # Automated test input commands
    └── sample_output.txt       # Corresponding system execution output
```

---

## 🛠️ How to Run in VS Code

### 1. Running the Simple Version (`student_record.c`)
```powershell
gcc student_record.c -o student_record.exe
.\student_record.exe
```

### 2. Running the Dynamic Memory Version (`student_record_dynamic.c`)
```powershell
gcc student_record_dynamic.c -o student_record_dynamic.exe
.\student_record_dynamic.exe
```

---

## 🧪 Testing with Sample Files
You can automatically run the test cases through the terminal:
```powershell
Get-Content tests\sample_input.txt | .\student_record.exe
```

---

## 👤 Author Information
- **Course:** Programming in C (PRC1001)
- **University:** UPES
