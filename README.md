
# 🎬 Movie Recommendation Engine – Structured Enquiry Project

This is a simple yet effective **C-based CLI application** that recommends movies based on user input and structured matching logic using **search strings**, **genre filtering**, and **viewership ranking**.

It mimics a mini search engine using `struct`, `file handling`, and `qsort()` based sorting techniques — ideal for understanding how structured data can be queried and filtered in a procedural programming paradigm.

---

## 📌 Project Highlights

- 🔍 **Search Functionality**  
  Search for movies by keyword & filter by genre.

- 🎯 **Genre-Based Filtering**  
  Supports matching based on genre (e.g., Action, Romance, SciFi).

- 📊 **Viewer Popularity Sort**  
  Sorts movies based on number of viewers using `qsort`.

- 📝 **Add New Entries**  
  Easily append new movie data directly into `MovieIndex.txt`.

- 📁 **Data Persistence**  
  Uses `MovieIndex.txt` file to store and retrieve movie records.

---

## 🧠 Data Structure Used

```c
struct recommendation_data {
    char movie_name[30];
    char recommendation_name[30];
    int viewers;
    char genre[20]; // Genre filtering
};
````

Each line in `MovieIndex.txt` follows this format:

```txt
<movie_name> <recommendation_name> <viewers> <genre>
```

Example:

```
interstellar gravity 28000 SciFi
ironman avengers 54000 Action
```

---

## 🖥️ Features & Menu

Upon execution, the program displays a structured menu:

```
1. Search recommendations
2. Add new movie data
3. Sort movies based on viewers
4. Display all movies
5. Exit
```

### 🔍 Search Recommendations

* Input search string (e.g., `ironman` as `ironman`)
* Input genre (e.g., `Action`)
* Displays recommendations + total matching results

### 🆕 Add New Movie

Prompts user for:

* Movie name
* Recommendation name
* Viewers
* Genre

Appends it to the database file and refreshes local state.

### 📈 Sort by Viewers

Sorts all movie data in descending order of viewers using:

```c
int compare_viewers(const void *a, const void *b)
```

### 📂 Display All

Prints all movies in the `MovieIndex.txt` file along with their metadata.

---

## 🛠️ How to Run

### 🧾 Prerequisites

* GCC Compiler or any C environment
* A file named `MovieIndex.txt` in the same folder

### 🔧 Compile

```bash
gcc recommendation_engine.c -o recommender
```

### ▶️ Run

```bash
./recommender
```

---

## 📚 Educational Concepts Covered

* File I/O (`fopen`, `fscanf`, `fprintf`)
* Strings & character manipulation
* Arrays of structures
* Pointer-based sorting (`qsort`)
* Menu-driven CLI in C

---

## 🧪 Sample Entry (MovieIndex.txt)

```
avatar titanic 52000 Romance
dangal chakde 43000 Sports
sholay deewar 40000 Drama
```

---

## 🙌 Authors

> 👨‍💻 *Structured Enquiry Team Project – C Programming*

* Prashanth Uppar

