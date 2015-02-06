#include "controller.hpp"
#include "system.hpp"
#include "settings.hpp"

#include <iostream>

using namespace controller;

int main(int argc, char **argv)
{
    // Configurações Iniciais:
    std::ios::sync_with_stdio(false);
    System::setPriority(-20);
    
    int scan;
    std::cout << "Tempo de Scan: ";
    std::cin >> scan;
    getSettings().setScanTime(scan);
    
    // Carrega as configurações.
    Settings::load();
    
    // Inicia o controlador.
    Controller::start();

    return -1;
}

