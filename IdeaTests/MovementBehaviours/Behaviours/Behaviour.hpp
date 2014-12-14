#include <math.h>
#include <vector>

#include <glm/glm.hpp>
using namespace glm;

namespace Behaviours
{
		
	void idenity(glm::vec2 &value)
	{
		value.x = 0;
		value.y = 0;
	}



	class Behaviour
	{
		public:
			virtual vec2 GetDirection(vec2 currentPosition) = 0;
	};

	class Object
	{
		std::vector<Behaviour*> behaviours;

		
		public:
		
		float Radius;
		vec2 CurrentPos;
		vec2 CurrentDirection;
		float CurrentSpeed;
		
		Object(vec2 startPos)
		{
				CurrentPos = startPos;
				CurrentSpeed = 1;
				
		}
		~Object()
		{
			for(int i = 0; i < behaviours.size(); ++i)
			{
				delete behaviours[i];
			}
		}
		
		int AddBehaviour(Behaviour* behaviour)
		{
			behaviours.push_back(behaviour);
			return behaviours.size()-1;
		}
		
		void UpdatePos()
		{
			idenity(CurrentDirection);
			for(int i = 0; i < behaviours.size(); ++i)
			{
				CurrentDirection += behaviours[i]->GetDirection(CurrentPos);
			}
			CurrentPos += CurrentDirection * CurrentSpeed;
		}
	};
}

