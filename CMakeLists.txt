cmake_minimum_required(VERSION 3.5)
project(teste VERSION 0.1 LANGUAGES CXX )

include_directories(include)


add_executable( main
                src/administrador.cpp
                src/encomenda.cpp
                src/funcionarios.cpp
                src/main.cpp
                src/pessoa.cpp
                src/porteiro.cpp
                src/residentes.cpp
                src/visitante.cpp
                src/zelador.cpp
                src/seguranca.cpp
                src/test.cpp
                
                )