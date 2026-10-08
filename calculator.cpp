// Basit hesap makinesi — C++ örneği.
//
// Derleme:  g++ calculator.cpp -o calculator
// Kullanım: ./calculator 6 "*" 7
#include <functional>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

class Calculator {
public:
    Calculator() {
        operations_["+"] = [](double a, double b) { return a + b; };
        operations_["-"] = [](double a, double b) { return a - b; };
        operations_["*"] = [](double a, double b) { return a * b; };
        operations_["/"] = [](double a, double b) {
            if (b == 0.0) {
                throw std::domain_error("Sifira bolme hatasi");
            }
            return a / b;
        };
    }

    double calculate(double a, const std::string& op, double b) {
        auto it = operations_.find(op);
        if (it == operations_.end()) {
            throw std::invalid_argument("Bilinmeyen islem: " + op);
        }
        double result = it->second(a, b);
        std::ostringstream entry;
        entry << a << " " << op << " " << b << " = " << result;
        history_.push_back(entry.str());
        return result;
    }

    const std::vector<std::string>& history() const { return history_; }

private:
    std::map<std::string, std::function<double(double, double)>> operations_;
    std::vector<std::string> history_;
};

static void printResult(double result) {
    if (result == static_cast<long long>(result)) {
        std::cout << static_cast<long long>(result) << std::endl;
    } else {
        std::cout << result << std::endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Kullanim: " << argv[0] << " <sayi> <islem> <sayi>" << std::endl;
        return 1;
    }

    try {
        double a = std::stod(argv[1]);
        std::string op = argv[2];
        double b = std::stod(argv[3]);

        Calculator calc;
        printResult(calc.calculate(a, op, b));
    } catch (const std::exception& e) {
        std::cerr << "Hata: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
