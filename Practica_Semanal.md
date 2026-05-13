| <div align="right"><img src="../../Logo-UNA-Rojo_FondoTransparente%20(2).png" width="120" alt="Logo UNA" /></div> | | <p align="right"><img src="../../images.jpeg" width="120" alt="Logo EscINF" /></p> |
|:----------------------------------------------------|:-------------------------------------------------------------:|------------------------------------------------------------:|

**Programa de curso** · **Programación II**  
**Carrera:** Ingeniería de Sistemas de Información con grado en Bachillerato y salida lateral de Diplomado en Programación de Aplicaciones Informáticas.

---

# Semana 13 – Práctica semanal

**Contenidos:** Patrón Strategy.

---

## Actividad 1 (Strategy)

- Interfaz `IEstrategiaDescuento` con `double aplicar(double precio)`. Implementaciones: SinDescuento, DescuentoFijo(10%), DescuentoPorcentaje(20%).
- Clase `CalculadorPrecio` que recibe la estrategia (inyección) y tiene `double calcular(double precio)`. En `main` use distintas estrategias sin modificar el calculador.

---

## Actividad 2 (Strategy + Factory)

- `FabricaDescuentos` con método que recibe un código ("FIJO", "PORCENTAJE", "NINGUNO") y devuelve la estrategia correspondiente. El cliente usa la fábrica y el calculador; no crea estrategias concretas directamente.

---

## Actividad 3 (Strategy vs State)

- En MD redacte un párrafo: similitudes entre Strategy y State (composición, delegación) y diferencias (quién cambia la estrategia/estado y cuándo). Dé un ejemplo de uso típico de cada uno.

---

**Formato de entrega:** Código y documentación en **archivo(s) MD (Markdown)**.
