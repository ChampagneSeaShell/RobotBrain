class vec2
{
	public:
	
	union{

	float x;
	float y;
	float p[2];
	}

	
	void Identy()
	{
		this->x = 0;
		this->y = 0;
	}

	vec2 Normalise()
	{
		this->x /= this->Length();
		this->y /= this->Length();
		return this;
	}
	float Length()
	{
		return sqrt(this->x * this->x + this->y * this->y)
	}
	
	inline float& operator[](int index)
	{
		return this->p[index];
	}
	inline const float& operator[](int index) const
	{
		return this->p[index];
	}

	vec2& operator+=(const vec2& rhs)
	{
		this->x += rhs.x;
		this->y += rhs.y;
		return *this;
	}
	vec2& operator-=(const vec2& rhs)
	{
		this->x -= rhs.x;
		this->y -= rhs.y;
		return *this;
	}
};
	
	inline vec2 operator-(vec2 lhs, const vec2& rhs)
	{
		lhs.x -= rhs.x;
		lhs.y -= rhs.y;
		return lhs;
	}
	inline vec2 operator+(vec2 lhs, const vec2& rhs)
	{
		lhs.x += rhs.x;
		lhs.y += rhs.y;
		return lhs;
	}
	
	inline vec2 operator/(vec2 lhs, const vec2& rhs)
	{
		lhs.x /= rhs.x;
		lhs.y /= rhs.y;
		return lhs;
	}
	inline vec2 operator*(vec2 lhs, const vec2& rhs)
	{
		lhs.x *= rhs.x;
		lhs.y *= rhs.y;
		return lhs;
	}
	inline vec2 operator*(vec2 lhs, const float& scale)
	{
		lhs.x *= scale;
		lhs.y *= scale;
		return lhs;
	}

	inline vec2 operator/(vec2 lhs, const float& scale)
	{
		lhs.x /= scale;
		lhs.y /= scale;
		return lhs;
	}
	
	inline X operator+(X lhs, const X& rhs)
{
  lhs += rhs;
  return lhs;
}
