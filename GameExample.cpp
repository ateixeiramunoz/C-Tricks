#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>

// Función para guardar el mapa en un archivo
void guardarEnFichero(const std::string& nombreFichero, const std::map<int, std::string>& datos) {
    std::ofstream archivo(nombreFichero);
    if (!archivo) {
        std::cerr << "Error al abrir el archivo para guardar.\n";
        return;
    }

    for (const auto& [clave, valor] : datos) {
        archivo << clave << " " << valor << '\n';
    }
}

// Función para cargar el mapa desde un archivo
std::map<int, std::string> cargarDesdeFichero(const std::string& nombreFichero) {
    std::map<int, std::string> datos;
    std::ifstream archivo(nombreFichero);
    if (!archivo) {
        std::cerr << "Error al abrir el archivo para lectura.\n";
        return datos;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        std::istringstream ss(linea);
        int clave;
        std::string valor;
        ss >> clave;
        std::getline(ss, valor);
        if (!valor.empty() && valor[0] == ' ') valor.erase(0, 1); // quitar espacio inicial
        datos[clave] = valor;
    }

    return datos;
}

// Función para comparar dos mapas
bool sonIguales(const std::map<int, std::string>& a, const std::map<int, std::string>& b) {
    return a == b;
}

// Simula una búsqueda de ítem por número
void buscarItem(const std::map<int, std::string>& datos) {
    int clave;
    std::cout << "\nIntroduce un número para buscar (ej. 5): ";
    std::cin >> clave;

    auto it = datos.find(clave);
    if (it != datos.end()) {
        std::cout << "¡Has encontrado: " << it->second << "!\n";
    } else {
        std::cout << "No se ha encontrado ningún ítem con ese número.\n";
    }
}

int main() {
    std::map<int, std::string> inventarioOriginal = {
        {1, "espada"},
        {2, "escudo"},
        {3, "poción"},
        {5, "llave"},
        {8, "anillo mágico"}
    };

    const std::string nombreArchivo = "inventario.txt";

    // Guardar el inventario en un fichero
    guardarEnFichero(nombreArchivo, inventarioOriginal);

    // Cargarlo de nuevo desde el fichero
    std::map<int, std::string> inventarioCargado = cargarDesdeFichero(nombreArchivo);

    // Comparar los mapas
    if (sonIguales(inventarioOriginal, inventarioCargado)) {
        std::cout << "✅ El inventario se ha cargado correctamente.\n";
    } else {
        std::cout << "❌ Error: los datos no coinciden.\n";
    }

    // Búsqueda simulando un juego
    buscarItem(inventarioCargado);

    return 0;
}
