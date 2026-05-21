# Programa de curso · Programación II

**Logo UNA**  
**Logo EscINF**

## Carrera

Ingeniería de Sistemas de Información con grado en Bachillerato y salida lateral de Diplomado en Programación de Aplicaciones Informáticas.

---

# Semana 13 – Sesión 2  
## Sesión 26

**Duración:** 2 horas  
**Tema:** Patrón Strategy – parte 2 y relación con otros patrones

---

# 1. Tema de la clase

## Patrón Strategy

El patrón **Strategy** permite definir una familia de algoritmos, encapsular cada uno en una clase diferente y hacerlos intercambiables en tiempo de ejecución.

En lugar de colocar muchos `if`, `else if` o `switch` dentro de una misma clase, se delega el comportamiento variable a objetos independientes llamados **estrategias**.

---

# 2. Objetivos de aprendizaje

Al finalizar la clase, el estudiante será capaz de:

1. Explicar el propósito del patrón **Strategy**.
2. Identificar los elementos principales del patrón:
   - Contexto
   - Interfaz estrategia
   - Estrategias concretas
3. Implementar Strategy en C++ usando herencia, polimorfismo y delegación.
4. Diferenciar Strategy de otros patrones como **State**, **Decorator**, **Bridge** y **Factory**.
5. Aplicar Strategy junto con Factory para crear estrategias según una configuración o entrada.

---

# 3. Explicación conceptual

## ¿Qué problema resuelve Strategy?

Strategy se utiliza cuando una clase necesita ejecutar un comportamiento que puede variar.

Por ejemplo:

- Calcular precios con diferentes descuentos.
- Aplicar distintos métodos de pago.
- Ordenar datos con diferentes algoritmos.
- Exportar información en distintos formatos.
- Calcular impuestos según diferentes reglas.

Sin Strategy, se podría tener una clase con muchos condicionales:

```cpp
if (tipo == "NINGUNO") {
    // sin descuento
} else if (tipo == "FIJO") {
    // descuento fijo
} else if (tipo == "PORCENTAJE") {
    // descuento porcentual
}
```

Esto puede funcionar en ejemplos pequeños, pero en sistemas más grandes genera código difícil de mantener.

Con Strategy, cada algoritmo se coloca en una clase separada.

---

# 4. Idea central del patrón

El patrón Strategy se basa en tres elementos:

| Elemento | Descripción |
|---|---|
| Contexto | Clase que necesita usar un algoritmo variable. |
| Interfaz Strategy | Define el método común que todas las estrategias deben implementar. |
| Estrategias concretas | Clases que implementan diferentes versiones del algoritmo. |

---

# 5. Ejemplo base: Strategy para descuentos

## Código completo

```cpp
#include <iostream>
using namespace std;

class IEstrategiaDescuento {
public:
    virtual double aplicar(double precio) const = 0;
    virtual ~IEstrategiaDescuento() = default;
};

class SinDescuento : public IEstrategiaDescuento {
public:
    double aplicar(double precio) const override {
        return precio;
    }
};

class DescuentoFijo : public IEstrategiaDescuento {
private:
    double monto;

public:
    DescuentoFijo(double m) : monto(m) {}

    double aplicar(double precio) const override {
        return precio - monto;
    }
};

class DescuentoPorcentaje : public IEstrategiaDescuento {
private:
    double pct;

public:
    DescuentoPorcentaje(double p) : pct(p) {}

    double aplicar(double precio) const override {
        return precio * (1 - pct / 100);
    }
};

class CalculadorPrecio {
private:
    IEstrategiaDescuento* estrategia;

public:
    CalculadorPrecio() : estrategia(nullptr) {}

    void setEstrategia(IEstrategiaDescuento* e) {
        estrategia = e;
    }

    double calcular(double precio) const {
        if (estrategia == nullptr) {
            return precio;
        }

        return estrategia->aplicar(precio);
    }
};

int main() {
    CalculadorPrecio calc;

    SinDescuento sd;
    DescuentoFijo df(10);
    DescuentoPorcentaje dp(20);

    calc.setEstrategia(&sd);
    cout << "100 sin descuento: " << calc.calcular(100) << endl;

    calc.setEstrategia(&df);
    cout << "100 con descuento fijo de 10: " << calc.calcular(100) << endl;

    calc.setEstrategia(&dp);
    cout << "100 con 20% de descuento: " << calc.calcular(100) << endl;

    return 0;
}
```

---

# 6. Explicación del código

## Interfaz Strategy

```cpp
class IEstrategiaDescuento {
public:
    virtual double aplicar(double precio) const = 0;
    virtual ~IEstrategiaDescuento() = default;
};
```

Esta clase define el contrato que deben cumplir todas las estrategias.

El método:

```cpp
virtual double aplicar(double precio) const = 0;
```

indica que toda estrategia debe saber aplicar un descuento a un precio.

---

## Estrategia concreta: SinDescuento

```cpp
class SinDescuento : public IEstrategiaDescuento {
public:
    double aplicar(double precio) const override {
        return precio;
    }
};
```

Esta estrategia no modifica el precio.

Si el precio es `100`, devuelve `100`.

---

## Estrategia concreta: DescuentoFijo

```cpp
class DescuentoFijo : public IEstrategiaDescuento {
private:
    double monto;

public:
    DescuentoFijo(double m) : monto(m) {}

    double aplicar(double precio) const override {
        return precio - monto;
    }
};
```

Esta estrategia resta un monto fijo al precio.

Por ejemplo:

```cpp
DescuentoFijo df(10);
```

Si el precio es `100`, el resultado será:

```cpp
100 - 10 = 90
```

---

## Estrategia concreta: DescuentoPorcentaje

```cpp
class DescuentoPorcentaje : public IEstrategiaDescuento {
private:
    double pct;

public:
    DescuentoPorcentaje(double p) : pct(p) {}

    double aplicar(double precio) const override {
        return precio * (1 - pct / 100);
    }
};
```

Esta estrategia aplica un porcentaje de descuento.

Por ejemplo:

```cpp
DescuentoPorcentaje dp(20);
```

Si el precio es `100`, el resultado será:

```cpp
100 * (1 - 20 / 100) = 80
```

---

## Contexto: CalculadorPrecio

```cpp
class CalculadorPrecio {
private:
    IEstrategiaDescuento* estrategia;

public:
    CalculadorPrecio() : estrategia(nullptr) {}

    void setEstrategia(IEstrategiaDescuento* e) {
        estrategia = e;
    }

    double calcular(double precio) const {
        if (estrategia == nullptr) {
            return precio;
        }

        return estrategia->aplicar(precio);
    }
};
```

La clase `CalculadorPrecio` no sabe qué descuento se aplicará.

Solo sabe que tiene una estrategia y le delega el cálculo:

```cpp
return estrategia->aplicar(precio);
```

Esto es una idea clave del patrón Strategy:  
**el contexto no implementa el algoritmo, solamente lo delega.**

---

# 7. Resultado esperado

```txt
100 sin descuento: 100
100 con descuento fijo de 10: 90
100 con 20% de descuento: 80
```

---

# 8. Añadiendo una nueva estrategia sin modificar el contexto

Una ventaja importante del patrón Strategy es que permite agregar nuevos algoritmos sin modificar la clase contexto.

Por ejemplo, se puede agregar una estrategia llamada `DescuentoPorCantidad`.

## Nueva estrategia

```cpp
class DescuentoPorCantidad : public IEstrategiaDescuento {
private:
    int cantidad;

public:
    DescuentoPorCantidad(int c) : cantidad(c) {}

    double aplicar(double precio) const override {
        if (cantidad >= 5) {
            return precio * 0.85;
        }

        return precio;
    }
};
```

Esta estrategia aplica un 15% de descuento si la cantidad es mayor o igual a 5.

---

## Uso en el `main`

```cpp
DescuentoPorCantidad dc(6);

calc.setEstrategia(&dc);
cout << "100 con descuento por cantidad: " << calc.calcular(100) << endl;
```

Resultado esperado:

```txt
100 con descuento por cantidad: 85
```

---

# 9. Ventaja principal del patrón Strategy

La clase `CalculadorPrecio` no se modifica cuando aparece una nueva forma de descuento.

Solo se agrega una nueva clase que implemente la interfaz:

```cpp
class NuevaEstrategia : public IEstrategiaDescuento {
public:
    double aplicar(double precio) const override {
        // nuevo algoritmo
    }
};
```

Esto favorece el principio de diseño:

## Principio Abierto-Cerrado

Una clase debe estar abierta a la extensión, pero cerrada a la modificación.

En este caso:

- Se extiende el sistema agregando nuevas estrategias.
- No se modifica la clase `CalculadorPrecio`.

---

# 10. Diagrama de clases

```mermaid
classDiagram
    class IEstrategiaDescuento {
        <<interface>>
        +aplicar(double precio) double
    }

    class SinDescuento {
        +aplicar(double precio) double
    }

    class DescuentoFijo {
        -double monto
        +DescuentoFijo(double m)
        +aplicar(double precio) double
    }

    class DescuentoPorcentaje {
        -double pct
        +DescuentoPorcentaje(double p)
        +aplicar(double precio) double
    }

    class DescuentoPorCantidad {
        -int cantidad
        +DescuentoPorCantidad(int c)
        +aplicar(double precio) double
    }

    class CalculadorPrecio {
        -IEstrategiaDescuento* estrategia
        +setEstrategia(IEstrategiaDescuento* e) void
        +calcular(double precio) double
    }

    IEstrategiaDescuento <|-- SinDescuento
    IEstrategiaDescuento <|-- DescuentoFijo
    IEstrategiaDescuento <|-- DescuentoPorcentaje
    IEstrategiaDescuento <|-- DescuentoPorCantidad

    CalculadorPrecio --> IEstrategiaDescuento : usa
```

---

# 11. Strategy junto con Factory

## ¿Por qué combinar Strategy con Factory?

En el ejemplo anterior, el cliente crea directamente las estrategias:

```cpp
SinDescuento sd;
DescuentoFijo df(10);
DescuentoPorcentaje dp(20);
```

Pero en sistemas reales, muchas veces se desea que el cliente no tenga que conocer qué clase concreta debe instanciar.

Para eso se puede usar una fábrica.

La fábrica recibe un código y devuelve la estrategia adecuada.

---

# 12. Ejemplo: Strategy + Factory

```cpp
#include <iostream>
#include <string>
using namespace std;

class IEstrategiaDescuento {
public:
    virtual double aplicar(double precio) const = 0;
    virtual ~IEstrategiaDescuento() = default;
};

class SinDescuento : public IEstrategiaDescuento {
public:
    double aplicar(double precio) const override {
        return precio;
    }
};

class DescuentoFijo : public IEstrategiaDescuento {
private:
    double monto;

public:
    DescuentoFijo(double m) : monto(m) {}

    double aplicar(double precio) const override {
        return precio - monto;
    }
};

class DescuentoPorcentaje : public IEstrategiaDescuento {
private:
    double pct;

public:
    DescuentoPorcentaje(double p) : pct(p) {}

    double aplicar(double precio) const override {
        return precio * (1 - pct / 100);
    }
};

class FabricaDescuentos {
public:
    static IEstrategiaDescuento* crear(const string& codigo) {
        if (codigo == "NINGUNO") {
            return new SinDescuento();
        }

        if (codigo == "FIJO") {
            return new DescuentoFijo(10);
        }

        if (codigo == "PORCENTAJE") {
            return new DescuentoPorcentaje(20);
        }

        return new SinDescuento();
    }
};

class CalculadorPrecio {
private:
    IEstrategiaDescuento* estrategia;

public:
    CalculadorPrecio() : estrategia(nullptr) {}

    void setEstrategia(IEstrategiaDescuento* e) {
        estrategia = e;
    }

    double calcular(double precio) const {
        if (estrategia == nullptr) {
            return precio;
        }

        return estrategia->aplicar(precio);
    }
};

int main() {
    CalculadorPrecio calc;

    IEstrategiaDescuento* estrategia = FabricaDescuentos::crear("PORCENTAJE");

    calc.setEstrategia(estrategia);

    cout << "Precio 100 con estrategia PORCENTAJE: ";
    cout << calc.calcular(100) << endl;

    delete estrategia;

    return 0;
}
```

---

# 13. Explicación de Strategy + Factory

La fábrica recibe un código:

```cpp
FabricaDescuentos::crear("PORCENTAJE");
```

Y devuelve un objeto de tipo:

```cpp
IEstrategiaDescuento*
```

El cliente no necesita saber si internamente se creó:

```cpp
new SinDescuento();
new DescuentoFijo(10);
new DescuentoPorcentaje(20);
```

Esto reduce el acoplamiento entre el cliente y las clases concretas.

---

# 14. Resultado esperado

```txt
Precio 100 con estrategia PORCENTAJE: 80
```

---

# 15. Strategy vs State

## Similitudes

Strategy y State son patrones que usan:

- Composición.
- Herencia.
- Polimorfismo.
- Delegación.
- Una interfaz común.
- Clases concretas que modifican el comportamiento.

Ambos permiten cambiar el comportamiento de un objeto sin llenar la clase principal de condicionales.

---

## Diferencias principales

| Aspecto | Strategy | State |
|---|---|---|
| Qué cambia | El algoritmo utilizado. | El comportamiento según el estado interno. |
| Quién decide el cambio | Normalmente el cliente o configuración externa. | Normalmente el propio objeto según eventos internos. |
| Uso típico | Seleccionar una forma de hacer algo. | Representar cambios de estado en un ciclo de vida. |
| Ejemplo | Escoger descuento fijo o porcentual. | Pedido: pendiente, pagado, enviado, cancelado. |

---

# 16. Ejemplo conceptual

## Strategy

```cpp
calc.setEstrategia(&descuentoPorcentaje);
```

El cliente decide qué estrategia usar.

---

## State

```cpp
pedido.pagar();
pedido.enviar();
pedido.cancelar();
```

El objeto cambia su comportamiento dependiendo de su estado actual.

Por ejemplo, un pedido cancelado no debería poder enviarse.

---

# 17. Delegación como idea común

La delegación aparece en varios patrones de diseño.

| Patrón | Qué delega |
|---|---|
| Strategy | Delega un algoritmo. |
| State | Delega comportamiento según el estado. |
| Decorator | Delega en el objeto envuelto y añade funcionalidad. |
| Bridge | Delega la implementación a otra jerarquía. |

---

# 18. Comparación breve con otros patrones

## Strategy

Se usa cuando se desea cambiar un algoritmo.

Ejemplo:

```txt
Calcular precio con descuento fijo, porcentual o sin descuento.
```

---

## State

Se usa cuando un objeto cambia su comportamiento según su estado interno.

Ejemplo:

```txt
Un pedido puede estar pendiente, pagado, enviado o cancelado.
```

---

## Decorator

Se usa para agregar responsabilidades a un objeto sin modificar su clase original.

Ejemplo:

```txt
Café básico + leche + chocolate + crema.
```

---

## Bridge

Se usa para separar una abstracción de su implementación.

Ejemplo:

```txt
Control remoto que puede funcionar con TV, radio o proyector.
```

---

# 19. Actividad en clase

## Actividad 1: Identificación del patrón

Analice el siguiente caso:

Una tienda necesita aplicar distintos tipos de descuento:

- Sin descuento.
- Descuento fijo.
- Descuento porcentual.
- Descuento por cantidad.
- Descuento por cliente frecuente.

Responda:

1. ¿Cuál sería el contexto?
2. ¿Cuál sería la interfaz Strategy?
3. ¿Cuáles serían las estrategias concretas?
4. ¿Qué clase debería encargarse de crear las estrategias?
5. ¿Dónde se aplica la delegación?

---

# 20. Actividad 2: Modificación del ejemplo

Agregue una nueva estrategia llamada:

```cpp
DescuentoClienteFrecuente
```

Regla:

- Si el cliente tiene más de 2 años de antigüedad, aplica 12% de descuento.
- Si tiene 2 años o menos, no aplica descuento.

Restricción:

No debe modificar la clase `CalculadorPrecio`.

---

# 21. Actividad 3: Discusión

Responda en parejas:

1. ¿Por qué Strategy ayuda a evitar muchos `if` o `switch`?
2. ¿Qué ventaja tiene usar una interfaz?
3. ¿Qué pasaría si se quisiera agregar una nueva estrategia?
4. ¿Por qué Factory puede ayudar a mejorar el diseño?
5. ¿En qué se parece Strategy a State?
6. ¿En qué se diferencia Strategy de State?

---

# 22. Ejercicios de tarea

## Ejercicio 1

Implemente un `CalculadorPrecio` que use una estrategia `IEstrategiaDescuento`.

La interfaz debe tener el método:

```cpp
double aplicar(double precio)
```

Debe implementar las siguientes estrategias:

1. `SinDescuento`
2. `DescuentoFijo`
3. `DescuentoPorcentaje`

El calculador debe tener un método:

```cpp
double calcular(double precio)
```

Este método debe delegar el cálculo en la estrategia seleccionada.

---

## Ejercicio 2

Añada una nueva estrategia llamada:

```cpp
DescuentoPorCantidad
```

Regla:

- Si la cantidad es mayor o igual a 5, se aplica un 15% de descuento.
- Si la cantidad es menor que 5, no se aplica descuento.

Restricción:

No modifique la clase `CalculadorPrecio`.

Solo debe crear una nueva clase de estrategia y utilizarla en el `main`.

---

## Ejercicio 3

Implemente una clase:

```cpp
FabricaDescuentos
```

La fábrica debe recibir un código de descuento:

```cpp
"NINGUNO"
"FIJO"
"PORCENTAJE"
"CANTIDAD"
```

Y debe devolver un objeto de tipo:

```cpp
IEstrategiaDescuento*
```

El cliente debe usar únicamente:

- La fábrica.
- El calculador.

No debe instanciar estrategias directamente.

---

## Ejercicio 4

Compare Strategy y State en un párrafo.

Debe incluir:

1. Una similitud.
2. Una diferencia.
3. Un ejemplo de Strategy.
4. Un ejemplo de State.

---

## Ejercicio 5

Liste tres situaciones reales, fuera del curso, donde se podría aplicar el patrón Strategy.

Ejemplos:

- Métodos de pago.
- Algoritmos de búsqueda.
- Formatos de exportación.
- Métodos de envío.
- Cálculo de impuestos.
- Validaciones de formularios.

---

# 23. Preguntas de repaso

1. ¿Qué es una estrategia?
2. ¿Qué es el contexto?
3. ¿Por qué el contexto no debería conocer las clases concretas?
4. ¿Qué ventaja tiene usar polimorfismo?
5. ¿Qué problema se genera si se usan muchos `if` o `switch`?
6. ¿Cómo ayuda Factory a Strategy?
7. ¿Cuál es la diferencia entre cambiar un algoritmo y cambiar un estado?
8. ¿Por qué Strategy favorece el principio abierto-cerrado?

---

# 24. Cierre de la clase

El patrón Strategy permite separar los algoritmos de la clase que los utiliza.

Su idea central es:

> El contexto no resuelve directamente el comportamiento variable, sino que lo delega en una estrategia.

Esto permite crear sistemas más flexibles, extensibles y fáciles de mantener.

Además, Strategy puede combinarse con Factory para crear la estrategia adecuada sin que el cliente conozca las clases concretas.

---

# 25. Referencia

Freeman, E., & Robson, E. (2020). *Head First Design Patterns: Building Extensible and Maintainable Object-Oriented Software* (2nd ed.). O’Reilly Media.
