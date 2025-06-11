
## 📝 ENUNCIADO: Sistema de Votación de un Concurso 🎤🏆 (versión con `struct`)

### 🎯 Descripción general

Vas a desarrollar un programa en C++ para gestionar el sistema de votaciones de un concurso de talentos. Cada participante tiene un **ID**, un **nombre artístico** y un número de **votos recibidos**.

El sistema debe:

1. Leer el listado de participantes desde un fichero.
2. Permitir buscar un participante por nombre.
3. Añadir nuevos participantes.
4. Actualizar el fichero con los cambios.
5. Comprobar si el listado ha sido modificado con respecto a la versión original.

---

### 📁 Formato del fichero `votos.txt`:

```
101 ElFuego 87
102 LaEstrella 94
103 VozProfunda 102
```

---

### 📦 Estructura sugerida

```cpp
struct Participante {
    std::string nombre;
    int votos;
};
```

Usarás un `std::map<int, Participante>` donde:

* `int` es el ID único del participante.
* `Participante` contiene el nombre y los votos.

---

### ✅ Requisitos del programa

* Cargar el fichero `votos.txt` en un `std::map<int, Participante>`.
* Mostrar todos los participantes.
* Buscar por **nombre artístico** y mostrar los votos.
* Añadir un nuevo participante (ID, nombre, votos).
* Guardar todo de nuevo en el fichero.
* Comparar los datos originales con los modificados para detectar si se ha cambiado algo.

---

### 🔧 Recomendaciones técnicas

* Usa `std::getline` y `std::istringstream` para leer las líneas del fichero.
* Asegúrate de que el nombre puede contener espacios (si quieres, usa comillas o lectura especial).
* Usa funciones separadas para:

  * Cargar desde fichero
  * Guardar en fichero
  * Buscar por nombre
  * Comparar dos mapas
  * Mostrar participantes

---

### 🧪 Extensiones opcionales (si quieres subir de nivel):

* Ordenar por número de votos y mostrar el ranking.
* Permitir modificar los votos de un participante existente.
* Bloquear IDs duplicados o nombres repetidos.
* Almacenar también la **edad**, **categoría**, o cualquier otro campo adicional en el `struct`.

---

### 🧠 Ejemplo de uso

```
> Cargando fichero votos.txt...
> Participantes cargados: 3
> ¿Buscar participante por nombre? VozProfunda
> VozProfunda tiene 102 votos.
> ¿Añadir nuevo participante? (s/n): s
> ID: 110
> Nombre: SuperNova
> Votos: 73
> Guardando...
> Comparando inventario original y actual...
> ¡Se ha modificado el fichero!
```
