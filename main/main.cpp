/**
 * Copyright 2014 Lucas Nunes de Lima
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 **/

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

