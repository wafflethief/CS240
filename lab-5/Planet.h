#ifndef Pl_H
#define Pl_H

class Planet{
public:
	char type;
	int distance;
	unsigned long id;
	static unsigned long s_id;
	/*void A(){
		this->id = s_id++;
	}
	void add(){
		v.push_back(Object());
	}*/

	Planet();
	Planet(int);
	unsigned long getID();
	unsigned int getDistance();
	char getType();
};
#endif
