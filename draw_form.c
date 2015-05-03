/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_form.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 20:21:08 by mbourdel          #+#    #+#             */
/*   Updated: 2015/05/03 12:42:05 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static void		brick_color(char c)
{
	if (c == 1)
		glColor3b(102, 102, 255);
	if (c == 2)
		glColor3b(255, 0, 127);
	if (c == 3)
		glColor3b(255, 102, 102);
	if (c == 4)
		glColor3b(255, 0, 0);
}

void		square_create(t_env *env)
{	
	while (env->squa.y > 0.f)
	{
		while (env->squa.x < 0.97f)
		{
			if (env->map[i] != '\n' && i < 139 && env->map[i] > '0')
			{
				glBegin(GL_QUADS);
				brick_color(env->map[i]);
				glVertex2f(env->squa.x - X_VAR, env->squa.y - Y_VAR);
				glVertex2f(env->squa.x + X_VAR, env->squa.y - Y_VAR);
				glVertex2f(env->squa.x + X_VAR, env->squa.y + Y_VAR);
				glVertex2f(env->squa.x - X_VAR, env->squa.y + Y_VAR);
				glEnd();
			}
			env->squa.x = env->squa.x + X_INC;
		}
		env->squa.x = X_BEGIN;
		env->squa.y = env->squa.y - 0.092f;
	}
}

void		the_bar(t_env *env)
{
	glBegin(GL_QUADS);
	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex2f(-0.1f + env->bar, -0.92f);
	glVertex2f(0.1f + env->bar, -0.92f);
	glVertex2f(0.1f + env->bar, -0.96f);
	glVertex2f(-0.1f + env->bar, -0.96f);
	glEnd();
}
