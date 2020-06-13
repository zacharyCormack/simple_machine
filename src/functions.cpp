#include "functions.hpp"
#include "Force.hpp"
#include <cmath>

line add_lines(line a, line b)
{
	return (line)
	{
		{0, a.x[0]+b.x[0]-a.x[1]-b.x[1]},
		{0, a.y[0]+b.y[0]-a.y[1]-b.y[1]},
		{0, a.z[0]+b.z[0]-a.z[1]-b.z[1]}
	};
}

line sub_lines(line a, line b)
{
	return (line)
	{
		{0, a.x[0]-b.x[0]-a.x[1]+b.x[1]},
		{0, a.y[0]-b.y[0]-a.y[1]+b.y[1]},
		{0, a.z[0]-b.z[0]-a.z[1]+b.z[1]}
	};
}

angle measure(line a, line b)
{
	angle angle_a_z = num_to_ang(atan((a.z[1]-a.z[0]) / sqrt(a.x[1]-a.x[0])*(a.x[1]-a.x[0]) + (a.y[1]-a.y[0])*(a.y[1]-a.y[0])));
	angle angle_a = num_to_ang(atan(sqrt((a.y[1]-a.y[0])*(a.y[1]-a.y[0]) + (a.z[1]-a.z[0])*(a.z[1]-a.z[0])) / (a.x[1]-a.x[0])));
	angle angle_b_z = num_to_ang(atan((b.z[1]-b.z[0]) / sqrt(b.x[1]-b.x[0])*(b.x[1]-b.x[0]) + (b.y[1]-b.y[0])*(b.y[1]-b.y[0])));
	angle angle_b = num_to_ang(atan(sqrt((b.y[1]-b.y[0])*(b.y[1]-a.y[0]) + (b.z[1]-b.z[0])*(b.z[1]-b.z[0])) / (b.x[1]-b.x[0])));
	return
	num_to_ang(ang_to_num(angle_a) - acos(sqrt(
		cos(ang_to_num(angle_b)) * cos(ang_to_num(angle_b)) +
		cos(ang_to_num(angle_a_z)+ang_to_num(angle_b_z)) * cos(ang_to_num(angle_a_z)+ang_to_num(angle_b_z))
	)));
}

double ang_to_num(angle ang)
{
	return (ang.portion / (char)255) * 2 * M_PI;
}

angle num_to_ang(double num)
{
	a:
	if (num > 2*M_PI)
	{
		num -= 2*M_PI;
		goto a;
	}
	else if (num < 0)
	{
		num += 2*M_PI;
		goto a;
	}
	return (angle){(char)floor(num*256)};
}

line uvec(line vec)
{
	double len = line_dist(vec);
	vec.x[1] = (vec.x[1] - vec.x[0]) / len;
	vec.y[1] = (vec.y[1] - vec.y[0]) / len;
	vec.z[1] = (vec.z[1] - vec.z[0]) / len;
	vec.x[0] = 0;
	vec.y[0] = 0;
	vec.z[0] = 0;
}

line uvec(angle vecxy, angle vecz)
{
	return (line)
	{
		.x = {0, cos(ang_to_num(vecxy))*cos(ang_to_num(vecz))},
		.y = {0, sin(ang_to_num(vecxy))*cos(ang_to_num(vecz))},
		.z = {0, sin(ang_to_num(vecxy))}
	};
}


//mag[0] is magnitude in direction of vector, mag[1, 2] are perpendicular
line vec_mult(line vec, double* mag)
{
	return (line)
	{
		.x = {vec.x[0]*mag[0] - vec.y[0]*mag[1] - vec.z[0]*mag[2], vec.x[1]*mag[0] - vec.y[1]*mag[1] - vec.z[1]*mag[2]},
		.y = {vec.x[0]*mag[1] + vec.y[0]*mag[0] + vec.z[0]*mag[1], vec.x[1]*mag[1] + vec.y[1]*mag[0] + vec.z[1]*mag[1]},
		.z = {vec.x[0]*mag[2] + vec.y[0]*mag[2] + vec.z[0]*mag[0], vec.x[1]*mag[2] + vec.y[1]*mag[2] + vec.z[1]*mag[0]}
	};
}

double* line_x_y_z(line dist)
{
	return (double [])
	{
		dist.x[1] - dist.x[0],
		dist.y[1] - dist.y[0],
		dist.z[1] - dist.z[0]
	};
}

double line_dist(line dist)
{
	return cbrt
	(
		(dist.x[0]-dist.x[1]) * (dist.x[0]-dist.x[1]) +
		(dist.y[0]-dist.y[1]) * (dist.y[0]-dist.y[1]) +
		(dist.z[0]-dist.z[1]) * (dist.z[0]-dist.z[1])
	);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void process_input(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
{
		glfwSetWindowShouldClose(window, true);
	}
}

void pan(float time)
{
	/* optionally, change perspective point */
}

double dot_product(double* a, double* b)
{
	double sum = 0;
	for (unsigned short i = 0; i < (sizeof(a) > sizeof(b) ? sizeof(b) : sizeof(a))/sizeof(double); i++) {
		sum += a[i]*b[i];
	}
	return sum;
}

double* collision_detect_and_react(Component::Instance actor_a, Component::Instance actor_b)
{
	unsigned short k = 0;
	double P[] = {actor_a.core.core.x[0], actor_a.core.core.y[0], actor_a.core.core.z[0]};
	double Q[] = {actor_b.core.core.x[0], actor_b.core.core.y[0], actor_b.core.core.z[0]};
	double R[] = {Q[0]-P[0], Q[1]-P[1], Q[2]-P[2]};
	double* U = line_x_y_z(vec_mult(actor_a.core.core, (double []){1/line_dist(actor_a.core.core), 0, 0}));
	double* V = line_x_y_z(vec_mult(actor_b.core.core, (double []){1/line_dist(actor_b.core.core), 0, 0}));
	double a, b, c, d, e, f, s, t;
	a =  dot_product(U, U);
	b = -dot_product(U, V);
	c =  dot_product(U, R);
	d =  dot_product(U, V);
	e = -dot_product(V, V);
	f =  dot_product(V, R);
	s =  (f*b-e*c)/(d*b-e*a);
	t =  (f*a-d*c)/(e*a-d*b);
	line cross =
	{
		{P[0]+U[0]*s, Q[0]+V[0]*t},
		{P[1]+U[1]*s, Q[1]+V[1]*t},
		{P[2]+U[2]*s, Q[2]+V[2]*t}
	};
	line straight = uvec(num_to_ang(0), num_to_ang(0));
	angle ang = measure(straight, cross);

	double ang_a = ang_to_num(ang) - ang_to_num(actor_a.core.rotation) + M_PI/2;
	b:
	ang_a -= M_PI;
	if (ang_a > M_PI)
	{
		goto b;
	}
	double line_a =
	(
		ang_a > M_PI
		?
		actor_a.core.thickness[0]*(1+tan(ang_a-M_PI))
		:
		actor_a.core.thickness[1]*(1+tan(ang_a))
	);

	double ang_j = ang_to_num(ang) - ang_to_num(actor_b.core.rotation) + M_PI/2;
	c:
	ang_j -= M_PI;
	if (ang_j > M_PI)
	{
		goto c;
	}
	double line_b =
	(
		ang_j > M_PI
		?
		actor_b.core.thickness[0]*(1+tan(ang_j-M_PI))
		:
		actor_b.core.thickness[1]*(1+tan(ang_j))
	);
	
	if
	(
		sqrt(line_a*line_a + line_a*line_a/tan(ang_to_num(measure(actor_a.core.core, cross)))/tan(ang_to_num(measure(actor_a.core.core, cross))))
		+
		sqrt(line_b*line_b + line_b*line_b/tan(ang_to_num(measure(actor_b.core.core, cross)))/tan(ang_to_num(measure(actor_b.core.core, cross))))
		>
		line_dist(cross)
	)
	{
		std::vector<double*> forces_acting;
		line exertion_sum =
		{
			{0, 0},
			{0, 0},
			{0, 0}
		};
		for (unsigned short l = 0; l < Force::forces_ptr.size(); l++)
		{
			double* this_force = Force::forces_ptr[l]->exert(actor_a, actor_b, ang);
			forces_acting.push_back(this_force);
			exertion_sum.x[1] += this_force[0];
			exertion_sum.y[1] += this_force[1];
			exertion_sum.z[1] += this_force[2];
		}
		double dist_to_stop = __DBL_MAX__;
		while (forces_acting.size() > 0)
		{
			for(unsigned short m = 0; m < Force::forces_ptr.size(); m++)
			{
				double force_dist = cbrt
				(
					forces_acting[m][0]*forces_acting[m][0] +
					forces_acting[m][1]*forces_acting[m][1] +
					forces_acting[m][2]*forces_acting[m][2]
				);
				if (forces_acting[m][3] < dist_to_stop)
				{
					dist_to_stop = forces_acting[m][3];
					exertion_sum = sub_lines(exertion_sum, (line){{0, forces_acting[m][0]}, {0, forces_acting[m][1]}, {0, forces_acting[m][2]}});
					double* swp = forces_acting[m];
					forces_acting[m] = forces_acting[forces_acting.size()-1];
					forces_acting[forces_acting.size()-1] = swp;
				}
				if (force_dist < dist_to_stop)
				{
					dist_to_stop = force_dist;
					double* swp = forces_acting[m];
					forces_acting[m] = forces_acting[forces_acting.size()-1];
					forces_acting[forces_acting.size()-1] = swp;
				}
			}
			forces_acting.pop_back();
		}
		return line_x_y_z(vec_mult(exertion_sum, line_x_y_z(cross)));
	}
	return (double []){0, 0, 0};
}