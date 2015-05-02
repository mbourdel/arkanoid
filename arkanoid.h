/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arkanoid.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 14:21:27 by jbahus            #+#    #+#             */
/*   Updated: 2015/05/02 23:21:14 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARKANOID_H
# define ARKANOID_H

# include "glfw/include/GLFW/glfw3.h"
# include "libft/libft.h"

# define X_BEGIN -0.918f
# define Y_BEGIN 0.92f
# define X_VAR 0.071f
# define X_INC 0.153f
# define Y_VAR 0.035f

typedef struct s_squa	t_squa;
struct					s_squa
{
	float				x;
	float				y;
	char				type;
};

typedef struct s_env	t_env;
struct					s_env
{
	int					width;
	int					height;
	float				bar;
	t_squa				squa;
};

void					square_create(t_squa squa);
void					the_bar(t_env *env);

#endif
