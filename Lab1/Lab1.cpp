// Lab1.cpp Нупрейчик Маргарита, гр. 2309, вариант 6

#include <iostream>

using namespace std;

// Класс - представление элемента однонаправленого списка

class Elem 
{
public:
	int* number; // число, хранящееся в элементе
	Elem* next; // ссылка на следующий элемент
	Elem(int number);
};

/*
	Список задач:
	1.	добавление в конец списка
	2.	добавление в начало списка
	3.	удаление последнего элемента
	4.	удаление первого элемента
	5.	добавление элемента по индексу (вставка перед элементом, который был ранее доступен по этому индексу)
	6.	получение элемента по индексу
	7.	удаление элемента по индексу
	8.	получение размера списка
	9.	удаление всех элементов списка 
	10.	замена элемента по индексу на передаваемый элемент
	11.	проверка на пустоту списка
	12.	меняет порядок элементов в списке на обратный
	13.	вставка другого списка в список, начиная с индекса
	14.	вставка другого списка в конец
	15.	вставка другого списка в начало
	16.	проверка на содержание другого списка в списке, можно сделать целочисленного типа
	17.	поиск первого вхождения другого списка в список
	18.	поиск последнего вхождения другого списка в список
	19.	обмен двух элементов списка по индексам

	Реализовать консольный интерфейс.

*/

// Класс - представление однонаправленного списка.

class OneLinkList 
{
public:
	Elem* head; Elem* tail;
	
	OneLinkList();

	void insLast(int toInsert);						// 1.	добавление в конец списка +
	void insFirst(int toInsert);					// 2.	добавление в начало списка +
	void delLast();									// 3.	удаление последнего элемента +
	void delFirst();								// 4.	удаление первого элемента +
	void insertBefore(int index);					// 5.	добавление элемента по индексу
	void getElem(int index);						// 6.	получение элемента по индексу
	void deleteElem(int index);						// 7.	удаление элемента по индексу
	void getListLen();								// 8.	получение размера списка
	void deleteAll();								// 9.	удаление всех элементов списка 
	void changeByIndex(int toChange);				// 10.	замена элемента по индексу на передаваемый элемент
	void checkIfEmpty();							// 11.	проверка на пустоту списка
	void changeDirection();							// 12.	меняет порядок элементов в списке на обратный
	void insertListAfterIndex(int index);			// 13.	вставка другого списка в список, начиная с индекса
	void insertListAfterLast();						// 14.	вставка другого списка в конец
	void insertListBeforeFirst();					// 15.	вставка другого списка в начало
	void ifListInCurrent(OneLinkList toFind);		// 16.	проверка на содержание другого списка в списке, можно сделать целочисленного типа
	void findFirstEntry(OneLinkList toFind);		// 17.	поиск первого вхождения другого списка в список
	void findLastEntry(OneLinkList toFind);			// 18.	поиск последнего вхождения другого списка в список
	void changeTwoByIndex(int index1, int index2);  // 19.	обмен двух элементов списка по индексам
	
	void printData();

	~OneLinkList();
};


int main()
{
    cout << "Hello World!\n";
}

Elem::Elem(int numb) 
{
	this->number = new int; 
	*(this->number) = numb;
	this->next = NULL;
};

OneLinkList::OneLinkList()
{
	this->head = NULL;
	this->tail = NULL;
}

void OneLinkList::insLast(int toInsert)
{
	Elem* elem = new Elem(toInsert);
	if (head == NULL) head = elem;
	if (tail != NULL) tail->next = elem;
	tail = elem;
}

void OneLinkList::insFirst(int toInsert)
{
	Elem* elem = new Elem(toInsert);
	if (head == NULL) head = elem;
	else {
		elem->next = head;
		head = elem;
	}
}

void OneLinkList::delLast()
{
	Elem* preLast = this->head;

	if (preLast == NULL) cout << "List is empty.\n";
	else {
		// переходим к предпоследнему элементу
		while (preLast->next != this->tail && preLast->next != NULL) {
			preLast = preLast->next;
		}

		// проверка на единственность элемента в списке
		if (preLast == head) {
			cout << "You're deleting the only element.\n";
			delete preLast;
		}
		else {
			delete preLast->next;
		}
	}
}

void OneLinkList::delFirst()
{
	if (head == NULL) return;
	if (head == tail) { // один элемент в односвязном списке
		delete tail;
		head = NULL; tail = NULL;
		return;
	}
	// в списке 2 и более элементов
	Elem* elem = head;
	head = elem->next;
	delete elem;

}

void OneLinkList::insertBefore(int index)
{
	if (index < 0) {
		cout << "Index must be positive.\n";
		return;
	}
	
	int indexCounter = 0;
	Elem* currentELem = head;

	// идем к указателю на 
	while (currentELem != NULL && index > indexCounter) {
		currentELem = currentELem->next;
		indexCounter++;
	}

	// 2 случая: индекс больше чем длина списка - 1 ИЛИ все нормально

	// if (currentELem == NULL && index)
}

void OneLinkList::getElem(int index)
{
}

void OneLinkList::deleteElem(int index)
{
}

void OneLinkList::getListLen()
{
}

void OneLinkList::deleteAll()
{
}

void OneLinkList::changeByIndex(int toChange)
{
}

void OneLinkList::checkIfEmpty()
{
}

void OneLinkList::changeDirection()
{
}

void OneLinkList::insertListAfterIndex(int index)
{
}

void OneLinkList::insertListAfterLast()
{
}

void OneLinkList::insertListBeforeFirst()
{
}

void OneLinkList::ifListInCurrent(OneLinkList toFind)
{
}

void OneLinkList::findFirstEntry(OneLinkList toFind)
{
}

void OneLinkList::findLastEntry(OneLinkList toFind)
{
}

void OneLinkList::changeTwoByIndex(int index1, int index2)
{
}

void OneLinkList::printData()
{
}

OneLinkList::~OneLinkList()
{
	while (head != NULL) {
		delFirst(); // удаление первого элемента списка, выполняется, пока список не очистится полностью.
	}
}
