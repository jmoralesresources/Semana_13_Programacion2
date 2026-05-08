#include <iostream>
#include <string>
#include <map>
using namespace std;

// ---------- INTERFAZ ESTRATEGIA ----------
class IEstrategiaDescuento {
public:
    virtual double aplicar(double precio) const = 0;
    virtual ~IEstrategiaDescuento() = default;
};

// Estrategia concreta: sin descuento
class SinDescuento : public IEstrategiaDescuento {
public:
    double aplicar(double precio) const override { return precio; }
};

// Estrategia concreta: descuento porcentual
class DescuentoPorcentaje : public IEstrategiaDescuento {
    double pct;   // porcentaje (ej: 10 = 10%)
public:
    DescuentoPorcentaje(double p) : pct(p) {}
    double aplicar(double precio) const override {
        return precio * (1 - pct / 100);
    }
};

// ---------- FÁBRICA DE ESTRATEGIAS ----------
// La fábrica crea la estrategia adecuada según un código textual.
// Permite ocultar al cliente la creación concreta de las estrategias.
class FabricaDescuentos {
public:
    static IEstrategiaDescuento* crear(const string& codigo) {
        if (codigo == "NINGUNO") return new SinDescuento();
        if (codigo == "10%") return new DescuentoPorcentaje(10);
        if (codigo == "20%") return new DescuentoPorcentaje(20);
        return new SinDescuento();  // por defecto, sin descuento
    }
};

int main() {
    // El cliente solo conoce la interfaz, no necesita saber qué clase concreta se crea
    IEstrategiaDescuento* est = FabricaDescuentos::crear("20%");
    cout << "Precio 100 con 20%: " << est->aplicar(100) << endl;
    delete est;   // liberamos la memoria
    return 0;
}