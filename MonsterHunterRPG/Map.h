#include <iostream>

enum Tile {WALL, PATH, DAMAGE, LAVA, ICE};
enum Alphabet {A, B, C, D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V}

class Map
{
	private:
		struct Position //A-1, A-2, A-3,..., B-1, B-2, B-3, etc...
		{
			int alpha;
			int digit;
		};
		int tileType;
		int dungeonNumber;
		int currentFloor;
		Position currentPosition;
		
		void setTile(Position pos, Tile t); //used by loadMap
		
	public:
		vector< vector<Position> >loadMap(int dungeonNum); //load it from a file
		vector< vector<Position> >& displayMap(); //getMap
		int changeFloor(int currFloor, int direction); //up or down
		Position move(int direction); //setPosition, wasd directions, check in direction for legal move
		Tile& getTileType(); //use current position by default
		Position getCurrentPosition();
		
} map;
