Aquí tienes una función en C++ que **escribe en un fichero** los datos contenidos en un `std::map<int, std::string>`

```cpp
#include <iostream>
#include <fstream>
#include <map>
#include <string>

// Función para guardar el map en un archivo
void guardarEnFichero(const std::string& nombreFichero, const std::map<int, std::string>& datos) {
    std::ofstream archivo(nombreFichero);
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo para escritura.\n";
        return;
    }

    for (const auto& [clave, valor] : datos) {
        archivo << clave << " " << valor << '\n';
    }

    archivo.close();
}
```

---

### 🔸 Ejemplo de uso:

```cpp
int main() {
    std::map<int, std::string> frutas;
    frutas[3] = "manzana";
    frutas[5] = "pera";
    frutas[7] = "platano";

    guardarEnFichero("frutas.txt", frutas);

    std::cout << "Fichero guardado correctamente.\n";
    return 0;
}
```

---

### 🔹 Resultado en `frutas.txt`:

```
3 manzana
5 pera
7 platano
```

---

Si quieres que los valores puedan contener espacios (por ejemplo `"manzana roja"`), esta función ya lo permite correctamente.
