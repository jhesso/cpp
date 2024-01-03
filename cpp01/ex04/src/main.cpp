/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:34:33 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/20 15:37:43 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

bool	openFiles(std::ifstream *ifs, std::ofstream *ofs,
					std::string infile, std::string outfile)
{
	ifs->open(infile.c_str(), std::ifstream::in);
	if (!ifs->good())
	{
		std::cerr << "Error: " << infile << ": open failed" << std::endl;
		return (false);
	}
	ofs->open(outfile.c_str(), std::ofstream::out | std::ofstream::trunc);
	if (!ofs->good())
	{
		ifs->close();
		std::cerr << "Error: " << outfile << ": open failed" << std::endl;
		return (false);
	}
	return (true);
}

void	replaceStr(std::string *buf, std::string const target, std::string const replace)
{
	size_t	pos;

	pos = 0;
	if (target.empty())
		return ;
	while (pos != std::string::npos)
	{
		pos = buf->find(target.c_str(), pos);
		if (pos == std::string::npos)
			break;
		buf->erase(pos, target.length());
		if (!replace.empty())
		{
			buf->insert(pos, replace);
			pos += replace.length();
		}
	}
}

bool	copy(std::ifstream *ifs, std::ofstream *ofs,
					std::string const target, std::string const replace)
{
	std::string	buf;

	while (std::getline(*ifs, buf))
	{
		if (ifs->fail())
			return (false);
		replaceStr(&buf, target, replace);
		*ofs << buf;
		if (!ifs->eof())
			*ofs << std::endl;
	}
	return (true);
}

int	main(int ac, char **av)
{
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		infile,
					outfile,
					target,
					replace;

	if (ac != 4)
	{
		std::cout	<< "Usage: " << av[0] << " <filename> <string_to_replace>"
					<< " <replacement_string>" << std::endl;
		return (1);
	}
	infile = av[1];
	outfile = infile;
	outfile.append(".replace");
	target = av[2];
	replace = av[3];
	if (!openFiles(&ifs, &ofs, infile, outfile))
		return (1);
	if (!copy(&ifs, &ofs, target, replace))
	{
		std::cerr << "Error: " << infile << ": read failed" << std::endl;
		return (1);
	}
	return (0);
}
