
Coltext is an open-source header-only C++ library for applying colors and styles to strings in linux terminals.

It introduces a new syntax for in-string ANSI effects (styles, background and foreground colors) parsing. With a few simple rules you won't need to care about remembering escape codes or resetting streams.

# Table of Contents

- [Table of Contents](#table-of-contents)
  - [How to use](#how-to-use)
    - [Including](#including)
    - [Casting strings](#casting-strings)
  - [Syntax](#syntax)
  - [Running the tests](#running-the-tests)
  - [Contributing](#contributing)
  - [Versioning](#versioning)
  - [Authors](#authors)
  - [License](#license)
  - [Acknowledgments](#acknowledgments)

## How to use

### Including

Just add `#include "coltext.hpp"` to your C++ file.

### Casting strings

In order to use features provided by Coltext, you MUST convert `std::string` to `Coltext` class.

There are currently 3 ways of doing it:

1. By constructor

~~~c++
std::string hello = "Hello, World!";
Coltext ctxt(hello);
~~~

2. By dynamic cast

~~~c++
std::string hello = "Hello, World!";
std::cout << (Coltext) hello << "\n";
~~~

Or symply

~~~c++
std::cout << (Coltext) "Hello, World!\n";
~~~

3. By literal

~~~c++
std::cout << "Hello, World!\n"_col;
~~~

## Syntax

`"#effect_name(text)"`

`"#effect_name next_word"`

`<style_name>() // Currently <\style_name> is not supported`

`<style_name> next_word`

|     Name    |     Keywords     |               Commentary               | 
|:-----------:|:----------------:|:--------------------------------------:|
|   black_fg  | `"black"`, `"k"` | `"k"` is acronym for black from [CMYK](https://en.wikipedia.org/wiki/CMYK_color_model) |

## Running the tests

## Contributing

## Versioning

## Authors

## License

## Acknowledgments
