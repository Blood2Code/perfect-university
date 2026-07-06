// Задание 3. Обнаружение и исправление утечек памяти.
// Часть А (утечки) оставлена закомментированной как иллюстрация ошибок,
// Часть Б показывает два безопасных варианта — try/catch и unique_ptr.
#include <iostream>
#include <memory>
#include <stdexcept>
using namespace std;

// ---- Часть А: примеры утечек (для сравнения, не вызываются в main) ----

void createLeak() {
    int* p = new int(100);
    // Утечка №1: нет delete — блок памяти никогда не освобождается.
    delete p; // исправлено
}

void losePointer() {
    int* p = new int(200);
    // Утечка №2: указатель перезаписывается до delete — адрес первого
    // блока теряется безвозвратно, освободить его уже невозможно.
    delete p;               // сначала освобождаем первый блок
    p = new int(300);
    delete p;               // и второй
}

// Утечка №3: если между new[] и delete[] выбрасывается исключение,
// delete[] не выполнится, и массив "утечёт".
void exceptionLeak() {
    int* arr = new int[1000];
    try {
        throw runtime_error("Ошибка!");
    } catch (...) {
        delete[] arr;   // ручная очистка перед пробросом исключения дальше
        throw;
    }
}

// ---- Часть Б: безопасные варианты ----

// Вариант А: try/catch гарантирует delete[] даже при исключении.
void safeArrayWithTryCatch() {
    int* arr = new int[1000];
    try {
        throw runtime_error("Ошибка внутри блока с массивом!");
    } catch (const exception& e) {
        cout << "safeArrayWithTryCatch поймал исключение: " << e.what() << endl;
        delete[] arr;
        return;
    }
}

// Вариант Б: unique_ptr освобождает память автоматически в любом случае —
// это и есть идиома RAII (Resource Acquisition Is Initialization).
void safeArrayWithSmartPtr() {
    unique_ptr<int[]> arr(new int[1000]);
    try {
        throw runtime_error("Ошибка внутри блока с умным указателем!");
    } catch (const exception& e) {
        cout << "safeArrayWithSmartPtr поймал исключение: " << e.what() << endl;
        // delete[] вызывать не нужно — unique_ptr сам освободит память
        // при выходе из области видимости, даже если бы исключение
        // не было поймано здесь.
    }
}

int main() {
    try {
        createLeak();
        losePointer();
        exceptionLeak();
    } catch (const exception& e) {
        cout << "Исключение из exceptionLeak: " << e.what() << endl;
    }

    cout << "\n=== Безопасные варианты (RAII) ===" << endl;
    safeArrayWithTryCatch();
    safeArrayWithSmartPtr();

    return 0;
}
