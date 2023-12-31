#include <iostream>
#include <vector>
#include <fstream>
#include <limits>

#include "administrador.hpp"

using namespace std;

void Administrador::menuAdministrador(){
    cout << "1- Cadastrar Residente" << endl;
    cout << "2- Cadastrar Funcionário" << endl;
    cout << "3- Listar Residentes" << endl;
    cout << "4- Listar Funcionários" << endl;
    cout << "5- Remover Residente" << endl;
    cout << "6- Remover Funcionário" << endl;
    cout << "7- Buscar Residente" << endl;
    cout << "8- Buscar Funcionário" << endl;
    cout << "9- Sair" << endl;
}

void Administrador::lerArquivo(string nomeArquivo){
    string nome, cpf, dataNascimento, dataEntrada, dataSaida, telefone, email, matricula, funcao, setor, turno;
    int predio, apartamento, andar, vagaGaragem;
    float cargaHoraria, salario;
    vector<string> linhas;
    fstream arquivo;

    arquivo.open(nomeArquivo + ".txt", ios::in | ios::app);

    if(arquivo.is_open()){
        string linha;

        while(getline(arquivo, linha)){
            linhas.push_back(linha);
        }

        arquivo.close();
    } else{
        cout << "Erro ao abrir o arquivo!" << endl;
    }

    for(int i = 0; i < linhas.size(); i+= 4){
        nome           = linhas[i];
        cpf            = linhas[i + 1];
        dataNascimento = linhas[i + 2];

        if(nomeArquivo == "archives/residentes"){
            predio      = stoi(linhas[i + 3]);
            apartamento = stoi(linhas[i + 4]);
            andar       = stoi(linhas[i + 5]);
            vagaGaragem = stoi(linhas[i + 6]);
            dataEntrada = linhas[i + 7];
            dataSaida   = linhas[i + 8];
            telefone    = linhas[i + 9];
            email       = linhas[i + 10];

            Residentes novoResidente(nome, cpf, dataNascimento, predio, apartamento, andar, vagaGaragem, dataEntrada, dataSaida, telefone, email);
            residentes.push_back(novoResidente);

            i += 8;
        } else{
            matricula    = linhas[i + 3];
            funcao       = linhas[i + 4];
            setor        = linhas[i + 5];
            cargaHoraria = stof(linhas[i + 6]);
            salario      = stof(linhas[i + 7]);
            turno        = linhas[i + 8];

            if(nomeArquivo == "archives/zeladores"){
                Zelador novoZelador(nome, cpf, dataNascimento, matricula, funcao, setor, cargaHoraria, salario, turno, true);
                zeladores.push_back(novoZelador);
            }

            if(nomeArquivo == "archives/segurancas"){
                Seguranca novoSeguranca(nome, cpf, dataNascimento, matricula, funcao, setor, cargaHoraria, salario, turno, true);
                segurancas.push_back(novoSeguranca);
            }
            i += 6;
        }
    }
}

void Administrador::atualizarArquivo(string nomeArquivo){
    fstream arquivo;

    arquivo.open(nomeArquivo + ".txt", ios::out);

    if(arquivo.is_open()){
        if(nomeArquivo == "archives/residentes"){
            for(int i = 0; i < residentes.size(); i++){
                arquivo << residentes[i].getNome() << endl;
                arquivo << residentes[i].getCpf() << endl;
                arquivo << residentes[i].getDataNascimento() << endl;
                arquivo << residentes[i].getPredio() << endl;
                arquivo << residentes[i].getApartamento() << endl;
                arquivo << residentes[i].getAndar() << endl;
                arquivo << residentes[i].getVagaGaragem() << endl;
                arquivo << residentes[i].getDataEntrada() << endl;
                arquivo << residentes[i].getDataSaida() << endl;
                arquivo << residentes[i].getTelefone() << endl;
                arquivo << residentes[i].getEmail() << endl;
                arquivo << endl;
            }
        } else if(nomeArquivo == "archives/zeladores"){
            for(int i = 0; i < zeladores.size(); i++){
                arquivo << zeladores[i].getNome() << endl;
                arquivo << zeladores[i].getCpf() << endl;
                arquivo << zeladores[i].getDataNascimento() << endl;
                arquivo << zeladores[i].getMatricula() << endl;
                arquivo << zeladores[i].getFuncao() << endl;
                arquivo << zeladores[i].getSetor() << endl;
                arquivo << zeladores[i].getCargaHoraria() << endl;
                arquivo << zeladores[i].getSalario() << endl;
                arquivo << zeladores[i].getTurno() << endl;
                arquivo << endl;
            }
        } else if(nomeArquivo == "archives/segurancas"){
            for(int i = 0; i < segurancas.size(); i++){
                arquivo << segurancas[i].getNome() << endl;
                arquivo << segurancas[i].getCpf() << endl;
                arquivo << segurancas[i].getDataNascimento() << endl;
                arquivo << segurancas[i].getMatricula() << endl;
                arquivo << segurancas[i].getFuncao() << endl;
                arquivo << segurancas[i].getSetor() << endl;
                arquivo << segurancas[i].getCargaHoraria() << endl;
                arquivo << segurancas[i].getSalario() << endl;
                arquivo << segurancas[i].getTurno() << endl;
                arquivo << endl;
            }
        }
    } else{
        cout << "Erro ao abrir o arquivo!" << endl;
    }
}

int Administrador::lerInt(int numero, std::string msg){
    bool flag = false;

    do{
        try{
            cout << msg;
            cin >> numero;
            if(cin.fail()){
                throw runtime_error("\n---Erro: Digite um número inteiro!---\n");
            } else{
                flag = true;
            }
        } catch(runtime_error &e){
            cout << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while(!flag);

    return numero;
}

float Administrador::lerFloat(float numero, std::string msg){
    bool flag = false;

    do{
        try{
            cout << msg;
            cin >> numero;
            if(cin.fail()){
                throw runtime_error("\n---Erro: Digite um número real!---\n");
            } else{
                flag = true;
            }
        } catch(runtime_error &e){
            cout << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while(!flag);

    return numero;
}

void Administrador::cadastrarResidente(){
    string nome, cpf, dataNascimento, dataEntrada, dataSaida, telefone, email;
    int predio, apartamento, andar, vagaGaragem;

    system("clear||cls");
    cout << "---Casdastro de Residente---" << endl;
    cout << "Nome: ";
    cin.ignore();
    getline(cin, nome);

    cout << "CPF: ";
    getline(cin, cpf);

    cout << "Data de Nascimento: ";
    getline(cin, dataNascimento);

    predio = lerInt(predio, "Número do Prédio: ");

    apartamento = lerInt(apartamento, "Número do Apartamento: ");

    andar = lerInt(andar, "Número do Andar: ");

    vagaGaragem = lerInt(vagaGaragem, "Número da Vaga de Garagem: ");

    cout << "Data de Entrada: ";
    cin.ignore();
    getline(cin, dataEntrada);

    cout << "Data de Saída: ";
    getline(cin, dataSaida);

    cout << "Telefone: ";
    getline(cin, telefone);

    cout << "E-mail: ";
    getline(cin, email);

    Residentes novoResidente(nome, cpf, dataNascimento, predio, apartamento, andar, vagaGaragem, dataEntrada, dataSaida, telefone, email);
    residentes.push_back(novoResidente);

    system("clear || cls");

    cout << "---Residente cadastrado com sucesso!\n" << endl;
}

void Administrador::cadastrarFuncionario(){
    string nome, cpf, dataNascimento, matricula, funcao, setor, turno;
    float cargaHoraria, salario;

    system("clear||cls");

    cout << "---Cadastro de Funcionário---" << endl;
    cin.ignore();
    cout << "Nome: ";
    getline(cin, nome);

    cout << "CPF: ";
    getline(cin, cpf);

    cout << "Data de Nascimento: ";
    getline(cin, dataNascimento);

    cout << "Matrícula: ";
    getline(cin, matricula);

    cout << "Função: ";
    getline(cin, funcao);

    cout << "Setor: ";
    getline(cin, setor);

    cargaHoraria = lerFloat(cargaHoraria, "Carga Horária: ");

    salario = lerFloat(salario, "Salário: ");

    cout << "Turno: ";
    cin.ignore();
    getline(cin, turno);

    system("clear || cls");

    if(funcao == "Zelador" || funcao == "zelador"){
        Zelador novoZelador(nome, cpf, dataNascimento, matricula, funcao, setor, cargaHoraria, salario, turno, false);
        zeladores.push_back(novoZelador);

        cout << "---Zelador cadastrado com sucesso!\n" << endl;
    } else if(funcao == "Segurança" || funcao == "segurança"){
        Seguranca novoSeguranca(nome, cpf, dataNascimento, matricula, funcao, setor, cargaHoraria, salario, turno, false);
        segurancas.push_back(novoSeguranca);

        cout << "---Segurança cadastrado com sucesso!\n" << endl;
    } else{
        cout << "\n---Função inválida!" << endl;
        cout << "---As funções válidas são: Zelador e Segurança\n" << endl;
    }
}

void Administrador::listarResidentes(){
    system("clear || cls");
    if(residentes.size() == 0){
        cout << "---Não há residentes cadastrados!---\n" << endl;
    } else{
        cout << "--------Lista de Residentes--------" << endl;
        for(int i = 0; i < residentes.size(); i++){
        cout << "---Residente N°" << i + 1 << endl;
        cout << "Nome: " << residentes[i].getNome() << endl;
        cout << "CPF: " << residentes[i].getCpf() << endl;
        cout << "Data de Nascimento: " << residentes[i].getDataNascimento() << endl;
        cout << "Número do Prédio: " << residentes[i].getPredio() << endl;
        cout << "Número do Apartamento: " << residentes[i].getApartamento() << endl;
        cout << "Número do Andar: " << residentes[i].getAndar() << endl;
        cout << "Número da Vaga de Garagem: " << residentes[i].getVagaGaragem() << endl;
        cout << "Data de Entrada: " << residentes[i].getDataEntrada() << endl;
        cout << "Data de Saída: " << residentes[i].getDataSaida() << endl;
        cout << "Telefone: " << residentes[i].getTelefone() << endl;
        cout << "E-mail: " << residentes[i].getEmail() << endl;
        cout << "-----------------------------------";
        cout << endl;
        }
    }
}

void Administrador::listarFuncionarios(){
    system("clear || cls");
    cout << "-----------Lista de Funcionários-----------" << endl;

    if(zeladores.size() == 0){
        cout << "\n---Não há zeladores cadastrados!---\n" << endl;
    } else{
        cout << "---Lista de Zeladores---" << endl;
        for(int i = 0; i < zeladores.size(); i++){
            cout << "Zelador N°" << i + 1 << endl;
            cout << "Nome: " << zeladores[i].getNome() << endl;
            cout << "CPF: " << zeladores[i].getCpf() << endl;
            cout << "Data de Nascimento: " << zeladores[i].getDataNascimento() << endl;
            cout << "Matrícula: " << zeladores[i].getMatricula() << endl;
            cout << "Função: " << zeladores[i].getFuncao() << endl;
            cout << "Setor: " << zeladores[i].getSetor() << endl;
            cout << "Carga Horária: " << zeladores[i].getCargaHoraria() << endl;
            cout << "Salário: " << zeladores[i].getSalario() << endl;
            cout << "Turno: " << zeladores[i].getTurno() << endl;
            cout << "-----------------------------------";
            cout << endl;
        }
    }

    if(segurancas.size() == 0){
        cout << "---Não há seguranças cadastrados!---\n" << endl;
    } else{
        cout << "---Lista de Seguranças---" << endl;
        for(int i = 0; i < segurancas.size(); i++){
            cout << "Segurança N°" << i + 1 << endl;
            cout << "Nome: " << segurancas[i].getNome() << endl;
            cout << "CPF: " << segurancas[i].getCpf() << endl;
            cout << "Data de Nascimento: " << segurancas[i].getDataNascimento() << endl;
            cout << "Matrícula: " << segurancas[i].getMatricula() << endl;
            cout << "Função: " << segurancas[i].getFuncao() << endl;
            cout << "Setor: " << segurancas[i].getSetor() << endl;
            cout << "Carga Horária: " << segurancas[i].getCargaHoraria() << endl;
            cout << "Salário: " << segurancas[i].getSalario() << endl;
            cout << "Turno: " << segurancas[i].getTurno() << endl;
            cout << "-----------------------------------";
            cout << endl;
        }
    }
}

void Administrador::removerResidente(){
    string cpf;
    bool residenteEncontrado = false;

    system("clear || cls");
    cout << "       ---Remover Residente---" << endl;
    cout << "Digite o CPF do Residente (000.000.000-00): ";
    cin.ignore();
    getline(cin, cpf);

    for(int i = 0; i < residentes.size(); i++){
        if(residentes[i].getCpf() == cpf){
            residentes.erase(residentes.begin() + i);
            residenteEncontrado = true;
            break;
        }
    }

    if(residenteEncontrado){
        cout << "---Residente removido com sucesso!\n" << endl;
    } else{
        cout << "---Residente não encontrado!\n" << endl;
    }
}

void Administrador::removerFuncionario(){
    string matricula, funcao;
    bool funcionarioEncontrado = false, flag = false;

    system("clear || cls");
    cout << "       ---Remover Funcionário---" << endl;
    cin.ignore();

    do{
        try{
            cout << "Função do Funcionário: ";
            getline(cin, funcao);

            if(funcao != "Zelador" && funcao != "zelador" && funcao != "Segurança" && funcao != "segurança"){
                throw runtime_error("---Erro: Função inválida!---\n");
            } else{
                flag = true;
            }
        } catch(runtime_error &e){
            cout << e.what() << endl;
            cin.clear();
        }
    } while(!flag);

    cout << "Digite a Matrícula do Funcionário: ";
    getline(cin, matricula);

    if(funcao == "Zelador" || funcao == "zelador"){
        for(int i = 0; i < zeladores.size(); i++){
            if(zeladores[i].getMatricula() == matricula){
                zeladores.erase(zeladores.begin() + i);
                funcionarioEncontrado = true;
                break;
            }
        }
    } else if(funcao == "Segurança" || funcao == "segurança"){
        for(int i = 0; i < segurancas.size(); i++){
            if(segurancas[i].getMatricula() == matricula){
                segurancas.erase(segurancas.begin() + i);
                funcionarioEncontrado = true;
                break;
            }
        }
    }

    if(funcionarioEncontrado){
        cout << "---Funcionário removido com sucesso!---\n" << endl;
    } else{
        cout << "\n---Funcionário não encontrado!---\n" << endl;
    }
}

void Administrador::buscarResidente(){
    string cpf;
    bool residenteEncontrado = false;

    system("clear || cls");
    cout << "       ---Buscar Residente---" << endl;
    cout << "Digite o CPF do Residente (000.000.000-00): ";
    cin.ignore();
    getline(cin, cpf);

    for(int i = 0; i < residentes.size(); i++){
        if(residentes[i].getCpf() == cpf){
            cout << "-------Residente encontrado!-------" << endl;
            cout << "Nome: " << residentes[i].getNome() << endl;
            cout << "CPF: " << residentes[i].getCpf() << endl;
            cout << "Data de Nascimento: " << residentes[i].getDataNascimento() << endl;
            cout << "Número do Prédio: " << residentes[i].getPredio() << endl;
            cout << "Número do Apartamento: " << residentes[i].getApartamento() << endl;
            cout << "Número do Andar: " << residentes[i].getAndar() << endl;
            cout << "Número da Vaga de Garagem: " << residentes[i].getVagaGaragem() << endl;
            cout << "Data de Entrada: " << residentes[i].getDataEntrada() << endl;
            cout << "Data de Saída: " << residentes[i].getDataSaida() << endl;
            cout << "Telefone: " << residentes[i].getTelefone() << endl;
            cout << "E-mail: " << residentes[i].getEmail() << endl;
            cout << "-----------------------------------";
            cout << endl;
            residenteEncontrado = true;
            break;
        }
    }

    if(!residenteEncontrado){
        cout << "---Residente não encontrado!\n" << endl;
    }
}

void Administrador::buscarFuncionario(){
    string matricula;
    bool funcionarioEncontrado = false;

    system("clear || cls");
    cout << "       ---Buscar Funcionário---" << endl;

    cout << "Digite a Matrícula do Funcionário: ";
    cin.ignore();
    getline(cin, matricula);

    if(zeladores.size() != 0){
        for(int i = 0; i < zeladores.size(); i++){
            if(zeladores[i].getMatricula() == matricula){
                cout << "------Funcionário encontrado!------" << endl;
                cout << "Nome: " << zeladores[i].getNome() << endl;
                cout << "CPF: " << zeladores[i].getCpf() << endl;
                cout << "Data de Nascimento: " << zeladores[i].getDataNascimento() << endl;
                cout << "Matrícula: " << zeladores[i].getMatricula() << endl;
                cout << "Função: " << zeladores[i].getFuncao() << endl;
                cout << "Setor: " << zeladores[i].getSetor() << endl;
                cout << "Carga Horária: " << zeladores[i].getCargaHoraria() << endl;
                cout << "Salário: " << zeladores[i].getSalario() << endl;
                cout << "Turno: " << zeladores[i].getTurno() << endl;
                cout << "-----------------------------------";
                cout << endl;
                funcionarioEncontrado = true;
                break;
            }
        }
    }

    if(segurancas.size() != 0){
        for(int i = 0; i < segurancas.size(); i++){
            if(segurancas[i].getMatricula() == matricula){
                cout << "------Funcionário encontrado!------" << endl;
                cout << "Nome: " << segurancas[i].getNome() << endl;
                cout << "CPF: " << segurancas[i].getCpf() << endl;
                cout << "Data de Nascimento: " << segurancas[i].getDataNascimento() << endl;
                cout << "Matrícula: " << segurancas[i].getMatricula() << endl;
                cout << "Função: " << segurancas[i].getFuncao() << endl;
                cout << "Setor: " << segurancas[i].getSetor() << endl;
                cout << "Carga Horária: " << segurancas[i].getCargaHoraria() << endl;
                cout << "Salário: " << segurancas[i].getSalario() << endl;
                cout << "Turno: " << segurancas[i].getTurno() << endl;
                cout << "-----------------------------------";
                cout << endl;
                funcionarioEncontrado = true;
                break;
            }
        }
    }

    if(!funcionarioEncontrado){
        system("clear || cls");
        cout << "---Funcionário não encontrado!\n" << endl;
    }
}