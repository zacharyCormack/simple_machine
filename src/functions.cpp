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


double* collision_detect_and_react(Component::Instance actor_a, Component::Instance actor_b)
{
	line crosses[] = {
		(line)
		{
			{actor_a.core.core.x[0], actor_b.core.core.x[0]},
			{actor_a.core.core.y[0], actor_b.core.core.y[0]},
			{actor_a.core.core.z[0], actor_b.core.core.z[0]}
		},
		(line)
		{
			{actor_a.core.core.x[1], actor_b.core.core.x[0]},
			{actor_a.core.core.y[1], actor_b.core.core.y[0]},
			{actor_a.core.core.z[1], actor_b.core.core.z[0]}
		},
		(line)
		{
			{actor_a.core.core.x[0], actor_b.core.core.x[1]},
			{actor_a.core.core.y[0], actor_b.core.core.y[1]},
			{actor_a.core.core.z[0], actor_b.core.core.z[1]}
		},
		(line)
		{
			{actor_a.core.core.x[1], actor_b.core.core.x[1]},
			{actor_a.core.core.y[1], actor_b.core.core.y[1]},
			{actor_a.core.core.z[1], actor_b.core.core.z[1]}
		}
	};
	line straight = uvec(num_to_ang(0), num_to_ang(0));
	angle angs[4][3] = {
		{measure(actor_a.core.core, crosses[0]), measure(actor_b.core.core, crosses[0]), measure(crosses[0], straight)},
		{measure(actor_a.core.core, crosses[1]), measure(actor_b.core.core, crosses[0]), measure(crosses[0], straight)},
		{measure(actor_a.core.core, crosses[2]), measure(actor_b.core.core, crosses[0]), measure(crosses[0], straight)},
		{measure(actor_a.core.core, crosses[3]), measure(actor_b.core.core, crosses[0]), measure(crosses[0], straight)}
	};
	unsigned short k = 0;
	while (k++ < 4)
	{
		double this_ang_i = ang_to_num(angs[k][2]) - ang_to_num(actor_a.core.rotation) + M_PI/2;
		b:
		this_ang_i -= M_PI;
		if (this_ang_i > M_PI)
		{
			goto b;
		}
		double this_i =
		(
			this_ang_i > M_PI
			?
			actor_a.core.thickness[0]*(1+tan(this_ang_i-M_PI))
			:
			actor_a.core.thickness[1]*(1+tan(this_ang_i))
		);

		double this_ang_j = ang_to_num(angs[k][2]) - ang_to_num(actor_b.core.rotation) + M_PI/2;
		c:
		this_ang_j -= M_PI;
		if (this_ang_j > M_PI)
		{
			goto c;
		}
		double this_j =
		(
			this_ang_j > M_PI
			?
			actor_b.core.thickness[0]*(1+tan(this_ang_j-M_PI))
			:
			actor_b.core.thickness[1]*(1+tan(this_ang_j))
		);
		if
		(
			sqrt(this_i*this_i + this_i*this_i/tan(ang_to_num(angs[k][0]))/tan(ang_to_num(angs[k][0])))
			+
			sqrt(this_j*this_j + this_j*this_j/tan(ang_to_num(angs[k][1]))/tan(ang_to_num(angs[k][1])))
			>
			line_dist(crosses[k])
		)
		{
			break;
		}
	}
	double* force_exerted = 0;
	if (k < 4)
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
			double* this_force = Force::forces_ptr[l]->exert(actor_a, actor_b, angs[k][2]);
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
		return line_x_y_z(vec_mult(exertion_sum, line_x_y_z(crosses[k])));
	}
	return (double []){0, 0, 0};
}