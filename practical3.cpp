//Write a C++ program to construct a tree and print the nodes. (A book 
//consists of chapters, chapters consist of sections and sections consists 
//of subsections). Find the time and space requirements of your method.
#include <iostream>

// Forward declarations
class Subsection;
class Section;
class Chapter;
class Book;

// Class representing a Subsection
class Subsection {
private:
    const char* title;

public:
    Subsection(const char* title) : title(title) {}

    void print() {
        std::cout << "Subsection: " << title << std::endl;
    }
};

// Class representing a Section
class Section {
private:
    const char* title;
    Subsection* subsections[10];
    int numSubsections;

public:
    Section(const char* title) : title(title), numSubsections(0) {}

    void addSubsection(Subsection* subsection) {
        if (numSubsections < 10) {
            subsections[numSubsections++] = subsection;
        }
    }

    void print() {
        std::cout << "Section: " << title << std::endl;
        for (int i = 0; i < numSubsections; ++i) {
            subsections[i]->print();
        }
    }
};

// Class representing a Chapter
class Chapter {
private:
    const char* title;
    Section* sections[10];
    int numSections;

public:
    Chapter(const char* title) : title(title), numSections(0) {}

    void addSection(Section* section) {
        if (numSections < 10) {
            sections[numSections++] = section;
        }
    }

    void print() {
        std::cout << "Chapter: " << title << std::endl;
        for (int i = 0; i < numSections; ++i) {
            sections[i]->print();
        }
    }
};

// Class representing a Book
class Book {
private:
    const char* title;
    Chapter* chapters[10];
    int numChapters;

public:
    Book(const char* title) : title(title), numChapters(0) {}

    void addChapter(Chapter* chapter) {
        if (numChapters < 10) {
            chapters[numChapters++] = chapter;
        }
    }

    void print() {
        std::cout << "Book: " << title << std::endl;
        for (int i = 0; i < numChapters; ++i) {
            chapters[i]->print();
        }
    }
};

int main() {
    // Constructing the book tree
    Book book("Data Structures and Algorithms");

    Chapter chapter1("Introduction");
    Section section11("Overview");
    section11.addSubsection(new Subsection("What are data structures?"));
    section11.addSubsection(new Subsection("Importance of algorithms"));
    chapter1.addSection(&section11);

    Section section12("History");
    section12.addSubsection(new Subsection("Evolution of data structures"));
    section12.addSubsection(new Subsection("Notable algorithms"));
    chapter1.addSection(&section12);

    book.addChapter(&chapter1);

    // Printing the book tree
    book.print();

    // Deallocating memory (optional)
    return 0;
}

