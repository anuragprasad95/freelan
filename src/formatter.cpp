/*
 * libkfather - C++ JSON parser/producer library.
 * Copyright (C) 2010-2012 Julien Kauffmann <julien.kauffmann@freelan.org>
 *
 * This file is part of libkfather.
 *
 * libkfather is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 3 of
 * the License, or (at your option) any later version.
 *
 * libkfather is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program. If not, see
 * <http://www.gnu.org/licenses/>.
 *
 * If you intend to use libkfather in a commercial software, please
 * contact me : we may arrange this for a small fee or no fee at all,
 * depending on the nature of your project.
 */

/**
 * \file formatter.cpp
 * \author Julien Kauffmann <julien.kauffmann@freelan.org>
 * \brief Formatter classes.
 */

#include "formatter.hpp"

#include "parser.hpp"

#include <boost/bind.hpp>

namespace kfather
{
	formatter::formatter(parser& parser, std::ostream& os) :
		m_os(os)
	{
		parser.reset_object_start_callback(boost::bind(&formatter::print_object_start, this));
		parser.reset_object_colon_callback(boost::bind(&formatter::print_object_colon, this));
		parser.reset_object_comma_callback(boost::bind(&formatter::print_object_comma, this));
		parser.reset_object_stop_callback(boost::bind(&formatter::print_object_stop, this));
		parser.reset_array_start_callback(boost::bind(&formatter::print_array_start, this));
		parser.reset_array_comma_callback(boost::bind(&formatter::print_array_comma, this));
		parser.reset_array_stop_callback(boost::bind(&formatter::print_array_stop, this));
	}

	void formatter::print_object_start()
	{
		m_os << "{";
	}

	void formatter::print_object_colon()
	{
		m_os << ": ";
	}

	void formatter::print_object_comma()
	{
		m_os << ", ";
	}

	void formatter::print_object_stop()
	{
		m_os << "}";
	}

	void formatter::print_array_start()
	{
		m_os << "[";
	}

	void formatter::print_array_comma()
	{
		m_os << ", ";
	}

	void formatter::print_array_stop()
	{
		m_os << "]";
	}
}
