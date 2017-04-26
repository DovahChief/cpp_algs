#ifndef binsearch_H
#define binsearch_H

#include <vector>

//binsearch para vector ordenado
template <typename T>
bool binsearch(const std::vector<T> &v, T elem){
	int low= 0, high = (v.size()-1);
	while(low <= high){
		int mid = (low+high)/2;
		if (elem == v[mid]) return (true);
		(elem > v[mid]) ? low = mid+1 : high = mid-1;
    } return (false);
}


#endif
