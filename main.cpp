#include <iostream>
#include <fstream>
#include <stdexcept>
#include "main.h"

using namespace std;

ConsoleBox *consoleBox = new ConsoleBox; // Asumiendo que ya está inicializado

void ConsoleBox::new_text()
{
    // Implementación si es necesaria
}

void ConsoleBox::set_text(const string &text)
{
    cout << text << endl;
}

void load_script(const string &filename, bool show_script)
{
    string script;
    ifstream file(filename);

    if (!file.is_open())
    {
        cerr << "Error al abrir el archivo: " << filename << endl;
        return;
    }

    try
    {
        script.assign((istreambuf_iterator<char>(file)),
                       istreambuf_iterator<char>());

        if (show_script)
        {
            cout << ColorConsole::fg_blue << ColorConsole::bg_white;
            cout << script << endl;
        }

        consoleBox->new_text();
        consoleBox->set_text(script);
    }
    catch (const runtime_error &e)
    {
        cerr << "Error durante la lectura del archivo: " << e.what() << endl;
    }
}

void load_script()
{
    string filename;
    cout << "Archivo: ";
    getline(cin, filename); // Cambiado a getline para permitir espacios en el nombre del archivo
    load_script(filename, true);
}

int main()
{
    load_script(); // Llama a la función para cargar el script
    delete consoleBox; // Liberar la memoria asignada
    return 0;
}