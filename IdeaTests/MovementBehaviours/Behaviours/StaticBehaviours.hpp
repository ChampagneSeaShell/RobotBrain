#include <math.h>
#include <vector>

#include <glm/glm.hpp>

namespace Behaviours
{
namespace Static
{

	class Pursue : public Behaviour
	{
	  vec2 targetPos;
	  
	  public:
	  
	  Pursue(vec2 pos)
	  {
		  targetPos = pos;
	  }
	  void SetTarget(vec2 object)
	  {
		targetPos = object;
	  }
	  
	  vec2 GetDirection(vec2 currentPos)
	  {
		vec2 distance = targetPos - currentPos;
		
		vec2 direction = glm::normalize(distance);
		return direction;
	  }

	};
	class Avoid : public Behaviour

	{
	  vec2 avoidTarget;
	  float avoidRadius;
	  
	  public:
	  
	  Avoid(vec2 target, float targetSize=1)
	  {
		  avoidTarget = target;
		  avoidRadius = targetSize;
	  }
	  
	  void SetTarget(vec2 object, float radius)
	  {
		avoidTarget = object;
		avoidRadius = radius; 
	  } 
	  vec2 GetDirection(vec2 currentPos)
	  {
		vec2 distance = avoidTarget- currentPos;
		float realDistance = length(distance);
		if(realDistance > avoidRadius)
		{
		  return -normalize(distance);
		}
	  }
	};
}
}

