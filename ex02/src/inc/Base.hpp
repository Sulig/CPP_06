/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:46:23 by sadoming          #+#    #+#             */
/*   Updated: 2025/04/24 17:46:48 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>
# include <stdint.h>

class	Base
{
	public:
		virtual	~Base();

		static Base	*	generate(void);
		static void	identify(Base *p);
		static void	identify(Base &p);

	protected:
		Base();
		Base(const Base &src);
		Base &operator=(const Base &src);
};

#endif
