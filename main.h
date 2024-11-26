#ifndef MAIN_H
#define MAIN_H

#include <string>

struct ColorConsole
{
    static constexpr auto fg_blue = "\033[34m";
    static constexpr auto bg_white = "\033[47m";
};

struct ConsoleBox
{
    void new_text();
    void set_text(const std::string &text);
};

void load_script(const std::string &filename, bool show_script = false);
void load_script();
void initialize_consoleBox();

#endif
