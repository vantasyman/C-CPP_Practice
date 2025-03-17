#pragma once
#include "map_RBTree.h"
namespace my_map_set {
	template<class K, class V>
	class map {
	public:
		struct MapKeyOfT {
			K operator()(const pair<K, V>& kv) {
				return kv.first;
			}
		};
		typedef typename RBTree<K, pair<K, V>, MapKeyOfT>::iterator iterator;
		bool Insert(const pair<K, V>& _pair) {
			return _t.insert(_pair);
		}
		bool Erase(const K& x) {
			return _t.erase(x);
		}
		iterator begin() {
			return _t.begin();
		}
		iterator end() {
			return _t.end();
		}
	private:
		RBTree<K,pair<K, V>,MapKeyOfT> _t;
	};


	template<class K>
	class set {
	public:
		struct SetKeyOfT {
			K operator()(const K& k) {
				return k;
			}
		};
		bool Insert(const K& _data) {
			return _t.insert(_data);
		}
	private:
		RBTree<K,K, SetKeyOfT> _t;

	};
}
