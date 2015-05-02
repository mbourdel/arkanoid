/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_form.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 20:21:08 by mbourdel          #+#    #+#             */
/*   Updated: 2015/05/02 23:20:43 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void		square_create(t_squa squa)
{	
	while (squa.y > 0.f)
	{
		while (squa.x < 0.97f)
		{
			glBegin(GL_QUADS);
			glColor3f(0.9f, 0.9f, 0.9f);
			glVertex2f(squa.x - X_VAR, squa.y - Y_VAR);
			glVertex2f(squa.x + X_VAR, squa.y - Y_VAR);
			glVertex2f(squa.x + X_VAR, squa.y + Y_VAR);
			glVertex2f(squa.x - X_VAR, squa.y + Y_VAR);
			glEnd();
			squa.x = squa.x + X_INC;
		}
		squa.x = X_BEGIN;
		squa.y = squa.y - 0.092f;
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
