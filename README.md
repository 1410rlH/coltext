# Coltext

[Coltext](https://github.com/1410rlH/coltext) is an open-source header-only C++ library for applying colors and styles to strings in terminals.

It introduces a new syntax for in-string ANSI effects (styles, background and foreground colors) parsing. With a few simple rules you won't need to care about remembering escape codes or resetting streams!

## Table of Contents

- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installing](#installing)
    - [Linux](#linux)
- [How to use](#how-to-use)
  - [Syntax](#syntax)
    - [Colors](#colors)
    - [Styles](#styles)
    - [Effect scope](#effect-scope)
    - [Escape symbols](#escape-symbols)
  - [Casting](#casting)
- [Running the tests](#running-the-tests)
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

1. Download [latest release](https://github.com/1410rlH/coltext/releases/latest) or just `coltext.hpp` file.
2. Add it to the folder where your code lies.
3. Add `#include "coltext.hpp"` to your C++ file.

## How to use

In order to use Coltext features you need to acquire syntax of Coltext and cast to its class.

### Syntax

Effects should start from a `#` special symbol, followed by effect's keyword.

> Note: if keyword is wrong then Coltext threats it as plain text. **NO ERROR TROWN EVER**.

#### Colors

The colors are standard 16 ANSI colors (8 colors + their bright versions)

| color |      keywords      |
|-------|--------------------|
|black  | `"black"`,   `"k"` |
|red    | `"red"`,     `"r"` |
|green  | `"green"`,   `"g"` |
|yellow | `"yellow"`,  `"y"` |
|blue   | `"blue"`,    `"b"` |
|cyan   | `"cyan"`,    `"c"` |
|magenta| `"magenta"`, `"m"` |
|white  | `"white"`,   `"w"` |

Background colors keywords start from big letter. (Example: `"Red"` and `"R"`)

Their bright versions are accessed by adding `"bright_"` to long keyword or `"b"` to short one. (Example: `"bright_red"` and `"br"`, or `"bright_Red"` and `"bR"` for background)

> Note: acronyms for colors come from [CMYK](https://en.wikipedia.org/wiki/CMYK_color_model) and [RGB](https://en.wikipedia.org/wiki/RGB_color_model) color models.

#### Styles

#### Effect scope

`"#effect_name(text)"`

`"#effect_name next_word"`

`<style_name>() // Currently <\style_name> is not supported`

`<style_name> next_word`

#### Escape symbols


### Casting

In order to use features provided by Coltext, you MUST convert `std::string` to `Coltext` class.

There are currently 3 ways of doing it:

By constructor:

~~~c++
Coltext ctxt("<b>(Hello, World!)\n"); // ctxt(std::string &) works as well
~~~

By dynamic cast:

~~~c++
std::cout << (Coltext) "<b>(Hello, World!)\n";
~~~

By literal:

~~~c++
std::cout << "<b>(Hello, World!)\n"_col;
~~~

## Running the tests

Compile and run `tests.cpp` file.

## Versioning

We use [SemVer](https://semver.org/) for versioning. For the versions available, see the [releases on this repository](https://github.com/1410rlH/coltext/releases).

## Authors

- **Earl H.** - *Initial work* - [1410rlH](https://github.com/1410rlH)

## License

This project is licensed under the GNU General Public License v3.0 - see the [LICENSE](https://github.com/1410rlH/coltext/blob/master/LICENSE) file for details.

## Acknowledgments

- CSS for `'#'` special symbol
- HTML for style tags
- [Ikalnytskyi/termcolor](https://github.com/ikalnytskyi/termcolor) for initial idea
- C++ for the difficulties of coloring text  

