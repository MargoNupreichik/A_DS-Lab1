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

	Определение и реализация 19 методов для однонаправленных списков.

	Реализовать консольный интерфейс.

	Определить размеры для дальнейшего сбора данных.

	Определить библиотеку для отслеживания времени выполнения функции.

	Создать внешнее приложение для отлова входных данных функций (размер списка, время выполнении операции) и создании графиков на их основе.

*/

// Класс - представление однонаправленного списка.

class OneLinkList
{
public:
	Elem* head; Elem* tail;

	OneLinkList();

	void insLast(int toInsert);												// 1.	добавление в конец списка +
	void insFirst(int toInsert);											// 2.	добавление в начало списка +
	void delLast();															// 3.	удаление последнего элемента +
	void delFirst();														// 4.	удаление первого элемента +
	void insertBefore(int index, int value);								// 5.	добавление элемента по индексу +
	int getElem(int index);													// 6.	получение элемента по индексу +
	void deleteElem(int index);												// 7.	удаление элемента по индексу +
	int getListLen();														// 8.	получение размера списка +
	void deleteAll();														// 9.	удаление всех элементов списка +
	void changeByIndex(int index, int toChange);							// 10.	замена элемента по индексу на передаваемый элемент +
	bool checkIsEmpty();													// 11.	проверка на пустоту списка + 
	void changeDirection();													// 12.	меняет порядок элементов в списке на обратный +
	void insertListAfterIndex(OneLinkList* toInsert, int index);			// 13.	вставка другого списка в список, начиная с индекса +
	void insertListAfterLast(OneLinkList* toInsert);						// 14.	вставка другого списка в конец +
	void insertListBeforeFirst(OneLinkList* toInsert);						// 15.	вставка другого списка в начало + 
	bool ifListInCurrent(OneLinkList* toFind);								// 16.	проверка на содержание другого списка в списке +
	int findFirstEntry(OneLinkList* toFind);								// 17.	поиск первого вхождения другого списка в список +
	int findLastEntry(OneLinkList* toFind);									// 18.	поиск последнего вхождения другого списка в список +
	void changeTwoByIndex(int index1, int index2);							// 19.	обмен двух элементов списка по индексам +

	~OneLinkList();
};


int main()
{
	// menu
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

void OneLinkList::insertBefore(int index, int value)
{
	if (index == (this->getListLen() - 1)) {
		this->insLast(value);
		return;
	}

	if (index == 0) {
		this->insFirst(value);
		return;
	}

	int indexCounter = 0;
	Elem* currentELem = head;

	// идем к указателю на 
	while (index != (indexCounter + 1)) {
		currentELem = currentELem->next;
		indexCounter++;
	}

	Elem* newest = new Elem(value);
	newest->next = currentELem->next;
	currentELem->next = newest;
}

int OneLinkList::getElem(int index)
{
	Elem* current = this->head;
	int indexCounter = 0;
	while (indexCounter != index) {
		indexCounter++;
		current = current->next;
	}
	return *(current->number);
}

void OneLinkList::deleteElem(int index)
{
	if (index == (this->getListLen() - 1)) {
		this->delLast();
		return;
	}

	if (index == 0) {
		this->delFirst();
		return;
	}

	int indexCounter = 0;
	Elem* currentELem = head;

	// идем к указателю на 
	while (index < indexCounter) {
		currentELem = currentELem->next;
		indexCounter++;
	}

	Elem* toDel = currentELem->next;
	currentELem->next = toDel->next;
	delete toDel;
}

int OneLinkList::getListLen()
{
	int indexCount = 0;
	Elem* current = this->head;
	while (current != NULL) {
		indexCount++;
		current = current->next;
	}
	return indexCount;
}

void OneLinkList::deleteAll()
{
	while (head != NULL) {
		this->delFirst();
	}
}

void OneLinkList::changeByIndex(int index, int toChange)
{
	if (index == (this->getListLen() - 1)) {
		*(this->tail->number) = toChange;
		return;
	}

	if (index == 0) {
		*(this->head->number) = toChange;
		return;
	}

	int indexCounter = 0;
	Elem* currentELem = head;

	// идем к указателю на 
	while (index < indexCounter) {
		currentELem = currentELem->next;
		indexCounter++;
	}

	*(currentELem->number) = toChange;
}

bool OneLinkList::checkIsEmpty()
{
	if (this->head == NULL) return true;
	return false;
}

void OneLinkList::changeDirection()
{
	Elem* currentElem = this->head;
	int indexCounter = 0;
	int length = this->getListLen();
	while (indexCounter < length / 2) {
		int fromBeginning = *(currentElem->number);
		int fromEnding = 0; this->getElem(length - indexCounter - 1);
		*(currentElem->number) = fromEnding;
		this->changeByIndex(length - indexCounter - 1, fromBeginning);
		indexCounter++;
		currentElem = currentElem->next;
	}
}

void OneLinkList::insertListAfterIndex(OneLinkList* toInsert, int index)
{
	Elem* toInsertAfter = this->head;
	int indexCounter = 0;
	while (indexCounter < index) {
		toInsertAfter = toInsertAfter->next;
		indexCounter++;
	}
	Elem* willBeAfter = toInsertAfter->next;
	toInsertAfter->next = toInsert->head;
	toInsert->tail->next = willBeAfter;
}

void OneLinkList::insertListAfterLast(OneLinkList* toInsert)
{
	Elem* wasLast = this->tail;
	wasLast->next = toInsert->head;
	this->tail = toInsert->tail;
}

void OneLinkList::insertListBeforeFirst(OneLinkList* toInsert)
{
	Elem* wasFirst = this->head;
	this->head = toInsert->head;
	toInsert->tail->next = wasFirst;
}

bool OneLinkList::ifListInCurrent(OneLinkList* toFind)
{
	Elem* currentL1 = this->head;
	Elem* currentL2 = toFind->head;
	while (currentL1 != NULL && currentL2 != NULL) {
		if (currentL1->number == currentL2->number) {
			bool flag = true;
			Elem* innerCompL1 = currentL1->next;
			while (flag && innerCompL1 != NULL && currentL2 != NULL) {
				if (innerCompL1->number == currentL2->number) {
					innerCompL1 = innerCompL1->next;
					currentL2 = currentL2->next;
				}
				else {
					flag = false;
					currentL2 = toFind->head;
				}
			}
			if (flag) return true;
		}
		else {
			currentL1 = currentL1->next;
		}
	}
	return false;
}

int OneLinkList::findFirstEntry(OneLinkList* toFind)
{
	Elem* currentL1 = this->head;
	Elem* currentL2 = toFind->head;
	int currentIndex = 0;
	while (currentL1 != NULL && currentL2 != NULL) {
		if (currentL1->number == currentL2->number) {
			bool flag = true;
			Elem* innerCompL1 = currentL1->next;
			while (flag && innerCompL1 != NULL && currentL2 != NULL) {
				if (innerCompL1->number == currentL2->number) {
					innerCompL1 = innerCompL1->next;
					currentL2 = currentL2->next;
				}
				else {
					flag = false;
					currentL2 = toFind->head;
				}
			}
			if (flag) return currentIndex;
		}
		else {
			currentL1 = currentL1->next;
			currentIndex++;
		}
	}
	return -1;
}

int OneLinkList::findLastEntry(OneLinkList* toFind)
{
	Elem* currentL1 = this->head;
	Elem* currentL2 = toFind->head;
	int currentIndex = 0; int lastIn = -1;
	while (currentL1 != NULL && currentL2 != NULL) {
		if (currentL1->number == currentL2->number) {
			bool flag = true;
			Elem* innerCompL1 = currentL1->next;
			while (flag && innerCompL1 != NULL && currentL2 != NULL) {
				if (innerCompL1->number == currentL2->number) {
					innerCompL1 = innerCompL1->next;
					currentL2 = currentL2->next;
				}
				else {
					flag = false;
					currentL2 = toFind->head;
				}
			}
			if (flag) { 
				lastIn = currentIndex; 
				currentL1 = innerCompL1;
				currentL2 = toFind->head;
			}
		}
		else {
			currentL1 = currentL1->next;
			currentIndex++;
		}
	}
	return lastIn;
}

void OneLinkList::changeTwoByIndex(int index1, int index2)
{
	Elem* first = NULL; Elem* second = NULL; Elem* currentElem = this->head;
	int currentIndex = 0;
	while (true) {
		if (currentIndex = min(index1, index2)) first = currentElem;
		if (currentIndex = max(index1, index2)) second = currentElem;
		if (first != NULL && second != NULL) break;
		currentIndex++;
	}
	int temp = *(first->number);
	*(first->number) = *(second->number);
	*(second->number) = temp;
}

OneLinkList::~OneLinkList()
{
	while (head != NULL) {
		delFirst(); 
	}
}
