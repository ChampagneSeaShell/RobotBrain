#include <math.h>
#include <vector>

#include <glm/glm.hpp>

namespace Behaviours
{
namespace Dynamic
{

	class Pursue : public Behaviour
	{
	  Object* target;
	  
	  public:
	  
	  Pursue(Object* tar)
	  {
		  target = tar;
	  }
	  void SetTarget(Object* object)
	  {
		target = object;
	  }
	  
	  vec2 GetDirection(vec2 currentPos)
	  {
		vec2 distance = target->CurrentPos - currentPos;
		
		vec2 direction = glm::normalize(distance);
		return direction;
	  }

	};
	class Avoid : public Behaviour

	{
	  Object* avoidTarget;
	  float avoidRadius;
	  
	  public:
	  
	  Avoid(Object* target, float targetSize=1)
	  {
		  avoidTarget = target;
		  avoidRadius = targetSize;
	  }
	  
	  void SetTarget(Object* object, float radius)
	  {
		avoidTarget = object;
		avoidRadius = radius; 
	  } 
	  vec2 GetDirection(vec2 currentPos)
	  {
		vec2 distance = avoidTarget->CurrentPos - currentPos;
		float realDistance = length(distance);
		if(realDistance > avoidRadius)
		{
		  return -normalize(distance);
		}
	  }
	};
}
}

