#include <iostream>
#include "win.cpp"

int main() {
    const unsigned count = 5; // Количество временных меток
    TimeMeter timer(count);

    // Установка временных меток
    for (unsigned i = 0; i < count; ++i) {
        Sleep(100); // Задержка для наглядности
        timer.setTimeStamp(i);
        std::cout << "Временная метка " << i << " установлена." << std::endl;
    }

    // Получение и вывод временных меток
    for (unsigned i = 0; i < count; ++i) {
        double timeStamp = timer.getSTimeStamp(i);
        std::cout << "Временная метка " << i << ": " << timeStamp << " секунд." << std::endl;
    }

    // Вычисление разницы между двумя временными метками
    double diff = timer.getSDiff(0, 1);
    std::cout << "Разница между метками 0 и 1: " << diff << " секунд." << std::endl;

    // Проверка, меньше ли одна метка другой
    if (timer.isLess(0, 1, 0.2)) {
        std::cout << "Метрика 0 меньше метрики 1 с учётом ожидаемого значения." << std::endl;
    }

    return 0;
}
