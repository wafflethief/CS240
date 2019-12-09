#ifndef HEADER_PLANET
#define HEADER_PLANET
class Planet{
	private:
		int id;
		int pos;
		int distance;
		char type;
	public:
		Planet(){this->id=-1;};
		Planet(int,int);
		int orbit();
		int getID();
		int getDistance();
		int getPos();
		char getType();
		//you may add any additional methods you may need.
};
#endif
