#include <map>
#include <set>
#include <iostream>
#include <string>
#include <cstdlib>
#include <queue>
#include <list>
#include <stack>

using namespace std;

bool soncomplementarios(const set<int> & s1,const set<int> &s2);



int main (){

	set<int> s1;
	set<int> s2;
	set<int> s3;
	set<int> s4;
	
	s1.insert(1);
	s1.insert(5);
	s1.insert(7);
	
	s2.insert(2);
	s2.insert(3);
	s2.insert(6);
	
	s3.insert(2);
	s3.insert(3);
	
	s4.insert(2);
	s4.insert(6);

	if (soncomplementarios(s1,s2)){
	
		cout << "Son complementarios \n";
	
	
	}else{
		cout<<"NO son complementarios \n";
	
	}
	
	if (soncomplementarios(s1,s3)){
	
		cout << "Son complementarios \n";
	
	
	}else{
		cout<<"NO son complementarios \n";
	
	}
	
	if (soncomplementarios(s1,s4)){
	
		cout << "Son complementarios \n";
	
	
	}else{
		cout<<"NO son complementarios \n";
	
	}
	


	return 0;
}


bool soncomplementarios(const set<int> & s1,const set<int> &s2){
	
	if (s2.size() != s1.size()-1){
		return false;
	
	}
	auto it = s1.begin();
	auto it2 = s1.begin();
	++it2;
	auto it3 = s2.begin();
	while (it3 != s2.end()){
		if ( *(it3) > *it && *it3 < *it2){
			it = it2;
			++it2;	
			++it3;
		}else{
			return false;
		
		}
		
		
		
	}
	return true;

}

