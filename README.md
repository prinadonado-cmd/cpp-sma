# cpp-sma

Учебный проект на C++20: вычисление простой скользящей средней
(SMA, Simple Moving Average).

[Документация Doxygen](https://prinadonado-cmd.github.io/cpp-sma/)

## Что делает программа

Функция calculate_sma получает последовательность цен и размер окна.
Для каждого полного окна она вычисляет среднее арифметическое.

Пример: для цен [10, 20, 30, 40] и окна 3 результат равен [20, 30].

Правила:
- Размер окна должен быть от 1 до количества входных элементов.
- При недопустимом окне выбрасывается std::invalid_argument.
- Пустой вход также приводит к std::invalid_argument.
- Входные данные не изменяются.
- Количество результатов равно n - window + 1.

Текущая реализация имеет временную сложность O(n * window).

Демонстрационная программа sma_app выводит: SMA: 20 30.

## Структура

- include/ — публичный интерфейс библиотеки.
- src/ — реализация SMA.
- app/ — демонстрационная программа.
- tests/ — модульные тесты GoogleTest.
- benchmarks/ — измерения Google Benchmark.
- .github/workflows/ci.yml — автоматические проверки и публикация.
- Doxyfile — настройки генерации документации.
- AGENTS.md — инструкции для ИИ-агента.

## Требования

- Компилятор с поддержкой C++20.
- CMake версии 3.26 или новее.
- Ninja.
- Git для получения проекта.

На Windows используется MSVC из Visual Studio с компонентами разработки
на C++. Команды выполняются в Developer PowerShell.

GoogleTest и Google Benchmark загружаются через CMake FetchContent.
Для первоначальной настройки сборки требуется доступ в интернет.

## Получение проекта

```text
git clone https://github.com/prinadonado-cmd/cpp-sma.git
cd cpp-sma
```

## Windows: сборка, запуск, тесты и бенчмарк

В Developer PowerShell из корня проекта:

```powershell
cmake -S . -B build-release -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=cl
cmake --build build-release
.\build-release\sma_app.exe
ctest --test-dir build-release --output-on-failure --no-tests=error
.\build-release\sma_benchmark.exe --benchmark_min_time=0.2s
```

## Linux: сборка, запуск, тесты и бенчмарк

При установленных GCC, CMake и Ninja, из корня проекта:

```bash
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=g++
cmake --build build --parallel 2
./build/sma_app
ctest --test-dir build --output-on-failure --no-tests=error
./build/sma_benchmark --benchmark_min_time=0.2s
```

## Проверки и измерения

Тесты проверяют обычное вычисление, окно 1, окно на весь вход,
дробные значения и недопустимые входные данные.

Бенчмарк измеряет три случая:
- 1000 чисел, окно 10.
- 10000 чисел, окно 10.
- 10000 чисел, окно 100.

Подготовка входного массива выполняется вне измеряемого цикла.
Время включает вычисление, создание результата и его освобождение.
Результаты зависят от оборудования и нагрузки.

## Документация и CI

При push и pull request GitHub Actions собирает проект, запускает тесты,
бенчмарк и генерацию документации.

После успешных проверок ветки main документация автоматически
публикуется на GitHub Pages.

Для локальной генерации при установленном Doxygen:

```text
doxygen Doxyfile
```

Главная страница результата: docs/html/index.html.