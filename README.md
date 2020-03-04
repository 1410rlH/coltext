[Coltext](https://github.com/1410rlH/coltext) is an open-source header-only C++ library for applying colors and styles to strings in linux terminals.

It introduces a new syntax for in-string ANSI effects (styles, background and foreground colors) parsing. With a few simple rules you won't need to care about remembering escape codes or resetting streams.

# Table of Contents

- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installing](#installing)
    - [Linux](#linux)
- [How to use](#how-to-use)
  - [Syntax](#syntax)
  - [Casting](#casting)
- [Running the tests](#running-the-tests)
- [Contributing](#contributing)
- [Versioning](#versioning)
- [Authors](#authors)
- [License](#license)
- [Acknowledgments](#acknowledgments)

## Getting Started

### Prerequisites

The only things you need to use Coltext is C++ compiler and terminal that supports ANSI escape codes.

### Installing

There is currently only Linux terminals support. But we plan to make Coltext cross-platform.

#### Linux

1. Download [latest release]() or just `coltext.hpp` file
2. Add it to the folder where your code lies 
3. Add `#include "coltext.hpp"` to your C++ file.

## How to use

### Syntax

`"#effect_name(text)"`

`"#effect_name next_word"`

`<style_name>() // Currently <\style_name> is not supported`

`<style_name> next_word`

|     Name    |     Keywords     |               Commentary               | 
|:-----------:|:----------------:|:--------------------------------------:|
|   black_fg  | `"black"`, `"k"` | `"k"` is acronym for black from [CMYK](https://en.wikipedia.org/wiki/CMYK_color_model) |

### Casting

In order to use features provided by Coltext, you MUST convert `std::string` to `Coltext` class.

There are currently 3 ways of doing it:

By constructor:

~~~c++
std::string hello = "Hello, World!";
Coltext ctxt(hello);
~~~

By dynamic cast:

~~~c++
std::string hello = "Hello, World!";
std::cout << (Coltext) hello << "\n";
~~~

Or symply

~~~c++
std::cout << (Coltext) "Hello, World!\n";
~~~

By literal:

~~~c++
std::cout << "Hello, World!\n"_col;
~~~

## Running the tests

## Contributing

Please read [CONTRIBUTING]() for details on our code of conduct and the process for submitting pull requests to us.

## Versioning

We use [SemVer](https://semver.org/) for versioning. For the versions available, see the [releases on this repository]().

## Authors

- **Earl H.** - *Initial work* - [1410rlH](https://github.com/1410rlH)

See also the list of [contributors]() who participated in this project.

## License

This project is licensed under the GNU General Public License v3.0 - see the [LICENSE](https://github.com/1410rlH/coltext/blob/master/LICENSE) file for details.

## Acknowledgments

- CSS for `'#'` special symbol
- HTML for style tags
- [Ikalnytskyi/termcolor](https://github.com/ikalnytskyi/termcolor) for initial idea
- C++ for the difficulties of coloring text  

