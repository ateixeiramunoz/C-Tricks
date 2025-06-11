# C-Tricks

Cargar un fichero en un `std::map` es una operación muy común. Te muestro cómo hacerlo paso a paso.

---

### 🔹 Supongamos que tienes un fichero `frutas.txt` así:

```
3 manzana
5 pera
7 platano
```

Cada línea tiene una **clave (entero)** y un **valor (cadena)**.

---

### ✅ Código para cargarlo en un `std::map<int, std::string>`

```cpp
#include <iostream>
#include <fstream>
#include <map>
#include <string>

int main() {
    std::map<int, std::string> frutas;

    std::ifstream archivo("frutas.txt");
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo.\n";
        return 1;
    }

    int clave;
    std::string valor;
    while (archivo >> clave >> valor) {
        frutas[clave] = valor;
    }

    // Mostrar contenido del map
    for (const auto& [k, v] : frutas) {
        std::cout << k << ": " << v << '\n';
    }

    return 0;
}
```

---

### 🔸 Salida esperada:

```
3: manzana
5: pera
7: platano
```

---

### 🔹 ¿Y si los valores tienen espacios? (como `manzana roja`)

Entonces hay que leer la línea completa con `std::getline` y separar tú mismo:

#### Ejemplo de `frutas.txt`:

```
3 manzana roja
5 pera verde
```

#### Código adaptado:

```cpp
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <string>

int main() {
    std::map<int, std::string> frutas;

    std::ifstream archivo("frutas.txt");
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo.\n";
        return 1;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        std::istringstream ss(linea);
        int clave;
        ss >> clave;
        std::string valor;
        std::getline(ss, valor);
        if (!valor.empty() && valor[0] == ' ') valor.erase(0, 1); // quitar espacio inicial
        frutas[clave] = valor;
    }

    for (const auto& [k, v] : frutas) {
        std::cout << k << ": " << v << '\n';
    }

    return 0;
}
```
