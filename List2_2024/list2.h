#pragma once

template <typename T>
struct list2_elem
{
	T data;
	list2_elem* next = nullptr;
	list2_elem* prev = nullptr;
};

template <typename T>
struct list2
{
	list2_elem<T>* first = nullptr;
	list2_elem<T>* last = nullptr;
	int count = 0;
};

template <typename T>
void add(list2<T>& list, T value)
{
	list2_elem<T>* new_el = new list2_elem<T>;
	new_el->data = value;
	if (list.count == 0)
	{
		list.last = list.first = new_el;
	}
	else
	{
		if (value <= list.first->data)
		{
			list.first->prev = new_el;
			new_el->next = list.first;
			list.first = new_el;
		}
		else if (value >= list.last->data)
		{
			list.last->next = new_el;
			new_el->prev = list.last;
			list.last = new_el;
		}
		else 
		{
			auto curr = list.first->next;
			while (curr && curr->data < value) curr = curr->next;
			curr->prev->next = new_el;
			new_el->prev = curr->prev;
			new_el->next = curr;
			curr->prev = new_el;
		}
	}
	++list.count;
}

template <typename T>
void clear(list2<T>& list)
{
	auto curr = list.first;
	while (curr)
	{
		auto del = curr;
		curr = curr->next;
		delete del;
	}
	list.first = list.last = nullptr;
	list.count = 0;
}

template <typename T>
bool get(list2<T> list, int index, T& value)
{
	if (index < 0 || index >= list.count) return false;
	bool forward = index < list.count / 2;
	auto curr = forward ? list.first : list.last;
	int i = 0;
	const int limit = forward ? index : list.count - index - 1;
	while (i++ < limit)
	{
		curr = forward ? curr->next : curr->prev;
	}
	value = curr->data;
	return true;
}

template <typename T>
bool removeAt(list2<T> list, int index)
{

}