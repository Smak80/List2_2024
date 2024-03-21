#include "list2.h"
#include <iostream>
using namespace std;
template <typename T>
void show_list(list2<T> lst)
{
	cout << "<-";
	auto curr = lst.first;
	int cnt = 0;
	while (curr)
	{
		cout << curr->data;
		if (++cnt < lst.count) cout << " = ";
		curr = curr->next;
	}
	cout << "->";
}

void main()
{
	setlocale(LC_ALL, "");
	list2<int> lst;
	const int sz = 12;
	int* arr = new int[] {7, 2, 4, 3, -7, -11, 4, 2, 0, 3, 2, 2};
	for (int i = 0; i<sz; i++)
	{
		add(lst, arr[i]);
		show_list(lst);
		cout << endl;
	}
	int val;
	int i;
	i = -1;
	if (get(lst, i, val)) cout << "lst[" << i << "]=" << val << endl;
	i = 0;																  
	if (get(lst, i, val)) cout << "lst[" << i << "]=" << val << endl;
	i = 5;																   
	if (get(lst, i, val)) cout << "lst[" << i << "]=" << val << endl;
	i = 11;																   
	if (get(lst, i, val)) cout << "lst[" << i << "]=" << val << endl;
	i = 12;																   
	if (get(lst, i, val)) cout << "lst[" << i << "]=" << val << endl;
	i = 100;															  
	if (get(lst, i, val)) cout << "lst[" << i << "]=" << val << endl;
	i = -1;
	removeAt(lst, i);
	show_list(lst);
	cout << endl;
	i = 0;
	removeAt(lst, i);
	show_list(lst);
	cout << endl;
	i = 5;
	removeAt(lst, i);
	show_list(lst);
	cout << endl;
	i = 9;
	removeAt(lst, i);
	show_list(lst);
	cout << endl;
	i = 9;
	removeAt(lst, i);
	show_list(lst);
	cout << endl;
	i = 100;
	removeAt(lst, i);
	show_list(lst);
	cout << endl;
	clear(lst);
	show_list(lst);
}