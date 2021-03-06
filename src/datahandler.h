#ifndef _DATAHANDLER
#define _DATAHANDLER

#include <cstddef>
#include <memory>

namespace Vector {
class Coord {
	Coord ();
public:
	Coord (int _x, int _y) : x (_x), y (_y) {}
	int x;
	int y;
	Coord & operator += (const Coord & delta) {
		x += delta.x;
		y += delta.y;
		return *this;
	}
	Coord & operator -= (const Coord & delta) {
		x -= delta.x;
		y -= delta.y;
		return *this;
	}
	Coord operator + (const Coord & delta) const {
		return Coord (x + delta.x, y + delta.y);
	}
	Coord operator - (const Coord & delta) const {
		return Coord (x - delta.x, y - delta.y);
	}
	Coord operator / (const int & rhs) const {
		return Coord (x / rhs, y / rhs);
	}
	Coord operator * (const int & rhs) const {
		return Coord (x * rhs, y * rhs);
	}
};
}

namespace Linked {

template <typename T>
class List {
	std::shared_ptr<T> & obj;
	List * next;
	List * prev;
	public:
	List (T & elem) : obj(&elem), next(nullptr), prev(nullptr) {}

	List (T * elem) : obj (elem), next(nullptr), prev(nullptr) {}

	List * operator + (List * elem) {
		if (next == elem || this == elem) return nullptr;
		if (next != nullptr) { *elem + next; }
		next = elem;
		*elem - this;
		return this;
	}

	List * operator + (List & elem) {
		return this + &elem;
	}

	List * operator + (std::nullptr_t) {
		if (next == nullptr) return nullptr;
		List * temp = next;
		next = nullptr;
		*temp - nullptr;
		return this;
	}

	List * operator + (T * elem) {
		return this + new List (elem);
	}

	List * operator + (T & elem) {
		return this + &elem;
	}

	List * operator - (List * elem) {
		if (prev == elem) return nullptr;
		if (prev != nullptr) { *elem - prev; }
		prev = elem;
		*elem + this;
		return this;
	}

	List * operator - (List & elem) {
		return this + &elem;
	}

	List * operator - (const std::nullptr_t) {
		if (prev == nullptr) return nullptr;
		List * temp = prev;
		prev = nullptr;
		*temp + nullptr;
		return this;
	}

	List * operator - (T * elem) {
		return this - new List (elem);
	}

	List * operator - (T & elem) {
		return this - &elem;
	}

	List * operator -- () const {
		return prev;
	}

	List * operator ++ () const {
		return next;
	}

	List * remove () {
		List * tmpNext = next;
		List * tmpPrev = prev;
		this + nullptr;
		this - nullptr;
		if (tmpNext != nullptr) { 
			if (tmpPrev != nullptr) {
		        	*tmpPrev + tmpNext;
				return tmpPrev;
			}
			return tmpNext;
		}
		return nullptr;
	}

	List * operator ! () {
		return remove ();
	}

	List & begin () const {
		return *this;
	}

	const bool end () const {
		return next == nullptr;
	}

	operator T () {
		return *obj;
	}

	operator T * () {
		return obj;
	}

	~List () {
		remove ();
		obj = nullptr;
	}
};
}

#endif
