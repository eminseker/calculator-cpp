# Calculator (C++)

`std::map` + `std::function` ile işlem tablosu kuran, geçmiş tutan hesap makinesi.

## Derleme ve Çalıştırma

```bash
g++ calculator.cpp -o calculator
./calculator 6 "*" 7        # => 42
./calculator 10 / 0         # => Hata: Sifira bolme hatasi
```

## Kapsam

- Sınıflar, `private`/`public` üyelikler
- `std::map<std::string, std::function<...>>` ile strateji deseni
- Lambda ifadeleri
- `try/catch` ile istisna yönetimi
- `std::ostringstream`, `std::vector`
