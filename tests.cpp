#include <iostream>

#include "coltext.hpp"

namespace test {

void plain_text() 
{
    std::cout << "Starting plain_text test:\n";

    std::string msg = "Hello, world!";
    Coltext ctxt(msg);

    std::cout << "\t"  << msg << "\n";
    std::cout << "\t"  << ctxt << "\n";

    std::cout << "[ OK ] Test plain_text succeded\n\n";
}

void plain_text_with_parentheses()
{
    std::cout << "Starting plain_text_with_parentheses test:\n";

    std::string msg = "Hello, world (and you)!";
    Coltext ctxt(msg);

    std::cout << "\t"  << msg << "\n";
    std::cout << "\t"  << ctxt << "\n";

    std::cout << "[ OK ] Test plain_text_with_parentheses succeded!\n\n";
}

void standard_escapes()
{
    std::cout << "Starting standard_escapes test:\n";

    std::string msg = "Add tab here.\n\tAnd new lines!";
    Coltext ctxt(msg);

    std::cout << "\t"  << msg << "\n";
    std::cout << "\t"  << ctxt << "\n";

    std::cout << "[ OK ] Test standard_escapes succeded\n\n";
}

void color_with_parenthese()
{
    std::cout << "Starting color_with_parenthese test:\n";

    std::string msg = "I love write black on #k(black!)";
    Coltext ctxt(msg);

    std::cout << "\t"  << msg << "\n";
    std::cout << "\t"  << ctxt << "\n";

    std::cout << "[ OK ] Test color_with_parenthese succeded\n\n"; 
}

void escaped_parenthese()
{
    std::cout << "Starting escaped_parenthese test:\n";

    std::string msg = "#r(Text \\(With parenthese escaped\\)) is ok!";
    Coltext ctxt(msg);

    std::cout << "\t"  << msg << "\n";
    std::cout << "\t"  << ctxt << "\n";

    std::cout << "[ OK ] Test escaped_parenthese succeded\n\n";
}

void escaped_right_parenthese()
{
    std::cout << "Starting escaped_right_parenthese test:\n";

    std::string msg = "#g(Text (With only right parenthese escaped\\)) is ok too!";
    Coltext ctxt(msg);
    
    std::cout << "\t"  << msg << "\n";
    std::cout << "\t"  << ctxt << "\n";

    std::cout << "[ OK ] Test escaped_right_parenthese succeded\n\n";
}

void color_next_word() {
    std::cout << "Starting color_next_word test:\n";

    std::string msg = "Next #y word will be colored";
    Coltext ctxt(msg);

    std::cout << "\t"  << msg << "\n";
    std::cout << "\t"  << ctxt << "\n";

    std::cout << "[ OK ] Test color_next_word succeded\n\n"; 
}

void literal()
{
    std::cout << "Starting literal test:\n";

    std::cout << "\t"  << "\"Text colored by #b(literal)\"_col" << "\n";
    std::cout << "\t" << "Text colored by #b(literal)"_col << "\n";

    std::cout << "[ OK ] Test literal succeded\n\n"; 
}

void bg_color()
{
    std::cout << "Starting bg_color test:\n";

    std::string msg = "In order to color bg, you need to put color with #M(big letter)!";
    Coltext ctxt(msg);

    std::cout << "\t"  << msg << "\n";
    std::cout << "\t"  << ctxt << "\n";

    std::cout << "[ OK ] Test bg_color succeded\n\n"; 
}

void styles() {
    std::cout << "Starting styles test:\n";

    std::string msg1 = "<i> italic <b> bold <f> faint <u> underline";
    std::string msg2 = "#<i> italic #<b> bold #<f> faint #<u> underline";
    Coltext ctxt(msg1);

    std::cout << "\t"  << msg1 << "\n";
    std::cout << "\t"  << ctxt << "\n\n";
    std::cout << "\t"  << msg2 << "\n";
    std::cout << "\t"  << (Coltext) msg2 << "\n";

    std::cout << "[ OK ] Test styles succeded\n\n"; 
}

void sequence()
{
    std::cout << "Starting sequence test:\n";

    std::string msg = "#C(You #r(can) use much more than just 1 effect!)";
    Coltext ctxt(msg);

    std::cout << "\t"  << msg << "\n";
    std::cout << "\t"  << ctxt << "\n";

    std::cout << "[ OK ] Test sequence succeded\n\n"; 
}

void get_from_cin()
{
    std::cout << "Starting get_from_cin test:\n";

    Coltext ctxt;
    std::cout << "\t"; std::cin >> ctxt;
    std::cout << "\t" << ctxt << "\n";

    std::cout << "[ OK ] Test get_from_cin succeded\n\n"; 
}

void all_colors()
{
    std::cout
        << "Foreground colors:\n"
        << "\t\\#k(black)   -> " << "#k(black)\n"_col
        << "\t\\#r(red)     -> " << "#r(red)\n"_col
        << "\t\\#g(green)   -> " << "#g(green)\n"_col
        << "\t\\#y(yellow)  -> " << "#y(yellow)\n"_col
        << "\t\\#b(blue)    -> " << "#b(blue)\n"_col
        << "\t\\#c(cyan)    -> " << "#c(cyan)\n"_col
        << "\t\\#m(magenta) -> " << "#m(magenta)\n"_col
        << "\t\\#w(white)   -> " << "#w(white)\n\n"_col

        << "\t#bk(bright_black)   -> " << "#bk(bright_black)\n"_col
        << "\t#br(bright_red)     -> " << "#br(bright_red)\n"_col
        << "\t#bg(bright_green)   -> " << "#bg(bright_green)\n"_col
        << "\t#by(bright_yellow)  -> " << "#by(bright_yellow)\n"_col
        << "\t#bb(bright_blue)    -> " << "#bb(bright_blue)\n"_col
        << "\t#bc(bright_cyan)    -> " << "#bc(bright_cyan)\n"_col
        << "\t#bm(bright_magenta) -> " << "#bm(bright_magenta)\n"_col
        << "\t#bw(bright_white)   -> " << "#bw(bright_white)\n\n"_col

        << "Background colors:\n"
        << "\t #K( ) -> " << "#K( )\n"_col
        << "\t #R( ) -> " << "#R( )\n"_col
        << "\t #G( ) -> " << "#G( )\n"_col
        << "\t #Y( ) -> " << "#Y( )\n"_col
        << "\t #B( ) -> " << "#B( )\n"_col
        << "\t #C( ) -> " << "#C( )\n"_col
        << "\t #M( ) -> " << "#M( )\n"_col
        << "\t #W( ) -> " << "#W( )\n\n"_col

        << "\t#bK( ) -> " << "#bK( )\n"_col
        << "\t#bR( ) -> " << "#bR( )\n"_col
        << "\t#bG( ) -> " << "#bG( )\n"_col
        << "\t#bY( ) -> " << "#bY( )\n"_col
        << "\t#bB( ) -> " << "#bB( )\n"_col
        << "\t#bC( ) -> " << "#bC( )\n"_col
        << "\t#bM( ) -> " << "#bM( )\n"_col
        << "\t#bW( ) -> " << "#bW( )\n\n"_col;
}

} // namespace test

int main(int argc, char const *argv[])
{
    /* Tests for not breaking standard functionality */
    test::plain_text();
    test::plain_text_with_parentheses();
    test::standard_escapes();

    test::color_with_parenthese();    // Does #xxx()# work ?
    test::escaped_parenthese();       // Does #xxx(\\(Text in patenthese\\)) work ?
    test::escaped_right_parenthese(); // Does #xxx((Text in patenthese\\)) work ?

    test::color_next_word();       // Does #xxx next_word other_words work ?
    test::styles();                // Does #<html_tag> work ?
    test::literal();               // Does "text"_col work ?

    test::bg_color();              // Does #Xxx work ?

    test::sequence();              // Do sequences work ?

    test::all_colors();

    test::get_from_cin();          // Does operator>> work ?
    return 0;
}
