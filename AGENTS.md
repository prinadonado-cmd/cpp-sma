# Инструкции для ИИ-агента

## Назначение проекта

cpp-sma — учебный проект на C++20 для вычисления простой скользящей
средней. При изменениях сохраняй понятность кода для начинающего студента.

## Структура

- include/ — публичные заголовки.
- src/ — реализация вычислений.
- app/ — демонстрационная программа.
- tests/ — тесты GoogleTest.
- benchmarks/ — измерения Google Benchmark.
- .github/workflows/ci.yml — сборка, проверки и публикация документации.
- Doxyfile — настройки Doxygen.
- README.md — описание проекта и инструкции пользователю.
- docs/ — сгенерированная документация, не хранится в Git.

## Контракт calculate_sma

- Допустимое окно: от 1 до prices.size().
- Недопустимое окно вызывает std::invalid_argument.
- Пустой вход недопустим.
- Входные данные не изменяются.
- Результат содержит prices.size() - window + 1 элементов.
- Вычисляются только полные окна.

## Команды Windows

Выполнять из корня проекта в Developer PowerShell с доступным MSVC:

```powershell
cmake -S . -B build-release -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=cl
cmake --build build-release
ctest --test-dir build-release --output-on-failure --no-tests=error
.\build-release\sma_benchmark.exe --benchmark_min_time=0.2s
```

## Команды Linux

Выполнять из корня проекта при установленных GCC, CMake и Ninja:

```bash
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=g++
cmake --build build --parallel 2
ctest --test-dir build --output-on-failure --no-tests=error
./build/sma_benchmark --benchmark_min_time=0.2s
```

## Документация

При установленном Doxygen: doxygen Doxyfile.
Результат: docs/html/index.html.
Обновляй комментарии Doxygen и README при изменении поведения программы.

## Оформление кода

- Используй C++20 и отступы в четыре пробела.
- Для обычных функций и переменных используй snake_case.
- Для бенчмарков допустим принятый шаблон BM_Sma.
- Разделяй интерфейс в include/ и реализацию в src/.
- Предпочитай стандартные контейнеры и автоматическое управление ресурсами.
- Комментарии должны объяснять назначение и причины решений.

## Проверки и ограничения

- После изменения C++ или CMake собери проект, запусти тесты и бенчмарк.
- При изменении поведения добавь или обнови содержательные тесты.
- После изменения документации проверь генерацию Doxygen.
- Если проверку выполнить невозможно, сообщи об этом явно.
- Не меняй публичный интерфейс, CI/CD и версии зависимостей без запроса.
- Не удаляй тесты и не ослабляй проверки ради успешного результата.
- Не добавляй в Git build/, build-release/, out/, .vs/ и docs/.
- В итоговом сообщении объясни изменения и перечисли выполненные проверки.