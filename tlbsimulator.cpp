#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <unordered_set>
#include <iomanip>

using namespace std;

// Definição de como a TLB é implementada
struct TLB {
    size_t size; // size - n° máximo de entradas
    // Utiliza-se uma fila para armazenar os índices de páginas
    // A política de substituição implementada é FIFO
    queue<unsigned long long> entries;
    // entrySet - contém todas as páginas que estão na TLB
    // sendo utilizada para operações de busca
    unordered_set<unsigned long long> entrySet;

    // Construtor: inicializa size com o que foi passado como parâmetro
    TLB(size_t capacity) : size(capacity) {}


    // Função de acesso: retorna true caso o acesso seja bem-sucedido
    // e false, caso tenha ocorrido uma falha.
    bool access(unsigned long long pageNumber) {
        // verifica se a página já está na TLB
        if (entrySet.find(pageNumber) != entrySet.end()) {
            // página está na TLB (Hit), nada feito
            return true;  // Hit
        }

        // Página não está na TLB (Miss)
        // Caso a TLB esteja cheia, remove a página que está há mais tempo na fila
        if (entries.size() == size) {
            entrySet.erase(entries.front());
            entries.pop();
        }


        // Adiciona a nova página na TLB
        entries.push(pageNumber);
        entrySet.insert(pageNumber);
        return false;  // Miss
    }
};

int main() {
    //const string traceFile = "christmastree.trace"; // Nome do arquivo com os traces
    //const string traceFile = "cryptotext.trace"; // Nome do arquivo com os traces
    const string traceFile = "seven.trace"; // Nome do arquivo com os traces
    const size_t pageSize = 4096;  // Tamanho das páginas de 4 KB
    const size_t tlbSize = 16;     // Número de entradas em ambas as TLBs

    TLB iTLB(tlbSize);
    TLB dTLB(tlbSize);

    unsigned long long iHits = 0, iMisses = 0;
    unsigned long long dHits = 0, dMisses = 0;

    ifstream file(traceFile);
    if (!file.is_open()) {
        cerr << "Erro: Não foi possível abrir o arquivo!" << traceFile << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        // Ignora linhas que não são acessos à memória
        if (line.empty() || (line[1] != 'S' && line[1] != 'L' && line[0] != 'I')) {
            continue;
        }

        stringstream ss(line);
        char type;
        string addressStr;
        ss >> type >> addressStr;

        // Extrai endereço de memória ao converter string hexa para inteiro
        unsigned long long address = stoull(addressStr.substr(0, addressStr.find(',')), nullptr, 16);

        // Calcula o número da página
        unsigned long long pageNumber = address / pageSize;

        // Caso seja uma instrução, o acesso é feito na TLB de Instrução
        // Caso seja Load/Store, utiliza-se a TLB de Dados
        if (type == 'I') {
            if (iTLB.access(pageNumber)) {
                ++iHits;
            } else {
                ++iMisses;
            }
        } else if (type == 'L' || type == 'S') {
            if (dTLB.access(pageNumber)) {
                ++dHits;
            } else {
                ++dMisses;
            }
        }
    }

    file.close();

    // Calcula e exibe a taxa de falhas de ambas as TLBs
    unsigned long long iTotalAccesses = iHits + iMisses;
    unsigned long long dTotalAccesses = dHits + dMisses;

    double iMissRate = (iTotalAccesses > 0) ? (static_cast<double>(iMisses) / iTotalAccesses) : 0.0;
    double dMissRate = (dTotalAccesses > 0) ? (static_cast<double>(dMisses) / dTotalAccesses) : 0.0;

    cout << "Acessos bem-sucedidos na TLB de Instrução: " << iHits << endl;
    cout << "Falhas na TLB de Instrução: " << iMisses << endl;
    cout << fixed << setprecision(2) << "Taxa de falhas na TLB de Instrução: " << iMissRate * 100 << "%" << endl << endl;

    cout << "Acessos bem-sucedidos na TLB de Dados: " << dHits << endl;
    cout << "Falhas na TLB de Dados: " << dMisses << endl;
    cout << fixed << setprecision(2) << "Taxa de falhas na TLB de Dados: " << dMissRate * 100 << "%" << endl;

    return 0;
}