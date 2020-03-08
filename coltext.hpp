// Coltext. Text's color and style manipulator.

// Copyright (C) 2020 by Earl H. (1410rlH)
//
// This library is created to be a convenient tool 
// for manipulations with text's color and style.
// 
// The main feature of Coltext is a special symbol '#'
// used for in-string ANSI effect parsing, which allows 
// programmers not to care about resetting streams.

// This is header only library.

//
// Distributed by the terms of GPL. 
// See LICENSE for details.
//

#ifndef COLTEXT_HPP
#define COLTEXT_HPP "1.0.0"


#include <iostream>
#include <string>

#include <list>
#include <stack>
#include <unordered_map>


/** 
 * @class Coltext
 * @brief:
 *  Colored text.
 *  
 *  In order to use Coltext ANSI features 
 *  you need to convert strings to it.
 */ 
class Coltext {
public:
    inline Coltext();
    inline Coltext(const std::string &);
    inline Coltext(const char *, size_t );

    Coltext & operator+= (const Coltext &);
    
    friend inline Coltext & operator+  (const Coltext &, const Coltext &);

    friend inline std::istream & operator>> (std::istream &, Coltext &);
    friend inline std::ostream & operator<< (std::ostream &, const Coltext &);

private:
    struct Token {
        enum class Type {
            text,
            effect,
            effect_stop
        };

        Type type;
        std::string value;
    };
    std::list<Token> tokenize(const char *str, size_t len) const noexcept; 
    void apply_effects (std::list<Token> &tokens) const noexcept;


    std::string str;
    std::string colored_str;
};

inline namespace literals {
    Coltext operator"" _col(const char *str, size_t len);
};

namespace ansi {

/** 
 * @enum class Effect
 * @brief:
 *  SGR (Set Graphic Rendition) codes.
 *  Enum of all common ANSI effects that Coltext supprorts.
 * @see: https://en.wikipedia.org/wiki/ANSI_escape_code;
 */ 
enum class Effect {
    reset     = 0, // Reset all effects

/* Foreground (text) style */
    bold      = 1,
    faint     = 2,
    italic    = 3,
    underline = 4,
    blink     = 5,

    reverse   = 7, // Reverse foreground and background colors

    crossed   = 9,

    double_underline = 21, 

/* Turn off foreground effect */
    normal_itensity = 22, // Bold and faint off

    italic_off    = 23,
    underline_off = 24,
    blink_off     = 25,

    reverse_off   = 27,

    crossed_off   = 29,


/* Foreground color */
    black_fg   = 30,
    red_fg     = 31,
    green_fg   = 32,
    yellow_fg  = 33,
    blue_fg    = 34,
    magenta_fg = 35,
    cyan_fg    = 36,
    white_fg   = 37,

    rgb_fg     = 38,
    default_fg = 39,

/* Background color */
    black_bg   = 40,
    red_bg     = 41,
    green_bg   = 42,
    yellow_bg  = 43,
    blue_bg    = 44,
    magenta_bg = 45,
    cyan_bg    = 46,
    white_bg   = 47,

    rgb_bg     = 48,
    default_bg = 49,

/* Frame styles */
 	framed     = 51, 	
 	encircled  = 52,
 	overlined  = 53, 	

/* Turn off frame style */
 	framed_off     = 54, // Framed and encircled off	
 	overlined_off = 55, 

/* Bright colors */
    bright_black_fg   = 90,
    bright_red_fg     = 91,
    bright_green_fg   = 92,
    bright_yellow_fg  = 93,
    bright_blue_fg    = 94,
    bright_magenta_fg = 95,
    bright_cyan_fg    = 96,
    bright_white_fg   = 97,

    bright_black_bg   = 100,
    bright_red_bg     = 101,
    bright_green_bg   = 102,
    bright_yellow_bg  = 103,
    bright_blue_bg    = 104,
    bright_magenta_bg = 105,
    bright_cyan_bg    = 106,
    bright_white_bg   = 107
};

/* Map of opposit effects. Colors can not be canceled like this.*/
const
std::unordered_map<Effect, Effect> effect_off = {
    {Effect::bold, Effect::normal_itensity}, {Effect::faint, Effect::normal_itensity},
     
    {Effect::underline, Effect::underline_off}, {Effect::double_underline, Effect::underline_off},
    {Effect::framed,    Effect::framed_off},    {Effect::encircled,        Effect::framed_off},
    
    {Effect::italic,    Effect::italic_off}, 
    {Effect::blink,     Effect::blink_off},
    {Effect::reverse,   Effect::reverse_off},
    {Effect::crossed,   Effect::crossed_off},
    {Effect::overlined, Effect::overlined_off}
};

/* Map of supported effect acronyms. Format: "#name:" or "#name(". */
const
std::unordered_map<std::string, Effect> name_to_effect = {
/* HTML tags used as acronyms for styles */
    {"bold",      Effect::bold},      {"<b>", Effect::bold},
    {"faint",     Effect::faint},     {"<f>", Effect::faint},
    {"italic",    Effect::italic},    {"<i>", Effect::italic},
    {"underline", Effect::underline}, {"<u>", Effect::underline},
    
/* Not frequently used functions are without acronyms. */
    {"double_underline", Effect::double_underline},

    {"crossed", Effect::crossed},

    {"blink",   Effect::blink}, 
    {"reverse", Effect::reverse},

    {"framed",    Effect::framed}, 
    {"encircled", Effect::encircled},
    {"overlined", Effect::overlined}, 

/* RGB and CMYK used as acronyms for colors */
    {"black",   Effect::black_fg},   {"k", Effect::black_fg},
    {"red",     Effect::red_fg},     {"r", Effect::red_fg},
    {"green",   Effect::green_fg},   {"g", Effect::green_fg},
    {"yellow",  Effect::yellow_fg},  {"y", Effect::yellow_fg},
    {"blue",    Effect::blue_fg},    {"b", Effect::blue_fg},
    {"magenta", Effect::magenta_fg}, {"m", Effect::magenta_fg},
    {"cyan",    Effect::cyan_fg},    {"c", Effect::cyan_fg},
    {"white",   Effect::white_fg},   {"w", Effect::white_fg},

    {"Black",   Effect::black_bg},   {"K", Effect::black_bg},
    {"Red",     Effect::red_bg},     {"R", Effect::red_bg},
    {"Green",   Effect::green_bg},   {"G", Effect::green_bg},
    {"Yellow",  Effect::yellow_bg},  {"Y", Effect::yellow_bg},
    {"Blue",    Effect::blue_bg},    {"B", Effect::blue_bg},
    {"Magenta", Effect::magenta_bg}, {"M", Effect::magenta_bg},
    {"Cyan",    Effect::cyan_bg},    {"C", Effect::cyan_bg},
    {"White",   Effect::white_bg},   {"W", Effect::white_bg},

    {"bright_black",   Effect::bright_black_fg},   {"bk", Effect::bright_black_fg},
    {"bright_red",     Effect::bright_red_fg},     {"br", Effect::bright_red_fg},
    {"bright_green",   Effect::bright_green_fg},   {"bg", Effect::bright_green_fg},
    {"bright_yellow",  Effect::bright_yellow_fg},  {"by", Effect::bright_yellow_fg},
    {"bright_blue",    Effect::bright_blue_fg},    {"bb", Effect::bright_blue_fg},
    {"bright_magenta", Effect::bright_magenta_fg}, {"bm", Effect::bright_magenta_fg},
    {"bright_cyan",    Effect::bright_cyan_fg},    {"bc", Effect::bright_cyan_fg},
    {"bright_white",   Effect::bright_white_fg},   {"bw", Effect::bright_white_fg},

    {"bright_Black",   Effect::bright_black_bg},   {"bK", Effect::bright_black_bg}, 
    {"bright_Red",     Effect::bright_red_bg},     {"bR", Effect::bright_red_bg},
    {"bright_Green",   Effect::bright_green_bg},   {"bG", Effect::bright_green_bg},
    {"bright_Yellow",  Effect::bright_yellow_bg},  {"bY", Effect::bright_yellow_bg},
    {"bright_Blue",    Effect::bright_blue_bg},    {"bB", Effect::bright_blue_bg},
    {"bright_Magenta", Effect::bright_magenta_bg}, {"bM", Effect::bright_magenta_bg},
    {"bright_Cyan",    Effect::bright_cyan_bg},    {"bC", Effect::bright_cyan_bg},
    {"bright_White",   Effect::bright_white_bg},   {"bW", Effect::bright_white_bg}
};

} // inline namespace ansi


inline Coltext::Coltext() 
: str(""),
  colored_str("")
{};

inline Coltext::Coltext(const std::string &str) 
: Coltext::Coltext(str.c_str(), str.size())
{};

inline Coltext::Coltext(const char *str, size_t len)
{
    this->str = std::string(str, len);
    auto tokens = this->tokenize(str, len);
    this->apply_effects(tokens);
    for (const auto &tkn : tokens) this->colored_str += tkn.value;
}

Coltext & Coltext::operator+= (const Coltext &rhs)
{
    return *this = Coltext(this->str + rhs.str);
}

inline std::istream & operator>> (std::istream &is, Coltext &ctxt)
{
    std::string str; std::getline(is, str);

    ctxt = Coltext(str);
    
    return is;
}

inline std::ostream & operator<< (std::ostream &os, const Coltext &ctxt)
{
    return os << ctxt.colored_str;
}

Coltext literals::operator"" _col(const char *str, size_t len)
{
    return Coltext(str, len);
}

std::list<Coltext::Token> 
Coltext::tokenize (const char *str, size_t len) const noexcept
{
    std::list<Token> tokens;
    
    int num_wait_closing = 0;
    bool wait_next_word = false;

    std::string buffer = "";
    for (size_t i = 0; i < len; ++i)
    {  
        char c = str[i];
        if (c == '\\' && i + 1 < len && 
            (str[i+1] == '(' || str[i+1] == ')' || str[i+1] == '#'))
        { 
        /* If parentheses are escaped,
           push them without slash */
            buffer.push_back(str[i+1]);
            ++i;
            continue;
        }
        else
        if (c == '#' || c == '<')
        {/* Coltext tags found */
            
            if (buffer.size() != 0) // Don't flush empty strings
            {
                tokens.push_back({ 
                    Token::Type::text, 
                    buffer
                });
                buffer.clear();
            }

            do { buffer.push_back(str[i]); ++i; }
            while (
                i < len && 
                str[i] != '('  && 
                str[i] != ' ' 
            ); // Get the whole tag

            if (i < len && str[i] == ' ')
            {
                buffer.push_back(' ');
                wait_next_word = true;
            }
            else buffer.push_back('(');

            tokens.push_back({ 
                Token::Type::effect, 
                buffer
            });
            buffer.clear();

            ++num_wait_closing;
            continue;
        }
        else
        if (num_wait_closing > 0 && c == ')')
        {
            --num_wait_closing;

            if (buffer.size() != 0) // In case of #r()
            {
                tokens.push_back({ 
                    Token::Type::text, 
                    buffer
                });
                buffer.clear();
            }

            tokens.push_back({ 
                Token::Type::effect_stop, 
                ")"
            });
            continue;
        }
        else
        if (wait_next_word && c == ' ')
        {
            --num_wait_closing;

            wait_next_word = false;
            tokens.push_back({ 
                Token::Type::text, 
                buffer
            });
            buffer.clear();

            tokens.push_back({ 
                Token::Type::effect_stop, 
                ")"
            });

            buffer.push_back(' ');
            continue;
        }
        else buffer.push_back(c);
    }

    if (buffer.size() != 0)
    {
        tokens.push_back({ 
            Token::Type::text, 
            buffer
        });
        buffer.clear();
    }
    
    for (; num_wait_closing > 0; --num_wait_closing)
    {
        tokens.push_back({ 
            Token::Type::effect_stop, 
            ")"
        });
    }

    return tokens;
}

void
Coltext::apply_effects (std::list<Coltext::Token> &tokens) const noexcept
{
    using namespace ansi;

    std::stack<Effect> effects;

    std::stack<Effect> last_bg({Effect::default_bg});
    std::stack<Effect> last_fg({Effect::default_fg});

    bool ignore_stop = false;

    auto tkn = tokens.begin();
    while (tkn != tokens.end())
    {
        if (tkn->type == Token::Type::text) { ++tkn; continue; }
        
        Effect e;
        if (tkn->type == Token::Type::effect)
        {
            std::string name = tkn->value;
            name.pop_back(); // Delete ' ' or '('

            if (name.at(0) == '#') name.erase(0, 1);

            auto it = ansi::name_to_effect.find(name);
            if (it == ansi::name_to_effect.end())
            {
            /* If it's not a valid effect, 
                we just leave it as text */
                tkn->type = Token::Type::text;
                ignore_stop = true; 
                ++tkn; continue;
            }
            else e = it->second;

            tkn->value = name;

            effects.push(e);
            if ((e >= Effect::black_bg && e <= Effect::white_bg) ||
                (e >= Effect::bright_black_bg && e <= Effect::bright_white_bg))
            {
                last_bg.push(e);
            }
            else
            if ((e >= Effect::black_fg && e <= Effect::white_fg) ||
                (e >= Effect::bright_black_fg && e <= Effect::bright_white_fg))
            {
                last_fg.push(e);
            } 
        }
        else 
        if (tkn->type == Token::Type::effect_stop)
        {
            if (ignore_stop)
            {
                tokens.erase(tkn++);
                ignore_stop = false;
                continue;
            }

            e = effects.top();
            effects.pop();
            
            if ((e >= Effect::black_bg && e <= Effect::white_bg) ||
                (e >= Effect::bright_black_bg && e <= Effect::bright_white_bg))
            {
                last_bg.pop();
                e = last_bg.top();
            }
            else
            if ((e >= Effect::black_fg && e <= Effect::white_fg) ||
                (e >= Effect::bright_black_fg && e <= Effect::bright_white_fg))
            {
                last_fg.pop();
                e = last_fg.top();
            } 
            else e = effect_off.at(e);
        }

        // Create ANSI escape code from effect enum
        std::string escape_code = "\033[" + std::to_string((int)e) + "m";

        tkn->value = escape_code;
        ++tkn; continue;
    }
}

#endif // COLTEXT_HPP