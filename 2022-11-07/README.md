# Упражнение 5


### Въпроси: Какъв е резултата от изпълнението на следните фрагменти код?

```cpp
int i = 42;
int *m = &i;

std::cout << (m == &m[0]) << std::endl;
std::cout << (m + 5 == &m[5]) << std::endl;
std::cout << *m << ' ' << m[0] << std::endl;
std::cout << *(m + 5) << ' ' << m[5] << std::endl;
```

```cpp
char c = 'c';
void *ptr = &c;

std::cout << ptr << std::endl;
std::cout << ptr + 1 << std::endl;
std::cout << *ptr << std::endl;
```

```cpp
void foo(int x) {
	std::cout << x + 1 << std::endl;
}

void foo(double x) {
	std::cout << 2 * x << std::endl;
}

foo(5);
foo(3.1415);
```

```cpp
int foo(int i) {
	return i + 1;
}

int foo(int *ptr) {
	if (ptr == NULL) {
		return 42;
	}
	return ptr[0];
}

int i = 5;
std::cout << foo(i) << std::endl;
std::cout << foo(&i) << std::endl;
std::cout << foo(NULL) << std::endl;
```


### Полезни линккове:
- [`<exception>`](https://en.cppreference.com/w/cpp/error/exception): смислени изключения за C++ (подобно на Java/C#).

- [Function overloading](https://en.cppreference.com/w/cpp/language/overload_resolution): правила как C++ решава коя дефиниция ще се извика (Прилично сложни! Само ако сте силно заинтересовани).

- [`nullptr`](https://en.cppreference.com/w/cpp/language/nullptr): смислено дефиниран _`NULL`_!

- [`size_t`](https://en.cppreference.com/w/cpp/types/size_t): правилният тип за индексиране/обхождане/размер на масиви!


### Функции с указатели (pointers) и масиви:
```cpp
bool areEqual(const int * const array1, const int * const array2, const size_t size) {
	for (size_t i = 0; i < size; i++) {
		if (array1[i] != array2[i]) {
			return false;
		}
	}
	return true;
}

template <typename T>
T sumElements(const T * const xs, const size_t n) {
	T res = 0;
	for (size_t i = 0; i < n; i ++) {
		res += xs[i];
	}
	return res;
}
```


## Задачи

1. [Hamming distance](https://en.wikipedia.org/wiki/Hamming_distance): Дефинирайте функция, която приема два масива с една и съща дължина и връща броя на различаващите се елементи на една и съща позиция в двата масива.

_Примери:_
- {1, 2, 2, 4}, {1, 2, 3, 4} -> 1
- {1, 2, 2, 4}, {1, 2, 4, 2} -> 2


2. Дефинирайте функция, която приема целочислен масив и цифра и връща колко общо пъти цифрата се среща във всички елементи на масива.

_Примери:_
- {1, 2, 333, 7}, 1 -> 1
- {1, 2, 333, 7}, 3 -> 3


3. Дефинирайте функция, която приема два целочислени масива (с потенциално различни дължини) и отпечатва всички елементи, които се срещат в и двата. Каква е сложността на вашата функция? Как бихте могли да я подобрите?

_Примери:_
- {1, 2, 3, 4}, {3, 7, 5, 1} -> отпечатва 1, 3 или 3, 1


4. Дефинирайте функция, която приема целочислен масив и пренарежда елементите му така, че всички прости числа в масива да се намират преди всички съставни числа и връща броя на простите числа в масива. Каква е сложността на функцията? (Mоже да приемете, че проверката дали едно число е просто отнема константно време).

_Примери:_
- {2, 3, 8, 12, 5, 6, 17, 1} -> {2, 3, 5, 17, 8, 12, 6, 1} + връща 4


5. Дефинирайте функция, която приема целочислен масив и отпечатва стартовия индекс и дължината на най-дългата последователност от повтарящи се едно след друго числа в масива.

_Примери:_
- {2, 2, 2, 3, 3, 5, 5, 5, 5, 1, 2, 3, 2, 2, 2, 3} -> индекс 5 и дължина 4


6. а). Дефинирайте функция, която приема два масива (с потенциално различни дължини), чиито елементи са подредени в нарастващ ред и трети масив - с дължина равна на сбора на дължините на предните два - и записава в него всички елементи от първите два масива в нарастващ ред.
   б). [Merge-sort](https://en.wikipedia.org/wiki/Merge_sort): Използвайте предната функция, за да напишете функция, която сортира един масив в нарастващ ред.

_Примери:_
- {1, 2, 15, 27}, {8, 12, 25} -> {1, 2, 8, 12, 15, 25, 27}


7. [Levenstein distance](https://en.wikipedia.org/wiki/Levenshtein_distance): Дефинирайте функция, която приема два масива с потенциално различни дължини и връща най-малкият брой промени нужни, за да превърнем единия в другия. Позволените промени са: добавяне на елемент (insertion); премахване на елемент (deleteion), замяна на стойността на даден елемент (substitution).

_Примери:_
- {1, 2, 3, 4}, {1, 2, 3} -> 1
- {1, 2, 3, 4}, {1, 2, 4} -> 1
- {1, 2, 3, 4}, {1, 2, 4, 3} -> 2
- {1, 2, 3, 4}, {1, 2, 4, 5} -> 2
