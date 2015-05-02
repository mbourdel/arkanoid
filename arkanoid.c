/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arkanoid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 17:17:10 by mbourdel          #+#    #+#             */
/*   Updated: 2015/05/02 23:36:55 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void	env_init(t_env *env)
{
	env->squa.x = -0.918f;
	env->squa.y = 0.92f;
	env->bar = 0.f;
}

void	key_callback(GLFWwindow *win, int key, int scancode, int action,
		int mods)
{
	if (!scancode && !win && !mods)
		scancode = scancode + 0;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(win, GL_TRUE);
}

int		main(int ac, char **av)
{
	GLFWwindow	*win;
	t_env		env;
	int			state;

	if (!glfwInit())
		exit(EXIT_FAILURE);
	win = glfwCreateWindow(2560, 1440, "Arkanoid",
			glfwGetPrimaryMonitor(), NULL);
	if (!win)
	{
		glfwTerminate();
		return (-1);
	}
	env_init(&env);
	glfwMakeContextCurrent(win);
	glfwSetKeyCallback(win, key_callback);
	while (!glfwWindowShouldClose(win))
	{
		if (GLFW_PRESS == (state = glfwGetKey(win, GLFW_KEY_LEFT)))
			env.bar -= 0.03f;
		if (GLFW_PRESS == (state = glfwGetKey(win, GLFW_KEY_RIGHT)))
			env.bar += 0.03f;
		glClear(GL_COLOR_BUFFER_BIT);
		glfwGetFramebufferSize(win, &env.width, &env.height);
		glViewport(0, 0, env.width, env.height);
		square_create(env.squa);
		the_bar(&env);
		glfwPollEvents();
		glfwSwapBuffers(win);
	}
	glfwDestroyWindow(win);
	glfwTerminate();
	return (0);
}
