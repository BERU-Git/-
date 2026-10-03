#include "all.h"

bool hit_check(float pos1_x,float pos1_y, float radius1, 
	           float pos2_x, float pos2_y, float radius2)
{
	float size_x = pos1_x - pos2_x;    
	float size_y = pos1_y - pos2_y;    

	float distance = (size_x * size_x) + (size_y * size_y);  
	float radius_sum = radius1 + radius2;          

	return (distance <= (radius_sum * radius_sum));          

}
