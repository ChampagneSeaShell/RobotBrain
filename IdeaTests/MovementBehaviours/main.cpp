#include "Behaviours/Behaviour.hpp"
#include "Behaviours/StaticBehaviours.hpp"
#include "Behaviours/DynamicBehaviours.hpp"
#include <iostream>
using namespace std;

void PrintVector(vec2 vec)
{
	cout << "( X:"<<vec.x << ", Y:"<<vec.y << ")";
}
int main()
{
		Behaviours::Object bob(vec2(0,0));
		Behaviours::Object geoff(vec2(100,100));
		bob.AddBehaviour(new Behaviours::Dynamic::Avoid(&geoff));
		bob.AddBehaviour(new Behaviours::Static::Pursue(vec2(100,100)));
		geoff.AddBehaviour(new Behaviours::Dynamic::Pursue( &bob ));
		
		int steps = 1;
		while(steps != -1)
		{
			while(steps--)
			{
				bob.UpdatePos();
				geoff.UpdatePos();
			}
			//print location
			cout << "Bob Pos: ";
			PrintVector(bob.CurrentPos);
			cout << "\nBob Direction";
			PrintVector(bob.CurrentDirection);
			
			cout << "\n\nGeoff Pos";
			PrintVector(geoff.CurrentPos);
			cout << "\nGeoff Direction";
			PrintVector(geoff.CurrentDirection);
			
			cout << "\n\n-----------------------\n Enter Number:";
			cin >> steps;
		}
		return 1;
}
