#include <iostream>
using namespace std;

// ------------------------------------------------------------
// ESTRATEGIA: interfaz común para todas las estrategias de descuento
// ------------------------------------------------------------
class IEstrategiaDescuento {
public:
    // Aplica el descuento sobre el precio original
    virtual double aplicar(double precio) const = 0;
    virtual ~IEstrategiaDescuento() = default;
};

// Estrategia concreta: sin descuento (devuelve el mismo precio)
class SinDescuento : public IEstrategiaDescuento {
public:
    double aplicar(double precio) const override { return precio; }
};

// Estrategia concreta: descuento fijo (resta una cantidad)
class DescuentoFijo : public IEstrategiaDescuento {
    double monto;   // cantidad a descontar
public:
    DescuentoFijo(double m) : monto(m) {}
    double aplicar(double precio) const override {
        return precio - monto;
    }
};

// Estrategia concreta: descuento porcentual (resta un %)
class DescuentoPorcentaje : public IEstrategiaDescuento {
    double pct;   // porcentaje de descuento (ej: 20 = 20%)
public:
    DescuentoPorcentaje(double p) : pct(p) {}
    double aplicar(double precio) const override {
        return precio * (1 - pct / 100);
    }
};

// ------------------------------------------------------------
// CONTEXTO: usa una estrategia para calcular el precio final
// ------------------------------------------------------------
class CalculadorPrecio {
    IEstrategiaDescuento* estrategia;   // referencia a la estrategia actual
public:
    // Permite cambiar la estrategia en tiempo de ejecución
    void setEstrategia(IEstrategiaDescuento* e) { estrategia = e; }
    // Calcula el precio delegando en la estrategia
    double calcular(double precio) const {
        return estrategia->aplicar(precio);
    }
};

int main() {
    CalculadorPrecio calc;          // creamos el contexto
    SinDescuento sd;                // estrategia: sin descuento
    DescuentoFijo df(10);           // estrategia: descuento fijo de $10
    DescuentoPorcentaje dp(20);     // estrategia: descuento del 20%

    // Probamos cada estrategia
    calc.setEstrategia(&sd);
    cout << "100 sin descuento: " << calc.calcular(100) << endl;

    calc.setEstrategia(&df);
    cout << "100 -10: " << calc.calcular(100) << endl;

    calc.setEstrategia(&dp);
    cout << "100 -20%: " << calc.calcular(100) << endl;

    return 0;
}