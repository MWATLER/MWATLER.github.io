//KeyValue.h - class declaration for a key value pair

#ifndef _KEYVALUE_H_
#define _KEYVALUE_H_

template <class K, class V>
class KeyValue {
	K key{};
	V value{};
public:
	KeyValue(K _key, V _value) {
		key = _key;
		value = _value;
	}
	K Key() const { return key; }
	V Value() const { return value; }
	void SetValue(V val) { value = val; }
};

#endif// _KEYVALUE_H_