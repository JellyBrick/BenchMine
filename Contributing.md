# <a name="main-section-overview"></a>Main sections

- [C++ coding style and formatting](#cpp-coding-style-and-formatting)
- [C++ code-specific guidelines](#cpp-code-specific-guidelines)

# <a name="cpp-coding-style-and-formatting"></a>C++ coding style and formatting

Summary:

- [General](#cpp-style-general)
- [Naming](#cpp-style-naming)
- [Conditionals](#cpp-style-conditionals)
- [Classes and structs](#cpp-style-classes-and-structs)

## <a name="cpp-style-general"></a>General
- Try to limit lines of code to a maximum of 100 characters.
    - Note that this does not mean you should try and use all 100 characters every time you have the chance. Typically with well formatted code, you normally shouldn't hit a line count of anything over 80 or 90 characters.
- The indentation style we use is tab.
- The opening brace for namespaces, classes, functions, enums, structs, unions, conditionals, and loops go on the same line.
- References and pointers have the ampersand or asterisk against the type name, not the variable name. Example: `int* var`, not `int *var`.
- Don't collapse single line conditional or loop bodies onto the same line as its header. Put it on the next line.
  - Yes:

    ```c++
    if (condition) {
      return 0;
	}

    while (var != 0) {
      var--;
	}
    ```
  - No:

    ```c++
    if (condition) return 0;

    if (condition) 
		return 0;

    while (var != 0) var--;

	while (var != 0) 
		var--;
    ```

## <a name="cpp-style-naming"></a>Naming
- All class, enum, function, and struct names should be in upper CamelCase. If the name contains an abbreviation uppercase it.
  - `class SomeClassName`
  - `enum IPCCommandType`
- All compile time constants should be fully uppercased. With constants that have more than one word in them, use an underscore to separate them.
  - `const double PI = 3.14159;`
  - `const int MAX_PATH = 260;`
- All variables should be follow the CamelCase style.
  - `int variableName;`
- Please do not use [Hungarian notation](http://en.wikipedia.org/wiki/Hungarian_notation) prefixes with variables.

## <a name="cpp-style-conditionals"></a>Conditionals
- Do not leave `else` or `else if` conditions dangling unless the `if` condition lacks braces.
  - Yes:

    ```c++
    if (condition) {
      // code
    } else {
      // code
    }
    ```
  - No:

    ```c++
    if (condition)
    {
      // code
    }
    else
      // code line
    ```


## <a name="cpp-style-classes-and-structs"></a>Classes and structs
- If making a [POD](http://en.wikipedia.org/wiki/Plain_Old_Data_Structures) type, use a `struct` for this. Use a `class` otherwise.
- Class layout should be in the order, `private`, `protected` and then `public`.
  - If one or more of these sections are not needed, then simply don't include them.
- For each of the above specified access levels, the contents of each should follow this given order: variables, constructor, destructor, operator overloads, then functions
- When defining the variables, define `static` variables before the non-static ones.

```c++
class ExampleClass : public SomeParent {
private:
  int m_x;
  int m_y;

protected:
  virtual void SomeProtectedFunction() = 0;
  static float s_some_variable;

public:
  ExampleClass(int x, int y);

  int GetX() const;
  int GetY() const;
};
```

# <a name="cpp-code-specific-guidelines"></a>C++ code-specific guidelines

Summary:

- [General](#cpp-code-general)
- [Headers](#cpp-code-headers)
- [Loops](#cpp-code-loops)
- [Functions](#cpp-code-functions)
- [Classes and Structs](#cpp-code-classes-and-structs)

## <a name="cpp-code-general"></a>General
- The codebase currently uses C++14.
- Use the [nullptr](http://en.cppreference.com/w/cpp/language/nullptr) type over the macro `NULL`.
- If a [range-based for loop](http://en.cppreference.com/w/cpp/language/range-for) can be used instead of container iterators, use it.
- Obviously, try not to use `goto` unless you have a *really* good reason for it.
- If a compiler warning is found, please try and fix it.
- Try to avoid using raw pointers (pointers allocated with `new`) as much as possible. There are cases where using a raw pointer is unavoidable, and in these situations it is OK to use them. An example of this is functions from a C library that require them. In cases where it is avoidable, the STL usually has a means to solve this (`vector`, `unique_ptr`, etc).
- Do not use the `auto` keyword everywhere. While it's nice that the type can be determined by the compiler, it cannot be resolved at 'readtime' by the developer as easily. Use auto only in cases where it is obvious what the type being assigned is (note: 'obvious' means not having to open other files or reading the header file). Some situations where it is appropriate to use `auto` is when iterating over a `std::map` container in a foreach loop, or to shorten the length of container iterator variable declarations.
- Do not use `using namespace [x];` in headers. Try not to use it at all if you can.
- The preferred form of the increment and decrement operator in for-loops is prefix-form (e.g. `++var`).

## <a name="cpp-code-headers"></a>Headers
- If a header is not necessary in a certain source file, remove them.
- If you find duplicate includes of a certain header, remove it.
- When declaring includes in a source file, make sure they follow the given pattern:
  - The header for the source file
  - Standard library headers
  - System-specific headers (these should also likely be in an `#ifdef` block unless the source file itself is system-specific).
  - Other BenchMine source file headers
- Each of the above header sections should also be in alphabetical order
- Don't use relative path to include
- This project uses `#pragma once` as header guards.

## <a name="cpp-code-loops"></a>Loops
- If an infinite loop is required, do not use `for (;;)`, use `while (true)`.
- Empty-bodied loops should use braces after their header, not a semicolon.
  - Yes: `while (condition) {}`
  - No: `while (condition);`
- For do-while loops, place 'while' on the same line as the closing brackets

  ```c++
  do
  {
  } while (false);
  ```

## <a name="cpp-code-functions"></a>Functions
- If a function parameter is a pointer or reference and its value or data isn't intended to be changed, please mark that parameter as `const`.
- Functions that specifically modify their parameters should have the respective parameter(s) marked as a pointer so that the variables being modified are syntaxically obvious.
  - What not to do:

    ```c++
    template<class T>
    inline void Clamp(T& val, const T& min, const T& max) {
     if (val < min) {
        val = min;
      } else if (val > max) {
        val = max;
	  }
    }
    ```

    Example call: `Clamp(var, 1000, 5000);`

  - What to do:

    ```c++
    template<class T>
    inline void Clamp(T* val, const T& min, const T& max) {
      if (*val < min) {
        *val = min;
      } else if (*val > max) {
        *val = max;
	  }
    }
    ```

    Example call: `Clamp(&var, 1000, 5000);`

- Class member functions that you do not want to be overridden in inheriting classes should be marked with the `final` specifier.

  ```c++
  class ClassName : ParentClass {
  public:
    void Update() final;
  };
  ```

- Overridden member functions that can also be inherited should be marked with the `override` specifier to make it easier to see which functions belong to the parent class.

  ```c++
  class ClassName : ParentClass {
  public:
    void Update() override;
  };
  ```

## <a name="cpp-code-classes-and-structs"></a>Classes and structs
- Classes and structs that are not intended to be extended through inheritance should be marked with the `final` specifier.

  ```c++
  class ClassName final : ParentClass {
    // Class definitions
  };
  ```

  ## <a name="author"></a>Original Authours
- This file is a modified version of the [Contribution file](https://github.com/dolphin-emu/dolphin/blob/master/Contributing.md) from the Dolphin Project