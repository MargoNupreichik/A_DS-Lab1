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

	Определение и реализация 19 методов для однонаправленных списков. +

	Реализовать консольный интерфейс. +

	Определить размеры для дальнейшего сбора данных.

	Определить библиотеку для отслеживания времени выполнения функции.

	Создать внешнее приложение для отлова входных данных функций (размер списка, время выполнении операции) и создании графиков на их основе.

*/

// Класс - представление однонаправленного списка.

/*
		!!!

		Блок, используемый для отслеживания состояния списка.

		cout << "Список имеет вид:\n";
		for (int j = 0; j < lenArray[i]; j++) {
			cout << lists[i]->getElem(j) << " ";
		}
		cout << endl;

		!!!
*/

class OneLinkList
{
public:
	Elem* head; Elem* tail;

	OneLinkList();
	OneLinkList(OneLinkList* copy);

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
	setlocale(LC_ALL, "Russian");

	srand(time(0));

	short int currentMethod = 0;

	cout << "Программа создает 5 списков, длины которых соответственно\nравны 1000, 2000, 3000, 4000, 5000.\n";
	cout << "Значения элементов списка создаются с помощью функции rand()/\n";

	int lenArray[5] = { 10, 20, 10, 40, 50 };

	// Генерация нескольких списков
	OneLinkList* lists[5];
	for (int i = 0; i < 5; i++) {
		lists[i] = new OneLinkList;
		for (int j = 0; j < lenArray[i]; j++) {
			int toAdd = rand();
			lists[i]->insLast(toAdd);
		}
	}

	cout << "Введите число от 1 по 19 (число соттветствует порядковому\nномеру из списка реализуемых методов)." << endl;
	cout << "Если вы хотите завершить работу программы, введите 0." << endl;
	cin >> currentMethod;
	while (currentMethod) {
		switch (currentMethod) {
		case 1:
			// Вставка в конец.
		{
			cout << "Введите значение, которое нужно вставить в конец списка.\n";
			int insertLast = 0;
			cin >> insertLast;
			for (int i = 0; i < 5; i++) {
				cout << "Вставка в конец " << i + 1 << " списка.\n";
				lists[i]->insLast(insertLast);
				lenArray[i]++;
			}
		}
		break;
		case 2:
			// Вставка в начало
		{
			cout << "Введите значение, которое нужно вставить в начало списка.\n";
			int insertFirst = 0;
			cin >> insertFirst;
			for (int i = 0; i < 5; i++) {
				cout << "Вставка в начало " << i + 1 << " списка.\n";
				lists[i]->insFirst(insertFirst);
				lenArray[i]++;
			}
		}
		break;
		case 3:
			// Удаление последнего элемента.
			for (int i = 0; i < 5; i++) {
				lists[i]->delLast();
				lenArray[i]--;
				cout << "Последний элемент списка " << i + 1 << " удален.\n";
			}
			break;
		case 4:
			// Удаление первого элемента.
			for (int i = 0; i < 5; i++) {
				lists[i]->delFirst();
				lenArray[i]--;
				cout << "Первый элемент списка " << i + 1 << " удален.\n";
			}
			break;
		case 5: // !!!!!!!!!! Где-то падает
			// Вставка перед элеентом с определенным индексом.
		{
			int value = 0, index = 0;
			cout << "Введите значение, которое хотите добавить в список:\n";
			cin >> value;
			cout << "Индекс для каждого списка создается отдельно.\n";
			for (int i = 0; i < 5; i++) {
				index = rand() % lenArray[i];
				lists[i]->insertBefore(index, value);
				cout << "Вставка в" << i + 1 << " список после " << index << " элемента." << endl;
				lenArray[i]++;
			}
		}
		break;
		case 6:
			// Получение элемента по индексу.
		{
			int index = 0;
			for (int i = 0; i < 5; i++) {
				index = rand() % lenArray[i];
				int elem = lists[i]->getElem(index);
				cout << "По индексу " << index << " списка " << i + 1 << " находится значение: " << elem << "." << endl;
			}
		}
		break;
		case 7:
			// Удаление элемента по индексу.
		{
			int index = 0;
			for (int i = 0; i < 5; i++) {
				index = rand() % lenArray[i];
				lists[i]->deleteElem(index);
				cout << "По индексу " << index << " списка " << i + 1 << " был удален элемент." << endl;
				lenArray[i]--;
			}
		}
		break;
		case 8:
			// Получение длины списка.
			for (int i = 0; i < 5; i++) {
				int length = lists[i]->getListLen();
				cout << "Длина списка " << i + 1 << " равна " << length << "." << endl;
			}
			break;
		case 9:
			// Удаление всех элементов списка.
			for (int i = 0; i < 5; i++) {
				lists[i]->deleteAll();
				cout << "Список " << i + 1 << " был полностью очищен." << endl;
				lenArray[i]--;
			}
			break;
		case 10:
			// Заменить значение по индексу.
		{
			int index = 0, value = 0;
			for (int i = 0; i < 5; i++) {
				index = rand() % lenArray[i];
				value = rand();
				cout << "Значение по индексу " << index << " в списке " << i + 1 << " было заменено на " << value << "." << endl;
			}
		}
		break;
		case 11:
			// Проверка на пустой список
			for (int i = 0; i < 5; i++) {
				bool isNull = lists[i]->checkIsEmpty();
				cout << "Список " << i + 1;
				if (!isNull) cout << "не";
				cout << " пуст." << endl;
			}
			break;
		case 12:
			//Поменять направление списка.
			cout << endl;
			for (int i = 0; i < 5; i++) {
				lists[i]->changeDirection();
				cout << "Направление списка " << i + 1 << " было изменено.\n";
			}
			break;
		case 13:
			// Вставка списка после определенного элемента.
			for (int i = 0; i < 4; i += 2) {
				int index = rand() % lenArray[i];
				lists[i]->insertListAfterIndex(lists[i + 1], index);
				lenArray[i] += lenArray[i + 1];
				cout << "Список " << i + 2 << " был вставлен в список " << i + 1 << "после элемента с индексом " << index << "." << endl;
			}
			break;
		case 14:
			// Вставка списка после последнего элемента.
			for (int i = 0; i < 4; i += 2) {
				int index = rand() % lenArray[i];
				lists[i]->insertListAfterLast(lists[i + 1]);
				lenArray[i] += lenArray[i + 1];
				cout << "Список " << i + 2 << " был вставлен в конец списка " << i + 1 << "." << endl;
			}
			break;
		case 15:
			// Вставка списка перед первым элементом.
			for (int i = 0; i < 4; i += 2) {
				int index = rand() % lenArray[i];
				lists[i]->insertListBeforeFirst(lists[i + 1]);
				lenArray[i] += lenArray[i + 1];
				cout << "Список " << i + 2 << " был вставлен в начало списка " << i + 1 << "." << endl;
			}
			break;
		case 16: // !!!!!!!!!!!!!
			// Определить вложен ли список.
			for (int i = 0; i < 4; i += 2) {
				bool isNull = lists[i]->ifListInCurrent(lists[i + 1]);
				cout << "Список " << i + 2;
				if (!isNull) cout << " не ";
				cout << " находится в списке " << i + 1 << "." << endl;
			}
			break;
		case 17:
			// Найти первое вхождение в список другого списка.
			for (int i = 0; i < 4; i += 2) {
				int isIn = lists[i]->findFirstEntry(lists[i + 1]);
				if (!isIn) cout << "Первое вхождение по индексу " << isIn << "." << endl;
				else cout << "Вхождений не обнаружено.\n";
			}
			break;
		case 18:
			// Найти последнее вхождение.
			for (int i = 0; i < 4; i += 2) {
				int isIn = lists[i]->findLastEntry(lists[i + 1]);
				if (!isIn) cout << "Последнее вхождение по индексу " << isIn << "." << endl;
				else cout << "Вхождений не обнаружено.\n";
			}
			break;
		case 19:
			// Поменять значения двух элементов по индексам местами.
			for (int i = 0; i < 5; i++) {
				int index1 = rand() % lenArray[i];
				int index2 = rand() % lenArray[i];
				lists[i]->changeTwoByIndex(index1, index2);
				cout << "В списке " << i + 1 << " изменены значения по индексам " << index1 << " и " << index2 << ".\n";
			}
			break;
		case 0:
			cout << "Работа программы завершена.";
			break;
		default: cout << "Недопустимое значение.\n";
		}
		cin >> currentMethod;
	}
}

void swap(int*& a, int*& b)
{
	int* c = a;
	a = b;
	b = c;
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

OneLinkList::OneLinkList(OneLinkList* copy)
{
	this->head = this->tail = NULL;
	Elem* fromCopy = copy->head;
	while (fromCopy != NULL) {
		this->insLast(*(fromCopy->number));
		fromCopy = fromCopy->next;
	}
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
	for (int i = 0; i < length / 2; i++) {
		this->changeTwoByIndex(i, length - i - 1);
	}
}

void OneLinkList::insertListAfterIndex(OneLinkList* toInsert, int index)
{
	OneLinkList* copied = new OneLinkList(toInsert);

	Elem* toInsertAfter = this->head;
	int indexCounter = 0;

	while (indexCounter < index) {
		toInsertAfter = toInsertAfter->next;
		indexCounter++;
	}

	Elem* wasAfter = toInsertAfter->next;
	toInsertAfter->next = copied->head;
	copied->tail->next = wasAfter;
}

void OneLinkList::insertListAfterLast(OneLinkList* toInsert)
{
	OneLinkList* copied = new OneLinkList(toInsert);
	this->tail = copied->head;

}

void OneLinkList::insertListBeforeFirst(OneLinkList* toInsert)
{
	OneLinkList* copied = new OneLinkList(toInsert);
	Elem* wasHead = this->head;
	this->head = copied->head;
	copied->tail->next = wasHead;
}

bool OneLinkList::ifListInCurrent(OneLinkList* toFind)
{
	Elem* element = this->head;
	Elem* compare = toFind->head;
	int indexCount = 0; bool atLeastOne = false;
	if (element != NULL) {
		do {
			if (*(element->number) == *(compare->number)) {
				while (element != NULL && compare != NULL && (*(element->number) == *(compare->number))) {
					element = element->next;
					compare = compare->next;
				}
				if (compare == NULL) {
					atLeastOne = true;
					break;
				}
				else {
					compare = toFind->head;
				}
			}
			element = element->next;
		} while (element != NULL && !atLeastOne);
	}
	return atLeastOne;
}

int OneLinkList::findFirstEntry(OneLinkList* toFind)
{
	Elem* element = this->head;
	Elem* compare = toFind->head;
	unsigned indexCount = 0; bool atLeastOne = false; int index = 0;
	if (element != NULL) {
		do {
			if (*(element->number) == *(compare->number)) {
				while (element != NULL && compare != NULL && (*(element->number) == *(compare->number))) {
					element = element->next;
					compare = compare->next;
				}
				if (compare == NULL) {
					atLeastOne = true;
					break;
				}
				else {
					compare = toFind->head;
				}
			}
			element = element->next;
			index++;
		} while (element != NULL && !atLeastOne);
	}
	if (atLeastOne) return index;
	else return -1;
}

int OneLinkList::findLastEntry(OneLinkList* toFind)
{
	Elem* element = this->head;
	Elem* compare = toFind->head;
	unsigned indexCount = 0; bool atLeastOne = false;
	int currentIndex = 0; int lasIndex = 0;
	if (element != NULL && compare != NULL) {
		while (element != NULL) {
			if (*(element->number) == *(compare->number)) {
				lasIndex = currentIndex;
				while (element != NULL && compare != NULL && (*(element->number) == *(compare->number))) {
					element = element->next;
					compare = compare->next;
					currentIndex++;
				}
				if (compare == NULL) {
					atLeastOne = true;
					lasIndex = currentIndex;
				}
				compare = toFind->head;
			}
			element = element->next;
		}
	}
	if (atLeastOne) return lasIndex;
	else return -1;
}

void OneLinkList::changeTwoByIndex(int index1, int index2)
{
	Elem* first = this->head; Elem* second = this->head; Elem* currentElem = this->head;
	int length = this->getListLen();
	bool ifFoundFirst = false;

	for (int i = 0; i < length; i++) {
		if ((i == index1 || i == index2) && !ifFoundFirst) {
			first = currentElem;
			ifFoundFirst = true;
		}
		if ((i == index1 || i == index2) && ifFoundFirst) second = currentElem;
		currentElem = currentElem->next;
	}

	swap(*(&first->number), *(&second->number));

}

OneLinkList::~OneLinkList()
{
	while (head != NULL) {
		delFirst();
	}
}
