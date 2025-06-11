Vamos a desglosar **`for (const auto& [clave, valor] : datos)`** para entender bien qué significa cada parte, especialmente **`const auto&`**.

---
### 🔹 ¿Qué hace ese `for`?

Está recorriendo un `std::map<int, std::string>`, que almacena **pares clave-valor**.
Cada elemento del `map` es un `std::pair<const int, std::string>`.

---

### 🔹 ¿Qué significa `const auto&`?

| Parte   | Significado                                                                                               |
| ------- | --------------------------------------------------------------------------------------------------------- |
| `auto`  | El compilador deduce automáticamente el tipo (`std::pair<const int, std::string>` en este caso).          |
| `&`     | Es una **referencia**, para evitar copiar el par clave-valor en cada iteración (ahorra memoria y tiempo). |
| `const` | Indica que **no se va a modificar** el elemento dentro del bucle. Protege de errores accidentales.        |

---

### 🔸 ¿Y el `[clave, valor]`?

Esto se llama **estructuración de bindings** (desde C++17), y descompone el `pair` en dos variables:

* `clave` → el primer elemento del par (`pair.first`)
* `valor` → el segundo (`pair.second`)

---

### 🔸 Equivalente sin estructuración

```cpp
for (const std::pair<const int, std::string>& par : datos) {
    archivo << par.first << " " << par.second << '\n';
}
```

O incluso:

```cpp
for (auto it = datos.begin(); it != datos.end(); ++it) {
    archivo << it->first << " " << it->second << '\n';
}
```

---

### ✅ Resumen

```cpp
for (const auto& [clave, valor] : datos)
```

* Recorre todos los pares del `map`
* No copia los pares (usa referencia)
* No permite modificarlos (por `const`)
* Separa automáticamente cada par en `clave` y `valor` para usar cómodamente

---
