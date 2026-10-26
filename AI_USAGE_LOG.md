# AI Usage Log

This document records the prompts asked to AI learning assistants during the design and development of the **AI-Assisted Student Record and Result Management System**, along with how each response was verified and integrated into the project.

---

## Log of AI Interactions

| AI Tool | Prompt / Question Asked | How I Used / Verified the Response |
| :--- | :--- | :--- |
| **ChatGPT / AI Assistant** | *"Suggest simple CGPA-based academic advice categories and recommendations for college students."* | The AI suggested 4 distinct categories: Excellent Performance (≥9.0), Good Performance (7.5–9.0), Needs Improvement (5.5–7.5), and Requires Immediate Attention (<5.5). I reviewed the thresholds, matched them with UPES grading norms, and implemented them using clean `if-else` statements in C. |
| **ChatGPT / AI Assistant** | *"How can I calculate CGPA by averaging only completed semesters in C when 8 semesters are stored?"* | The AI recommended looping up to the student's current semester and checking for non-zero SGPA values to avoid dividing by 8 when a 1st or 2nd year student has fewer completed semesters. I verified the logic manually with sample students across Year 1 through Year 4. |
| **ChatGPT / AI Assistant** | *"Suggest test cases for menu-driven student record management in C."* | The AI provided a sequence of operations covering adding, searching by ID and name, sorting by SAP ID and Name, year-wise CGPA average, and advisor feedback. I formatted these into `tests/sample_input.txt` and generated `tests/sample_output.txt`. |
| **ChatGPT / AI Assistant** | *"How to keep C code simple for a 1st semester student without complex pointer or dynamic allocation bugs?"* | Guided using fixed arrays (`struct Student students[MAX]`), standard headers (`<stdio.h>` and `<string.h>`), and standard Bubble Sort for sorting, which is easy to explain during the lab viva. |

---

## Student Reflection
- **Verification:** Every AI suggestion was reviewed and tested to ensure it complies strictly with C standards (without complex external dependencies or unsupported functions).
- **Understanding:** All functions, data structures, and algorithms (bubble sort, average calculations) are understood and can be explained during the lab viva.
