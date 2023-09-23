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
	setlocale(LC_ALL, "Russian");

	srand(time(0));

	short int currentMethod = 0;

	cout << "Программа создает 5 списков, длины которых соответственно\nравны 1000, 2000, 3000, 4000, 5000.\n";
	cout << "Значения элементов списка создаются с помощью функции rand()/\n";

	int lenArray[5] = { 10, 20, 30, 40, 50 };

	// Генерация нескольких списков
	OneLinkList* lists[5];
	for (int i = 0; i < 5; i++) {
		lists[i] = new OneLinkList;
		for (int j = 0; j < lenArray[i]; j++) {
			int toAdd = rand();
			lists[i]->insLast(toAdd);
		}
		/*cout << "Список имеет вид:\n";
		for (int j = 0; j < lenArray[i]; j++) {
			cout << lists[i]->getElem(j) << " ";
		}
		cout << endl;*/
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
				cout << "Вставка в" << i+1 << " список после " << index << " элемента." << endl;
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
			for (int i = 0; i < 5; i++) {
				lists[i]->changeDirection();
				cout << "Направление списка " << i + 1 << " было изменено.";
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
			// Вставка списка перед первым элементом
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
				bool isNull = lists[i]->ifListInCurrent(lists[i+1]);
				cout << "Список " << i + 2;
				if (!isNull) cout << " не ";
				cout << " находится в списке " << i+1 << "." << endl;
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
			for (int i = 0; i < 5; i ++) {
				int index1 = rand() * lenArray[i];
				int index2 = rand() * lenArray[i];
				lists[i]->changeByIndex(index1, index2);
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
